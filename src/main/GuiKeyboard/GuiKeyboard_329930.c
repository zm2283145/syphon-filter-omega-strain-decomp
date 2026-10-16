#pragma cplusplus on

#include "types.h"
#include "short_string_assign.h"

/* Assign one string to another; returns the destination. */
extern "C" ShortStr* func_00329930(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
    return self;
}
