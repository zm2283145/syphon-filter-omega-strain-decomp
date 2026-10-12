#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
#define DEFINE_VIF_UF(name, T, maxN, halfN, errSym, allocFile, allocLine, swapFn, freeFile, freeLine) \
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
    extern char freeFile[];                                         \
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
            *tcount = 0; { T* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, freeFile, freeLine); } } \
        }                                                                       \
    }


union E_002AD1F0 { struct { int a, b, c; } w; struct { char b[12]; } c; };
extern "C" { char D_004ABA20[] = "vector::insert length error\n"; }
DEFINE_VIF_UF(func_002AD1F0, E_002AD1F0, 0x800000, 0x400000, D_004ABA20, D_004ABA70, 0x5C, func_002AD730, D_004ABA60, 0x64)
