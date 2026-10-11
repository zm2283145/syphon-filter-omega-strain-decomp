#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_21AC80 { virtual void Destroy(int f); };
struct Obj_21AC80 { void* vt; char pad04[0x60]; VObj_21AC80* obj; char pad68[0xC]; char m74[0x10]; char m84[0x10]; };
extern "C" {
extern char D_004DB4C0[];
extern char D_004A4550[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0021BFA0(void* p, int f);
void func_001363C0(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void L3_21AC80(void* p) { if (p) func_0021BFA0(p, 0); }
static inline void L2_21AC80(void* p) { if (p) L3_21AC80(p); }
static inline void L1_21AC80(void* p) { if (p) L2_21AC80(p); }
extern "C" Obj_21AC80* cGameGOBJ_dtor(Obj_21AC80* l, short flag)
{
    if (l) {
        VObj_21AC80* o;
        l->vt = D_004DB4C0;
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            Mem_Free(0, o, D_004A4550, 0xFE);
        }
        L1_21AC80(l->m84);
        if (l->m74)
            func_001363C0(l->m74, -1);
        cGOBJ_dtor(l, 0);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}