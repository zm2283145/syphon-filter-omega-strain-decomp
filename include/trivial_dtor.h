#ifndef TRIVIAL_DTOR_H
#define TRIVIAL_DTOR_H

/*
 * Deleting destructor of a class with no members to destroy (one clone
 * per translation unit): delete the object when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

#define DEFINE_TRIVIAL_DTOR(name)                                             \
    extern "C" void* name(void* self, short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* TRIVIAL_DTOR_H */