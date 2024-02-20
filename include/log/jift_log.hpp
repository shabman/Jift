#ifndef JIFT_LOGGER_H
#define JIFT_LOGGER_H

#include <iostream>

enum LogLevel {
    DEBUG,
    VERBOSE,
    INFO,
    FATAL,
    TEST_OK
};

class JiftLogger final {
public:
    static void log(LogLevel level, const std::string& message, bool end) {
        switch (level) {
            case DEBUG:
                printColoredText("\033[1;34m[DEBUG] " + message + "\033[0m", end); // Blue
                break;
            case VERBOSE:
                printColoredText("\033[1;35m[VERBOSE] " + message + "\033[0m", end); // Magenta
                break;
            case INFO:
                printColoredText("[INFO] " + message, end); // Default color
                break;
            case FATAL:
                printColoredText("\033[1;31m[FATAL] " + message + "\033[0m", end); // Red
                break;
            case TEST_OK:
                printColoredText("\033[1;32m[PASSED] " + message + "\033[0m", end); // Green
                break;
            default:
                break;
        }
    }

private:
    static void printColoredText(const std::string& text, bool end) {
        if (end) {
            std::cout << text << std::endl;
        } else {
            std::cout << text;
        }
    }
};

#endif // JIFT_LOGGER_H
