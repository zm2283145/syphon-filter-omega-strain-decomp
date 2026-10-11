#ifndef MEMBER_DTOR_CHAIN_H
#define MEMBER_DTOR_CHAIN_H

/*
 * Deleting destructor whose only work is one nested member destructor
 * memberDtor(self, 0) (three inlined null tests on self), then delete
 * when deleteFlag > 0. One clone per translation unit.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_MEMBER_DTOR_CHAIN(name, memberDtor)                            \
    extern "C" void* memberDtor(void* self, short deleteFlag);                \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self)                                                     \
                    memberDtor(self, 0);                                      \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* MEMBER_DTOR_CHAIN_H */