#ifndef TREE_INSERT_UNIQUE_KT_H
#define TREE_INSERT_UNIQUE_KT_H

/*
 * set/map<KT,...>::insert(value) (KT = key type, e.g. int) returning pair<iterator, bool>:
 * walk down from the root remembering the last node passed on the right,
 * insert through insertFn(tree, parent, left, leftmost, value) when the key
 * is new, else return the existing node. The bool comes from the static
 * true/false constants (trueSym/falseSym).
 * C++ only (#pragma cplusplus on before including).
 */


#define DEFINE_TREE_INSERT_UNIQUE_KT(name, KT, insertFn, trueSym, falseSym)    \
    struct name##_N { name##_N* left; name##_N* right; unsigned int parentAndColor; KT key; }; \
    struct name##_T { unsigned int count; name##_N* root; };                  \
    struct name##_P { name##_N* it; bool ok; };                               \
    extern "C" {                                                              \
    extern bool trueSym;                                                      \
    extern bool falseSym;                                                     \
    name##_N* insertFn(name##_T* t, name##_N* parent, bool left, bool first,        \
                     const KT* v);                                  \
    }                                                                         \
    extern "C" void name(name##_P* ret, name##_T* t, const KT* v)       \
    {                                                                         \
        bool left = true;                                                     \
        bool first = left;                                                    \
        name##_N* y = 0;                                                        \
        name##_N* parent = (name##_N*)&t->root;                                   \
        name##_N* x = t->root;                                                  \
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

#endif /* TREE_INSERT_UNIQUE_KT_H */