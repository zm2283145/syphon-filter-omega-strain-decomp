#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_allocator.h"

extern "C" {
char D_004BFB78[] = "allocator.hh";
extern char D_004BFBB8[];
}

typedef TransferTreeAllocator<TransferObjectEntry*, D_004BFB78, D_004BFBB8> ObjectAllocator;

/* Allocate and link an owned-object map node. */
extern "C" ObjectAllocator::Node* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_3(
    RbTree* tree, ObjectAllocator::Node* parent, int left, int first,
    const ObjectAllocator::Value* value)
{
    return ObjectAllocator::insert(tree, parent, left, first, value);
}

/* Release an owned-object node through the caller's allocator context. */
extern "C" void opDelete_nodeP_int_bool_charP_etc_13(
    ObjectAllocator::Node* node, int pool, int flags, char* file, int line)
{
    ObjectAllocator::release(node, pool, flags, file, line);
}

/* Release one owned-object node using the map's allocation metadata. */
extern "C" void cAllocator_node_deallocate_nodeP_uint_14(void* allocator, ObjectAllocator::Node* node, int count)
{
    ObjectAllocator::deallocate(allocator, node, count);
}
