#ifndef VTABLE3_BASE_DTOR_H
#define VTABLE3_BASE_DTOR_H

/*
 * Deleting destructor of a class three levels above a base with an
 * out-of-line destructor: restore each inlined level's vtable behind its
 * null test, then the last level calls baseDtor(self, 0); delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct Vtable3Object {
    void* vtable;
};

#define DEFINE_VTABLE3_BASE_DTOR(name, vt0, vt1, vt2, baseDtor)               \
    extern "C" {                                                              \
    extern char vt0[];                                                        \
    extern char vt1[];                                                        \
    extern char vt2[];                                                        \
    void* baseDtor(void* self, short deleteFlag);                             \
    }                                                                         \
    extern "C" Vtable3Object* name(Vtable3Object* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vt0;                                               \
            if (self) {                                                       \
                self->vtable = vt1;                                           \
                if (self) {                                                   \
                    self->vtable = vt2;                                       \
                    baseDtor(self, 0);                                        \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE3_BASE_DTOR_H */