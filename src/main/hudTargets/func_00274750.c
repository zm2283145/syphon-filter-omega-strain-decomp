#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int, int, char*, int);
int IeElement_Create(int);
void HudTracker_Construct(void*, int, void*);
void IeElement_SetColour(int, void*);
extern char D_004A8F40[];
extern char D_004A8F50[];
extern char D_004A8F60[];
extern char D_004DC810[];
extern char D_004E0360[];
extern int D_004FFD50;
extern int D_004FFD58;
extern int D_004FFD60;
extern int D_004FFD68;
extern int D_004FFD70;
extern int D_004FFD78;
extern char g_IdentityMatrix[];
}

#define S4(n) virtual void s##n##a(); virtual void s##n##b(); virtual void s##n##c(); virtual void s##n##d();
struct Icon274750 {
    S4(0) S4(1) S4(2) S4(3) S4(4) S4(5) S4(6) S4(7)
    virtual void s32(); virtual void s33();
    virtual void SetProp(void*, int);
};

struct Marker274750 {
    int pad0;
    Icon274750* icon;
    void* label;
    signed char big;
    int type;
};

extern "C" void ObjMarker_ConstructIcon(Marker274750* m, signed char big)
{
    int s1;
    void* o;
    int id;
    unsigned char f;

    m->big = big;
    f = 1;
    if (!(m->type == 1 || m->type == 2))
        f = 0;
    id = f ? D_004FFD78 : (big ? D_004FFD68 : D_004FFD70);
    s1 = IeElement_Create(id);
    {
        AllocGuard g;
        o = Mem_Alloc(0, 0x90, D_004A8F60, 0xE9);
    }
    if (o) {
        HudTracker_Construct(o, s1, m);
        *(char**)o = D_004E0360;
    }
    m->label = o;
    IeElement_SetColour(s1, big ? D_004A8F50 : D_004A8F40);
    f = 1;
    if (!(m->type == 1 || m->type == 2))
        f = 0;
    id = f ? D_004FFD60 : (big ? D_004FFD50 : D_004FFD58);
    {
        AllocGuard g;
        o = Mem_Alloc(0, 0x90, D_004A8F60, 0xF3);
    }
    if (o) {
        HudTracker_Construct(o, IeElement_Create(id), m);
        *(char**)o = D_004DC810;
    }
    m->icon = (Icon274750*)o;
    m->icon->SetProp(g_IdentityMatrix, 0);
}


