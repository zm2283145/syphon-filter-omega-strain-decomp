#pragma cplusplus on

#include "types.h"
#include "short_string_assign.h"

/* Assign one string to another; returns the destination. */
extern "C" ShortStr* cString_opAssign(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
    return self;
}
