#ifndef GATED_VCALL_H
#define GATED_VCALL_H

/*
 * Call one virtual method on self unless the byte at +0x2D is set.
 *   DEFINE_GATED_VCALL(name, Cls, pads)
 * pads is the VPADn() list in front of the called slot (vslot_pad.h).
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_pad.h"

#define DEFINE_GATED_VCALL(name, Cls, pads)                                   \
    class Cls {                                                               \
    public:                                                                   \
        pads                                                                  \
        virtual void Call();                                                  \
        char pad4[0x29];                                                      \
        unsigned char b2D;                                                    \
    };                                                                        \
    extern "C" void name(Cls* self)                                           \
    {                                                                         \
        if (!self->b2D)                                                       \
            self->Call();                                                     \
    }

#endif /* GATED_VCALL_H */