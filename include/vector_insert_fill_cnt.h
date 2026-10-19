#ifndef VECTOR_INSERT_FILL_CNT_H
#define VECTOR_INSERT_FILL_CNT_H
/*
 * vector<T>::insert(pos, n, value) for POD T (any size): the count is cached
 * before the capacity test and the old end is recomputed from data/byte-offset
 * locals (data_ + off_) at each use and CSE'd by the compiler; a named end
 * local gives a different register order.
 * TAIL is the old-storage release statement of the grow path; ASSIGN(d, s)
 * is the element assignment used by the shift and fill loops, COPY(p, s) the
 * placement copy-construction.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"
#define DEFINE_VECTOR_INSERT_FILL_CNT(name, T, maxN, halfN, errSym, allocFile, allocLine, swapFn, DECLS, TAIL, ASSIGN, COPY) \
    struct name##_V { unsigned int cap; unsigned int count; T* data; };       \
    static inline void name##_Construct(T* p, const T* src)                   \
    {                                                                         \
        if (p)                                                                \
            COPY(p, src);                                                     \
    }                                                                         \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void swapFn(name##_V* a, name##_V* b);                                    \
    DECLS                                                                     \
    }                                                                         \
extern "C" void name(name##_V* v, T* pos, unsigned int n, const T* value)     \
{                                                                             \
    if (n == 0)                                                               \
        return;                                                               \
    if (n > (maxN) || v->count > (maxN) - n) {                                \
        func_00123BE8(D_00489738->stream, errSym);                            \
        Libc_Abort();                                                      \
    }                                                                         \
    unsigned int cnt_ = v->count;                                             \
    if (cnt_ + n <= v->cap) {                                                 \
        unsigned int off_ = cnt_ * sizeof(T); T* data_ = v->data;         \
        unsigned int after = ((T*)((char*)data_ + off_)) - pos;               \
        if (after < n) {                                                      \
            T* p = ((T*)((char*)data_ + off_));                               \
            for (; after < n; n--) {                                          \
                name##_Construct(p, value);                                   \
                p++;                                                          \
                v->count++;                                                   \
            }                                                                 \
            for (T* q = pos; q < ((T*)((char*)data_ + off_)); q++, p++) {     \
                name##_Construct(p, q);                                       \
                v->count++;                                                   \
            }                                                                 \
        } else {                                                              \
            T* src = ((T*)((char*)data_ + off_)) - n;                         \
            T* dst = ((T*)((char*)data_ + off_));                             \
            for (; src < ((T*)((char*)data_ + off_)); src++, dst++) {         \
                name##_Construct(dst, src);                                   \
                v->count++;                                                   \
            }                                                                 \
            if (((T*)((char*)data_ + off_)) - (after - n) <= value && value < ((T*)((char*)data_ + off_)))\
                value += n;                                                   \
            T* last = pos + (after - n);                                      \
            T* d = ((T*)((char*)data_ + off_));                               \
            while (pos < last) {                                              \
                --last;                                                       \
                --d;                                                          \
                ASSIGN(d, last);                                              \
            }                                                                 \
        }                                                                     \
        if (n) do {                                                           \
            ASSIGN(pos, value);                                               \
            --n;                                                              \
            ++pos;                                                            \
        } while (n);                                                          \
    } else {                                                                  \
        name##_V tmp;                                                         \
        T* dst;                                                               \
        unsigned int newCap;                                                  \
        T** tdata;                                                            \
        T* src;                                                               \
        unsigned int* tcount;                                                 \
        T* srcEnd;                                                            \
        unsigned int need;                                                    \
        tcount = &tmp.count;                                                  \
        tdata = &tmp.data;                                                    \
        tmp.cap = 0;                                                          \
        *tcount = 0;                                                          \
        *tdata = 0;                                                           \
        need = v->count + n;                                                  \
        newCap = v->cap ? v->cap : 1;                                         \
        while (need > newCap) {                                               \
            if (newCap < (halfN))                                             \
                newCap *= 2;                                                  \
            else                                                              \
                newCap = (maxN);                                              \
        }                                                                     \
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), allocFile, allocLine);    \
        tmp.cap = newCap;                                                     \
        src = v->data;                                                        \
        srcEnd = src + v->count;                                              \
        dst = *tdata;                                                         \
        for (; src < pos; src++, dst++) {                                     \
            name##_Construct(dst, src);                                       \
            (*tcount)++;                                                      \
        }                                                                     \
        for (; n; n--, dst++) {                                               \
            name##_Construct(dst, value);                                     \
            (*tcount)++;                                                      \
        }                                                                     \
        for (; src < srcEnd; src++, dst++) {                                  \
            name##_Construct(dst, src);                                       \
            (*tcount)++;                                                      \
        }                                                                     \
        swapFn(&tmp, v);                                                      \
        TAIL;                                                                 \
    }                                                                         \
}                                                                             

#endif
