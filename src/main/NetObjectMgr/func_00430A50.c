#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_allocator.h"

extern "C" {
char D_004BFB68[] = "allocator.hh";
extern char D_004BFBA8[];
}

typedef TransferTreeAllocator<TransferMessage*, D_004BFB68, D_004BFBA8> MessageAllocator;

/* Allocate and link a pending-message map node. */
extern "C" MessageAllocator::Node* func_00430A50(
    RbTree* tree, MessageAllocator::Node* parent, int left, int first,
    const MessageAllocator::Value* value)
{
    return MessageAllocator::insert(tree, parent, left, first, value);
}

/* Release a pending-message node through the caller's allocator context. */
extern "C" void opDelete_nodeP_int_bool_charP_etc_14(
    MessageAllocator::Node* node, int pool, int flags, char* file, int line)
{
    MessageAllocator::release(node, pool, flags, file, line);
}

/* Release one pending-message node using the map's allocation metadata. */
extern "C" void func_00430C70(void* allocator, MessageAllocator::Node* node, int count)
{
    MessageAllocator::deallocate(allocator, node, count);
}
