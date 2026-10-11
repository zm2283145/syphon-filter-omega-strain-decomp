#ifndef TREE_INSERT_UNIQUE_U32_H
#define TREE_INSERT_UNIQUE_U32_H

/*
 * set/map<unsigned int,...>::insert(value) returning pair<iterator, bool>:
 * walk down from the root remembering the last node passed on the right,
 * insert through insertFn(tree, parent, left, leftmost, value) when the key
 * is new, else return the existing node. The bool comes from the static
 * true/false constants (trueSym/falseSym).
 * C++ only (#pragma cplusplus on before including).
 */
struct TUNode { TUNode* left; TUNode* right; unsigned int parentAndColor; unsigned int key; };
struct TUTree { unsigned int count; TUNode* root; };
struct TUPair { TUNode* it; bool ok; };

#define DEFINE_TREE_INSERT_UNIQUE_U32(name, insertFn, trueSym, falseSym)      \
    extern "C" {                                                              \
    extern bool trueSym;                                                      \
    extern bool falseSym;                                                     \
    TUNode* insertFn(TUTree* t, TUNode* parent, bool left, bool first,        \
                     const unsigned int* v);                                  \
    }                                                                         \
    extern "C" void name(TUPair* ret, TUTree* t, const unsigned int* v)       \
    {                                                                         \
        bool left = true;                                                     \
        bool first = left;                                                    \
        TUNode* y = 0;                                                        \
        TUNode* parent = (TUNode*)&t->root;                                   \
        TUNode* x = t->root;                                                  \
        while (x) {                                                           \
            parent = x;                                                       \
            if (*v < x->key) {                                                \
                x = x->left;                                                  \
                left = true;                                                  \
            } else {                                                          \
                y = x;                                                        \
                x = x->right;                                                 \
                left = false;                                                 \
                first = false;                                                \
            }                                                                 \
        }                                                                     \
        if (!y || y->key < *v) {                                              \
            ret->it = insertFn(t, parent, left, first, v);                    \
            ret->ok = trueSym;                                                \
        } else {                                                              \
            ret->it = y;                                                      \
            ret->ok = falseSym;                                               \
        }                                                                     \
    }

#endif /* TREE_INSERT_UNIQUE_U32_H */