#include "types.h"
typedef struct { int top; int cur[2]; int dirty[2]; } Bits_18A0B0;
static inline unsigned char Get_18A0B0(int* a, int bit) { return ((a[bit/32] >> (bit&31)) & 1) != 0; }
static inline void Set_18A0B0(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
void ActionPriority_Reset(Bits_18A0B0* b, int bit)
{
    int old[2];
    int i;
    unsigned int j;
    old[0] = b->cur[0];
    old[1] = b->cur[1];
    b->cur[0] = 0;
    b->cur[1] = 0;
    Set_18A0B0(b->cur, bit);
    for (i = 31; i >= 0 && !Get_18A0B0(b->cur, i); i--) {
    }
    if (!Get_18A0B0(b->cur, i)) b->top = -1; else b->top = i;
    for (j = 0; j < 32; j++) {
        if (Get_18A0B0(b->cur, j) != Get_18A0B0(old, j)) Set_18A0B0(b->dirty, j);
    }
}

