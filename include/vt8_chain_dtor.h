#ifndef VT8_CHAIN_DTOR_H
#define VT8_CHAIN_DTOR_H

/*
 * Deleting destructor of a class whose vtable pointer sits at +8 (after
 * two words of a non-polymorphic base) and whose base has nothing to
 * destroy: restore the class vtable, then the base vtable, then delete
 * when deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct Vt8Object {
    int words[2];
    void* vtable;
};

#define DEFINE_VT8_CHAIN_DTOR(name, vtableSym, baseVtableSym)                 \
    extern "C" {                                                              \
    extern char vtableSym[];                                                  \
    extern char baseVtableSym[];                                              \
    }                                                                         \
    extern "C" Vt8Object* name(Vt8Object* self, short deleteFlag)             \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            if (self)                                                         \
                self->vtable = baseVtableSym;                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VT8_CHAIN_DTOR_H */