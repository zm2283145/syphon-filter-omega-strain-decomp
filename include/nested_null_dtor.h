#ifndef NESTED_NULL_DTOR_H
#define NESTED_NULL_DTOR_H

/*
 * Deleting destructor whose base destructor is inlined behind repeated
 * null checks (one per inlined class level), calling baseDtor(self, 0),
 * then delete when deleteFlag > 0. C++ only (#pragma cplusplus on).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_NESTED_NULL_DTOR2(name, baseDtor)                              \
    extern "C" void baseDtor(void* self, short deleteFlag);                   \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            if (self)                                                         \
                baseDtor(self, 0);                                            \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_NESTED_NULL_DTOR3(name, baseDtor)                              \
    extern "C" void baseDtor(void* self, short deleteFlag);                   \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self)                                                     \
                    baseDtor(self, 0);                                        \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* NESTED_NULL_DTOR_H */