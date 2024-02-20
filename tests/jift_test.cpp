#include "jift_util.hpp"

#include "lexer/package/jift_test_package.h"

int main(int argc, char* argv[]) {
    
    JiftLogger::log(VERBOSE, "[Jift Compiler Tests]: Starting Tests...\n", true);

    __jift_test_package();
}