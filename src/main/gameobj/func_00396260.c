#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00396340(void* self, short flags);
void func_00396260(void* allocation, int pool, int destroy, char* file, int line);
}
void func_00396260(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_00396340((char*)allocation + 16, -1);
    }
    Mem_Free(pool, allocation, file, line);
}