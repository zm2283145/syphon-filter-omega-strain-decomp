#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int, int, char*, int);
extern char D_004C1EB0;
}
typedef struct { char pad[0x50]; int buf; int n; } S_459450;
#pragma opt_common_subs off
extern "C" void func_00459450(S_459450* s)
{
    int p = s->buf;
    if (p != 0) {
        {
            AllocGuard g;
            Mem_Free(0, p, &D_004C1EB0, 0x3F);
        }
        s->buf = 0;
    }
    s->n = 0;
}