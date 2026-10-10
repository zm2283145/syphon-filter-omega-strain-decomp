#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
struct F6Actor;
struct F6Comp { virtual void Destroy(int f); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void Attach(F6Actor* a); };
struct F6Actor { char pad[0x58]; F6Comp* comp; };
extern "C" {
extern char D_004BD228[];
void Mem_Free(int, void*, char*, int);
}
static inline void F6Delete(F6Comp* p)
{
    AllocGuard g;
    p->Destroy(-1);
    Mem_Free(0, p, D_004BD228, 0x291);
}
extern "C" void Actor_AttachComponent(F6Actor* a, F6Comp* c)
{
    if (a->comp) {
        if (a->comp) {
            F6Delete(a->comp);
            a->comp = 0;
        }
    }
    a->comp = c;
    if (a->comp) a->comp->Attach(a);
}
