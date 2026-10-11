#ifndef GOBJ_FLAG_SLOT16_H
#define GOBJ_FLAG_SLOT16_H

/*
 * GOBJ method shared by several classes: unless flags +0x2D and +0x2C are
 * set and +0x2E is clear, call self's virtual slot 16.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_classes.h"

struct GobjFlags {
    void* vtable;
    char pad04[0x28];
    unsigned char flag2C;
    unsigned char flag2D;
    unsigned char flag2E;
};

#define DEFINE_GOBJ_FLAG_SLOT16(name)                                         \
    extern "C" void name(GobjFlags* self)                                     \
    {                                                                         \
        bool on = self->flag2D && self->flag2C && !self->flag2E;              \
        if (!on)                                                              \
            ((VSlots67*)self)->slot16();                                      \
    }

#endif /* GOBJ_FLAG_SLOT16_H */