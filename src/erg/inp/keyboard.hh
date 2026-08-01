#pragma once
#include <array>

#include "../window.hh"

namespace erg::inp {
    class Keyboard {
    public:
        static constexpr usize MAX_KEYS{GLFW_KEY_F12};

        Keyboard();

        bool isKeyDown(u32 keycode) const;
        bool isKeyPressed(u32 keycode) const;

        void tick(const Window& window);

    private:
        std::array<bool, MAX_KEYS> current_keys;
        std::array<bool, MAX_KEYS> previous_keys;
    };
} // erg::inp
