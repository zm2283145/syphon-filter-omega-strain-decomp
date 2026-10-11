#ifndef O1_VECTOR_RESERVE_H
#define O1_VECTOR_RESERVE_H

/*
 * vector<T>::reserve(n) from the units built at optimization level 1,
 * where every accessor is an out-of-line call: if capacity < n, check
 * max_size (throwFn(errSym)), build a temporary vector with the same
 * allocator, allocate n elements, copy-construct the old elements into it
 * (constructFn), swap it in and destroy the temporary (dtorFn(&tmp, -1)).
 * Plain C; T has elemBytes bytes. Wrap the DEFINE in #pragma push /\n * #pragma optimization_level 1 ... #pragma pop.
 */
#define DEFINE_O1_VECTOR_RESERVE(name, elemBytes, errSym, capFn, maxFn, throwFn, getAllocFn, \
                                 vecCtorFn, allocateFn, dataRefFn, capRefFn, beginFn, endFn, \
                                 constructFn, swapFn, dtorFn)                  \
    typedef struct name##_E { int w[(elemBytes) / 4]; } name##_E;             \
    typedef struct name##_V { name##_E* data; unsigned int count; unsigned int cap; } name##_V; \
    extern char errSym[];                                                     \
    extern unsigned int capFn(name##_V* v);                                   \
    extern unsigned int maxFn(name##_V* v);                                   \
    extern void throwFn(const char* msg);                                     \
    extern void* getAllocFn(name##_V* v);                                     \
    extern void vecCtorFn(name##_V* v, void* alloc);                          \
    extern name##_E* allocateFn(void* alloc, unsigned int n, int hint);       \
    extern name##_E** dataRefFn(name##_V* v);                                 \
    extern unsigned int* capRefFn(name##_V* v);                               \
    extern name##_E* beginFn(name##_V* v);                                    \
    extern name##_E* endFn(name##_V* v);                                      \
    extern void constructFn(void* alloc, name##_E* p, const name##_E* src);   \
    extern void swapFn(name##_V* a, name##_V* b);                             \
    extern void dtorFn(name##_V* v, int flags);                               \
    void name(name##_V* v, unsigned int n)                                    \
    {                                                                         \
        name##_V tmp;                                                         \
        name##_E* dst;                                                        \
        name##_E* src;                                                        \
        name##_E* end;                                                        \
        if (capFn(v) < n) {                                                   \
            if (maxFn(v) < n)                                                 \
                throwFn(errSym);                                              \
            vecCtorFn(&tmp, getAllocFn(v));                                   \
            {                                                                 \
                name##_E* p = allocateFn(getAllocFn(&tmp), n, 0);             \
                *dataRefFn(&tmp) = p;                                         \
            }                                                                 \
            *capRefFn(&tmp) = n;                                              \
            dst = *dataRefFn(&tmp);                                           \
            src = beginFn(v);                                                 \
            end = endFn(v);                                                   \
            while (src < end) {                                               \
                constructFn(getAllocFn(&tmp), dst, src);                      \
                src++;                                                        \
                dst++;                                                        \
                tmp.count++;                                                  \
            }                                                                 \
            swapFn(&tmp, v);                                                  \
            dtorFn(&tmp, -1);                                                 \
        }                                                                     \
    }

#endif /* O1_VECTOR_RESERVE_H */