#ifndef WORD_VECTOR_ERASE_H
#define WORD_VECTOR_ERASE_H

/*
 * erase(first, last) for a vector of 4-byte elements (count at +4,
 * data at +8). Matches CodeWarrior 3.0 build 50/52 only (mw38 schedules
 * the unrolled copy differently).
 */
typedef struct WordVector {
    int capacity;
    int count;
    int* data;
} WordVector;

#define DEFINE_WORD_VECTOR_ERASE(name)                                        \
    int* name(WordVector* v, int* first, int* last)                           \
    {                                                                         \
        int* end;                                                             \
        int* s;                                                               \
        int* d;                                                               \
        if (first == last)                                                    \
            return first;                                                     \
        end = v->data + v->count;                                             \
        if (end - last != 0) {                                                \
            d = first;                                                        \
            s = last;                                                         \
            while (s < end) {                                                 \
                *d = *s;                                                      \
                s++;                                                          \
                d++;                                                          \
            }                                                                 \
        }                                                                     \
        v->count -= last - first;                                             \
        return first;                                                         \
    }

#endif /* WORD_VECTOR_ERASE_H */