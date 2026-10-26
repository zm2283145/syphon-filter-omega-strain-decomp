#include "types.h"
extern void cTimerDisable_ctor(void* g);
extern void cTimerDisable_dtor(void* g, int flags);
extern void cSkaTransBLEND_dtor(void* p, int flags);
extern void Mem_Free(void* a, void* b, void* c, int d);
#pragma optimization_level 1
void opDelete_cSkaTransBLENDP_int_bool_charP_etc(void* p, void* pool, int destroy, void* file, int line)
{
    int g[1];
    cTimerDisable_ctor(g);
    if (destroy)
        cSkaTransBLEND_dtor(p, -1);
    Mem_Free(pool, p, file, line);
    cTimerDisable_dtor(g, -1);
}
#pragma optimization_level reset