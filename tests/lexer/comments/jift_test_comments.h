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

#pragma once

#include "compiler/lexer/jift_lexer.hpp"
#include "log/jift_log.hpp"
#include "jift_assert.h"
#include "jift_util.hpp"

#include <map>
#include <iostream>

#define SHOULD_FAIL true
#define SHOULD_PASS false

#ifndef __JIFT_DEBUG_TEST__
#   error Please define __JIFT_DEBUG_TEST__ before testing any Compiler Behaviour
#endif

void __jift_test_comments() {
    Jift::Compiler::Lexer lexer;

    /* WILL PASS = FALSE, WILL FAIL = TRUE */
    std::unordered_map<std::string, bool> start_comments = {
        {"//",  SHOULD_PASS},
        {"/*",  SHOULD_PASS},
        {"/**", SHOULD_PASS},
    };

    std::unordered_map<std::string, bool> end_comments = {
        {"*/",          SHOULD_PASS},
        {"****/",       SHOULD_PASS},
        {"*******/",    SHOULD_PASS},
    };

    for (const std::pair<std::string, bool>& package : start_comments) {

        JIFT_SLEEP_MS(150);

        lexer.set_source(package.first);
        bool result = lexer.validate_package();
        std::string pkg = package.first + " ";

        // if (package.first == "package 123;" || package.first == "package 123.test;" || package.first == "package !!;") {
        //     std::cout << result << std::endl;
        // }

        jift_assert((package.second != result), pkg, ": TEST PASSED");
        if (package.second == result) {
            std::string err = package.first + " what the hell man...???\n"; 
            JiftLogger::log(ALERT, err, true);
        }
    }
}