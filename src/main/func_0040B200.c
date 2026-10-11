#pragma cplusplus on
#include "types.h"
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct SB40B200 { ShortStr s; unsigned char c; };
extern "C" SB40B200* func_0040B200(SB40B200* self, const SB40B200* src)
{
    if (!ShortStr_IsLong(&src->s)) {
        self->s = src->s;
    } else {
        self->s.u.l.word = 0;
        self->s.u.l.length = 0;
        self->s.u.l.data = 0;
        String_Reserve(&self->s, src->s.u.l.length);
        ShortStrIterTag tag;
        String_Replace(&self->s, 0, 0, src->s.u.l.data, src->s.u.l.data + src->s.u.l.length, tag);
    }
    self->c = src->c;
    return self;
}