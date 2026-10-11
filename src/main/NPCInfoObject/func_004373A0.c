#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BFD10[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_004373A0(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BFD10, 0x64);
    }
}