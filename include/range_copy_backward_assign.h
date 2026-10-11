#ifndef RANGE_COPY_BACKWARD_ASSIGN_H
#define RANGE_COPY_BACKWARD_ASSIGN_H

/*
 * copy_backward(first, last, destEnd) for an element type with a
 * non-trivial assignment assignFn(dest, src); returns the new start of the
 * destination. C++ only (#pragma cplusplus on before including).
 *
 *   DEFINE_COPY_BACKWARD_ELEMENT(T, bytes)
 *   DEFINE_RANGE_COPY_BACKWARD_ASSIGN(name, T, assignFn)
 */
#define DEFINE_COPY_BACKWARD_ELEMENT(T, bytes)                                \
    struct T {                                                                \
        int words[(bytes) / 4];                                               \
    };

#define DEFINE_RANGE_COPY_BACKWARD_ASSIGN(name, T, assignFn)                  \
    extern "C" T* assignFn(T* dest, const T* src);                            \
    extern "C" T* name(T* first, T* last, T* dest)                            \
    {                                                                         \
        while (first < last) {                                                \
            --last;                                                           \
            --dest;                                                           \
            assignFn(dest, last);                                             \
        }                                                                     \
        return dest;                                                          \
    }

#endif /* RANGE_COPY_BACKWARD_ASSIGN_H */