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