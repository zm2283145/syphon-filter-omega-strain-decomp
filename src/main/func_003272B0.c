#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x10]; int n; char pad14[8]; int sel; } G_3272B0;
typedef struct { char pad[0x4C]; int count; G_3272B0* groups; int pad54; int cur; } S_3272B0;
extern "C" void func_00327890(S_3272B0* o, int dir);

static inline G_3272B0* At_3272B0(G_3272B0** gp, int i) { return &(*gp)[i]; }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
extern "C" bool func_003272B0(S_3272B0* o, int dir)
{
    unsigned char any = 0;
    int i;
    bool f;
    int oldSel;
    int oldCur;
    G_3272B0** gp;
    G_3272B0* g;
    for (i = 0; (unsigned char)any == 0 && i < o->count; i++) {
        if (o->groups[i].n) any = 1;
    }
    if (!any) return 0;
    if (o->cur < 0 || o->cur >= o->count) o->cur = 0;
    oldCur = o->cur;
    g = o->groups;
    g += oldCur;
    oldSel = g->sel;
    gp = &o->groups;
    if (oldSel < 0 || oldSel >= g->n) g->sel = 0;
    if (dir) {
        At_3272B0(gp, o->cur)->sel++;
        if (At_3272B0(gp, o->cur)->sel >= At_3272B0(gp, o->cur)->n) {
            f = 0;
            do {
                o->cur++;
                if (o->cur == o->count) o->cur = 0;
                if (o->groups[o->cur].n) f = 1;
            } while (!f);
            At_3272B0(gp, o->cur)->sel = 0;
        }
    } else {
        At_3272B0(gp, o->cur)->sel--;
        if (At_3272B0(gp, o->cur)->sel < 0) {
            f = 0;
            do {
                o->cur--;
                if (o->cur < 0) o->cur = o->count - 1;
                if (o->groups[o->cur].n) f = 1;
            } while (!f);
            At_3272B0(gp, o->cur)->sel = At_3272B0(gp, o->cur)->n - 1;
        }
    }
    func_00327890(o, dir);
    {
        bool r = 1;
        if (oldCur == o->cur && oldSel == At_3272B0(gp, o->cur)->sel) r = 0;
        return r;
    }
}
#pragma pop