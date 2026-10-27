#include "types.h"
void MEMCPY16(Q* d, Q* s, int n)
{
    asm {
        .set noreorder
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}