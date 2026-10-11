#include "types.h"
typedef struct { char c[128]; } Name_198760;
typedef struct { int a; Name_198760 name; short s84; int i88; int i8C; int i90; unsigned char b94; int i98; } S_198760;
S_198760* func_00198760(S_198760* d, S_198760* s)
{
    d->a = s->a;
    d->name = s->name;
    d->s84 = s->s84;
    d->i88 = s->i88;
    d->i8C = s->i8C;
    d->i90 = s->i90;
    d->b94 = s->b94;
    d->i98 = s->i98;
    return d;
}