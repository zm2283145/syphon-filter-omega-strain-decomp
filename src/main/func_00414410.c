#pragma cplusplus on
#include "types.h"
#include "short_string_assign.h"

static inline void Assign414410(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" void func_00414410(ShortStr* first, unsigned int n, const ShortStr* value)
{
    for (; n != 0; --n, ++first) {
        Assign414410(first, value);
    }
}
