#ifndef VTABLE_NESTED_MEMBER_DTOR_H
#define VTABLE_NESTED_MEMBER_DTOR_H

/*
 * Deleting destructor: set this class's vtable, destroy the member at +0x20
 * (whose own inlined destructors add two more null tests), restore the base
 * vtable, then delete when deleteFlag > 0. Plain C.
 *
 *   DEFINE_VTABLE_NESTED_MEMBER_DTOR(name, vtable, baseVtable, memberDtor)
 */
extern void operator_delete(void* p);

#define DEFINE_VTABLE_NESTED_MEMBER_DTOR(name, vtable, baseVtable, memberDtor) \
    extern char vtable[];                                                     \
    extern char baseVtable[];                                                 \
    extern void memberDtor(void* self, short del);                            \
    typedef struct { void* vt; char pad[0x1C]; char m20[4]; } name##_T;       \
    name##_T* name(name##_T* self, short del)                                 \
    {                                                                         \
        if (self) {                                                           \
            void* m;                                                          \
            self->vt = vtable;                                                \
            m = self->m20;                                                    \
            if (m) {                                                          \
                if (m) {                                                      \
                    if (m)                                                    \
                        memberDtor(m, 0);                                     \
                }                                                             \
            }                                                                 \
            if (self)                                                         \
                self->vt = baseVtable;                                        \
            if (del > 0)                                                      \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE_NESTED_MEMBER_DTOR_H */