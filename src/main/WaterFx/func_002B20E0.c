#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cWake_dtor(void* p, int n);
void cSplash_dtor(void* p, int n);
}
static inline void WF_Destroy(char* rec, int pool, int full, char* file, int line)
{
    AllocGuard g;
    if (full && rec) {
        cWake_dtor(rec + 0x70, -1);
        cSplash_dtor(rec + 0x40, -1);
    }
    cMemMan_Deallocate(pool, rec, file, line);
}
/* Frees a water effect record, optionally destroying its sub-lists first. */
extern "C" void opDelete_tBodyP_int_bool_charP_etc(char* rec, int pool, int full, char* file, int line)
{
    WF_Destroy(rec, pool, full, file, line);
}
