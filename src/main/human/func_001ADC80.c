#include "types.h"
typedef struct { void* p; int id; } H_1ADC80;
typedef struct { int pad0; unsigned char state; char pad5[0x3B]; int id; } N_1ADC80;
typedef struct { char pad[0x30]; N_1ADC80* node; H_1ADC80 h; } R_1ADC80;
static inline void Make_1ADC80(H_1ADC80* h, N_1ADC80* o)
{
    h->p = (o->id == -1) ? o : 0;
    h->id = o->id;
}
static inline unsigned char Live_1ADC80(N_1ADC80* n)
{
    unsigned char ok = 1;
    if (n->state != 0 && n->state != 1) ok = 0;
    return ok;
}
void cSkaSystem_RequestTransition_GetPlaybackGroupId(H_1ADC80* out, R_1ADC80* r)
{
    H_1ADC80 a;
    H_1ADC80 b;
    H_1ADC80* p;
    int valid = (r->h.p != 0 || r->h.id != -1);
    if (valid) {
        p = &r->h;
    } else {
        unsigned char ok = 0;
        if (r->node && Live_1ADC80(r->node)) ok = 1;
        if (ok) {
            Make_1ADC80(&a, r->node);
            p = &a;
        } else {
            b.p = 0;
            b.id = -1;
            p = &b;
        }
    }
    out->p = p->p;
    out->id = p->id;
}


