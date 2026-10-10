#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct {
    char pad0[8]; int state; char padC[0xC4 - 0xC];
    int unkC4; char padC8[0x130 - 0xC8]; int unk130; char pad134[0x838 - 0x134]; int unk838;
} Dec;

/* Switches the decoder to state 2 (copying +0x130 to +0xC4 on entry) and sets the +0x838 flag. */
void func_00109128(Dec* d)
{
    if (d->state != 2) {
        d->state = 2;
        d->unkC4 = d->unk130;
    }
    d->unk838 = 1;
}
