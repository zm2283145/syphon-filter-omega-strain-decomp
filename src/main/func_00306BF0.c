#include "types.h"
int func_00306BF0(void) {
    int c;
    asm { mfc0 c, $9
     sync.p }
    return c;
}