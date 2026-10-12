#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { void* vt; char p4[0x1C]; void* arr[29]; char p94[0x7C]; char a110[0xC]; char a11C[4]; } M22D4F0;
extern "C" {
void Receiver_Construct(M22D4F0*, void*);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* func_001005E0(void* p, void* ctor, int dtor, int size, int n);
void func_00222B60(void*);
void func_0022D3C0(M22D4F0*);
void func_0022DBC0(void*);
extern char D_004DB850[];
extern char D_004F77A8[];
extern char func_0022D630[];
}
#pragma push

#pragma opt_strength_reduction off

extern "C" M22D4F0* func_0022D4F0(M22D4F0* m) {
    int i;
    int n;
    int off;
    void* p;
    Receiver_Construct(m, D_004F77A8);
    m->vt = D_004DB850;
    func_0022DBC0(m->a110);
    func_00222B60(m->a11C);
    for (i = 0, off = 0; i < 29; i++, off += 4) {
        n = 29 - i;
        { AllocGuard g; p = Mem_Alloc(0, (n << 4) + 0x10, "targetManager.cc", 0x2B); }
        *(void**)((char*)m + off + 0x20) = func_001005E0(p, func_0022D630, 0, 0x10, n);
    }
    func_0022D3C0(m);
    return m;
}
#pragma pop
