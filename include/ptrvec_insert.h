#ifndef PTRVEC_INSERT_H
#define PTRVEC_INSERT_H

/*
 * insert(pos, n, src) of a vector of 4-byte elements (cap at +0, count at
 * +4, data at +8): copies n elements from src (adjusted when it aliases the
 * moved tail). In place when the capacity suffices, else grows (doubling,
 * capped at maxN) into a new buffer. The unrolled copies need CodeWarrior
 * 3.0 build 50 (kind mw50). C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

/* the free helper's inline guard needs a deeper inline limit */
#pragma inline_depth(10)

struct PIVec { unsigned int cap; unsigned int count; int* data; };
#define DEFINE_PTRVEC_INSERT(name, maxN, halfN, errSym, allocFile, allocLine, freeFile, freeLine) \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    extern char freeFile[];                                                   \
    }                                                                         \
    static inline unsigned int name##_Cap(const PIVec* v) { return v->cap; }  \
    static inline unsigned int name##_Cap2(const PIVec* v) { return *(const unsigned int*)v; }\
                                                                              \
    static inline void name##_Free(int* p)                                    \
    {                                                                         \
        if (p)                                                                \
            TStr_Free((char*)p, freeFile, (freeLine));                        \
    }                                                                         \
                                                                              \
    extern "C" void name(PIVec* v, int* pos, unsigned int n, const int* src)  \
    {                                                                         \
        if (n == 0)                                                           \
            return;                                                           \
        if (n > (maxN) || v->count > (maxN) - n) {                            \
            Libc_Fprintf(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        unsigned int need = v->count + n;                                     \
        if (need <= name##_Cap2(v)) {                                         \
            int* end = v->data + v->count;                                    \
            unsigned int after = end - pos;                                   \
            if (end - (after - n) <= src && src < end)                        \
                src += n;                                                     \
            if (after) {                                                      \
                int* s = end;                                                 \
                int* d = end + n;                                             \
                while (pos < s) {                                             \
                    --s;                                                      \
                    --d;                                                      \
                    *d = *s;                                                  \
                }                                                             \
            }                                                                 \
            for (unsigned int k = n; k; k--) {                                \
                *pos = *src;                                                  \
                pos++;                                                        \
            }                                                                 \
            v->count += n;                                                    \
        } else {                                                              \
            int idx;                                                          \
            int* nd;                                                          \
            int* d;                                                           \
            unsigned int newCap;                                              \
            int** pdata;                                                      \
            int* old;                                                         \
            old = v->data;                                                    \
            idx = pos - old;                                                  \
            newCap = name##_Cap(v) ? name##_Cap(v) : 1;                       \
            while (need > newCap) {                                           \
                if (newCap < (halfN))                                         \
                    newCap *= 2;                                              \
                else                                                          \
                    newCap = (maxN);                                          \
            }                                                                 \
            pdata = &v->data;                                                 \
            nd = (int*)TStr_Alloc(newCap * 4, allocFile, (allocLine));        \
            *pdata = nd;                                                      \
            d = v->data + idx;                                                \
            for (unsigned int k = n; k; k--) {                                \
                *d = *src;                                                    \
                d++;                                                          \
            }                                                                 \
            if (old) {                                                        \
                {                                                             \
                    int* s = old;                                             \
                    int* dd = v->data;                                        \
                    int* e = old + idx;                                       \
                    while (s < e) {                                           \
                        *dd = *s;                                             \
                        s++;                                                  \
                        dd++;                                                 \
                    }                                                         \
                }                                                             \
                {                                                             \
                    int* e = old + v->count;                                  \
                    int* s = old + idx;                                       \
                    int* dd = v->data + idx + n;                              \
                    while (s < e) {                                           \
                        *dd = *s;                                             \
                        s++;                                                  \
                        dd++;                                                 \
                    }                                                         \
                }                                                             \
                name##_Free(old);                                             \
            }                                                                 \
            v->count = need;                                                  \
            v->cap = newCap;                                                  \
        }                                                                     \
    }

#endif /* PTRVEC_INSERT_H */
