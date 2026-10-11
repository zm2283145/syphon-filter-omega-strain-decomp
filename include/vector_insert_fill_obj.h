#ifndef VECTOR_INSERT_FILL_OBJ_H
#define VECTOR_INSERT_FILL_OBJ_H

/*
 * vector<T>::insert(pos, n, value) for a class element (cap at +0, count at
 * +4, data at +8): elements are built with placement new (newFn) plus the
 * copy constructor (ctorFn); the in-place path shifts with copyBackFn and
 * fills with fillFn, the grow path builds a new vector (capacity doubled up
 * to maxN), swaps it in (swapFn) and destroys the old one (dtorFn(&tmp,-1)).
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"
#define DEFINE_VECTOR_INSERT_FILL_OBJ(name, elemBytes, maxN, halfN, errSym, allocFile, allocLine, newFn, ctorFn, copyBackFn, fillFn, swapFn, dtorFn) \
    struct name##_E { int w[(elemBytes) / 4]; };                              \
    struct name##_V { unsigned int cap; unsigned int count; name##_E* data; };\
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void* newFn(unsigned int size, void* p);                                  \
    void ctorFn(name##_E* d, const name##_E* s);                              \
    void copyBackFn(name##_E* first, name##_E* last, name##_E* dlast);        \
    void fillFn(name##_E* first, unsigned int n, const name##_E* value);      \
    void swapFn(name##_V* a, name##_V* b);                                    \
    void dtorFn(name##_V* v, int flags);                                      \
    }                                                                         \
    static inline void name##_Construct(name##_E* p, const name##_E* src)     \
    {                                                                         \
        name##_E* r = (name##_E*)newFn(sizeof(name##_E), p);                  \
        if (r)                                                                \
            ctorFn(r, src);                                                   \
    }                                                                         \
                                                                              \
    extern "C" void name(name##_V* v, name##_E* pos, unsigned int n, const name##_E* value)\
    {                                                                         \
        if (n == 0)                                                           \
            return;                                                           \
        if (n > maxN || v->count > maxN - n) {                                \
            func_00123BE8(D_00489738->stream, errSym);                        \
            func_00121B60();                                                  \
        }                                                                     \
        if (v->count + n <= v->cap) {                                         \
            name##_E* end = v->data + v->count;                               \
            unsigned int after = end - pos;                                   \
            if (after < n) {                                                  \
                name##_E* p = end;                                            \
                for (; after < n; n--) {                                      \
                    name##_Construct(p, value);                               \
                    p++;                                                      \
                    v->count++;                                               \
                }                                                             \
                for (name##_E* q = pos; q < end; q++, p++) {                  \
                    name##_Construct(p, q);                                   \
                    v->count++;                                               \
                }                                                             \
            } else {                                                          \
                name##_E* src = end - n;                                      \
                name##_E* dst = end;                                          \
                for (; src < end; src++, dst++) {                             \
                    name##_Construct(dst, src);                               \
                    v->count++;                                               \
                }                                                             \
                if (end - (after - n) <= value && value < end)                \
                    value += n;                                               \
                copyBackFn(pos, pos + (after - n), end);                      \
            }                                                                 \
            fillFn(pos, n, value);                                            \
        } else {                                                              \
            name##_V tmp;                                                     \
            name##_E* dst;                                                    \
            unsigned int newCap;                                              \
            name##_E** tdata;                                                 \
            name##_E* src;                                                    \
            unsigned int* tcount;                                             \
            name##_E* srcEnd;                                                 \
            unsigned int need;                                                \
            tcount = &tmp.count;                                              \
            tdata = &tmp.data;                                                \
            tmp.cap = 0;                                                      \
            *tcount = 0;                                                      \
            *tdata = 0;                                                       \
            need = v->count + n;                                              \
            newCap = v->cap ? v->cap : 1;                                     \
            while (need > newCap) {                                           \
                if (newCap < halfN)                                           \
                    newCap *= 2;                                              \
                else                                                          \
                    newCap = maxN;                                            \
            }                                                                 \
            *tdata = (name##_E*)TStr_Alloc(newCap * sizeof(name##_E), allocFile, allocLine);\
            tmp.cap = newCap;                                                 \
            src = v->data;                                                    \
            srcEnd = src + v->count;                                          \
            dst = *tdata;                                                     \
            for (; src < pos; src++, dst++) {                                 \
                name##_Construct(dst, src);                                   \
                (*tcount)++;                                                  \
            }                                                                 \
            for (; n; n--, dst++) {                                           \
                name##_Construct(dst, value);                                 \
                (*tcount)++;                                                  \
            }                                                                 \
            for (; src < srcEnd; src++, dst++) {                              \
                name##_Construct(dst, src);                                   \
                (*tcount)++;                                                  \
            }                                                                 \
            swapFn(&tmp, v);                                                  \
            dtorFn(&tmp, -1);                                                 \
        }                                                                     \
    }

#endif /* VECTOR_INSERT_FILL_OBJ_H */
