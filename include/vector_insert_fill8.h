#ifndef VECTOR_INSERT_FILL8_H
#define VECTOR_INSERT_FILL8_H

/*
 * vector<T>::insert(pos, n, value) for an 8-byte POD element (cap at +0,
 * count at +4, data at +8): length check, in-place shift/fill when the
 * capacity suffices, otherwise build a new vector (capacity doubled, capped
 * at 0xC00000), swap it in with swapFn and destroy the old storage with
 * dtorFn(&tmp, -1). Element copies are placement copies (null-checked).
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct VIElem { int a; int b; };
struct VIVec { unsigned int cap; unsigned int count; VIElem* data; };

static inline void VI_Construct(VIElem* p, const VIElem* src)
{
    if (p)
        *p = *src;
}
#define DEFINE_VECTOR_INSERT_FILL8(name, errSym, allocFile, allocLine, swapFn, dtorFn) \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void swapFn(VIVec* a, VIVec* b);                                          \
    void dtorFn(VIVec* v, int flags);                                         \
    }                                                                         \
    extern "C" void name(VIVec* v, VIElem* pos, unsigned int n, const VIElem* value)\
    {                                                                           \
        if (n == 0)                                                             \
            return;                                                             \
        if (n > 0xC00000 || v->count > 0xC00000 - n) {                          \
            Libc_Fprintf(D_00489738->stream, errSym);                          \
            Libc_Abort();                                                    \
        }                                                                       \
        if (v->count + n <= v->cap) {                                           \
            VIElem* end = v->data + v->count;                                   \
            unsigned int after = end - pos;                                     \
            if (after < n) {                                                    \
                VIElem* p = end;                                                \
                for (; after < n; n--) {                                        \
                    VI_Construct(p, value);                                     \
                    p++;                                                        \
                    v->count++;                                                 \
                }                                                               \
                for (VIElem* q = pos; q < end; q++, p++) {                      \
                    VI_Construct(p, q);                                         \
                    v->count++;                                                 \
                }                                                               \
            } else {                                                            \
                VIElem* src = end - n;                                          \
                VIElem* dst = end;                                              \
                for (; src < end; src++, dst++) {                               \
                    VI_Construct(dst, src);                                     \
                    v->count++;                                                 \
                }                                                               \
                if (end - (after - n) <= value && value < end)                  \
                    value += n;                                                 \
                VIElem* last = pos + (after - n);                               \
                VIElem* d = end;                                                \
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
            VIVec tmp;                                                          \
            VIElem* dst;                                                        \
            unsigned int newCap;                                                \
            VIElem** tdata;                                                     \
            VIElem* src;                                                        \
            unsigned int* tcount;                                               \
            VIElem* srcEnd;                                                     \
            unsigned int need;                                                  \
            tcount = &tmp.count;                                                \
            tdata = &tmp.data;                                                  \
            tmp.cap = 0;                                                        \
            *tcount = 0;                                                        \
            *tdata = 0;                                                         \
            need = v->count + n;                                                \
            newCap = v->cap ? v->cap : 1;                                       \
            while (need > newCap) {                                             \
                if (newCap < 0x600000)                                          \
                    newCap *= 2;                                                \
                else                                                            \
                    newCap = 0xC00000;                                          \
            }                                                                   \
            *tdata = (VIElem*)TStr_Alloc(newCap * 8, allocFile, allocLine);     \
            tmp.cap = newCap;                                                   \
            src = v->data;                                                      \
            srcEnd = src + v->count;                                            \
            dst = *tdata;                                                       \
            for (; src < pos; src++, dst++) {                                   \
                VI_Construct(dst, src);                                         \
                (*tcount)++;                                                    \
            }                                                                   \
            for (; n; n--, dst++) {                                             \
                VI_Construct(dst, value);                                       \
                (*tcount)++;                                                    \
            }                                                                   \
            for (; src < srcEnd; src++, dst++) {                                \
                VI_Construct(dst, src);                                         \
                (*tcount)++;                                                    \
            }                                                                   \
            swapFn(&tmp, v);                                                    \
            dtorFn(&tmp, -1);                                                   \
        }                                                                       \
    }

#endif /* VECTOR_INSERT_FILL8_H */
