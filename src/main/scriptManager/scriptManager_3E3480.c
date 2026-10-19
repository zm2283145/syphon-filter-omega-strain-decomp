/*
 * main/scriptManager: 2 files, 003E3480-003E3660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E3480 */
#pragma push /* merge_units */
typedef struct Int3E3 { int x; int y; int z; } Int3E3;
typedef struct { int capacity; int count; Int3E3 *data; } Int3E3Vector;
Int3E3 *func_003E3480(Int3E3Vector *v, Int3E3 *first, Int3E3 *last)
{
    Int3E3 *end;
    Int3E3 *s;
    Int3E3 *d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last != 0) {
        d = first;
        s = last;
        while (s < end) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3480 */

/* merge_units: begin func_003E3660 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
#define DEFINE_VIF_U(name, T, maxN, halfN, errSym, allocFile, allocLine, swapFn, dtorFn) \
    struct name##_V { unsigned int cap; unsigned int count; T* data; };       \
    static inline void name##_Construct(T* p, const T* src)                   \
    {                                                                         \
        if (p)                                                                \
            *p = *src;                                                        \
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
            Libc_Abort();                                                    \
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
                    d->w = last->w;                                               \
                }                                                               \
            }                                                                   \
            if (n) do {                                                         \
                pos->w = value->w;                                                \
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


union E_003E3660 { struct { int a, b, c; } w; struct { char b[12]; } c; };
extern "C" { char D_004BDA60[] = "vector::insert length error\n"; }
DEFINE_VIF_U(func_003E3660, E_003E3660, 0x800000, 0x400000, D_004BDA60, D_004BD408, 0x5C, func_003E3B20, func_003D95D0)
#pragma pop /* merge_units */
/* merge_units: end func_003E3660 */
