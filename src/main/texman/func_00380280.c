#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void Mem_Free(int pool, void* allocation, char* file, int line);
extern "C" void func_003BBBC0(void* p, int flags);
extern "C" void Tex_DestroyRecord(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy)
        func_003BBBC0(allocation, -1);
    Mem_Free(pool, allocation, file, line);
}