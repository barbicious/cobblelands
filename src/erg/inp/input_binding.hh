#pragma once
#include <functional>
#include <memory>

#include "i_command.hh"
#include "keyboard.hh"

namespace erg::inp {
    template <typename T>
    struct InputBinding {
        std::function<bool(T)> function;
        std::unique_ptr<ICommand> command;
    };
} // erg::inp
