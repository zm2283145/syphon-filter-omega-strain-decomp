#include "types.h"
typedef struct { char pad[0xC]; int serial; } Tgt_40B0;
typedef struct { Tgt_40B0* t; int serial; int x8; char c; unsigned char d; unsigned char e; } S_40B0;
S_40B0* func_001640B0(S_40B0* self, Tgt_40B0* t, char c)
{
    int none;
    int* p;
    self->serial = -2;
    self->t = 0;
    self->d = 1;
    self->e = 0;
    self->c = c;
    self->t = t;
    if (t)
        p = &t->serial;
    else {
        none = -1;
        p = &none;
    }
    self->serial = *p;
    if (t)
        self->x8 = t->serial;
    return self;
}