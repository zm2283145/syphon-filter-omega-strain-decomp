#ifndef BYTEVEC_INSERT_H
#define BYTEVEC_INSERT_H

/*
 * insert(pos, n, value) of a vector of 1-byte elements (cap at +0, count at
 * +4, data at +8): in place with moveFn (memmove) + memset when the
 * capacity suffices, else grow (doubling, capped at maxN), memset the new
 * gap and memcpy both halves, then free the old buffer.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

/* the free helper's inline guard needs a deeper inline limit */
#pragma inline_depth(10)

struct BVVec { unsigned int cap; unsigned int count; char* data; };
extern "C" void* memset(void* d, int c, unsigned int n);
#define DEFINE_BYTEVEC_INSERT(name, maxN, halfN, errSym, allocFile, allocLine, freeFile, freeLine, moveFn) \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    extern char freeFile[];                                                   \
    void* moveFn(void* d, const void* s, unsigned int n);                     \
    }                                                                         \
    static inline unsigned int name##_Cap(const BVVec* v) { return v->cap; }  \
    static inline unsigned int name##_Cap2(const BVVec* v) { return *(const volatile unsigned int*)v; }\
                                                                              \
    static inline void name##_Free(char* p)                                   \
    {                                                                         \
        if (p)                                                                \
            TStr_Free(p, freeFile, (freeLine));                               \
    }                                                                         \
                                                                              \
    extern "C" void name(BVVec* v, char* pos, unsigned int n, const char* value)\
    {                                                                         \
        if (n == 0)                                                           \
            return;                                                           \
        if (n > (maxN) || v->count > (maxN) - n) {                            \
            Libc_Fprintf(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        unsigned int need = v->count + n;                                     \
        if (need <= name##_Cap2(v)) {                                         \
            char* end = v->data + v->count;                                   \
            unsigned int after = end - pos;                                   \
            if (end - (after - n) <= value && value < end)                    \
                value += n;                                                   \
            if (after) {                                                      \
                char* d = end + n;                                            \
                d -= after;                                                   \
                moveFn(d, pos, after);                                        \
            }                                                                 \
            memset(pos, *(unsigned char*)value, n);                           \
            v->count += n;                                                    \
        } else {                                                              \
            int idx;                                                          \
            char* nd;                                                         \
            unsigned int newCap;                                              \
            char** pdata;                                                     \
            char* old;                                                        \
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
            nd = TStr_Alloc(newCap, allocFile, (allocLine));                  \
            *pdata = nd;                                                      \
            memset(v->data + idx, *(unsigned char*)value, n);                 \
            if (old) {                                                        \
                memcpy(v->data, old, idx);                                    \
                {                                                             \
                    char* f = old + idx;                                      \
                    char* l = old + v->count;                                 \
                    memcpy(v->data + idx + n, f, l - f);                      \
                }                                                             \
                name##_Free(old);                                             \
            }                                                                 \
            v->count = need;                                                  \
            v->cap = newCap;                                                  \
        }                                                                     \
    }

#endif /* BYTEVEC_INSERT_H */
