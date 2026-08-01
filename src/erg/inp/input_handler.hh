#pragma once
#include <vector>

#include "input_binding.hh"

namespace erg::inp {
    class InputHandler {
    public:
        InputHandler();

        void tick(const Keyboard& keyboard) const;

        void operator+=(InputBinding<Keyboard>& input_binding);

    private:
        std::vector<InputBinding<Keyboard>> key_bindings;
    };
} // erg::inp
