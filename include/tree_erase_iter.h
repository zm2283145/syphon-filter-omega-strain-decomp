#ifndef TREE_ERASE_ITER_H
#define TREE_ERASE_ITER_H

/*
 * Red-black tree erase(iterator) for a node with no destructor: if the
 * node is the leftmost one, advance the iterator and store it as the new
 * leftmost; unlink/rebalance through rebalanceFn(node, root), free the node
 * under the allocator guard and decrement the count.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct TXNode { TXNode* left; TXNode* right; unsigned int parentAndColor; };
struct TXTree { unsigned int count; TXNode* root; int pad; TXNode* leftmost; };

static inline void TX_Increment(TXNode** it)
{
    TXNode* n = (*it)->right;
    if (n) {
        TXNode* l = n->left;
        while (l) {
            n = l;
            l = l->left;
        }
        *it = n;
    } else {
        TXNode* p;
        while (*it != (p = (TXNode*)((*it)->parentAndColor & ~1))->left)
            *it = p;
        *it = p;
    }
}

#define DEFINE_TREE_ERASE_ITER(name, rebalanceFn, fileSym, line)              \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    void rebalanceFn(TXNode* node, TXNode* root);                             \
    }                                                                         \
    extern "C" void name(TXTree* t, TXNode** pos)                             \
    {                                                                         \
        TXNode** plm = &t->leftmost;                                          \
        TXNode* n = *pos;                                                     \
        if (n == t->leftmost) {                                               \
            TX_Increment(pos);                                                \
            *plm = *pos;                                                      \
        }                                                                     \
        rebalanceFn(n, t->root);                                              \
        if (n)                                                                \
            TStr_Free((char*)n, fileSym, (line));                             \
        t->count--;                                                           \
    }

#endif /* TREE_ERASE_ITER_H */