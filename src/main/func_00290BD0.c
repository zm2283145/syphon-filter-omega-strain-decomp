#include "types.h"

int func_00290BD0(char* a, char* b) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*++a != *++b) return 0;
    }
    return 1;
}