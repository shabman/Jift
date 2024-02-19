#pragma once

#include <vector>
#include <tuple>
#include <map>
#include <string>

#include "compiler/jift_tokens.h"

#define JIFT_EOS '\0'
#define OUT(o, m) o << m << '\n';

#define JIFT_LEXER_TOOLS(source) \
    int sourceLen = source.length(); \
    int cursor = 0;

namespace Jift {
namespace Compiler {

class Lexer final {
private:
    std::string m_SourceCode;
    std::string m_TruncCode;

    std::vector<jift_tokens_t> m_Tokens;
    std::unordered_map<jift_tokens_t, std::string> m_CharToken;

    bool m_IsInvisible;
public:
    Lexer(const std::string&);
    ~Lexer();
public:
    const bool parse_source()           noexcept(false);
    const bool validate_package()       noexcept(false);
    const bool validiate_file_class()   noexcept(false);

    const std::vector<jift_tokens_t> getTokens() const noexcept;
    const std::unordered_map<jift_tokens_t, std::string> getMappedTokens() const noexcept;
};

}
}
