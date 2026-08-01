#include "keyboard.hh"

namespace erg::inp {
    Keyboard::Keyboard() : current_keys{}, previous_keys{} {
    }

    bool Keyboard::isKeyDown(const u32 keycode) const {
        return current_keys[keycode] && previous_keys[keycode];
    }

    bool Keyboard::isKeyPressed(const u32 keycode) const {
        return current_keys[keycode] && !previous_keys[keycode];
    }

    void Keyboard::tick(const Window& window) {
        for (usize i{0}; i < MAX_KEYS; ++i) {
            previous_keys[i] = current_keys[i];
        }

        for (usize i{0}; i < MAX_KEYS; ++i) {
            if (window.getKey(i)) {
                current_keys[i] = true;
            } else {
                current_keys[i] = false;
            }
        }
    }
} // erg::inp
