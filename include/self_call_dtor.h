#ifndef SELF_CALL_DTOR_H
#define SELF_CALL_DTOR_H

/*
 * Deleting destructor whose body is one out-of-line cleanup call
 * cleanupFn(self) (no destructor flag), then delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_SELF_CALL_DTOR(name, cleanupFn)                                \
    extern "C" void cleanupFn(void* self);                                    \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            cleanupFn(self);                                                  \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* SELF_CALL_DTOR_H */