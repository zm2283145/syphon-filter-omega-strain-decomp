#include "types.h"
extern volatile int D_0055C220;
extern char D_0055C460[];
extern void func_003F5E80(void* p);
/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI3F7010(void) { asm { sync }
    asm { ei } }
#pragma push
#pragma optimization_level 3
int func_003F7010(void)
{
    if (D_0055C220) {
        func_003F5E80(D_0055C460);
        D_0055C220 = 0;
    }
    asm { .set reorder } /* scheduling barrier: keeps the beqz delay slot empty and the label padded */
    EI3F7010();
    return 0;
}
#pragma pop
