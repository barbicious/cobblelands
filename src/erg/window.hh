#pragma once
#include <string>

#include "../types.hh"
#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace erg {
    class Window {
    public:
        struct Config {
            u32 width;
            u32 height;
            std::string title;
        };

        explicit Window(const Config &config);

        ~Window();

        bool isGood() const noexcept;

        void display() const noexcept;

        friend void framebufferSizeCallback(GLFWwindow *glfw_window, i32 width, i32 height);

    private:
        GLFWwindow *handle;
        u32 width;
        u32 height;
    };
} // eg
