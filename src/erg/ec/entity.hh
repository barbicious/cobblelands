#pragma once

#include <vector>
#include <memory>

#include "entity.hh"

#include "component.hh"
#include "i_blittable.hh"
#include "i_tickable.hh"

namespace erg::ec {
    class Entity : public ITickable, public IBlittable {
    public:
        template<typename... Cs>
        explicit Entity(Cs... components) {
            (this->components.emplace_back(std::make_unique<std::decay_t<Cs> >(std::forward<Cs>(components))), ...);
        }

        void addComponent(std::unique_ptr<Component> component);

        void tick() override;

        void blit() override;

    private:
        std::vector<std::unique_ptr<Component> > components;
        std::vector<IBlittable *> blittables;
        std::vector<ITickable *> tickables;
    };
} // erg::ec
