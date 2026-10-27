/*
 * Libs/SFOLib/Source/DME: 1 file, 004292B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004292B0 */
#pragma push /* merge_units */
#include "types.h"
#include "DME.h"
extern volatile int D_00572538; /* Timer0 tick counter */
extern unsigned char D_00572528; /* DME thread running */
extern int g_DmeLastWakeTick;
extern volatile int g_DmeThreadId;
extern int D_00572508;
extern char D_004BF990[]; /* "\n\n\t\tERROR IN iWAKEUPTHREAD\n" */
extern int iWakeupThread(int a);
extern void scePrintf(const char* s); /* printf-like */
/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI4292B0(void) { asm { sync }
    asm { ei } }
#pragma push
#pragma optimization_level 3
/* Timer0 interrupt handler: counts ticks and wakes the DME thread every 100 ticks. */
int cThreadMgr_ThreadInterruptHandler(void)
{
    int mode = T0_MODE;
    T0_MODE = mode; /* acknowledge the interrupt flags */
    if (mode & T0_MODE_EQUF) {
        D_00572538++;
        T0_COUNT = 0;
    }
    if (D_00572528 && (unsigned)(D_00572538 - g_DmeLastWakeTick) >= 100) {
        int woken = iWakeupThread(g_DmeThreadId);
        if (woken != g_DmeThreadId)
            scePrintf(D_004BF990);
        T0_COUNT = 0;
        D_00572508 = 0;
        g_DmeLastWakeTick = D_00572538;
    }
    asm { .set reorder } /* scheduling barrier: keeps every branch delay slot empty */
    EI4292B0();
    return 0;
}
#pragma pop
static inline void merge_flush_func_004292B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004292B0 */
