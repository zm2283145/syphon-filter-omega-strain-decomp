#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_allocator.h"

extern "C" {
char D_004BFB58[] = "allocator.hh";
extern char D_004BFB98[];
}

typedef TransferTreeAllocator<TransferReference*, D_004BFB58, D_004BFB98> ReferenceAllocator;

/* Allocate and link a registered-reference map node. */
extern "C" ReferenceAllocator::Node* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_4(
    RbTree* tree, ReferenceAllocator::Node* parent, int left, int first,
    const ReferenceAllocator::Value* value)
{
    return ReferenceAllocator::insert(tree, parent, left, first, value);
}

/* Release a reference node through the caller's allocator context. */
extern "C" void opDelete_nodeP_int_bool_charP_etc_15(
    ReferenceAllocator::Node* node, int pool, int flags, char* file, int line)
{
    ReferenceAllocator::release(node, pool, flags, file, line);
}

/* Release one reference node using the map's allocation metadata. */
extern "C" void cAllocator_node_deallocate_nodeP_uint_15(void* allocator, ReferenceAllocator::Node* node, int count)
{
    ReferenceAllocator::deallocate(allocator, node, count);
}
