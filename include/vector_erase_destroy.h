#ifndef VECTOR_ERASE_DESTROY_H
#define VECTOR_ERASE_DESTROY_H

/*
 * vector::erase(first, last) for element types with non-trivial copy and
 * destruction (count at +4, data at +8): copy the tail down with the
 * element range-copy helper, destroy the vacated tail elements, shrink the
 * count. Identical template clones, one per translation unit.
 * C++ only (#pragma cplusplus on before including).
 *
 *   DEFINE_ERASE_ELEMENT(T, bytes)                 declares a T of that size
 *   DEFINE_VECTOR_ERASE_DESTROY(name, T, copyFn, destroyFn)
 *     copyFn(first, last, dest) returns dest end; destroyFn(elem, -1).
 */
#define DEFINE_ERASE_ELEMENT(T, bytes)                                        \
    struct T {                                                                \
        int words[(bytes) / 4];                                               \
    };                                                                        \
    struct T##Vector {                                                        \
        int capacity;                                                         \
        int count;                                                            \
        T* data;                                                              \
    };

#define DEFINE_VECTOR_ERASE_DESTROY(name, T, copyFn, destroyFn)               \
    extern "C" {                                                              \
    T* copyFn(T* first, T* last, T* dest);                                    \
    void destroyFn(T* elem, int flags);                                       \
    }                                                                         \
    extern "C" T* name(T##Vector* self, T* first, T* last)                    \
    {                                                                         \
        if (first == last)                                                    \
            return first;                                                     \
        T* end = self->data + self->count;                                    \
        int tailCount = end - last;                                           \
        if (tailCount)                                                        \
            copyFn(last, end, first);                                         \
        T* tail = first + tailCount;                                          \
        while (tail < end) {                                                  \
            destroyFn(tail, -1);                                              \
            ++tail;                                                           \
        }                                                                     \
        self->count -= last - first;                                          \
        return first;                                                         \
    }

#endif /* VECTOR_ERASE_DESTROY_H */