#pragma cplusplus on
#include "types.h"
/* TargetVis_Register: add an actor to the visibility registry (30 slots + handle list) */
struct Pt1TvActor { char pad0[0xC]; int serial; };
struct Pt1TvHandle { Pt1TvActor* target; int serial; };
struct Pt1TvIt { void* p; };
struct Pt1TvReg {
    char pad0[0x98];
    Pt1TvActor* slots[30];
    char pad110[0x11C - 0x110];
    char list[4];
    char sentinel[4];
};
extern "C" void func_00222980(Pt1TvIt* out, void* list, Pt1TvIt* pos, Pt1TvHandle* h);
extern "C" int TargetVis_Register(Pt1TvReg* r, Pt1TvActor* a)
{
    for (int i = 0; i < 30; i++)
        if (r->slots[i] == a)
            return 0;
    for (int i = 0; i < 30; i++) {
        if (!r->slots[i]) {
            Pt1TvIt res;
            Pt1TvIt pos;
            int none;
            Pt1TvHandle h;
            r->slots[i] = a;
            h.serial = -1;
            h.target = a;
            h.serial = *(a ? &a->serial : (none = -1, &none));
            pos.p = r->sentinel;
            func_00222980(&res, r->list, &pos, &h);
            return 1;
        }
    }
    return 0;
}