#ifndef TRANSFER_TREE_DESTROY_H
#define TRANSFER_TREE_DESTROY_H

#include "NetObjectMgr_types.h"
#include "alloc_guard.h"

/* Common node prefix; the map-specific payload follows the ID. */
struct TransferTreeNode {
    TransferTreeNode* left;
    TransferTreeNode* right;
    TransferTreeNode* parent;
    GobjId id;
};

extern "C" void Mem_Free(int pool, void* allocation, char* file, int line);

/* Retail expands two descendant levels, with progressively inlined deallocation. */
template <
    void (*Recurse)(RbTree*, TransferTreeNode*),
    void* (*ValueAllocator)(RbTree*),
    void (*DestroyValue)(void*, GobjId*),
    void* (*NodeAllocator)(RbTree*),
    void (*Deallocate)(void*, TransferTreeNode*, int),
    void (*Release)(TransferTreeNode*, int, int, char*, int),
    char* File
> struct TransferTreeDestroy {
    static inline void destroy_descendant(RbTree* tree, TransferTreeNode* node)
    {
        if (node->left)
            Recurse(tree, node->left);
        if (node->right)
            Recurse(tree, node->right);
        DestroyValue(ValueAllocator(tree), &node->id);
        Deallocate(NodeAllocator(tree), node, 1);
    }

    static inline void destroy_child(RbTree* tree, TransferTreeNode* node)
    {
        if (node->left)
            destroy_descendant(tree, node->left);
        if (node->right)
            destroy_descendant(tree, node->right);
        ValueAllocator(tree);
        NodeAllocator(tree);
        if (node)
            Release(node, 0, 0, File, 0x64);
    }

    static inline void destroy(RbTree* tree, TransferTreeNode* node)
    {
        if (node->left)
            destroy_child(tree, node->left);
        if (node->right)
            destroy_child(tree, node->right);
        if (node) {
            AllocGuard guard;
            Mem_Free(0, node, File, 0x64);
        }
    }
};

#endif
