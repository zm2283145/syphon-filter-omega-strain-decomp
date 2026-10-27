#ifndef TREE_NODE_FREE_H
#define TREE_NODE_FREE_H

/*
 * Recursive tree node release: free both subtrees through the same
 * function, then free the node (file fileSym, line 100) under the
 * allocator guard. DEFINE_TREE_ROOT_DTOR: deleting destructor that releases
 * the root at +4 through freeFn(self, root).
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

typedef struct TreeFreeNode {
    struct TreeFreeNode* left;
    struct TreeFreeNode* right;
} TreeFreeNode;

typedef struct TreeFreeOwner {
    int header;
    TreeFreeNode* root;
} TreeFreeOwner;

#define DEFINE_TREE_NODE_FREE(name, fileSym)                                  \
    extern "C" char fileSym[];                                                \
    extern "C" void name(void* tree, TreeFreeNode* node)                      \
    {                                                                         \
        if (node->left)                                                       \
            name(tree, node->left);                                           \
        if (node->right)                                                      \
            name(tree, node->right);                                          \
        if (node) {                                                           \
            AllocGuard guard;                                                 \
            cMemMan_Deallocate(0, node, fileSym, 0x64);                                 \
        }                                                                     \
    }

#define DEFINE_TREE_ROOT_DTOR(name, freeFn)                                   \
    extern "C" void freeFn(void* tree, TreeFreeNode* node);                   \
    extern "C" TreeFreeOwner* name(TreeFreeOwner* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self->root)                                               \
                    freeFn(self, self->root);                                 \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* TREE_NODE_FREE_H */