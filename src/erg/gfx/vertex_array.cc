#include "vertex_array.hh"

#include "glad/gl.h"

namespace erg::gfx {
    VertexArray::VertexArray() : handle{} {
        glGenVertexArrays(GL_VERTEX_ARRAY, &handle);
    }

    void VertexArray::bind() {
        glBindVertexArray(handle);
    }
}
