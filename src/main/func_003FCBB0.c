#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_0049ED08[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_8(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_0049ED08, 0x64);
    }
}