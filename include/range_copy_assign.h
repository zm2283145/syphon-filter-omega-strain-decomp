#ifndef RANGE_COPY_ASSIGN_H
#define RANGE_COPY_ASSIGN_H

/*
 * copy(first, last, dest) for an element type with a non-trivial
 * assignment assignFn(dest, src); returns the end of the destination.
 * C++ only (#pragma cplusplus on before including).
 *
 *   DEFINE_COPY_ELEMENT(T, bytes)
 *   DEFINE_RANGE_COPY_ASSIGN(name, T, assignFn)
 */
#define DEFINE_COPY_ELEMENT(T, bytes)                                         \
    struct T {                                                                \
        int words[(bytes) / 4];                                               \
    };

#define DEFINE_RANGE_COPY_ASSIGN(name, T, assignFn)                           \
    extern "C" T* assignFn(T* dest, const T* src);                            \
    extern "C" T* name(T* first, T* last, T* dest)                            \
    {                                                                         \
        while (first < last) {                                                \
            assignFn(dest, first);                                            \
            ++first;                                                          \
            ++dest;                                                           \
        }                                                                     \
        return dest;                                                          \
    }

#endif /* RANGE_COPY_ASSIGN_H */