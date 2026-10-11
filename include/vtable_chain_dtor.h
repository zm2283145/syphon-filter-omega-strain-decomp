#ifndef VTABLE_CHAIN_DTOR_H
#define VTABLE_CHAIN_DTOR_H

/*
 * Deleting destructors of classes whose whole destructor chain is inlined
 * and only restores vtables: store each class vtable from most derived to
 * the root (each nested base step repeats the null test on self), then
 * delete when deleteFlag > 0. CHAIN1/2/3 = number of vtable stores.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct VtableChainObject {
    void* vtable;
};

#define DEFINE_VTABLE_CHAIN_DTOR1(name, vt0)                                  \
    extern "C" char vt0[];                                                    \
    extern "C" VtableChainObject* name(VtableChainObject* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vt0;                                               \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_VTABLE_CHAIN_DTOR2(name, vt0, vt1)                             \
    extern "C" char vt0[];                                                    \
    extern "C" char vt1[];                                                    \
    extern "C" VtableChainObject* name(VtableChainObject* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vt0;                                               \
            if (self)                                                         \
                self->vtable = vt1;                                           \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_VTABLE_CHAIN_DTOR3(name, vt0, vt1, vt2)                        \
    extern "C" char vt0[];                                                    \
    extern "C" char vt1[];                                                    \
    extern "C" char vt2[];                                                    \
    extern "C" VtableChainObject* name(VtableChainObject* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vt0;                                               \
            if (self) {                                                       \
                self->vtable = vt1;                                           \
                if (self)                                                     \
                    self->vtable = vt2;                                       \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE_CHAIN_DTOR_H */