#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BE020[]; void* Mem_Alloc(int pool, int size, char* file, int line); }
extern "C" void* func_003EC9F0(int size)
{
    AllocGuard guard;
    return Mem_Alloc(0, size, D_004BE020, 0x12);
}