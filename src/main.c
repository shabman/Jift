#include <stdio.h>
#include <string.h>
#include "jiftc.h"

int main(int argc, char* argv[]) {
    printf("%d\n", argc);
    if (argc > 0) {
        if (strcmp(argv[argc - 1], "-v") == 0) {
            printf("Jift Compiler Version %s\n", JIFTC_MAJOR_DOT_MINOR_VERSION);
        }
    }
}