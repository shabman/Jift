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

#include <map>
#include <string>
#include <vector>

enum class Token {
    TOK_KEYWORD,
    TOK_WHITESPACE,
    TOK_OPEN_PAREN,
    TOK_CLOSE_PAREN,
    TOK_OPEN_BRACE,
    TOK_CLOSE_BRACE,
    TOK_INVALID_IDENTIFIER,
    TOK_PACKAGE_NAME
};

class Lexer {
    std::string m_Src;
    std::vector<Token> m_TokArr;
public:
    Lexer(const std::string&);
    ~Lexer();
public:
    void ParseSourceCode() noexcept(false);
    std::vector<Token> GetTokens() const noexcept;
};