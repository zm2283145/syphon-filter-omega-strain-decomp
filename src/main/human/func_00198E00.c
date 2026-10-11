#include "types.h"
typedef struct { void* p; int id; } H_198E00;
typedef struct { char pad[0x40]; int id; } N_198E00;
typedef struct { int id; int pad4; int kind; N_198E00** node; } R_198E00;
static inline void Make_198E00(H_198E00* h, N_198E00* o)
{
    h->p = (o->id == -1) ? o : 0;
    h->id = o->id;
}
void func_00198E00(H_198E00* out, R_198E00* r)
{
    H_198E00 a;
    H_198E00 b;
    H_198E00* p;
    if (r->kind == 1) {
        Make_198E00(&a, *r->node);
        p = &a;
    } else {
        b.id = r->id;
        b.p = 0;
        p = &b;
    }
    out->p = p->p;
    out->id = p->id;
}
