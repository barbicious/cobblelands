#include "buffer.hh"

#include "glad/gl.h"

namespace erg::gfx {
    Buffer::Buffer(const u32 buffer_target) {
        glGenBuffers(1, &handle);
        glBindBuffer(buffer_target, handle);
    }
}
