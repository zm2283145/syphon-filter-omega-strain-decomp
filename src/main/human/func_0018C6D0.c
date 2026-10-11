#include "types.h"
typedef struct { Q a; Q b; Q c; } MR_18C6D0;
static inline void QCopy_18C6D0(void* d0, void* s0) { int n = 3; void* d = d0; void* s = s0;
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
MR_18C6D0* MotionRequest_Construct(MR_18C6D0* d, MR_18C6D0* s)
{
    QCopy_18C6D0(d, s);
    return d;
}