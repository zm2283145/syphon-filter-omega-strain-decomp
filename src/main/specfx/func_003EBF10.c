#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_003EBF10(void* node)
{
    AllocGuard guard;
    Mem_Free(0, node, "specfx.cc", 0xE9);
}