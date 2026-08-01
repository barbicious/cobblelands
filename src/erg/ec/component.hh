#pragma once

namespace erg::ec {
    class Entity;

    class Component {
    public:
        Component();

        virtual ~Component() = default;

        void setOwner(Entity* owner);

    private:
        Entity* owner;
    };
} // erg::ec
