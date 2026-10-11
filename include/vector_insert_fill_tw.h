#ifndef VECTOR_INSERT_FILL_TW_H
#define VECTOR_INSERT_FILL_TW_H

/*
 * vector_insert_fill_t.h variant for 8-byte T whose placement copies are two word copies (copy constructor) while
 * assignments use T::operator= (member-wise, e.g. float members through FPRs): vector<T>::insert(pos, n, value) with the
 * in-place shift/fill path and the grow-swap-destroy path.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"
#define DEFINE_VECTOR_INSERT_FILL_TW(name, T, maxN, halfN, errSym, allocFile, allocLine, swapFn, dtorFn) \
    struct name##_V { unsigned int cap; unsigned int count; T* data; };       \
    static inline void name##_Construct(T* p, const T* src)                   \
    {                                                                         \
        if (p)                                                                \
            {                                                                 \
                int* d_ = (int*)p;                                            \
                const int* s_ = (const int*)src;                              \
                d_[0] = s_[0];                                                \
                d_[1] = s_[1];                                                \
            }                                                                 \
    }                                                                         \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void swapFn(name##_V* a, name##_V* b);                                          \
    void dtorFn(name##_V* v, int flags);                                         \
    }                                                                         \
    extern "C" void name(name##_V* v, T* pos, unsigned int n, const T* value)\
    {                                                                           \
        if (n == 0)                                                             \
            return;                                                             \
        if (n > (maxN) || v->count > (maxN) - n) {                          \
            func_00123BE8(D_00489738->stream, errSym);                          \
            func_00121B60();                                                    \
        }                                                                       \
        if (v->count + n <= v->cap) {                                           \
            T* end = v->data + v->count;                                   \
            unsigned int after = end - pos;                                     \
            if (after < n) {                                                    \
                T* p = end;                                                \
                for (; after < n; n--) {                                        \
                    name##_Construct(p, value);                                     \
                    p++;                                                        \
                    v->count++;                                                 \
                }                                                               \
                for (T* q = pos; q < end; q++, p++) {                      \
                    name##_Construct(p, q);                                         \
                    v->count++;                                                 \
                }                                                               \
            } else {                                                            \
                T* src = end - n;                                          \
                T* dst = end;                                              \
                for (; src < end; src++, dst++) {                               \
                    name##_Construct(dst, src);                                     \
                    v->count++;                                                 \
                }                                                               \
                if (end - (after - n) <= value && value < end)                  \
                    value += n;                                                 \
                T* last = pos + (after - n);                               \
                T* d = end;                                                \
                while (pos < last) {                                            \
                    --last;                                                     \
                    --d;                                                        \
                    *d = *last;                                                 \
                }                                                               \
            }                                                                   \
            if (n) do {                                                         \
                *pos = *value;                                                  \
                --n;                                                            \
                ++pos;                                                          \
            } while (n);                                                        \
        } else {                                                                \
            name##_V tmp;                                                          \
            T* dst;                                                        \
            unsigned int newCap;                                                \
            T** tdata;                                                     \
            T* src;                                                        \
            unsigned int* tcount;                                               \
            T* srcEnd;                                                     \
            unsigned int need;                                                  \
            tcount = &tmp.count;                                                \
            tdata = &tmp.data;                                                  \
            tmp.cap = 0;                                                        \
            *tcount = 0;                                                        \
            *tdata = 0;                                                         \
            need = v->count + n;                                                \
            newCap = v->cap ? v->cap : 1;                                       \
            while (need > newCap) {                                             \
                if (newCap < (halfN))                                          \
                    newCap *= 2;                                                \
                else                                                            \
                    newCap = (maxN);                                          \
            }                                                                   \
            *tdata = (T*)TStr_Alloc(newCap * sizeof(T), allocFile, allocLine);     \
            tmp.cap = newCap;                                                   \
            src = v->data;                                                      \
            srcEnd = src + v->count;                                            \
            dst = *tdata;                                                       \
            for (; src < pos; src++, dst++) {                                   \
                name##_Construct(dst, src);                                         \
                (*tcount)++;                                                    \
            }                                                                   \
            for (; n; n--, dst++) {                                             \
                name##_Construct(dst, value);                                       \
                (*tcount)++;                                                    \
            }                                                                   \
            for (; src < srcEnd; src++, dst++) {                                \
                name##_Construct(dst, src);                                         \
                (*tcount)++;                                                    \
            }                                                                   \
            swapFn(&tmp, v);                                                    \
            dtorFn(&tmp, -1);                                                   \
        }                                                                       \
    }

#endif /* VECTOR_INSERT_FILL_TW_H */
