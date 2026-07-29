#pragma once
#include "../../types.hh"

namespace erg::gfx {
    class Buffer {
    public:
        explicit Buffer(u32 buffer_target);
    private:
        u32 handle;
    };
}
