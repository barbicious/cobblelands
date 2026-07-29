cmake_minimum_required(VERSION 4.2)
project(cobblelands)

set(CMAKE_CXX_STANDARD 23)

add_executable(cobblelands ext/glad/src/gl.c src/main.cc
        src/types.hh
        src/erg/ec/entity.cc
        src/erg/ec/entity.hh
        src/erg/ec/i_blittable.hh
        src/erg/ec/i_tickable.hh
        src/erg/ec/component.cc
        src/erg/ec/component.hh
        src/erg/window.cc
        src/erg/window.hh
        src/erg/logger.cc
        src/erg/logger.hh
        src/erg/gfx/i_bindable.hh
        src/erg/gfx/vertex_array.cc
        src/erg/gfx/vertex_array.hh
        src/erg/gfx/buffer.cc
        src/erg/gfx/buffer.hh
        src/erg/gfx/vertex_buffer.cc
        src/erg/gfx/vertex_buffer.hh)

add_subdirectory(ext/glfw)

target_include_directories(cobblelands PRIVATE ext/glad/include)

target_link_libraries(cobblelands PRIVATE glfw)