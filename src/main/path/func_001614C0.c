#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
static inline void QCopy_14C0(void* dst, void* src, int n0)
{
    int n;
    int t;
    int m;
    char* d;
    n = n0;
    d = (char*)dst;

    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu d, d, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

extern "C" {
typedef struct { char pad[0x14]; int id; int arg; int pad1c; void* buf; int count; } S_14C0;
extern char D_0049C1B8[];
extern char D_004FFB50[];
extern char D_004ED9B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void* Service_Lookup(void* reg, void* key);
void func_0015F3D0(void* svc, int id, int arg, S_14C0* s);
}
#pragma opt_common_subs off
extern "C" void func_001614C0(void* src, S_14C0* self)
{
    QCopy_14C0(self, src, 0x20);
    if (!self->buf) {
        int size = self->count * 4;
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, size, D_0049C1B8, 0x4F2);
        }
        self->buf = p;
    }
    if (self->id >= 0)
        func_0015F3D0(Service_Lookup(D_004FFB50, D_004ED9B0), self->id, self->arg, self);
}
