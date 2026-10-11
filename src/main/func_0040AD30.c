#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00408D20(void* self, short flags);
void func_0040AD30(void* allocation, int pool, int destroy, char* file, int line);
}
void func_0040AD30(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_00408D20((char*)allocation + 12, -1);
    }
    Mem_Free(pool, allocation, file, line);
}