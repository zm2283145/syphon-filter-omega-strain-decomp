#include "types.h"
int func_00345030(char* a, char* b) {
    int i;
    for (i = 0; i < 5; i++) {
        a++; b++;
        if (*a != *b) return 0;
    }
    return 1;
}