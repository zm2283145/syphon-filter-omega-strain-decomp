#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" {
char* WeaponDb_Get(int, int);
void WeaponDb_Preload(int, int, int);
char* Loc_LookupText(char*);
void GuiTextWidget_SetText(int, char*, int);
extern int D_004FFD30;
extern char D_004C03B8[];
}

static inline void SetIcon(char* self, char* w) {
    int v;
    if (F_(w, 0xF0, unsigned char) == 7 && (v = F_(w, 0x11C, int)) != 0) F_(self, 0x4C, int) = v;
    else F_(self, 0x4C, int) = F_(w, 0x13C, int);
}

extern "C" void GuiWeaponDisplay_Set(char* self, int id) {
    char* w;
    char* t;
    int cur;

    if (F_(self, 0x48, int) == id) return;
    F_(self, 0x48, int) = id;
    F_(self, 0x4C, int) = 0;
    cur = F_(self, 0x48, int);
    if (cur != -1) {
        w = WeaponDb_Get(D_004FFD30, cur);
        SetIcon(self, w);
        if (F_(self, 0x4C, int) == 0) {
            WeaponDb_Preload(D_004FFD30, F_(self, 0x48, int), 0);
            SetIcon(self, w);
        }
        if (F_(self, 0xA0, int) != 0) {
            t = Loc_LookupText(w + 0x80);
            GuiTextWidget_SetText(F_(self, 0xA0, int), t ? t : w + 0x80, 0);
        }
    } else {
        int lbl = F_(self, 0xA0, int);
        if (lbl != 0) GuiTextWidget_SetText(lbl, D_004C03B8, 0);
    }
}




