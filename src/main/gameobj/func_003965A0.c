#include "types.h"
typedef struct { void** data; int count; } G1Vec;
extern void* func_00171EC0(G1Vec* v);
extern void* func_001A0280(void* p);
extern void func_00393380(void* p);
typedef struct { char pad[0xB4]; G1Vec v; } G1Obj;
#pragma opt_loop_invariants off
void func_003965A0(G1Obj* o)
{
    while (o->v.count != 0) {
        G1Vec* v = &o->v;
        void* e = ((void**)*(void**)func_00171EC0(v))[v->count - 1];
        if (func_001A0280(e) == o)
            func_00393380(e);
    }
}
#pragma opt_loop_invariants reset