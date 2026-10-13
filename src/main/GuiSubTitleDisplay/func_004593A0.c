#include "types.h"
typedef struct { void** data; int count; } Vec_4593A0;
typedef struct { char pad[0x58]; Vec_4593A0 v; char pad60[0x6C - 0x60]; int f6C; } S_4593A0;
extern void*** func_00171EC0(Vec_4593A0*);
extern void func_00136DA0(int*);
extern void func_00459320(void*, int);
extern void Mem_Free(int, void*, char*, int);
extern void func_0012F530(int*, int);
extern char D_004C1EB0[];

#pragma push
#pragma opt_strength_reduction off
void func_004593A0(S_4593A0* s)
{
    int i;
    for (i = 0; i < s->v.count; i++) {
        void* e = (*func_00171EC0(&s->v))[i];
        int guard;
        func_00136DA0(&guard);
        func_00459320(e, -1);
        Mem_Free(0, e, D_004C1EB0, 0x48);
        func_0012F530(&guard, -1);
    }
    s->v.count = 0;
    s->f6C = 0;
}
#pragma pop

