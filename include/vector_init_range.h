#ifndef VECTOR_INIT_RANGE_H
#define VECTOR_INIT_RANGE_H

/*
 * vector<T>(first, last) range initialisation for a POD T: n = last - first,
 * length check on the current count (count > maxN raises the length error),
 * allocate n elements, set the capacity and placement-copy the range,
 * bumping the count per element. C++ only (#pragma cplusplus on).
 */
#include "tstr_types.h"

#define DEFINE_VECTOR_INIT_RANGE(name, T, maxN, errSym, allocFile, allocLine) \
    struct name##_V { unsigned int cap; unsigned int count; T* data; };       \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    }                                                                         \
    extern "C" void name(name##_V* v, const T* first, const T* last)          \
    {                                                                         \
        unsigned int n = last - first;                                        \
        if (v->count > (maxN)) {                                              \
            func_00123BE8(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        if (n) {                                                              \
            T** pdata = &v->data;                                             \
            *pdata = (T*)TStr_Alloc(n * sizeof(T), allocFile, (allocLine));   \
            v->cap = n;                                                       \
            T* p = v->data;                                                   \
            for (; first != last; first++, p++) {                             \
                if (p)                                                        \
                    *p = *first;                                              \
                v->count++;                                                   \
            }                                                                 \
        }                                                                     \
    }

#endif /* VECTOR_INIT_RANGE_H */