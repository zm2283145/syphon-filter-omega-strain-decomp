#include "types.h"
int func_002F5150(void) {
    int c;
    asm { mfc0 c, $9
     sync.p }
    return c;
}