#include "vertex_buffer.hh"

#include <numeric>

#include "glad/gl.h"

namespace erg::gfx {
    VertexBuffer::VertexBuffer(const std::span<f32> vertices, const std::span<i32> vertex_attrib_sizes) : Buffer{
        GL_ARRAY_BUFFER
    } {
        glBufferData(getBufferTarget(), vertices.size() * sizeof(f32), vertices.data(), GL_STATIC_DRAW);

        const i32 stride{std::accumulate(vertex_attrib_sizes.begin(), vertex_attrib_sizes.end(), 0)};

        i32 i{0};
        i32 last_size{0};
        for (const i32& vertex_attrib_size: vertex_attrib_sizes) {
            glVertexAttribPointer(i, vertex_attrib_size, GL_FLOAT, GL_FALSE, stride * sizeof(f32),
                                  reinterpret_cast<void*>(last_size * sizeof(f32)));
            glEnableVertexAttribArray(i);
            last_size = vertex_attrib_size;
            ++i;
        }
    }
}
