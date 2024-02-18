#include "compiler/lexer/jift_lexer.hpp"
#include <iostream>

using namespace Jift;

Compiler::Lexer::Lexer(const std::string& source) : m_SourceCode(source)  {
    /* Initialise Flags */
    this->m_IsInvisible = true;
}
Compiler::Lexer::~Lexer() { }

const bool Compiler::Lexer::parse_source() noexcept(false) {
return false;
}

const bool Compiler::Lexer::validate_package() noexcept(false) {
    /* A regular java file will have a package;
    though that may not always be the case, 
    it is best to see if the file has a package
    to work with first. However, non-package Java files
    become invisible and should produce an error for
    accessing an invisible file. That is if the java file
    is not a module obviously... */
    bool valid_package = false;
    int startIndex = 0;
    int stopIndex = 7;
    std::string package_keyword = "package";

    JIFT_LEXER_TOOLS(this->m_SourceCode)
    do {
        if (this->m_SourceCode.substr(startIndex, stopIndex) == package_keyword) {
            this->m_IsInvisible = false;
            this->m_Tokens.push_back(JIFT_TOKEN_PACKAGE);
        }
        if (!this->m_IsInvisible) {
            const char next_advance = this->m_SourceCode[stopIndex];
            if (next_advance == '\n' || next_advance == ';') {
                valid_package = false;
                this->m_Tokens.push_back(JIFT_TOKEN_INVALID_SYNTAX);
                break;
            } else {
                valid_package = true;
                std::cout << "Package is OK\n";
            }
        }
        cursor++;
    } while (cursor < sourceLen);
    return valid_package;
}

const bool Compiler::Lexer::validiate_file_class() noexcept(false) {
return false;
}
