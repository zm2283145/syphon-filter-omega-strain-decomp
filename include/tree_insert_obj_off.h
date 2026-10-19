#ifndef TREE_INSERT_OBJ_OFF_H
#define TREE_INSERT_OBJ_OFF_H

/*
 * Red-black tree node insert for a class value (node: left, right,
 * parent|color, value at +0xC): count overflow check, allocate the node
 * (nodeSize bytes) under the allocator guard, construct the value with
 * placement new (newFn(valSize, &node->value)) plus the copy constructor
 * (ctorFn), link it under parent, bump the count and rebalance.
 * This variant takes the value offset in the node (valueOff).
 * C++ only (#pragma cplusplus on before including).
 */
#include "tree_insert_obj.h"

#define DEFINE_TREE_INSERT_OBJ_OFF(name, nodeSize, valueOff, valSize, errSym, allocFile, allocLine, newFn, ctorFn, rebalanceFn) \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void* newFn(unsigned int size, void* p);                                  \
    void ctorFn(void* d, const void* s);                                      \
    void rebalanceFn(void* node, void* root);                                 \
    }                                                                         \
    extern "C" TONode* name(TOTree* tree, TONode* parent, int left, int first, \
                            const void* src)                                  \
    {                                                                         \
        if (tree->count > 0xFFFFFFFFU - 1) {                                  \
            func_00123BE8(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        TONode* node = (TONode*)TStr_Alloc((nodeSize), allocFile, (allocLine)); \
        void* v = newFn((valSize), (char*)node + (valueOff));                              \
        if (v)                                                                \
            ctorFn(v, src);                                                   \
        node->right = 0;                                                      \
        node->left = 0;                                                       \
        node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1); \
        if (left)                                                             \
            parent->left = node;                                              \
        else                                                                  \
            parent->right = node;                                             \
        tree->count++;                                                        \
        rebalanceFn(node, tree->root);                                        \
        if (first)                                                            \
            tree->leftmost = node;                                            \
        return node;                                                          \
    }

#endif /* TREE_INSERT_OBJ_OFF_H */