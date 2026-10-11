#ifndef NIEVENT_V10_H
#define NIEVENT_V10_H

/*
 * Virtual method 10 shared by the cNIEvent* classes (identical bodies):
 * when the field at +0x94 is zero, call self's virtual slot 66.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_classes.h"

struct NIEventV10 {
    void* vtable;
    char pad04[0x90];
    int active;
};

#define DEFINE_NIEVENT_V10(name)                                              \
    extern "C" void name(NIEventV10* self)                                    \
    {                                                                         \
        if (!self->active)                                                    \
            ((VSlots67*)self)->slot66();                                      \
    }

#endif /* NIEVENT_V10_H */