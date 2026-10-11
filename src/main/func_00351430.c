#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element (member at +0x4C, then base), then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_0034F7A0(void* self, short flags);
void* func_00138350(void* self, short flags);
void func_00351430(void* allocation, int pool, int destroy, char* file, int line);
}
void func_00351430(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            func_0034F7A0((char*)allocation + 0x4C, -1);
            func_00138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
}