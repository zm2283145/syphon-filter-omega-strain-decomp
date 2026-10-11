#ifndef DIRECT_BASE_DTOR_H
#define DIRECT_BASE_DTOR_H

/*
 * Deleting destructor that only runs baseDtor(self, 0) (no inlined extra
 * null test), then deletes when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_DIRECT_BASE_DTOR(name, baseDtor)                               \
    extern "C" void* baseDtor(void* self, short deleteFlag);                  \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            baseDtor(self, 0);                                                \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* DIRECT_BASE_DTOR_H */