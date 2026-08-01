#pragma once
#include <string>

namespace erg {
    class Logger {
    public:
        static void fatal(const std::string& message);
        static void error(std::string_view message);
    };
} // erg
