#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Elem_239370 { void* vt; };
struct Vec_239370 { int cap; };
struct Obj_239370 { char pad[0xC]; Vec_239370 vec; int count; };
extern "C" {
extern char D_004A6FA8[];
extern char D_004DC038[];
void Mem_Free(int pool, void* p, char* file, int line);
Elem_239370** func_00239590(Vec_239370* v, int i);
void func_002394A0(Vec_239370* v, int f);
void operator_delete(void* p);
}
extern "C" Obj_239370* func_00239370(Obj_239370* o, short flag)
{
    if (o) {
        int i;
        for (i = 0; i < o->count; i++) {
            Elem_239370* e = *func_00239590(&o->vec, i);
            AllocGuard g;
            if (e)
                e->vt = D_004DC038;
            Mem_Free(0, e, D_004A6FA8, 0x667);
        }
        o->count = 0;
        Vec_239370* v = &o->vec;
        if (v)
            func_002394A0(v, -1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}