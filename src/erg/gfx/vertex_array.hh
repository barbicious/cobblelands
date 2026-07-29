#pragma once
#include "i_bindable.hh"
#include "../../types.hh"

namespace erg::gfx {
    class VertexArray : public IBindable {
    public:
        VertexArray();

        void bind() override;

    private:
        u32 handle;
    };
}
