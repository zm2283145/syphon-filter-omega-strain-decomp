#ifndef KEYED_COPY_H
#define KEYED_COPY_H

/*
 * Element = word vector (count at +4, data at +8) + one byte flag at +0xC,
 * 16 bytes. DEFINE_WORDVEC_ASSIGN: operator= through
 * assignRangeFn(self, first, last, tag). DEFINE_FLAGGED_COPY(_BACKWARD):
 * copy / copy_backward of the element through the vector assign plus the
 * flag byte. C++ only (#pragma cplusplus on before including).
 */
struct KcTag {};

struct KcWordVec {
    int capacity;
    int count;
    int* data;
};

struct KcFlagged {
    KcWordVec vec;
    unsigned char flag;
};

#define DEFINE_WORDVEC_ASSIGN(name, assignRangeFn)                            \
    extern "C" void assignRangeFn(KcWordVec* self, int* first, int* last,     \
                                  KcTag tag);                                 \
    extern "C" KcWordVec* name(KcWordVec* self, const KcWordVec* other)       \
    {                                                                         \
        if (self != other) {                                                  \
            KcTag tag;                                                        \
            assignRangeFn(self, other->data, other->data + other->count, tag); \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_FLAGGED_COPY(name, assignFn)                                   \
    extern "C" KcWordVec* assignFn(KcWordVec* self, const KcWordVec* other);  \
    extern "C" KcFlagged* name(KcFlagged* first, KcFlagged* last,             \
                               KcFlagged* dest)                               \
    {                                                                         \
        while (first < last) {                                                \
            assignFn(&dest->vec, &first->vec);                                \
            dest->flag = first->flag;                                         \
            ++first;                                                          \
            ++dest;                                                           \
        }                                                                     \
        return dest;                                                          \
    }

#define DEFINE_FLAGGED_COPY_BACKWARD(name, assignFn)                          \
    extern "C" KcWordVec* assignFn(KcWordVec* self, const KcWordVec* other);  \
    extern "C" KcFlagged* name(KcFlagged* first, KcFlagged* last,             \
                               KcFlagged* dest)                               \
    {                                                                         \
        while (first < last) {                                                \
            --last;                                                           \
            --dest;                                                           \
            assignFn(&dest->vec, &last->vec);                                 \
            dest->flag = last->flag;                                          \
        }                                                                     \
        return dest;                                                          \
    }

#endif /* KEYED_COPY_H */