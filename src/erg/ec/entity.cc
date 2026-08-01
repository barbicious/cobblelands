#include "entity.hh"

#include <iostream>

namespace erg::ec {
    void Entity::addComponent(std::unique_ptr<Component> component) {
        component->setOwner(this);

        if (auto* blittable{dynamic_cast<IBlittable*>(component.get())}) {
            blittables.push_back(blittable);
        }

        if (auto* tickable{dynamic_cast<ITickable*>(component.get())}) {
            tickables.push_back(tickable);
        }

        components.push_back(std::move(component));
    }

    void Entity::tick() {
        for (auto tickable: tickables) {
            tickable->tick();
        }
    }

    void Entity::blit() {
        for (auto blittable: blittables) {
            blittable->blit();
        }
    }
} // erg::ec
