#ifndef BASE_DTOR_CHAIN_H
#define BASE_DTOR_CHAIN_H

/*
 * Deleting destructor whose only work is the (non-deleting) destructor of
 * its base/first member: call baseDtor(self, 0), then delete the object
 * when deleteFlag > 0. One clone per translation unit.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_BASE_DTOR_CHAIN(name, baseDtor)                                \
    extern "C" void* baseDtor(void* self, short deleteFlag);                  \
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

#endif /* BASE_DTOR_CHAIN_H */