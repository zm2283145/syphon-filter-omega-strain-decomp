#ifndef NIEVENT_TARGET_QUERY_H
#define NIEVENT_TARGET_QUERY_H

/*
 * cNIEventOBJ virtual queries forwarded to the target object at +0x140:
 * return 0 unless the event is enabled (+0xDC), has a target, flags +0x2D
 * and +0x2C are set and +0x2E is clear; otherwise return the target's
 * virtual slot `slot` (vtable offset 8 + 4*slot) result.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_pad.h"

class NIQueryTarget {
public:
    VPAD32(a) VPAD8(b) VPAD4(c)
    virtual int slot44();
};

class NIQueryTarget32 {
public:
    VPAD32(a)
    virtual int slot32();
};

#define DEFINE_NIEVENT_TARGET_QUERY(name, Cls, method)                        \
    struct name##_Obj {                                                       \
        char pad00[0x2C];                                                     \
        unsigned char ready;                                                  \
        unsigned char armed;                                                  \
        unsigned char blocked;                                                \
        char pad2F[0xDC - 0x2F];                                              \
        unsigned char enabled;                                                \
        char padDD[0x140 - 0xDD];                                             \
        Cls* target;                                                          \
    };                                                                        \
    extern "C" int name(name##_Obj* self)                                     \
    {                                                                         \
        Cls* t;                                                               \
        if (!self->enabled)                                                   \
            return 0;                                                         \
        t = self->target;                                                     \
        if (!t || !self->armed || !self->ready || self->blocked)              \
            return 0;                                                         \
        return t->method();                                                   \
    }

#endif /* NIEVENT_TARGET_QUERY_H */