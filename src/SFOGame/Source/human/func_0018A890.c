#include "types.h"
typedef struct { Q a; Q b; Q c; } Z_18A890;
static inline void QZero_18A890(void* d0) { int n = 3; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
Z_18A890* cString16N_3_ctor_void(Z_18A890* d)
{
    QZero_18A890(d);
    return d;
}
