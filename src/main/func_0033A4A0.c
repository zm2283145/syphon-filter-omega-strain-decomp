#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00336BF0(void* self, short flags);
void func_0033A4A0(void* allocation, int pool, int destroy, char* file, int line);
}
void func_0033A4A0(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_00336BF0((char*)allocation + 4, -1);
    }
    Mem_Free(pool, allocation, file, line);
}