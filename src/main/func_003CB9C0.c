#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BD1D8[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_003CB9C0(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BD1D8, 0x64);
    }
}