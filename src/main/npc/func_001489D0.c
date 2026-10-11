#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
static inline void QCopy_89D0(void* dst, void* src, int n0)
{
    int n;
    int t;
    int m;
    char* s;
    n = n0;
    s = (char*)src;

    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu dst, dst, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
typedef struct { char pad[0x74]; void* obj; int arg; } Sub_89D0;
typedef struct { char pad[0x1AC]; int id; Sub_89D0* sub; } Src_89D0;
extern "C" {
extern char D_0049C080[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_0016EFE0(void* dst, Src_89D0* obj);
void func_0016E890(void* a, int id, void* b, void* c);
void func_001613E0(void* dst, Sub_89D0* s);
void* func_00161930(void* p, int arg);
void func_001614C0(void* dst, void* obj);
}
extern "C" void func_001489D0(char* self, Src_89D0* obj)
{
    char* d = (char*)obj;
    Sub_89D0* s;
    if (d)
        d += 0x60;
    QCopy_89D0(d, self, 0xF0);
    func_0016EFE0(self + 0xF0, obj);
    func_0016E890(self + 0x110, obj->id, self + 0x1D0, self + 0x1E0);
    func_001613E0(self + 0x140, obj->sub);
    s = obj->sub;
    if (!s->obj) {
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0x30, D_0049C080, 0x1CC);
        }
        if (p)
            p = func_00161930(p, s->arg);
        s->obj = p;
    }
    func_001614C0(self + 0x1B0, s->obj);
}