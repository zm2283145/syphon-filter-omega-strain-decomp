#pragma cplusplus on
#include "types.h"
#include "string_int_pair_copy_ctor.h"
struct SF6_3D1490 { ShortStr first; int second; float a, b, c, d, e, f; };
extern "C" SF6_3D1490* func_003D1490(SF6_3D1490* self, const SF6_3D1490* src)
{
    if (!ShortStr_IsLong(&src->first)) {
        self->first = src->first;
    } else {
        self->first.u.l.word = 0;
        self->first.u.l.length = 0;
        self->first.u.l.data = 0;
        String_Reserve(&self->first, src->first.u.l.length);
        ShortStrIterTag tag;
        String_Replace(&self->first, 0, 0, src->first.u.l.data,
                       src->first.u.l.data + src->first.u.l.length, tag);
    }
    self->second = src->second;
    self->a = src->a;
    self->b = src->b;
    self->c = src->c;
    self->d = src->d;
    self->e = src->e;
    self->f = src->f;
    return self;
}