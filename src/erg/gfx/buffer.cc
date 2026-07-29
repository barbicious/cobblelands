#include "buffer.hh"

#include "glad/gl.h"

namespace erg::gfx {
    Buffer::Buffer(const u32 buffer_target) : handle{}, buffer_target{buffer_target} {
        glGenBuffers(1, &handle);
        Buffer::bind();
    }

    void Buffer::bind() {
        glBindBuffer(buffer_target, handle);
    }
}
