#include "types.h"
extern int D_0048C350;
extern unsigned char D_0051EE90;
extern void iWakeupThread(int id);
#pragma push
#pragma optimization_level 2
#pragma peephole on
#pragma optimization_level 3
int func_002C8460(void) {
    if (D_0048C350 != -1 && !D_0051EE90) iWakeupThread(D_0048C350);
    asm {
        sync
        ei
    }
    asm { .set reorder } /* barrier: keeps retail block layout */ return -1;
}
#pragma pop
