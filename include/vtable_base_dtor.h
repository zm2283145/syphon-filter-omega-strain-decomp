#ifndef VTABLE_BASE_DTOR_H
#define VTABLE_BASE_DTOR_H

/*
 * Deleting destructor of a derived class with nothing of its own to
 * destroy: restore the class vtable, run the base destructor
 * baseDtor(self, 0), then delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct VtableObject {
    void* vtable;
};

#define DEFINE_VTABLE_BASE_DTOR(name, vtableSym, baseDtor)                    \
    extern "C" {                                                              \
    extern char vtableSym[];                                                  \
    void* baseDtor(void* self, short deleteFlag);                             \
    }                                                                         \
    extern "C" VtableObject* name(VtableObject* self, short deleteFlag)       \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            baseDtor(self, 0);                                                \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE_BASE_DTOR_H */