#pragma once

namespace erg::ec {
    class IBlittable {
    public:
        virtual ~IBlittable() = default;

        virtual void blit() = 0;
    };
} // erg::ec
