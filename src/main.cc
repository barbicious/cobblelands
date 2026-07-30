#include <array>
#include <iostream>

#include "types.hh"
#include "erg/ec/component.hh"
#include "erg/ec/entity.hh"
#include "erg/ec/i_blittable.hh"
#include "erg/window.hh"
#include "erg/gfx/shader.hh"
#include "erg/gfx/vertex_array.hh"
#include "erg/gfx/vertex_buffer.hh"

class TestComponent : public erg::ec::Component, public erg::ec::IBlittable {
public:
    void blit() override {
        std::cout << "BLIT!" << std::endl;
    }
};

class CppComponent : public erg::ec::Component {
public:
    bool cpp_rules;

    CppComponent() : cpp_rules{true} {

    }
};

i32 main() {
    TestComponent component{};

    erg::ec::Entity entity{};
    entity.addComponent(std::make_unique<CppComponent>(CppComponent{}));

    std::cout << (entity.getComponent<TestComponent>() == nullptr) << std::endl;

    entity.blit();

    const erg::Window window{erg::Window::Config{.width = 1280, .height = 720, .title = "Cobblelands"}};

    glViewport(0, 0, 1280, 720);

    erg::gfx::Shader shader{
            {
                erg::gfx::Shader::Desc{
                    .type = GL_VERTEX_SHADER,
                    .path = "res/shaders/triangle.vert"
                },
                erg::gfx::Shader::Desc{
                    .type = GL_FRAGMENT_SHADER,
                    .path = "res/shaders/triangle.frag"
                }
            }
    };
    shader.bind();

    erg::gfx::VertexArray vertex_array{};
    vertex_array.bind();

    std::array vertices{
        -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
    };

    std::array sizes{ 3 };

    erg::gfx::VertexBuffer vertex_buffer{vertices, sizes};
    vertex_buffer.bind();

    while (window.isGood()) {
        glClearColor(1.0, 0.75, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.display();
    }

    glfwTerminate();
}
