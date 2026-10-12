#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_allocator.h"

extern "C" {
char D_004BFB48[] = "allocator.hh";
extern char D_004BFB88[];
}

typedef TransferTreeAllocator<unsigned int, D_004BFB48, D_004BFB88> TimerAllocator;

/* Allocate and link a transfer-timer map node. */
extern "C" TimerAllocator::Node* func_00431030(
    RbTree* tree, TimerAllocator::Node* parent, int left, int first,
    const TimerAllocator::Value* value)
{
    return TimerAllocator::insert(tree, parent, left, first, value);
}

/* Release a timer node through the caller's allocator context. */
extern "C" void func_004311A0(
    TimerAllocator::Node* node, int pool, int flags, char* file, int line)
{
    TimerAllocator::release(node, pool, flags, file, line);
}

/* Release one timer node using the map's allocation metadata. */
extern "C" void func_00431250(void* allocator, TimerAllocator::Node* node, int count)
{
    TimerAllocator::deallocate(allocator, node, count);
}
