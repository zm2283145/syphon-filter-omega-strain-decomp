#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004C0B20[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_00443EA0(void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004C0B20, 0x3A);
    }
}