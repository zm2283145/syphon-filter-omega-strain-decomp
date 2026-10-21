#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#pragma inline_depth(10)

union It { char* p; float f; };
struct L { int sz; char* s0; char* first; };
struct Mgr { L obs; L recs; L l18; L l24; float range; int p34; int p38; char* sel; };

class OObj { public: int x; virtual void Update(int a); };

extern "C" {
int Mem_Free(...);
int String_Dtor(...);
int func_002731A0(...);
int func_002731B0(...);
int func_002731C0(...);
int func_002731D0(...);
int func_002731E0(...);
int List_Begin(...);
int func_00273EF0(...);
int func_00273EE0(...);
int func_0015AF40(...);
int List_Erase(...);
int HudRadar_SetMeter(float, char*, int);
int HudTracker_Kill(...);
int Player_ClearRecentTargets(...);
int ObjectList_EraseRange(...);
int HudTargets_RemoveMarker(float, char*, char*, char*, float*);
extern unsigned char D_0048B308;
extern char D_004A8F60;
extern char* g_Hud;
void HudTargets_Update(Mgr* mgr, int arg);
}

static inline void beg0(It* o, char* l) { It r; List_Begin(&r, l); func_00273EF0(o, &r); }
static inline void end0(It* o, char* l) { It r; func_002731D0(&r, l); func_002731E0(o, &r); }
static inline void beg2(It* o, char* l) { It r; List_Begin(&r, l); func_002731C0(o, &r); }
static inline void end1(It* o, char* l) { It r; func_002731B0(&r, l); func_002731A0(o, &r); }
static inline void clr18(char* a) { int r; char* f; char* l; l = a + 0x1C; f = F_(a, 0x20, char*); Player_ClearRecentTargets(&r, a + 0x18, &f, &l); }
static inline void clr24(char* a) { int r; char* f; char* l; l = a + 0x28; f = F_(a, 0x2C, char*); ObjectList_EraseRange(&r, a + 0x24, &f, &l); }
static inline void er2(char* l, It* a, It* o) { It c; It b; func_00273EE0(&b, a); List_Erase(&c, l, &b); func_00273EF0(o, &c); }
static inline void er(char* l, It* it, It* out) { It o; It a; func_0015AF40(&a, it); er2(l, &a, &o); out->p = o.p; }
static inline void Beg0(It* o, char* l) { beg0(o, l); }
static inline void End0(It* o, char* l) { end0(o, l); }
static inline void Beg2(It* o, char* l) { beg2(o, l); }
static inline void End1(It* o, char* l) { end1(o, l); }

void HudTargets_Update(Mgr* mgr, int arg)
{
    It it;
    float dist;
    It t;
    It e;
    It e2;
    It e3;
    It b1;
    clr18((char*)mgr);
    clr24((char*)mgr);
    Beg0(&b1, (char*)&mgr->recs);
    dist = 0.0f;
    it.p = b1.p;
    while ((End0(&e, (char*)&mgr->recs), it.p != e.p)) {
        char* rec = F_(it.p, 8, char*);
        if (HudTargets_RemoveMarker(mgr->range, rec, (char*)&mgr->l24, (char*)&mgr->l18, &dist) == 0) {
            if (rec == mgr->sel) mgr->sel = 0;
            {
                AllocGuard g;
                if (rec != NULL) {
                    if (D_0048B308 != 0) {
                        HudTracker_Kill(F_(rec, 8, int));
                        HudTracker_Kill(F_(rec, 4, int));
                    }
                    char* s;
                    s = rec + 0x28;
                    if (s != NULL) String_Dtor(s, 0);
                    s = rec + 0x1C;
                    if (s != NULL) String_Dtor(s, 0);
                }
                Mem_Free(0, rec, &D_004A8F60, 0x193);
            }
            {
                It r;
                er((char*)&mgr->recs, &it, &r);
                t.p = r.p;
                it = t;
            }
        } else {
            it.p = F_(it.p, 4, char*);
        }
    }
    if (mgr->sel != 0) {
        bool found = false;
        It b2;
        Beg0(&b2, (char*)&mgr->l24);
        char* n = b2.p;
        for (; (End0(&e2, (char*)&mgr->l24), n != e2.p); n = F_(n, 4, char*)) {
            if (F_(n, 8, char*) == mgr->sel) { found = true; break; }
        }
        if (!found) mgr->sel = 0;
    }
    HudRadar_SetMeter(dist, g_Hud + 0xD0, 0);
    {
        It b3;
        Beg2(&b3, (char*)mgr);
        char* n = b3.p;
        for (; (End1(&e3, (char*)mgr), n != e3.p); n = F_(n, 4, char*)) {
            F_(n, 8, OObj*)->Update(arg);
        }
    }
}
