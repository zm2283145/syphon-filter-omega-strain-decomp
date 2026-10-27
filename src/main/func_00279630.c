#pragma cplusplus on
#include "types.h"
struct Ctl_279630 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E;
    bool Active() { return b2D && b2C && !b2E; } };
struct Item_279630 { char pad[0x58]; Ctl_279630* ctl; float t; };
struct Mgr_279630 { Item_279630** a; Item_279630** b; char pad8[8]; int na; int nb; };
static inline void Tick_279630(Item_279630* it, float dt) {
    if (*(volatile float*)&it->t >= 0.0f) {
        it->t += dt;
        if (it->t >= 2.0f) it->t = -2.0f;
    }
    { Ctl_279630* c = it->ctl; if (c && !c->Active()) it->t = -2.0f; }
}
extern "C" void cDecalMan_NextFrame(Mgr_279630* m, float dt) {
    { int i; for (i = 0; i < m->na; i++) Tick_279630(m->a[i], dt); }
    { int i; for (i = 0; i < m->nb; i++) Tick_279630(m->b[i], dt); }
}
