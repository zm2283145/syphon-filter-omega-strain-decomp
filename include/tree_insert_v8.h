#ifndef TREE_INSERT_V8_H
#define TREE_INSERT_V8_H

/*
 * Red-black tree node insert for an 8-byte value (node: left, right,
 * parent|color, value at +0xC; tree: count, root, -, leftmost): count
 * overflow check, allocate the 0x14-byte node under the allocator guard,
 * placement-copy the value, link it under parent, bump the count and
 * rebalance (rebalanceFn). VT is TIValueFI (float, int) or TIValueII.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct TIValueFI { float f; int i; };
struct TIValueII { int a; int b; };

#define DEFINE_TREE_INSERT_V8(name, VT, errSym, allocFile, allocLine, rebalanceFn) \
    struct name##_Node { name##_Node* left; name##_Node* right; unsigned int parentAndColor; VT value; }; \
    struct name##_Tree { unsigned int count; name##_Node* root; int pad; name##_Node* leftmost; }; \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void rebalanceFn(void* node, void* root);                                 \
    }                                                                         \
    extern "C" name##_Node* name(name##_Tree* tree, name##_Node* parent,      \
                                 int left, int first, const VT* src)          \
    {                                                                         \
        if (tree->count > 0xFFFFFFFFU - 1) {                                  \
            func_00123BE8(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        name##_Node* node = (name##_Node*)TStr_Alloc(0x14, allocFile, (allocLine)); \
        VT* v = &node->value;                                                 \
        if (v)                                                                \
            *v = *src;                                                        \
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

#endif /* TREE_INSERT_V8_H */