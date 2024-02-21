#pragma once

#include "compiler/lexer/jift_lexer.hpp"
#include "log/jift_log.hpp"
#include "jift_assert.h"

#include <map>
#include <iostream>

void __jift_test_package() {
    Jift::Compiler::Lexer lexer;

    std::unordered_map<std::string, bool> packages = {
        {"package com.test;",   false},
        {"package",             true},
        {"package;",            true},
        {"package com",         true},
        {"packagecom",          true},
        {"package com.",        true},
        {"package .com",        true},
        {"package.com",         true},
        {"package com.test",    true},
        {"package com.;",       true}
    };

    for (const std::pair<std::string, bool>& package : packages) {
        lexer.set_source(package.first);
        bool result = lexer.validate_package();
        std::string pkg = package.first + " ";

        jift_assert((package.second != result), pkg, ": TEST PASSED");
    }
}