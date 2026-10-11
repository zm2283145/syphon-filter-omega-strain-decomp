#ifndef O1_VECTOR_CLEAR_H
#define O1_VECTOR_CLEAR_H

/*
 * vector<T>::clear() from the units built at optimization level 1: destroy
 * the elements back to front through destroyFn(getAllocFn(v), --p) and
 * zero the count. Plain C; wrap the DEFINE in #pragma push /
 * #pragma optimization_level 1 ... #pragma pop.
 */
#define DEFINE_O1_VECTOR_CLEAR(name, elemBytes, dataRefFn, getAllocFn, destroyFn) \
    typedef struct name##_E { int w[(elemBytes) / 4]; } name##_E;             \
    typedef struct name##_V { name##_E* data; unsigned int count; unsigned int cap; } name##_V; \
    extern name##_E** dataRefFn(name##_V* v);                                 \
    extern void* getAllocFn(name##_V* v);                                     \
    extern void destroyFn(void* alloc, name##_E* p);                          \
    void name(name##_V* v)                                                    \
    {                                                                         \
        name##_E* first;                                                      \
        name##_E* p;                                                          \
        first = *dataRefFn(v);                                                \
        p = first + v->count;                                                 \
        while (p > first)                                                     \
            destroyFn(getAllocFn(v), --p);                                    \
        v->count = 0;                                                         \
    }

#endif /* O1_VECTOR_CLEAR_H */