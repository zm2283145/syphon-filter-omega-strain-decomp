#include "types.h"
int GetPS2Timer(void) {
    int c;
    asm { mfc0 c, $9
     sync.p }
    return c;
}