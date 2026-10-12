#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Blast_DamageCall: deliver blast damage to the target through its damage vcall */
struct Pt1BdTarget {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void TakeDamage(float amount, Pt1BdTarget* source, int kind, int type, int a, int b, void* pos);
    char pad[0x8];
    int serial;
};
struct Pt1BdHandle { Pt1BdTarget* target; int serial; };
static inline Pt1BdTarget* Pt1Bd_Get(Pt1BdHandle* h)
{
    Pt1BdTarget* t = h->target;
    bool ok = !t || t->serial == h->serial;
    return ok ? t : 0;
}
static inline Pt1BdTarget* Pt1Bd_Get2(Pt1BdHandle* h)
{
    Pt1BdTarget* t = h->target;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != h->serial)
            ok = false;
    return ok ? t : 0;
}
struct Pt1BdEvent {
    char pad0[0xC];
    Pt1BdHandle target;
    int damage;
    Pt1BdHandle source;
    signed char type;
    char pad21[0xF];
    char pos[0x10];
};
extern "C" void Blast_DamageCall(Pt1BdEvent* e)
{
    if (Pt1Bd_Get(&e->target)) {
        Pt1BdTarget* src = Pt1Bd_Get2(&e->source);
        Pt1Bd_Get(&e->target)->TakeDamage((float)e->damage, src, 1, e->type, 0, 0, e->pos);
    }
}
