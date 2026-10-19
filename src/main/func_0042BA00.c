#include "types.h"

/* func_0042BA00: append an 8-byte entry to the first of three fixed queues (80 entries each);
 * returns the entry size, or 0 when the queue is full. */

typedef struct { int a; int b; } Item;

extern Item* D_00582628;
extern unsigned char D_00582630;
extern Item* D_00582638;
extern unsigned char D_00582640;
extern Item* D_00582648;
extern unsigned char D_00582650;

/* 8-byte copy macro, hand-written asm in the original (every branch delay slot of the function
 * stays unfilled, which MW only does when an asm block is present) */
static inline void Copy8(void* d, const void* s) { long long t; asm volatile { ld t, 0(s) } asm volatile { sd t, 0(d) } }

/* keeps the switch on the overwritten argument unfolded (retail: li a0,1 and a 3/2/1 compare chain) */
#pragma opt_propagation off
int func_0042BA00(int queue, Item* it)
{
    queue = 1;
    switch (queue) {
    case 1:
        if (D_00582630 <= 80) {
            Copy8(&D_00582628[D_00582630], it);
            D_00582630++;
            return 8;
        }
        return 0;
    case 2:
        if (D_00582640 <= 80) {
            Copy8(&D_00582638[D_00582640], it);
            D_00582640++;
            return 8;
        }
        return 0;
    case 3:
        if (D_00582650 <= 80) {
            Copy8(&D_00582648[D_00582650], it);
            D_00582650++;
            return 8;
        }
        return 0;
    }
    return 0;
}

