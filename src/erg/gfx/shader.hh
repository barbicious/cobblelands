#pragma once

#include <filesystem>

#include "i_bindable.hh"
#include "../../types.hh"

namespace erg::gfx {
    class Shader : public IBindable {
    public:
        struct Desc {
            i32 type;
            std::filesystem::path path;
        };

        explicit Shader(std::array<const std::optional<const Desc>, 3> descs);

        ~Shader() override;

        void bind() override;
        void unbind() override;

    private:
        u32 handle;
    };
} // erg::gfx
