#ifndef TRANSFER_TREE_ALLOCATOR_H
#define TRANSFER_TREE_ALLOCATOR_H

#include "types.h"
#include "NetObjectMgr_types.h"
#include "loose01_types.h"
#include "alloc_guard.h"

struct TransferObjectEntry;
struct TransferMessage;
struct TransferReference;

template <class Payload> struct TransferAllocationValue {
    GobjId id;
    Payload payload;
};

template <class Payload> struct TransferAllocationNode {
    TransferAllocationNode* left;
    TransferAllocationNode* right;
    unsigned int parentAndColor;
    TransferAllocationValue<Payload> value;
};

extern "C" {
extern Unk489738* D_00489738;
extern char D_004BFB10[];
void Libc_Fprintf(int channel, const char* message);
void Libc_Abort(void);
void std_red_black_tree_1_balance_insert(void* node, void* root);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

template <class Payload, char* AllocateFile, char* DeallocateFile>
struct TransferTreeAllocator {
    typedef TransferAllocationValue<Payload> Value;
    typedef TransferAllocationNode<Payload> Node;

    static inline unsigned int max_size()
    {
        return 0xFFFFFFFFU;
    }

    static inline Node* insert(RbTree* tree, Node* parent, int left, int first,
                               const Value* source)
    {
        /* This form retains the retail unsigned relational comparison. */
        if ((unsigned int)tree->count > max_size() - 1) {
            Libc_Fprintf(D_00489738->unk0C, D_004BFB10);
            Libc_Abort();
        }
        Node* node;
        {
            AllocGuard guard;
            node = (Node*)cMemMan_Allocate(0, sizeof(Node), AllocateFile, 0x5C);
        }
        /* The placement-copy guard tests the value subobject, not the node. */
        Value* value = &node->value;
        if (value) {
            value->id.word = source->id.word;
            value->payload = source->payload;
        }
        node->right = 0;
        node->left = 0;
        node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1);
        if (left)
            parent->left = node;
        else
            parent->right = node;
        tree->count++;
        std_red_black_tree_1_balance_insert(node, tree->root);
        if (first)
            tree->leftmost = node;
        return node;
    }

    static inline void release(Node* node, int pool, int flags, char* file, int line)
    {
        AllocGuard guard;
        cMemMan_Deallocate(pool, node, file, line);
    }

    static inline void deallocate(void* allocator, Node* node, int count)
    {
        if (node) {
            AllocGuard guard;
            cMemMan_Deallocate(0, node, DeallocateFile, 0x64);
        }
    }
};

#endif
