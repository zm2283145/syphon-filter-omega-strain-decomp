#ifndef GOBJ_V06_UPDATE_H
#define GOBJ_V06_UPDATE_H

/*
 * Virtual method 6 shared by several GOBJ classes (identical bodies):
 * notify the attached object at +0x64 (its slot 21 with 1), run
 * cGOBJ_NetActivate on self, then call self's virtual slot 47.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_classes.h"

struct GobjV06 {
    void* vtable;
    char pad04[0x60];
    VSlotsInt22* attached;
};

extern "C" void cGOBJ_NetActivate(GobjV06* self);

#define DEFINE_GOBJ_V06_UPDATE(name)                                          \
    extern "C" void name(GobjV06* self)                                       \
    {                                                                         \
        VSlotsInt22* a = self->attached;                                      \
        if (a)                                                                \
            a->slot21(1);                                                     \
        cGOBJ_NetActivate(self);                                                  \
        ((VSlots67*)self)->slot47();                                          \
    }

#endif /* GOBJ_V06_UPDATE_H */