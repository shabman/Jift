#pragma once

#include <vector>
#include <tuple>
#include <map>
#include <string>

#include "compiler/jift_tokens.h"

#define JIFT_EOS '\0'

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
    std::unordered_map<jift_tokens_t, char> m_CharToken;

    bool m_IsInvisible;
public:
    Lexer(const std::string&);
    ~Lexer();
public:
    const bool parse_source()           noexcept(false);
    const bool validate_package()       noexcept(false);
    const bool validiate_file_class()   noexcept(false);
};

}
}