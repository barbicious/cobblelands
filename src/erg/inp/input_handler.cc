#include "input_handler.hh"

namespace erg::inp {
    InputHandler::InputHandler() {
    }

    void InputHandler::tick(const Keyboard& keyboard) const {
        for (const InputBinding<Keyboard>& key_binding: key_bindings) {
            if (key_binding.function(keyboard)) {
                key_binding.command->execute();
            }
        }
    }

    void InputHandler::operator+=(InputBinding<Keyboard>& input_binding) {
        key_bindings.emplace_back(std::move(input_binding));
    }
} // erg::inp
