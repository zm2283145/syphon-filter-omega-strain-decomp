#pragma cplusplus on
#include "types.h"
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct E_32A730 { ShortStr name; int val; ShortStr desc; unsigned char flag; int a, b, c; };
static inline void StrCopy_32A730(ShortStr* self, const ShortStr* src)
{
    if (!ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        self->u.l.word = 0;
        self->u.l.length = 0;
        self->u.l.data = 0;
        String_Reserve(self, src->u.l.length);
        ShortStrIterTag tag;
        String_Replace(self, 0, 0, src->u.l.data, src->u.l.data + src->u.l.length, tag);
    }
}
static inline void StrCopy2_32A730(ShortStr* self, const ShortStr* src)
{
    if (!ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        self->u.l.word = 0;
        self->u.l.length = 0;
        self->u.l.data = 0;
        const unsigned int& len = src->u.l.length;
        String_Reserve(self, len);
        ShortStrIterTag tag;
        String_Replace(self, 0, 0, src->u.l.data, src->u.l.data + len, tag);
    }
}
extern "C" E_32A730* func_0032A730(E_32A730* self, const E_32A730* src)
{
    StrCopy_32A730(&self->name, &src->name);
    self->val = src->val;
    { ShortStr* d = &self->desc; StrCopy2_32A730(d, &src->desc); }
    self->flag = src->flag;
    self->a = src->a;
    self->b = src->b;
    self->c = src->c;
    return self;
}

