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

#include "compiler/lexer/jift_lexer.hpp"
#include <iostream>
#include <algorithm>

using namespace Jift;

Compiler::Lexer::Lexer() { }

Compiler::Lexer::Lexer(const std::string& source) : m_SourceCode(source)  {
    /* Initialise Flags */
    this->m_IsInvisible = true;
}
Compiler::Lexer::~Lexer() { }

const std::tuple<Compiler::CommentType, bool> Compiler::Lexer::has_comment_identifier(const std::string& source, const int& cursor) noexcept {
    // Look for regular comments
    if ((cursor + 1) != source.length() + 1) {
        if (source[cursor] == '/' && source[cursor + 1] == '/') {
            this->m_CommentStart = true;
            return std::make_tuple(Compiler::CommentType::COMMENT_START, true);
        }
    }
    // TODO: Scan for multi-line comments and documentation comments
    return std::make_tuple(Compiler::CommentType::COMMENT_UNKNOWN, false);
}

const bool Compiler::Lexer::has_comment_ended() noexcept {
    // TODO: Implement me!
    // ok let's go
    int c = 0;
    char aster_term = '*';
    char terminator = '/';
    std::tuple<Compiler::CommentType, bool> has_comment;

    bool found_terminator = false;

    while (this->m_SourceCode[c] != '\0') {
        has_comment = this->has_comment_identifier(this->m_SourceCode, c);
        if (JIFT_UNPACK(has_comment, 1)) {
            if (this->m_SourceCode[c] == aster_term) {
                while (this->m_SourceCode[c] == aster_term) {
                    if (this->m_SourceCode[c] == terminator) {
                        found_terminator = true;
                        break;
                    }
                    c++;
                }
            } 
        }
        c++;
    }

    return found_terminator;
}

const bool Compiler::Lexer::parse_source() noexcept(false) {
    return (
        this->validate_package() &&
        this->validate_imports() &&
        this->validate_file_class()
    );
}

const bool Compiler::Lexer::validate_package() noexcept(false) {
    /* A regular java file will have a package;
    though that may not always be the case, 
    it is best to see if the file has a package
    to work with first. However, non-package Java files
    become invisible and should produce an error for
    accessing an invisible file. That is if the java file
    is not a module obviously... */

    // new idea: append each character a token and bind it to a hashmap to compare it to keywords

    JIFT_LEXER_TOOLS(this->m_SourceCode)
    std::string pkw = "package";
    std::string tok_source;
    std::string pkw_name;
    char ch;

    bool has_package_kw     = false;
    bool has_package_name   = false;

    /*
        Current Bugs:
        Packages starting with numbers are valid (WHICH IS INCORRECT)
        Packages starting with random symbols are valid (WHICH IS INCORRECT)
        Package names after the separator starting with digits are valid (WHICH IS INCORRECT)
     */

    while ((ch = this->m_SourceCode[cursor]) != JIFT_EOS) {
        if (JIFT_UNPACK(this->has_comment_identifier(this->m_SourceCode, cursor), 1)) {
            cursor++;
            continue;
        }
        tok_source += ch;
        if (tok_source == pkw) { 
            has_package_kw = true;
            this->m_Tokens.push_back(JIFT_TOKEN_PACKAGE);
        }
        if (has_package_kw) {
            if (tok_source.substr(0, cursor) == pkw && std::isdigit(this->m_SourceCode[cursor + 1])) break;
            if (ch == '.') {
                if (std::isdigit(this->m_SourceCode[cursor + 1])) break;
                this->m_Tokens.push_back(JIFT_TOKEN_PACKAGE_NAME_SEP);
            } else {
                if (ch == ';') {
                    if (tok_source[cursor - 1] == '.') break;
                    if (tok_source.substr(0, cursor) == pkw) break;
                    has_package_name = true;
                    this->m_Tokens.push_back(JIFT_TOKEN_TERMINATOR);
                    break; // Finished analysing the package
                }
                if (std::isalpha(ch)) this->m_Tokens.push_back(JIFT_TOKEN_CHARACTER);
                if (std::isdigit(ch)) this->m_Tokens.push_back(JIFT_TOKEN_NUMERICAL);
                // NOTE: Symbols like "!@#$" etc... will be marked as valid
                // They will be corrected during the next phase.
                // This makes it easier to generate tokens for packages
                if (!std::isdigit(ch) && !std::isalpha(ch)) this->m_Tokens.push_back(JIFT_TOKEN_DIFF_SYMBOL);
            }
        }
        cursor++;
    }

    //std::cout << "Dup: " << tok_source << std::endl;

    return (has_package_kw && has_package_name);
}

const bool Compiler::Lexer::validate_imports() noexcept(false) {
    JIFT_LEXER_TOOLS(this->m_SourceCode);

    const std::string imprt_kw = "import";
    const std::string accepts = "static";

    char ch;

    while ((ch = this->m_SourceCode[cursor]) != JIFT_EOS) {
        if (JIFT_UNPACK(this->has_comment_identifier(this->m_SourceCode, cursor), 1)) {
            cursor++;
            continue;
        }
    }

    return false;
}

const bool Compiler::Lexer::validate_file_class() noexcept(false) {
    return false;
}

const std::vector<jift_tokens_t> Compiler::Lexer::getTokens() const noexcept {
    return this->m_Tokens;
}

const std::unordered_map<jift_tokens_t, std::string> Compiler::Lexer::getMappedTokens() const noexcept {
    return this->m_CharToken;
}

void Compiler::Lexer::set_source(const std::string& nsource) noexcept {
    this->m_SourceCode = nsource;
}