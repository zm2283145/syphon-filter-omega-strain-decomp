#pragma cplusplus on

#include "types.h"

/* Run the per-element cleanup over a vector of 0x180-byte entries. */
typedef struct { unsigned char pad[0x10]; unsigned char sub[0x170]; } Elem_3932F0;
typedef struct { int pad0; int count; } Vec_3932F0;
typedef struct { unsigned char pad[0xB0]; Vec_3932F0 vec; } Obj_3932F0;

extern "C" {
Elem_3932F0** func_00393680(Vec_3932F0* v);
void func_00393380(void* p);
}

static inline bool Ne_3932F0(Elem_3932F0* a, Elem_3932F0* b) { return !(a == b); }

extern "C" void func_003932F0(Obj_3932F0* o)
{
    Elem_3932F0* it;
    Vec_3932F0* v = &o->vec;
    Elem_3932F0* end;
    it = *func_00393680(v);
    end = *func_00393680(v) + v->count;
    for (; Ne_3932F0(it, end); it++) {
        func_00393380(it->sub);
    }
}