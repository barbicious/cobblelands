#include "component.hh"

namespace erg::ec {
    Component::Component() : owner{nullptr} {
    }

    void Component::setOwner(Entity* owner) {
        this->owner = owner;
    }
} // erg::ec
