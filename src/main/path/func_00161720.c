#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct T_1720 { char pad[0x14]; int last; int first; char pad1C[4]; int* ids; int pad24; int n; };
extern "C" {
extern char D_0049C1B8[];
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
extern "C" T_1720* func_00161720(T_1720* t, short del)
{
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
        if (del > 0)
            operator_delete(t);
    }
    return t;
}