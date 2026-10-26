#pragma cplusplus on
#include "alloc_guard.h"
#pragma opt_strength_reduction off
struct E_00136BD0 { int f0; int f4; int f8; int fC; };
struct L_00136BD0 { int f0; int n; E_00136BD0* arr; };
struct O_00136BD0 { char pad[0x98]; L_00136BD0* l; };
extern "C" { extern char D_0049A890[]; void func_00139EE0(void* p, short f); void Mem_Free(int pool, void* p, const char* file, int line); }
extern "C" void cGameSystem_ClearNodeGroups(O_00136BD0* o)
{
    if (o->l) {
        int i;
        L_00136BD0* l;
        for (i = 0; i < o->l->n; i++) o->l->arr[i].f4 = 0;
        l = o->l;
        {
            AllocGuard g;
            if (l) { if (l) { if (l) func_00139EE0(l, 0); } }
            Mem_Free(0, l, D_0049A890, 0x107);
        }
        o->l = 0;
    }
}
#pragma opt_strength_reduction reset
