#ifndef VTABLE2_BASE_DTOR_H
#define VTABLE2_BASE_DTOR_H

/*
 * Deleting destructors of a class two levels below a base with an
 * out-of-line destructor: restore the class vtable, (optionally destroy a
 * nested member at memberOffset with memberDtor(member, 0), three inlined
 * null tests), then the inlined middle destructor restores baseVtable and
 * calls baseDtor(self, 0); delete when deleteFlag > 0.
 *   DEFINE_VTABLE2_BASE_DTOR(name, vtableSym, baseVtableSym, baseDtor)
 *   DEFINE_VTABLE2_MEMBER_DTOR(name, vtableSym, memberOffset, memberDtor,
 *                              baseVtableSym, baseDtor)
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct Vtable2Object {
    void* vtable;
};

#define DEFINE_VTABLE2_BASE_DTOR(name, vtableSym, baseVtableSym, baseDtor)    \
    extern "C" {                                                              \
    extern char vtableSym[];                                                  \
    extern char baseVtableSym[];                                              \
    void* baseDtor(void* self, short deleteFlag);                             \
    }                                                                         \
    extern "C" Vtable2Object* name(Vtable2Object* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            if (self) {                                                       \
                self->vtable = baseVtableSym;                                 \
                baseDtor(self, 0);                                            \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_VTABLE2_MEMBER_DTOR(name, vtableSym, memberOffset, memberDtor, \
                                   baseVtableSym, baseDtor)                   \
    extern "C" {                                                              \
    extern char vtableSym[];                                                  \
    extern char baseVtableSym[];                                              \
    void* memberDtor(void* self, short deleteFlag);                           \
    void* baseDtor(void* self, short deleteFlag);                             \
    }                                                                         \
    extern "C" Vtable2Object* name(Vtable2Object* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            char* member = (char*)self + (memberOffset);                      \
            if (member) {                                                     \
                if (member) {                                                 \
                    if (member)                                               \
                        memberDtor(member, 0);                                \
                }                                                             \
            }                                                                 \
            if (self) {                                                       \
                self->vtable = baseVtableSym;                                 \
                baseDtor(self, 0);                                            \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE2_BASE_DTOR_H */