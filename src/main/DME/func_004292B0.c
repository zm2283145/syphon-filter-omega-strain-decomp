#include "types.h"
extern volatile int D_00572538;
extern unsigned char D_00572528;
extern int D_00582540;
extern volatile int D_00572510;
extern int D_00572508;
extern char D_004BF990[];
extern int func_0010E010(int a);
extern void func_0010F388(const char* s);
/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI4292B0(void) { asm { sync }
    asm { ei } }
#pragma push
#pragma optimization_level 3
int func_004292B0(void)
{
    int stat = *(volatile int*)0x10000010;
    *(volatile int*)0x10000010 = stat;
    if (stat & 0x400) {
        D_00572538++;
        *(volatile int*)0x10000000 = 0;
    }
    if (D_00572528 && (unsigned)(D_00572538 - D_00582540) >= 100) {
        int r = func_0010E010(D_00572510);
        if (r != D_00572510)
            func_0010F388(D_004BF990);
        *(volatile int*)0x10000000 = 0;
        D_00572508 = 0;
        D_00582540 = D_00572538;
    }
    asm { .set reorder } /* scheduling barrier: keeps every branch delay slot empty */
    EI4292B0();
    return 0;
}
#pragma pop




