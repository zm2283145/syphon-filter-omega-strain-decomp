#ifndef TREE_ERASE3_STRVAL_H
#define TREE_ERASE3_STRVAL_H

/*
 * tree_erase3.h variant for a node whose value (at +0xC) is a string with a
 * destructor: children destroy the value out of line (valDtorFn(&v, -1)),
 * the node itself runs the string destructor inline (flag test, length,
 * data, clear, then strFreeFn on the heap buffer) before the guarded free.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct TSNode { TSNode* left; TSNode* right; int color; int value; };
struct TSFlag { unsigned int w; };
#define DEFINE_TREE_ERASE3_STRVAL(name, getValAlloc, getNodeAlloc, destroyFn, deallocFn, freeFn, fileSym, valDtorFn, flagFn, lenFn, dataFn, clearFn, strFreeFn, strFileSym) \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char strFileSym[];                                                 \
    void* getValAlloc(void* t);                                               \
    void* getNodeAlloc(void* t);                                              \
    void destroyFn(void* a, int* v);                                          \
    void deallocFn(void* a, TSNode* n, int count);                            \
    void freeFn(TSNode* n, int a, int b, char* file, int line);               \
    void valDtorFn(int* v, int flags);                                        \
    TSFlag* flagFn(int* s);                                                   \
    unsigned int lenFn(int* s);                                               \
    char** dataFn(int* s);                                                    \
    void clearFn(int* s);                                                     \
    void strFreeFn(char* p, int a, int b, char* file, int line);              \
    void name(void* t, TSNode* x);                                            \
    }                                                                         \
    static inline void name##_L2(void* t, TSNode* g)                          \
    {                                                                         \
        if (g->left)                                                          \
            name(t, g->left);                                                 \
        if (g->right)                                                         \
            name(t, g->right);                                                \
        destroyFn(getValAlloc(t), &g->value);                                 \
        deallocFn(getNodeAlloc(t), g, 1);                                     \
    }                                                                         \
                                                                              \
    static inline void name##_L1(void* t, TSNode* c)                          \
    {                                                                         \
        TSNode* g;                                                            \
        if ((g = c->left) != 0)                                               \
            name##_L2(t, g);                                                  \
        if ((g = c->right) != 0)                                              \
            name##_L2(t, g);                                                  \
        getValAlloc(t);                                                       \
        valDtorFn(&c->value, -1);                                             \
        getNodeAlloc(t);                                                      \
        if (c)                                                                \
            freeFn(c, 0, 0, fileSym, 0x64);                                   \
    }                                                                         \
                                                                              \
    extern "C" void name(void* t, TSNode* x)                                  \
    {                                                                         \
        TSNode* c;                                                            \
        if ((c = x->left) != 0)                                               \
            name##_L1(t, c);                                                  \
        if ((c = x->right) != 0)                                              \
            name##_L1(t, c);                                                  \
        {                                                                     \
            if (&x->value) {                                                  \
                if (&x->value) {                                              \
                    if (&x->value) {                                          \
                        if (flagFn(&x->value)->w & 1) {                       \
                            char* p;                                          \
                            lenFn(&x->value);                                 \
                            p = *dataFn(&x->value);                           \
                            clearFn(&x->value);                               \
                            if (p)                                            \
                                strFreeFn(p, 0, 0, strFileSym, 0x64);         \
                        }                                                     \
                    }                                                         \
                }                                                             \
            }                                                                 \
        }                                                                     \
        if (x)                                                                \
            TStr_Free((char*)x, fileSym, 0x64);                               \
    }

#endif /* TREE_ERASE3_STRVAL_H */
