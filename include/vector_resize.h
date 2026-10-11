#ifndef VECTOR_RESIZE_H
#define VECTOR_RESIZE_H

/*
 * vector::resize(n, value) shared by identical template clones (count at
 * +4, data at +8): grow through growFn(v, end, n - size, value) or shrink
 * through eraseFn(v, begin + n, end).
 * C++ only (#pragma cplusplus on before including).
 *
 *   DEFINE_RESIZE_ELEMENT(T, bytes)
 *   DEFINE_VECTOR_RESIZE(name, T, growFn, eraseFn)
 * Compile the member with #pragma opt_common_subs off (the size is re-read).
 */
#define DEFINE_RESIZE_ELEMENT(T, bytes)                                       \
    struct T {                                                                \
        int words[(bytes) / 4];                                               \
    };                                                                        \
    struct T##ResizeVector {                                                  \
        int capacity;                                                         \
        unsigned int count;                                                   \
        T* data;                                                              \
    };                                                                        \
    static inline T* T##_end(T##ResizeVector* v)                              \
    {                                                                         \
        return v->data + v->count;                                            \
    }

#define DEFINE_VECTOR_RESIZE(name, T, growFn, eraseFn)                        \
    extern "C" {                                                              \
    void growFn(T##ResizeVector* v, T* pos, unsigned int n, const T* value);  \
    T* eraseFn(T##ResizeVector* v, T* first, T* last);                        \
    }                                                                         \
    extern "C" void name(T##ResizeVector* v, unsigned int n, const T* value)  \
    {                                                                         \
        unsigned int sz = v->count;                                           \
        if (sz < n)                                                           \
            growFn(v, T##_end(v), n - sz, value);                             \
        else if (n < sz) {                                                    \
            T* p = v->data;                                                   \
            eraseFn(v, p + n, p + v->count);                                  \
        }                                                                     \
    }

#endif /* VECTOR_RESIZE_H */