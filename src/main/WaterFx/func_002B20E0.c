#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void func_002B3FC0(void* p, int n);
void func_002B4810(void* p, int n);
}
static inline void WF_Destroy(char* rec, int pool, int full, char* file, int line)
{
    AllocGuard g;
    if (full && rec) {
        func_002B3FC0(rec + 0x70, -1);
        func_002B4810(rec + 0x40, -1);
    }
    Mem_Free(pool, rec, file, line);
}
/* Frees a water effect record, optionally destroying its sub-lists first. */
extern "C" void WaterFx_DestroyRecord(char* rec, int pool, int full, char* file, int line)
{
    WF_Destroy(rec, pool, full, file, line);
}
