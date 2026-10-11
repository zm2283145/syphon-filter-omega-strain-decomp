#ifndef GOBJ_FLAG_DTOR_H
#define GOBJ_FLAG_DTOR_H

/*
 * Deleting destructors of GOBJ-derived classes whose inlined middle
 * destructor (vtable baseVtableSym) calls virtual slot 22 (offset 0x60)
 * with 1 when flags +0x2D and +0x2C are set and +0x2E is clear, then runs
 * cGOBJ_dtor(self, 0); delete when deleteFlag > 0.
 *   DEFINE_GOBJ_FLAG_DTOR(name, baseVtableSym)            middle class itself
 *   DEFINE_GOBJ_FLAG_DTOR2(name, vtableSym, baseVtableSym) one level below
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
void cGOBJ_dtor(void* self, int flags);
void operator_delete(void* allocation);
}

#include "vslot_pad.h"

class GobjFlagSlots {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void slot22(int arg);
};

struct GobjFlagObj {
    void* vtable;
    char pad04[0x28];
    unsigned char flag2C;
    unsigned char flag2D;
    unsigned char flag2E;
};

static inline void GobjFlag_Release(GobjFlagObj* self)
{
    bool on = self->flag2D && self->flag2C && !self->flag2E;
    if (on)
        ((GobjFlagSlots*)self)->slot22(1);
    cGOBJ_dtor(self, 0);
}

#define DEFINE_GOBJ_FLAG_DTOR(name, baseVtableSym)                            \
    extern "C" char baseVtableSym[];                                          \
    extern "C" GobjFlagObj* name(GobjFlagObj* self, short deleteFlag)         \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = baseVtableSym;       \
            GobjFlag_Release(self);                                           \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_GOBJ_FLAG_DTOR2(name, vtableSym, baseVtableSym)                \
    extern "C" char vtableSym[];                                              \
    extern "C" char baseVtableSym[];                                          \
    extern "C" GobjFlagObj* name(GobjFlagObj* self, short deleteFlag)         \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;           \
            if (self) {                                                       \
                self->vtable = baseVtableSym;   \
                GobjFlag_Release(self);                                       \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* GOBJ_FLAG_DTOR_H */