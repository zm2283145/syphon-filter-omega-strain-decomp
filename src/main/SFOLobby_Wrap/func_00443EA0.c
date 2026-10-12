#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00443EA0(void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, "SFOLobby_Wrap.cc", 0x3A);
    }
}