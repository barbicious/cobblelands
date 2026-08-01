#pragma once

namespace erg::inp {
    class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual void execute() = 0;
    };
} // erg::inp
