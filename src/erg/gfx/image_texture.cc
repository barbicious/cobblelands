#include "image_texture.hh"

#define STB_IMAGE_IMPLEMENTATION
#include <iostream>

#include "stb_image.h"

#include <glad/gl.h>

#include "../logger.hh"

namespace erg::gfx {
    ImageTexture::ImageTexture(const std::string_view file_path) : Texture{GL_TEXTURE_2D}, channels{}, width{},
                                                                   height{} {
        if (u8* data{stbi_load(file_path.data(), &width, &height, &channels, 0)}; data != nullptr) {
            const u32 target{getTarget()};

            glTexImage2D(target, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(target);

            stbi_image_free(data);
        } else {
            Logger::error(std::format("Failed to load image {}", file_path));
        }

        Texture::unbind();
    }
} // erg::gfx
