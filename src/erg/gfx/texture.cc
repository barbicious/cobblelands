#include "texture.hh"

#include <glad/gl.h>

namespace erg::gfx {
    Texture::Texture(const u32 target) : handle{0}, target{target} {
        glGenTextures(1, &handle);

        Texture::bind();
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &handle);
    }

    void Texture::bind() {
        glBindTexture(target, handle);
    }

    void Texture::unbind() {
        glBindTexture(target, 0);
    }

    u32 Texture::getTarget() const noexcept {
        return target;
    }
} // erg::gfx
