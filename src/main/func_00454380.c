#include "types.h"
typedef struct { char p[0x14]; unsigned short flags; } C454380;
typedef struct { char p[0x88]; C454380* c; char p8C[8]; int f94; } S454380;
typedef struct { char p[0x14]; unsigned short flags; char p16[0x32]; S454380* s; } W454380;
typedef struct { int p0; int f4; } G454380;
extern G454380* D_004FFC2C;
extern void func_0041E3B0(W454380* w);
extern void func_00454280(W454380* w);
void func_00454380(W454380* w)
{
    C454380* c;
    func_0041E3B0(w);
    {
        G454380* g;
S454380* s;
        if ((g = D_004FFC2C) && (s = w->s) && g->f4 != s->f94) func_00454280(w);
    }
    if (w->s && (c = w->s->c)) {
        int on = w->s->f94 != 0 && (w->flags & 4) != 0; if (on) c->flags |= 2; else c->flags &= ~2;
    }
}
