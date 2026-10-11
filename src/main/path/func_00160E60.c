#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct T_0E60 { char pad[0x14]; int last; int first; char pad1C[4]; int* ids; int pad24; int n; };
struct S_0E60 { char pad[0x74]; T_0E60* t; };
extern "C" {
extern char D_0049C1B8[];
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00160E60(S_0E60* self)
{
    T_0E60* t = self->t;
    if (t) {
        int* a;
        if (t->n > 0) {
            t->last = t->ids[t->n - 1];
            t->first = t->ids[0];
        } else {
            t->last = -1;
        }
        a = t->ids;
        if (a) {
            {
                AllocGuard g;
                Mem_Free(0, a, D_0049C1B8, 0x508);
            }
            t->ids = 0;
            t->n = 0;
        }
    }
}