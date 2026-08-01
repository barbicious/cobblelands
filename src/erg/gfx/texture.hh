#pragma once
#include "i_bindable.hh"
#include "../../types.hh"

namespace erg::gfx {
    class Texture : public IBindable {
    public:
        explicit Texture(u32 target);
        ~Texture() override;

        void bind() override;
        void unbind() override;

    protected:
        u32 getTarget() const noexcept;

    private:
        u32 handle;
        u32 target;
    };
} // erg::gfx
