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

#include <vector>
#include <tuple>
#include <map>
#include <string>

#include "compiler/jift_tokens.h"

#define JIFT_EOS '\0'
#define JIFT_UNPACK(t, i) std::get<i>(t)

#define JIFT_LEXER_TOOLS(source) \
    int sourceLen = source.length(); \
    int cursor = 0;

namespace Jift {
namespace Compiler {

enum class CommentType {
    COMMENT_START,
    COMMENT_END,
    COMMENT_UNKNOWN
};

class Lexer final {
private:
    std::string m_SourceCode;
    std::string m_TruncCode;

    std::vector<jift_tokens_t> m_Tokens;
    std::unordered_map<jift_tokens_t, std::string> m_CharToken;

    bool m_IsInvisible;
    bool m_CommentStart;
private:
    const std::tuple<CommentType, bool> has_comment_identifier(const std::string&, const int&) noexcept;
    const bool has_comment_ended(char&) noexcept;
public:
    Lexer();
    Lexer(const std::string&);
    ~Lexer();
public:
    const bool parse_source()           noexcept(false);
    const bool validate_package()       noexcept(false);
    const bool validiate_file_class()   noexcept(false);

    const std::vector<jift_tokens_t> getTokens() const noexcept;
    const std::unordered_map<jift_tokens_t, std::string> getMappedTokens() const noexcept;

    void set_source(const std::string&) noexcept;
};

}
}
