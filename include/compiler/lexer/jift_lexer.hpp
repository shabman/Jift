#pragma once

#include <vector>
#include <tuple>
#include <string>

#include "compiler/jift_tokens.h"

#define JIFT_LEXER_TOOLS(source) \
    int sourceLen = source.length() + 1; \
    int cursor = 0;

namespace Jift {
namespace Compiler {

class Lexer final {
private:
    std::string m_SourceCode;
    std::string m_TruncCode;
    std::vector<jift_tokens_t> m_Tokens;

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