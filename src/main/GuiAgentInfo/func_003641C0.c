#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V3641C0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct O3641C0 { char pad[0x48]; V3641C0* p48; char pad4C[0x44]; V3641C0* p90; };
extern "C" {
extern char D_004BBA20[];
extern void* D_004FFC04;
void Mem_Free(int pool, void* p, char* file, int line);
void func_0041F090(void* p);
void func_002C9C80(void* p, int f);
}
static inline void Del3641C0(V3641C0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, D_004BBA20, line);
}
extern "C" void func_003641C0(O3641C0* s)
{
    func_0041F090(s);
    func_002C9C80(D_004FFC04, 0);
    if (s->p48) {
        s->p48->v22(1);
        Del3641C0(s->p48, 0x5B);
        s->p48 = 0;
    }
    {
        V3641C0* p = s->p90;
        if (p) {
            Del3641C0(p, 0x61);
            s->p90 = 0;
        }
    }
}