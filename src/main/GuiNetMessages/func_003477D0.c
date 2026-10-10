#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } Widget;
typedef struct { char pad[0x8C]; Widget* a; Widget* b; Widget* c; char pad2[0xC]; Widget* d; } Screen;
extern void func_0033D3A0(Screen* s);
/* Hides three widgets, shows the fourth, then refreshes. */
#pragma opt_common_subs off
void func_003477D0(Screen* s)
{
    s->a->flags &= ~2;
    s->b->flags &= ~2;
    s->c->flags &= ~2;
    s->d->flags |= 2;
    func_0033D3A0(s);
}
#pragma opt_common_subs reset
