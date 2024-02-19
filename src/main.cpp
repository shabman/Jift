#include <iostream>
#include "compiler/lexer/jift_lexer.hpp"

using namespace Jift;

int main(int argc, char* argv[]) {
        std::string javaSourceCode = 
        "package me.bob;"
        "public class Test {" 
            "public static void main(String[] args) {"
                "System.out.println('Hello world!');"
            "}" 
        "}";

    Compiler::Lexer lexer(javaSourceCode);
    bool result = lexer.validate_package();
    if (!result) {
        std::cout << "jift.lang.InvalidPackageException:\n\tPackage identifier was invalid\n";
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