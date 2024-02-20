#pragma once

#include "compiler/lexer/jift_lexer.hpp"
#include "log/jift_log.hpp"
#include <vector>
#include <iostream>

void __jift_test_package() {
    Jift::Compiler::Lexer lexer;
    std::vector<std::string> packages = {
        "package com.test;",
        "package",
        "package;",
        "package com",
        "packagecom",
        "package com.",
        "package .com",
        "package.com",
        "package com.test"
    };

    JiftLogger::log(INFO, "Testing Jift Lexer Packages", true);

    for (const std::string& package : packages) {
        lexer.set_source(package);
        bool result = lexer.validate_package();
        std::string pkg = package + " ";
        JiftLogger::log(VERBOSE, pkg, false);
        if (result) {
            JiftLogger::log(TEST_OK, "Test Pass: Package OK", true);
        } else {
            JiftLogger::log(FATAL, "Test Fail: Package NOT OK", true);
        }
    }
}