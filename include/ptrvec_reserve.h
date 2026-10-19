#ifndef PTRVEC_RESERVE_H
#define PTRVEC_RESERVE_H

/*
 * reserve(n) of a vector of 4-byte elements (cap at +0, count at +4, data
 * at +8): length-check n, allocate the new buffer, copy the old contents
 * (the unrolled copy needs CodeWarrior 3.0 build 50, kind mw50), free the
 * old buffer and store the new capacity.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

/* the deallocate helper's inline guard needs a deeper inline limit */
#pragma inline_depth(10)

struct PRVec {
    unsigned int cap;
    unsigned int count;
    int* data;
};

#define DEFINE_PTRVEC_RESERVE(name, maxN, errSym, allocFile, allocLine, freeFile, freeLine) \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    extern char freeFile[];                                                   \
    }                                                                         \
    static inline void name##_Free(int* p)                                    \
    {                                                                         \
        if (p)                                                                \
            TStr_Free((char*)p, freeFile, (freeLine));                        \
    }                                                                         \
    extern "C" void name(PRVec* v, unsigned int n)                            \
    {                                                                         \
        if (v->cap < n) {                                                     \
            if (n > (maxN)) {                                                 \
                func_00123BE8(D_00489738->stream, errSym);                    \
                Libc_Abort();                                              \
            }                                                                 \
            int* old = v->data;                                               \
            int** pdata = &v->data;                                           \
            *pdata = (int*)TStr_Alloc(n * 4, allocFile, (allocLine));         \
            if (old) {                                                        \
                int* e = old + v->count;                                      \
                int* s = old;                                                 \
                int* d = v->data;                                             \
                while (s < e) {                                               \
                    *d = *s;                                                  \
                    s++;                                                      \
                    d++;                                                      \
                }                                                             \
                name##_Free(old);                                             \
            }                                                                 \
            v->cap = n;                                                       \
        }                                                                     \
    }

#endif /* PTRVEC_RESERVE_H */