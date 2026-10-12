#ifndef VECTOR_INSERT_FILL_V2_H
#define VECTOR_INSERT_FILL_V2_H
/*
 * vector<T>::insert(pos, n, value), second library build: max_size kept in a
 * register (half computed once before the growth loop), loops not rotated,
 * fill through an inline helper, temporary vector on the stack released by an
 * inline destructor (element destructor loop, count reset, guarded free).
 * Instances need, before the DEFINE and never popped (C++ code generation is
 * deferred to the end of the file):
 *   #pragma opt_rotateloops off / opt_propagation off / opt_common_subs off /
 *   opt_dead_code off / opt_loop_invariants off
 * T must have an empty user destructor. COPY(p, s) is the placement copy,
 * ASSIGN(d, s) the element assignment, TAIL the release of the old storage.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"
#define VIF2_FREE(T, freeFile, freeLine)                                      \
        {                                                                     \
            T* b_ = tmp.data;                                                 \
            T* e_ = b_ + tmp.count;                                           \
            while (b_ < e_) (--e_)->~T();                                     \
            T* fp_ = tmp.data;                                                \
            tmp.count = 0; if (fp_) { if (fp_) TStr_Free((char*)fp_, freeFile, freeLine); } \
        }
#define DEFINE_VECTOR_INSERT_FILL_V2(name, T, maxN, errSym, allocFile, allocLine, swapFn, DECLS, TAIL, COPY, ASSIGN) \
    struct name##_V { unsigned int cap; unsigned int count; T* data; };      \
    static inline void name##_Construct(T* p, const T* src) { if (p) COPY(p, src); } \
    static inline void name##_Fill(T* p, unsigned int k, const T* x) { for (; k; --k, ++p) ASSIGN(p, x); } \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void swapFn(name##_V* a, name##_V* b);                                    \
    DECLS                                                                     \
    }                                                                         \
    extern "C" void name(name##_V* v, T* pos, unsigned int n, const T* value) \
    {                                                                         \
        if (n == 0)                                                           \
            return;                                                           \
        unsigned int max = (maxN);                                            \
        if (n > max || v->count > max - n) {                                  \
            func_00123BE8(D_00489738->stream, errSym);                        \
            func_00121B60();                                                  \
        }                                                                     \
        unsigned int cap = v->cap; unsigned int cnt = v->count;               \
        if (cnt + n <= cap) {                                                 \
            T* end = v->data + cnt;                                           \
            unsigned int after = end - pos;                                   \
            if (after < n) {                                                  \
                T* p = end;                                                   \
                for (; after < n; n--) {                                      \
                    name##_Construct(p, value);                               \
                    p++;                                                      \
                    v->count++;                                               \
                }                                                             \
                for (T* q = pos; q < end; q++, p++) {                         \
                    name##_Construct(p, q);                                   \
                    v->count++;                                               \
                }                                                             \
            } else {                                                          \
                T* src = end - n;                                             \
                T* dst = end;                                                 \
                for (; src < end; src++, dst++) {                             \
                    name##_Construct(dst, src);                               \
                    v->count++;                                               \
                }                                                             \
                if (end - (after - n) <= value && value < end)                \
                    value += n;                                               \
                T* last = pos + (after - n);                                  \
                T* d = end;                                                   \
                while (pos < last) {                                          \
                    --last;                                                   \
                    --d;                                                      \
                    ASSIGN(d, last);                                          \
                }                                                             \
            }                                                                 \
            name##_Fill(pos, n, value);                                       \
        } else {                                                              \
            name##_V tmp;                                                     \
            tmp.cap = 0; tmp.count = 0; tmp.data = 0;                         \
            unsigned int need = v->count + n;                                 \
            /* empty then-arm (scheduling barrier) keeps retail's block layout */ \
            unsigned int newCap = v->cap; if (newCap != 0) asm { .set reorder } else newCap = 1; \
            unsigned int half = max / 2;                                      \
            while (need > newCap) { if (newCap < half) newCap *= 2; else newCap = max; } \
            T* buf = (T*)TStr_Alloc(newCap * sizeof(T), allocFile, allocLine); \
            { name##_V* tp = &tmp; tmp.data = buf; tp->cap = newCap; }        \
            T* dst; T* src; T* srcEnd;                                        \
            src = v->data;                                                    \
            srcEnd = src + v->count;                                          \
            dst = tmp.data;                                                   \
            for (; src < pos; src++, dst++) {                                 \
                name##_Construct(dst, src);                                   \
                tmp.count++;                                                  \
            }                                                                 \
            for (; n; dst++, n--) {                                           \
                name##_Construct(dst, value);                                 \
                tmp.count++;                                                  \
            }                                                                 \
            for (; src < srcEnd; src++, dst++) {                              \
                name##_Construct(dst, src);                                   \
                tmp.count++;                                                  \
            }                                                                 \
            swapFn(&tmp, v);                                                  \
            TAIL;                                                             \
        }                                                                     \
    }
#endif
