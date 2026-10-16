#pragma cplusplus on
#include "types.h"
struct Spr { int f0; float f4; };
struct SprVec { int cap; int n; Spr** data; int pad; };
struct Tgt { char pad[0x130]; int f130; };
struct Ent { char pad[0xF0]; unsigned char type; char padF1[0xF]; signed char b100; char p101[0x2F]; int f130; };
struct Hud { char pad[0x7C]; SprVec v; int cur; };
extern "C" {
extern char D_004FFC14[];
extern void* D_004FFC10;
int func_00159570(void*);
void** List_Front(void*);
void func_00244A10(Hud*);
void func_00244A00(Hud*);
void Hud_HideNoFire(Hud*);
Spr** func_00242180(SprVec*, int);
void IeElement_SetShown(Spr*, int);
void IeElement_EvaluateAt(Spr*, float);
void IeElement_Fade(Spr*, float);
}
static inline void* GetCam() { if (func_00159570(D_004FFC14)) return *List_Front(D_004FFC14); return 0; }
static inline bool IsNoCross(Ent* e) {
    unsigned char b = 0;
    unsigned int k = e->type - 3;
    if (k < 8 && ((1 << k) & 0x83)) b = 1;
    return b;
}
static inline void Select(Hud* h, int idx) {
    if (idx >= 0) {
        if (idx == 0) func_00244A10(h);
        else {
            Spr* s = h->v.data[(unsigned)(idx - 1)];
            if (s) {
                IeElement_SetShown(s, 1);
                IeElement_EvaluateAt(s, 1.0f);
                IeElement_Fade(s, 10.0f);
            }
            func_00244A00(h);
        }
    }
}
static inline void Unselect(Hud* h, int c) {
    if (c >= 0) {
        if (c == 0) func_00244A00(h);
        else {
            Spr* s = h->v.data[(unsigned)(c - 1)];
            if (s) IeElement_Fade(s, 0.0f);
        }
    }
}
#pragma push
#pragma opt_strength_reduction off
extern "C" int Hud_UpdateCrosshair(Hud* h, int on, int a2_, Ent* e, Tgt* t)
{
    int idx = -1;
    int a2 = a2_;
    bool ok = true;
    if (on) {
        if (!a2 && t) {
            idx = t->f130 + 1;
            ok = idx < 0;
        }
        if (ok && e && !IsNoCross(e) && D_004FFC10 == GetCam()) {
            if (!a2 && e->f130 >= 0) idx = e->f130 + 1;
            else if (idx < 0 || e->type == 1) idx = 0;
        }
    }
    if (idx >= 0 && e) a2 = e->b100;
    else a2 = 0;
    if (idx != h->cur) {
        Select(h, idx);
        Unselect(h, h->cur);
    }
    if (idx < 0) Hud_HideNoFire(h);
    if (e && e->type == 1) Hud_HideNoFire(h);
    for (int i = 0; i < h->v.n; i++) {
        if (i != idx - 1 && h->v.data[i]->f4 == 0.0f)
            IeElement_SetShown(*func_00242180(&h->v, i), 0);
    }
    h->cur = idx;
    return a2;
}
#pragma pop
