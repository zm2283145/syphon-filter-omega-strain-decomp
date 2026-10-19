/*
 * main/inventory: 2 files, 00471250-00471290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00471250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* swap(a, b) */
void func_00471250(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00471250 */

/* merge_units: begin func_00471290 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"
/*
 * vector<T>::insert(pos, n, value) for a 0x2C-byte element: count cached
 * before the capacity test and a named old-end local. Copy-construction is
 * a bitwise union copy (FPR block copy); assignment is member-wise (words +
 * char array byte loop).
 */
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
        func_00121B60();                                                      \
    }                                                                         \
    unsigned int cnt_ = v->count;                                             \
    if (cnt_ + n <= v->cap) {                                                 \
        T* end_ = v->data + cnt_;         \
        unsigned int after = end_ - pos;               \
        if (after < n) {                                                      \
            T* p = end_;                               \
            for (; after < n; n--) {                                          \
                name##_Construct(p, value);                                   \
                p++;                                                          \
                v->count++;                                                   \
            }                                                                 \
            for (T* q = pos; q < end_; q++, p++) {     \
                name##_Construct(p, q);                                       \
                v->count++;                                                   \
            }                                                                 \
        } else {                                                              \
            T* src = end_ - n;                         \
            T* dst = end_;                             \
            for (; src < end_; src++, dst++) {         \
                name##_Construct(dst, src);                                   \
                v->count++;                                                   \
            }                                                                 \
            if (end_ - (after - n) <= value && value < end_)\
                value += n;                                                   \
            T* last = pos + (after - n);                                      \
            T* d = end_;                               \
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


struct W_00471290 { int a; int b; char s[32]; int d; };
union E_00471290 { W_00471290 w; struct { float f[11]; } c; };
#define VIFC_ASSIGN(d, s) ((d)->w = (s)->w)
#define VIFC_COPY(d, s) (*(d) = *(s))
DEFINE_VECTOR_INSERT_FILL_CNT(ItemRegTable_Append, E_00471290, 0x22E8BA, 0x11745D, D_004C3360, D_004C33F0, 0x5C, func_00471960, void func_004719B0(ItemRegTable_Append_V* v, int flags);, func_004719B0(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
#pragma pop /* merge_units */
/* merge_units: end func_00471290 */
