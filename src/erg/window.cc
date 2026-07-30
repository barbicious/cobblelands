#include "window.hh"

#include <stdexcept>

#include "logger.hh"

namespace erg {
    static void framebufferSizeCallback(GLFWwindow *glfw_window, i32 width, i32 height) {
        auto *window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(glfw_window));

        window->width = width;
        window->height = height;

        glViewport(0, 0, window->width, window->height);
    }

    Window::Window(const Config &config) : handle{nullptr}, width{config.width}, height{config.height} {
        if (!glfwInit()) {
            Logger::fatal("Failed to init glfw");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        GLFWwindow *handle{
            glfwCreateWindow(static_cast<i32>(config.width), static_cast<i32>(config.height), config.title.c_str(),
                             nullptr, nullptr)
        };
        if (handle == nullptr) {
            glfwTerminate();
            Logger::fatal("Failed to create GLFW window");
        }

        this->handle = handle;

        glfwMakeContextCurrent(handle);

        if (!gladLoadGL(glfwGetProcAddress)) {
            glfwTerminate();
            Logger::fatal("Failed to load GL functions");
        }

        glfwSetWindowUserPointer(this->handle, this);
        glfwSetFramebufferSizeCallback(this->handle, framebufferSizeCallback);
    }

    Window::~Window() {
        glfwDestroyWindow(handle);
    }

    bool Window::isGood() const noexcept {
        glfwPollEvents();
        return !glfwWindowShouldClose(handle);
    }

    void Window::display() const noexcept {
        glfwSwapBuffers(handle);
    }
} // eg
