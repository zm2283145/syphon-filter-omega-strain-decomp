#include "types.h"
static inline void MemClear_3BB(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a1, dst, 0xF
        andi $v1, n, 0xF
        or $a1, $a1, $v1
        nop
        bgtz $a1, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}
#pragma opt_propagation off
void* func_003BBC90(void* d)
{
    MemClear_3BB(d, 0x70);
    return d;
}
#pragma opt_propagation reset
