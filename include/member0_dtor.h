#ifndef MEMBER0_DTOR_H
#define MEMBER0_DTOR_H

/*
 * Deleting destructor whose only work is destroying a member at offset 0:
 * memberDtor(self, -1), then delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_MEMBER0_DTOR(name, memberDtor)                                 \
    extern "C" void* memberDtor(void* self, short deleteFlag);                \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            memberDtor(self, -1);                                             \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

/* Same, with an extra inlined null test on self around the member call. */
#define DEFINE_NESTED_MEMBER0_DTOR(name, memberDtor)                          \
    extern "C" void* memberDtor(void* self, short deleteFlag);                \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            if (self)                                                         \
                memberDtor(self, -1);                                         \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* MEMBER0_DTOR_H */