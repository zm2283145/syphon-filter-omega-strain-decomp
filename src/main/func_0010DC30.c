#include "types.h"
int QueryIntrContext(void) {
    int s;
    asm { mfc0 s, $12 }
    return (s ^ 1) & 1;
}