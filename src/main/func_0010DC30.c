#include "types.h"
int func_0010DC30(void) {
    int s;
    asm { mfc0 s, $12 }
    return (s ^ 1) & 1;
}