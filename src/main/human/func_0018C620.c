#include "types.h"
typedef struct { void* p; int id; } H_18C620;
typedef struct { int pad0; unsigned char state; char pad5[0x3B]; int id; } O_18C620;
static inline void Make_18C620(H_18C620* h, O_18C620* o)
{
    int* id = &o->id;
    h->p = (*id == -1) ? o : 0;
    h->id = *id;
}
void nSka_GetPlaybackGroupId(H_18C620* out, O_18C620* o)
{
    H_18C620 a;
    H_18C620 b;
    H_18C620* r;
    unsigned char ok = 1;
    if (o->state != 0 && o->state != 1) ok = 0;
    if (ok) {
        Make_18C620(&a, o);
        r = &a;
    } else {
        b.p = 0;
        b.id = -1;
        r = &b;
    }
    out->p = r->p;
    out->id = r->id;
}
