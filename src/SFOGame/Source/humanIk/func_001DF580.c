#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004A02F8[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_2(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004A02F8, 0x64);
    }
}