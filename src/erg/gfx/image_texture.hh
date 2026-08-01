#pragma once
#include <filesystem>

#include "texture.hh"

namespace erg::gfx {
    class ImageTexture : public Texture {
    public:
        explicit ImageTexture(std::string_view file_path);

    private:
        i32 channels;
        i32 width;
        i32 height;
    };
}
