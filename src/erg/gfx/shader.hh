#pragma once

#include <filesystem>
#include <span>

#include "i_bindable.hh"
#include "../../types.hh"

namespace erg::gfx {
    class Shader : public IBindable {
    public:
        struct Desc {
            i32 type;
            std::filesystem::path path;
        };

        explicit Shader(std::vector<Desc> descs);
        ~Shader() override;
        void bind() override;

    private:
        u32 handle;
    };
} // erg::gfx
