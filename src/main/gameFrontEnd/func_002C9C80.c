#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V2C9C80 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct S2C9C80 { char pad[0x260]; V2C9C80* p260; };
extern "C" {
extern char D_004ACF10[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0040F540(void);
}
static inline void Del2C9C80(V2C9C80* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, D_004ACF10, line);
}
extern "C" void func_002C9C80(S2C9C80* s, int flag)
{
    V2C9C80* p = s->p260;
    if (p) {
        if (flag) {
            Del2C9C80(p, 0x653);
            s->p260 = 0;
        } else {
            func_0040F540();
        }
    }
}