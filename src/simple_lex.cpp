#include "simple_lex.hpp"
#include <iostream>

static std::vector<std::string> JAVA_KEYWORDS = {
    "package",
    "public",
    "static",
    "void",

    /* Non primitive Types */
    "String"
};

Lexer::Lexer(const std::string& src) : m_Src(src) { }

Lexer::~Lexer() { }

void Lexer::ParseSourceCode() noexcept(false) {
    int cLen = this->m_Src.length() + 1;
    int cursor = 0;

    std::cout << "Parsing Java Source Code...\n";

    while (cursor < cLen) {
        // Scan for package decl (range 0 - 7)
        if (this->m_Src.substr(0, 7) == JAVA_KEYWORDS[cursor]) {
            this->m_TokArr.push_back(Token::TOK_KEYWORD);
            if (this->m_Src.substr(8, 8).find_first_not_of(' ') != std::string::npos) {
                std::cout << this->m_Src.substr(8,8) << std::endl;
                this->m_TokArr.push_back(Token::TOK_PACKAGE_NAME);
            } else {
                goto invalid_syntax_stub;
            }
        } else {
            // Invalid Source Code
            if (cursor == 0) {
                goto invalid_syntax_stub;
            }
        }
        // Move the cursor
        cursor++;

        invalid_syntax_stub:
            this->m_TokArr.push_back(Token::TOK_INVALID_IDENTIFIER);
            break;
    }
}

std::vector<Token> Lexer::GetTokens() const noexcept {
    return this->m_TokArr;
}