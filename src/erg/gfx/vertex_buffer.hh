#pragma once

#include "buffer.hh"

#include <span>

namespace erg::gfx {
    class VertexBuffer : public Buffer {
    public:
        VertexBuffer(std::span<f32> vertices, std::span<i32> vertex_attrib_sizes);
    };
}
