#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BD4C0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
}

static inline void MemClear_3D9(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
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
    done:
        .set reorder
    }
}

struct Arr_3D9DA0 { int* data; int count; };

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_003D9DA0(Arr_3D9DA0* a, int n)
{
    int* old = a->data;
    if (old) {
        AllocGuard g;
        Mem_Free(0, old, D_004BD4C0, 0xD54);
    }
    a->count = n;
    if (n) {
        int* p;
        {
            AllocGuard g;
            p = (int*)Mem_Alloc(0, n * 4, D_004BD4C0, 0xD58);
        }
        a->data = p;
        MemClear_3D9(a->data, n * 4);
    }
}