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

#include <iostream>
#include "compiler/lexer/jift_lexer.hpp"

using namespace Jift;

template<typename Enumeration>
auto etoi(Enumeration const value) -> typename std::underlying_type<Enumeration>::type {
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

int main(int argc, char* argv[]) {
    std::string javaSourceCode = 
        "package test.company.as_12s;"
        "//Test Comment"
        "public class Test {" 
            "public static void main(String[] args) {"
                "System.out.println('Hello world!');"
                "System.out.println(10 / 2);"
            "}" 
        "}";

    /*
    char v = '!';
    std::cout << (std::isdigit(v)) << std::endl;
    std::cout << (std::isalpha(v)) << std::endl;
    */

    Compiler::Lexer lexer(javaSourceCode);
    bool result = lexer.validate_package();
    if (!result) {
        std::cout << "jift.lang.InvalidPackageException:\n\tPackage identifier was invalid\n";
    }

    for (const auto& tokVal : lexer.getTokens()) {
        std::cout << etoi(tokVal) << std::endl;
    }
    for (const std::pair<jift_tokens_t, std::string>& pair : lexer.getMappedTokens()) {
        std::cout << pair.second << std::endl;
    }

    try {
        std::string test = "eee";
        std::string::size_type sz;
        std::cout << std::stoi(test, &sz) << std::endl;
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
        std::cout << "fail\n";
    }
}


// int main(int argc, char* argv[]) {
//     std::string javaSourceCode = 
//     "package com.test; "
//     "public class Test {" 
//         "public static void main(String[] args) {"
//             "System.out.println('Hello world!');"
//         "}" 
//     "}";

//     Lexer lexer(javaSourceCode);
//     lexer.ParseSourceCode();

//     std::cout << "\n\n";
//     std::cout << "Parse complete, displaying tokens: \n";
//     for (const auto& tok: lexer.GetTokens()) {
//         switch (tok) {
//             case Token::TOK_KEYWORD: { 
//                 std::cout << "Token Keyword\n";
//                 break;
//              }
//             case Token::TOK_WHITESPACE: { }
//             case Token::TOK_OPEN_PAREN: { }
//             case Token::TOK_CLOSE_PAREN: { }
//             case Token::TOK_OPEN_BRACE: { }
//             case Token::TOK_CLOSE_BRACE: { }
//             case Token::TOK_INVALID_IDENTIFIER: {
//                 std::cout << "Invalid Token Found\n";
//                 break;
//             }
//             case Token::TOK_PACKAGE_NAME: {
//                 std::cout << "Token Java Package Name\n";
//                 break;
//             }
//             default:
//                 std::cout << "Invalid Token Detected\n";
//                 break;
//         }
//     }
// }