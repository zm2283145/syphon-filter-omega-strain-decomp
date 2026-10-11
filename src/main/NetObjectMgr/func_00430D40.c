#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_allocator.h"

extern "C" {
extern char D_004BFB58[];
extern char D_004BFB98[];
}

typedef TransferTreeAllocator<TransferReference*, D_004BFB58, D_004BFB98> ReferenceAllocator;

/* Allocate and link a registered-reference map node. */
extern "C" ReferenceAllocator::Node* func_00430D40(
    RbTree* tree, ReferenceAllocator::Node* parent, int left, int first,
    const ReferenceAllocator::Value* value)
{
    return ReferenceAllocator::insert(tree, parent, left, first, value);
}

/* Release a reference node through the caller's allocator context. */
extern "C" void func_00430EB0(
    ReferenceAllocator::Node* node, int pool, int flags, char* file, int line)
{
    ReferenceAllocator::release(node, pool, flags, file, line);
}

/* Release one reference node using the map's allocation metadata. */
extern "C" void func_00430F60(void* allocator, ReferenceAllocator::Node* node, int count)
{
    ReferenceAllocator::deallocate(allocator, node, count);
}
