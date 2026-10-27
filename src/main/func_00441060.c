#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" {
char* cWeaponDB_GetEntry(int, int);
void cWeaponDB_LoadWeapon(int, int, int);
char* nGlobalization_GetString_charP(char*);
void GuiTextWidget_SetText(int, char*, int);
extern int g_WeaponDatabase;
extern char D_004C03B8[];
}

static inline void SetIcon(char* self, char* w) {
    int v;
    if (F_(w, 0xF0, unsigned char) == 7 && (v = F_(w, 0x11C, int)) != 0) F_(self, 0x4C, int) = v;
    else F_(self, 0x4C, int) = F_(w, 0x13C, int);
}

extern "C" void GuiWeaponDisplay_SetWeapon(char* self, int id) {
    char* w;
    char* t;
    int cur;

    if (F_(self, 0x48, int) == id) return;
    F_(self, 0x48, int) = id;
    F_(self, 0x4C, int) = 0;
    cur = F_(self, 0x48, int);
    if (cur != -1) {
        w = cWeaponDB_GetEntry(g_WeaponDatabase, cur);
        SetIcon(self, w);
        if (F_(self, 0x4C, int) == 0) {
            cWeaponDB_LoadWeapon(g_WeaponDatabase, F_(self, 0x48, int), 0);
            SetIcon(self, w);
        }
        if (F_(self, 0xA0, int) != 0) {
            t = nGlobalization_GetString_charP(w + 0x80);
            GuiTextWidget_SetText(F_(self, 0xA0, int), t ? t : w + 0x80, 0);
        }
    } else {
        int lbl = F_(self, 0xA0, int);
        if (lbl != 0) GuiTextWidget_SetText(lbl, D_004C03B8, 0);
    }
}




