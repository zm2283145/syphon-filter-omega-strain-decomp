#pragma cplusplus on
#include "types.h"
#include "short_string_assign.h"

static inline void Assign4144D0(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" ShortStr* func_004144D0(ShortStr* first, ShortStr* last, ShortStr* result)
{
    while (first < last) {
        Assign4144D0(--result, --last);
    }
    return result;
}

