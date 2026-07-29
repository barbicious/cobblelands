#pragma once

namespace erg::ec {
    class ITickable {
    public:
        virtual ~ITickable() = default;

        virtual void tick() = 0;
    };
} // erg::ec
