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

    // new idea: append each character a token and bind it to a hashmap to compare it to keywords

    JIFT_LEXER_TOOLS(this->m_SourceCode)
    std::string pkw = "package";
    std::string tok_source;
    std::string pkw_name;
    char ch;

    bool has_package_kw     = false;
    bool has_package_name   = false;

    while ((ch = this->m_SourceCode[cursor]) != JIFT_EOS) {
        tok_source += ch;
        // std::cout << "TOK: " << tok_source << std::endl;
        // std::cout << "CH: " << ch << std::endl;
        if (tok_source == pkw) { 
            has_package_kw = true;
            this->m_Tokens.push_back(JIFT_TOKEN_PACKAGE);
            this->m_CharToken[JIFT_TOKEN_PACKAGE] = tok_source;
        }
        cursor++;
    }

    return true;
}

const bool Compiler::Lexer::validiate_file_class() noexcept(false) {
return false;
}

const std::vector<jift_tokens_t> Compiler::Lexer::getTokens() const noexcept {
    return this->m_Tokens;
}

const std::unordered_map<jift_tokens_t, std::string> Compiler::Lexer::getMappedTokens() const noexcept {
    return this->m_CharToken;
}
