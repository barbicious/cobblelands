#include "shader.hh"

#include <array>
#include <fstream>
#include <span>
#include <stack>
#include <glad/gl.h>

#include "../logger.hh"

namespace erg::gfx {
    Shader::Shader(std::array<const std::optional<const Desc>, 3> descs) : handle{glCreateProgram()} {
        std::stack<i32> shaders{};

        for (const std::optional<Desc> desc: descs) {
            if (!desc) {
                continue;
            }

            const u32 shader{glCreateShader(desc->type)};

            std::ifstream file{};
            file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
            file.open(desc->path);

            std::stringstream shader_stream{};
            shader_stream << file.rdbuf();

            file.close();

            std::string shader_src{shader_stream.str()};
            const char* shader_c_src{shader_src.c_str()};

            glShaderSource(shader, 1, &shader_c_src, nullptr);
            glCompileShader(shader);

            i32 success{0};
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                std::array < char, 512 > info_log{};
                glGetShaderInfoLog(shader, info_log.size(), nullptr, info_log.data());
                Logger::fatal(std::format("Failed to compile shader!\nError: {}", info_log.data()));
            }

            shaders.push(shader);
        }

        while (!shaders.empty()) {
            const i32 shader{shaders.top()};
            shaders.pop();

            glAttachShader(handle, shader);
        }

        glLinkProgram(handle);

        i32 success{0};
        glGetProgramiv(handle, GL_LINK_STATUS, &success);
        if (!success) {
            std::array < char, 512 > info_log{};
            glGetProgramInfoLog(handle, info_log.size(), nullptr, info_log.data());
            Logger::fatal(std::format("Failed to link shader!\nError: {}", info_log.data()));
        }
    }

    Shader::~Shader() {
        glDeleteProgram(handle);
    }

    void Shader::bind() {
        glUseProgram(handle);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }
} // erg::gfx
