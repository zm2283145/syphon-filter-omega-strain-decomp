#pragma cplusplus on
#include "types.h"
#include "short_string_assign.h"
struct E409EC0 { ShortStr a; int b; int c; ShortStr d; ShortStr e; int f; float g; char h; };
static inline void Assign409EC0(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}
extern "C" E409EC0* func_00409EC0(E409EC0* self, const E409EC0* src)
{
    Assign409EC0(&self->a, &src->a);
    self->b = src->b;
    self->c = src->c;
    Assign409EC0(&self->d, &src->d);
    Assign409EC0(&self->e, &src->e);
    self->f = src->f;
    self->g = src->g;
    self->h = src->h;
    return self;
}
