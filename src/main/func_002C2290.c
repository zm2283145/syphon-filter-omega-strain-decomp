#include "types.h"
typedef struct { char p0[0x40A]; short h40A; } O2C2290;
typedef struct { char p0[0x2470]; O2C2290* arr[1]; } P2C2290;
typedef struct { char p0[0x4C]; P2C2290* p4C; char p50[0x34]; int f84; int f88; char p8C[0x44]; int fD0; char pD4[0x28]; int fFC; } G2C2290;
typedef struct { char p0[0xF0]; unsigned char kind; char pF1[0x2B]; O2C2290* alt; } W2C2290;
extern G2C2290* D_0051EE10;
extern void* D_004FFD30;
extern W2C2290* WeaponDb_Get(void* db, int id);
extern void func_002BF4B0(G2C2290* g, O2C2290* o, int v);
/* Applies the current (or alternate-mode) weapon of the active slot. */
void func_002C2290(void)
{
    G2C2290* g = D_0051EE10;
    if (g->f84) {
        O2C2290* o;
        if (g->f88 != g->fFC) o = g->p4C->arr[g->f88];
        else o = g->p4C->arr[0];
        if (o && g->fD0) {
            W2C2290* w = WeaponDb_Get(D_004FFD30, o->h40A);
            if (w->kind == 7) o = w->alt;
            if (o) func_002BF4B0(D_0051EE10, o, D_0051EE10->fD0);
        }
    }
}
