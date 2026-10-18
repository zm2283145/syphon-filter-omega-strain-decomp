#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
extern char D_004BC150[];
}

/* the original zeroes each pool with this inline-asm clear (quadword or byte loop) */
static inline void MemClear_4270(void* dst, int n) {
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

struct LightA_4270 { int f0; int f4; int f8; char pad[0x40 - 0xC]; };
struct LightB_4270 { int f0; int f4; int f8; char pad[0x50 - 0xC]; };
struct LightC_4270 { int f0; int f4; int f8; char pad[0x40 - 0xC]; };
struct LightD_4270 { int f0; int f4; int f8; char pad[0xE0 - 0xC]; };

struct LightPools_4270 {
    LightA_4270* a;
    LightB_4270* b;
    LightC_4270* c;
    LightD_4270* d;
    unsigned int na;
    unsigned int nb;
    unsigned int nc;
    unsigned int nd;
};

/* pool init loops: no unrolling or strength reduction, test at the bottom; the
   explicit off/mid/neg temporaries in this declaration order give retail's registers */
#pragma opt_unroll_loops off
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
extern "C" void LightMgr_AllocPool(LightPools_4270* m, unsigned char type, unsigned int n)
{
    switch (type) {
    case 1: {
        int size = n * sizeof(LightA_4270);
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, size, D_004BC150, 0x5E);
        }
        m->a = (LightA_4270*)p;
        MemClear_4270(m->a, size);
        m->na = n;
        {
            unsigned int i;
            int off;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                off = i * sizeof(*m->a);
                *(int*)((char*)m->a + off + 8) = neg;
            }
        }
        break;
    }
    case 2: {
        int size = n * sizeof(LightB_4270);
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, size, D_004BC150, 0x6A);
        }
        m->b = (LightB_4270*)p;
        MemClear_4270(m->b, size);
        m->nb = n;
        {
            unsigned int i;
            int off;
            int mid;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                mid = i * 5;
                off = mid << 4;
                *(int*)((char*)m->b + off + 8) = neg;
            }
        }
        break;
    }
    case 4: {
        int size = n * sizeof(LightC_4270);
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, size, D_004BC150, 0x76);
        }
        m->c = (LightC_4270*)p;
        MemClear_4270(m->c, size);
        m->nc = n;
        {
            unsigned int i;
            int off;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                off = i * sizeof(*m->c);
                *(int*)((char*)m->c + off + 8) = neg;
            }
        }
        break;
    }
    case 0x10: {
        int size = n * sizeof(LightD_4270);
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, size, D_004BC150, 0x82);
        }
        m->d = (LightD_4270*)p;
        MemClear_4270(m->d, size);
        m->nd = n;
        {
            unsigned int i;
            int off;
            int mid;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                mid = i * 7;
                off = mid << 5;
                *(int*)((char*)m->d + off + 8) = neg;
            }
        }
        break;
    }
    }
}
