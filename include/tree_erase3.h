#ifndef TREE_ERASE3_H
#define TREE_ERASE3_H

/*
 * Recursive red-black-tree subtree erase as CodeWarrior inlined it into
 * itself three levels deep: grandchildren are destroyed through
 * destroyFn(getValAlloc(t), &value) and deallocFn(getNodeAlloc(t), node, 1),
 * children through freeFn(node, 0, 0, file, line) after calling both
 * getters, and the node itself with an inline Mem_Free under the allocator
 * guard. C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct TENode {
    TENode* left;
    TENode* right;
    int parentColor;
};

#define DEFINE_TREE_ERASE3(name, valueOff, getValAlloc, getNodeAlloc, destroyFn, deallocFn, freeFn, fileSym, line) \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    void* getValAlloc(void* t);                                               \
    void* getNodeAlloc(void* t);                                              \
    void destroyFn(void* a, void* v);                                         \
    void deallocFn(void* a, TENode* n, int count);                            \
    void freeFn(TENode* n, int a, int b, char* file, int ln);                 \
    void name(void* t, TENode* x);                                            \
    }                                                                         \
    static inline void name##_L2(void* t, TENode* g)                          \
    {                                                                         \
        if (g->left)                                                          \
            name(t, g->left);                                                 \
        if (g->right)                                                         \
            name(t, g->right);                                                \
        destroyFn(getValAlloc(t), (char*)g + (valueOff));                     \
        deallocFn(getNodeAlloc(t), g, 1);                                     \
    }                                                                         \
    static inline void name##_L1(void* t, TENode* c)                          \
    {                                                                         \
        TENode* g;                                                            \
        if ((g = c->left) != 0)                                               \
            name##_L2(t, g);                                                  \
        if ((g = c->right) != 0)                                              \
            name##_L2(t, g);                                                  \
        getValAlloc(t);                                                       \
        getNodeAlloc(t);                                                      \
        if (c)                                                                \
            freeFn(c, 0, 0, fileSym, (line));                                 \
    }                                                                         \
    extern "C" void name(void* t, TENode* x)                                  \
    {                                                                         \
        TENode* c;                                                            \
        if ((c = x->left) != 0)                                               \
            name##_L1(t, c);                                                  \
        if ((c = x->right) != 0)                                              \
            name##_L1(t, c);                                                  \
        if (x)                                                                \
            TStr_Free((char*)x, fileSym, (line));                             \
    }

#endif /* TREE_ERASE3_H */