#pragma cplusplus on
#include "types.h"
struct Wd_5C5E0 { char pad[0x50]; float f50; char pad54[0xC]; char m60[0x40]; char padA0[4]; unsigned char bA4; };
struct Sub_5C5E0 { char pad[0x14]; unsigned short flags; };
struct Scr_5C5E0 {
    char pad[0x6C];
    Sub_5C5E0* sub;
    char pad70[4];
    int count;
    int* items;
    char pad7C[0x90 - 0x7C];
    int cur;
    char pad94[0xA8 - 0x94];
    Wd_5C5E0* panels[5];
    char padBC[0xD8 - 0xBC];
    int xD8;
};
extern "C" {
void GuiWeaponDisplay_SetItem(Wd_5C5E0* w, int item, int a, int b);
void GuiWeaponDisplay_SetWeapon(Wd_5C5E0* w, int item);
void GuiGameScreen_UpdateWeaponPanels(Scr_5C5E0* s);
}
static inline void UM(void* p0) { void* p = p0; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
#pragma opt_rotateloops off
void GuiGameScreen_UpdateWeaponPanels(Scr_5C5E0* s)
{
    int idx;
    bool done;
    int i;
    if (!s->sub || !(s->sub->flags & 4)) return;
    idx = s->cur;
    done = false;
    for (i = 0; i < 5; i++) {
        if (!done) {
            int item = s->items[idx];
            if (item == -2) GuiWeaponDisplay_SetItem(s->panels[i], -2, s->xD8, 0);
            else GuiWeaponDisplay_SetWeapon(s->panels[i], item);
            idx++;
            if (idx >= s->count) idx = 0;
            if (idx == s->cur) done = true;
        } else {
            GuiWeaponDisplay_SetWeapon(s->panels[i], -1);
        }
    }
    { Wd_5C5E0* p = s->panels[0]; p->bA4 = s->items[s->cur] != -2; }
    {
        Wd_5C5E0* w = s->panels[0];
        UM(w->m60);
        w->f50 = 0.0f;
    }
}
