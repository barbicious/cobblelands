#include <array>
#include <iostream>

#include "types.hh"
#include "erg/ec/component.hh"
#include "erg/ec/entity.hh"
#include "erg/ec/i_blittable.hh"
#include "erg/window.hh"
#include "erg/gfx/image_texture.hh"
#include "erg/gfx/shader.hh"
#include "erg/gfx/vertex_array.hh"
#include "erg/gfx/vertex_buffer.hh"
#include "erg/inp/input_binding.hh"
#include "erg/inp/input_handler.hh"
#include "erg/inp/keyboard.hh"

class CppComponent : public erg::ec::Component {
public:
    bool cpp_rules;

    explicit CppComponent(const bool whatever) : cpp_rules{whatever} {
    }
};

class TestComponent : public erg::ec::Component, public erg::ec::IBlittable {
public:
    void blit() override {
        std::cout << "BLIT!" << std::endl;
    }
};

class UpCommand : public erg::inp::ICommand {
public:
    UpCommand(std::tuple<i32, i32>& window_pos) : window_pos{window_pos} {

    }

    void execute() override {
        std::get<1>(window_pos)--;
    }

private:
    std::tuple<i32, i32>& window_pos;
};

class RightCommand : public erg::inp::ICommand {
public:
    RightCommand(std::tuple<i32, i32>& window_pos) : window_pos{window_pos} {

    }

    void execute() override {
        std::get<0>(window_pos)++;
    }

private:
    std::tuple<i32, i32>& window_pos;
};

i32 main() {
    erg::ec::Entity entity{TestComponent{}, CppComponent{true}, TestComponent{}};

    entity.blit();

    erg::Window window{{.width = 1280, .height = 720, .title = "Cobblelands"}};
    erg::inp::Keyboard keyboard{};

    std::tuple window_pos{300, 100};

    erg::inp::InputBinding<erg::inp::Keyboard> up_binding{
        .function = [](const erg::inp::Keyboard& k) { return k.isKeyDown(GLFW_KEY_W); },
        .command = std::make_unique<UpCommand>(window_pos)
    };

    erg::inp::InputBinding<erg::inp::Keyboard> right_binding{
        .function = [](const erg::inp::Keyboard& k) { return k.isKeyDown(GLFW_KEY_D); },
        .command = std::make_unique<RightCommand>(window_pos)
    };

    erg::inp::InputHandler input_handler{};

    input_handler += up_binding;
    input_handler += right_binding;

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
            },
            std::nullopt
        }
    };
    shader.bind();

    erg::gfx::VertexArray vertex_array{};
    vertex_array.bind();

    std::array vertices{
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
    };

    std::array sizes{3, 2};

    erg::gfx::VertexBuffer vertex_buffer{vertices, sizes};
    vertex_buffer.bind();

    erg::gfx::ImageTexture image_texture{"res/textures/atlas.png"};
    image_texture.bind();

    while (window.isGood()) {
        keyboard.tick(window);
        input_handler.tick(keyboard);

        window.setPosition(std::get<0>(window_pos), std::get<1>(window_pos));

        glClearColor(1.0, 0.75, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        window.display();
    }

    glfwTerminate();
}
