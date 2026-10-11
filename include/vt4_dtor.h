#ifndef VT4_DTOR_H
#define VT4_DTOR_H
/*
 * Deleting destructors of classes whose vtable pointer sits at offset 4
 * (after a leading data member) and that have nothing else to destroy:
 *   DEFINE_VT4_DTOR(name, vtableSym)                  one level
 *   DEFINE_VT4_DTOR2(name, vtableSym, baseVtableSym)  derived + inlined base
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);
struct Vt4Object { int head; void* vtable; };
#define DEFINE_VT4_DTOR(name, vtableSym)                                      \
    extern "C" { extern char vtableSym[]; }                                   \
    extern "C" Vt4Object* name(Vt4Object* self, short deleteFlag) {           \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            if (deleteFlag > 0) operator_delete(self);                        \
        }                                                                     \
        return self;                                                          \
    }
#define DEFINE_VT4_DTOR2(name, vtableSym, baseVtableSym)                      \
    extern "C" { extern char vtableSym[]; extern char baseVtableSym[]; }      \
    extern "C" Vt4Object* name(Vt4Object* self, short deleteFlag) {           \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            if (self) self->vtable = baseVtableSym;                           \
            if (deleteFlag > 0) operator_delete(self);                        \
        }                                                                     \
        return self;                                                          \
    }
#endif