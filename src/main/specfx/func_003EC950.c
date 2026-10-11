#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BE020[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_003EC950(void* node)
{
    AllocGuard guard;
    Mem_Free(0, node, D_004BE020, 0x18);
}