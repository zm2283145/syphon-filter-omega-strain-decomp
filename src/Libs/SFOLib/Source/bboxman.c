/*
 * Libs/SFOLib/Source/bboxman: 1 file, 003C8690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C8690 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3E8]; int ival[125]; float fval[125]; int on; int pad7D4; int count; } VU_3C8690;
#pragma opt_rotateloops off
void cBBoxMan_EndVisibilityTest(VU_3C8690* p)
{
    int i;
    if (p->on) {
        unsigned char busy;
        do {
            unsigned char t;
            busy = 1;
            t = busy;
            if (!(*(volatile int*)0x10008000 & 0x100) && !(*(volatile int*)0x10003800 & 3)) t = 0;
            if (!t && !(*(volatile int*)0x10003800 & 0x0F000000)) busy = 0;
        } while (busy);
        asm __volatile__("vnop");
        asm __volatile__("sync");
        for (i = 0; i < p->count; i++) {
            volatile int* r = (volatile int*)(((i + 5) << 4) | 0x11004000);
            p->ival[i] = r[0];
            p->fval[i] = *(volatile float*)&r[2];
        }
    }
}
#pragma opt_rotateloops reset
static inline void merge_flush_func_003C8690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8690 */
