#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BFDB0[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_0043B910(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BFDB0, 0x64);
    }
}