#pragma once
#include "i_bindable.hh"
#include "../../types.hh"

namespace erg::gfx {
    class Buffer : public IBindable {
    public:
        explicit Buffer(u32 buffer_target);
        void bind() override;
    private:
        u32 handle;
        u32 buffer_target;
    };
}
