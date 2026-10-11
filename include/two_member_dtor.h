#ifndef TWO_MEMBER_DTOR_H
#define TWO_MEMBER_DTOR_H

/*
 * Deleting destructor whose only work is destroying two members with
 * memberDtor(member, -1) (second member first), then delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_TWO_MEMBER_DTOR(name, memberDtor, offsetA, offsetB)            \
    extern "C" void memberDtor(void* member, int flags);                      \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            memberDtor((char*)self + (offsetB), -1);                          \
            memberDtor((char*)self + (offsetA), -1);                          \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* TWO_MEMBER_DTOR_H */