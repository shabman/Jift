/* 
 * This file is part of the JiftUI distribution (https://github.com/shabman/Jift.git)
 * Copyright (c) 2024 Mustafa Malik.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef JIFT_LOGGER_H
#define JIFT_LOGGER_H

#include <iostream>

enum LogLevel {
    DEBUG,
    VERBOSE,
    INFO,
    FATAL,
    TEST_OK,
    ALERT
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
            case ALERT:
                printColoredText("\033[1;34m[ALERT] " + message + "\033[0m", end); // Blue
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
