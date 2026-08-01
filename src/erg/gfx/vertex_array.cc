#include "vertex_array.hh"

#include "glad/gl.h"

namespace erg::gfx {
    VertexArray::VertexArray() : handle{} {
        glGenVertexArrays(1, &handle);
    }

    void VertexArray::bind() {
        glBindVertexArray(handle);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }
}
