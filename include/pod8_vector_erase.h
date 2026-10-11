#ifndef POD8_VECTOR_ERASE_H
#define POD8_VECTOR_ERASE_H

/*
 * erase(first, last) for a vector of 8-byte two-word elements
 * (count at +4, data at +8): shift the tail down, shrink the count.
 * Identical template clones, one per translation unit.
 */
typedef struct Pod8 {
    int a;
    int b;
} Pod8;

typedef struct Pod8Vector {
    int capacity;
    int count;
    Pod8* data;
} Pod8Vector;

#define DEFINE_POD8_VECTOR_ERASE(name)                                        \
    Pod8* name(Pod8Vector* v, Pod8* first, Pod8* last)                        \
    {                                                                         \
        Pod8* end;                                                            \
        Pod8* s;                                                              \
        Pod8* d;                                                              \
        if (first == last)                                                    \
            return first;                                                     \
        end = v->data + v->count;                                             \
        if (end - last != 0) {                                                \
            d = first;                                                        \
            s = last;                                                         \
            while (s < end) {                                                 \
                d->a = s->a;                                                  \
                d->b = s->b;                                                  \
                s++;                                                          \
                d++;                                                          \
            }                                                                 \
        }                                                                     \
        v->count -= last - first;                                             \
        return first;                                                         \
    }

#endif /* POD8_VECTOR_ERASE_H */