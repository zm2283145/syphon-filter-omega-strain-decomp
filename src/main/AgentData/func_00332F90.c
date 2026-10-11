#include "types.h"
typedef struct { char pad[0xB08]; int bits[1]; } Pt2_Flags;
int func_00332F90(Pt2_Flags* p, unsigned char bit) {
    int b = bit;
    if (b > -1) return ((p->bits[b / 32] >> (b & 0x1F)) & 1) != 0;
    else asm { .set reorder } /* barrier: keeps the else block unmerged */
    return 0;
}