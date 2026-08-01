#include "logger.hh"

#include <iostream>

namespace erg {
    void Logger::fatal(const std::string& message) {
        std::cout << "\033[31;41m" << message << "\033[0m" << std::endl;
        std::abort();
    }

    void Logger::error(std::string_view message) {
        std::cout << "\033[31m" << message << "\033[0m" << std::endl;
    }
} // erg
