#pragma cplusplus on
#include "types.h"
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct V40A110 { int a, b, c; };
extern "C" V40A110* func_00207310(V40A110* dst, const V40A110* src);
struct E40A110 { V40A110 a; int b; int c; V40A110 d; V40A110 e; int f; float g; char h; };
struct S40A110 { ShortStr s; E40A110 e[5]; };
extern "C" S40A110* func_0040A110(S40A110* self, const S40A110* src)
{
    E40A110* d;
    const E40A110* s;
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
    d = self->e;
    s = src->e;
    do {
        func_00207310(&d->a, &s->a);
        d->b = s->b;
        d->c = s->c;
        func_00207310(&d->d, &s->d);
        func_00207310(&d->e, &s->e);
        d->f = s->f;
        d->g = s->g;
        d->h = s->h;
        d++;
        s++;
    } while (d != self->e + 5);
    return self;
}


