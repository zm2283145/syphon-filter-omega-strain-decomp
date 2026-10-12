#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S374020 { void* p[4]; int n[4]; };
extern "C" {
extern char D_004BC150[];
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Rel374020(void* p, int line)
{
    AllocGuard g;
    Mem_Free(0, p, D_004BC150, line);
}
extern "C" void LightMgr_FreePools(S374020* s)
{
    if (s->p[0]) {
        Rel374020(s->p[0], 0x94);
        s->p[0] = 0;
        s->n[0] = 0;
    }
    if (s->p[1]) {
        Rel374020(s->p[1], 0x9B);
        s->p[1] = 0;
        s->n[1] = 0;
    }
    if (s->p[2]) {
        Rel374020(s->p[2], 0xA1);
        s->p[2] = 0;
        s->n[2] = 0;
    }
    if (s->p[3]) {
        Rel374020(s->p[3], 0xA7);
        s->p[3] = 0;
        s->n[3] = 0;
    }
}