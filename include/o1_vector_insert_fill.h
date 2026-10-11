#ifndef O1_VECTOR_INSERT_FILL_H
#define O1_VECTOR_INSERT_FILL_H

/*
 * vector<T>::insert(pos, n, value) from the units built at optimization
 * level 1 (all accessors out of line): length check against max_size,
 * in-place construct/shift/fill when the capacity suffices, otherwise grow
 * into a temporary vector (capacity doubled up to max_size), swap it in and
 * destroy it. Plain C; wrap the DEFINE in #pragma push /
 * #pragma optimization_level 1 ... #pragma pop.
 */#define DEFINE_O1_VECTOR_INSERT_FILL(name, elemBytes, errSym, capFn, maxFn, throwFn, getAllocFn, vecCtorFn, allocateFn, dataRefFn, capRefFn, beginFn, endFn, constructFn, swapFn, dtorFn, copyBackFn, fillFn) \
    typedef struct name##_E { int w[(elemBytes) / 4]; } name##_E;             \
    typedef struct name##_V { name##_E* data; unsigned int count; unsigned int cap; } name##_V;\
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
    extern void copyBackFn(name##_E* first, name##_E* last, name##_E* dlast); \
    extern void fillFn(name##_E* first, unsigned int n, const name##_E* value);\
    void name(name##_V* v, name##_E* pos, unsigned int n, const name##_E* value)\
    {                                                                         \
        name##_V tmp;                                                         \
        name##_E* src;                                                        \
        name##_E* q;                                                          \
        unsigned int need;                                                    \
        name##_E* srcEnd;                                                     \
        unsigned int max;                                                     \
        name##_E* p;                                                          \
        name##_E* end;                                                        \
        unsigned int newCap;                                                  \
        unsigned int after;                                                   \
        name##_E* dst;                                                        \
        if (n == 0)                                                           \
            return;                                                           \
        max = maxFn(v);                                                       \
        if (n > max || v->count > max - n)                                    \
            throwFn(errSym);                                                  \
        if (v->count + n <= capFn(v)) {                                       \
            end = endFn(v);                                                   \
            after = end - pos;                                                \
            if (after < n) {                                                  \
                p = end;                                                      \
                while (n > after) {                                           \
                    constructFn(getAllocFn(v), p, value);                     \
                    p++;                                                      \
                    n--;                                                      \
                    v->count++;                                               \
                }                                                             \
                {                                                             \
                    name##_E* q2 = pos;                                       \
                    while (q2 < end) {                                        \
                        constructFn(getAllocFn(v), p, q2);                    \
                        q2++;                                                 \
                        p++;                                                  \
                        v->count++;                                           \
                    }                                                         \
                }                                                             \
            } else {                                                          \
                q = end - n;                                                  \
                p = end;                                                      \
                while (q < end) {                                             \
                    constructFn(getAllocFn(v), p, q);                         \
                    q++;                                                      \
                    p++;                                                      \
                    v->count++;                                               \
                }                                                             \
                if (end - (after - n) <= value && value < end)                \
                    value += n;                                               \
                copyBackFn(pos, pos + (after - n), end);                      \
            }                                                                 \
            fillFn(pos, n, value);                                            \
        } else {                                                              \
            vecCtorFn(&tmp, getAllocFn(v));                                   \
            need = v->count + n;                                              \
            newCap = *capRefFn(v) ? *capRefFn(v) : 1;                         \
            while (need > newCap) {                                           \
                if (newCap < max >> 1)                                        \
                    newCap <<= 1;                                             \
                else                                                          \
                    newCap = max;                                             \
            }                                                                 \
            dst = allocateFn(getAllocFn(&tmp), newCap, 0);                    \
            *dataRefFn(&tmp) = dst;                                           \
            *capRefFn(&tmp) = newCap;                                         \
            dst = *dataRefFn(&tmp);                                           \
            src = beginFn(v);                                                 \
            srcEnd = endFn(v);                                                \
            while (src < pos) {                                               \
                constructFn(getAllocFn(&tmp), dst, src);                      \
                src++;                                                        \
                dst++;                                                        \
                tmp.count++;                                                  \
            }                                                                 \
            while (n) {                                                       \
                constructFn(getAllocFn(&tmp), dst, value);                    \
                dst++;                                                        \
                n--;                                                          \
                tmp.count++;                                                  \
            }                                                                 \
            while (src < srcEnd) {                                            \
                constructFn(getAllocFn(&tmp), dst, src);                      \
                src++;                                                        \
                dst++;                                                        \
                tmp.count++;                                                  \
            }                                                                 \
            swapFn(&tmp, v);                                                  \
            dtorFn(&tmp, -1);                                                 \
        }                                                                     \
    }

#endif /* O1_VECTOR_INSERT_FILL_H */
