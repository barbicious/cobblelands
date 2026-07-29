#include <iostream>

#include "types.hh"
#include "erg/logger.hh"
#include "erg/ec/component.hh"
#include "erg/ec/entity.hh"
#include "erg/ec/i_blittable.hh"
#include "erg/window.hh"

class TestComponent : public erg::ec::Component, public erg::ec::IBlittable {
public:
    void blit() override {
        std::cout << "BLIT!" << std::endl;
    }
};

i32 main() {
    TestComponent component{};

    erg::ec::Entity entity{};
    entity.addComponent(std::make_unique<TestComponent>(component));

    entity.blit();

    const erg::Window window{erg::Window::Config{.width = 1280, .height = 720, .title = "Cobblelands"}};

    glViewport(0, 0, 1280, 720);

    while (window.isGood()) {
        glClearColor(1.0, 0.75, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        window.display();
    }

    glfwTerminate();
}
