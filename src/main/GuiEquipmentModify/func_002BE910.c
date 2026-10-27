#pragma cplusplus on
#include "types.h"
struct W_002BE910 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct Wpn_002BE910 { char pad0[0x60]; void* p60; void* p64; char pad68[8]; int f70; int f74; char pad78[8]; char name[0x3C]; unsigned char bBC; };
struct Item_002BE910 { char pad[0x40A]; short h40A; };
struct Inv_002BE910 { char pad[0x2410]; Item_002BE910* slots[8]; };
struct Act_002BE910 { char pad[0x60]; Inv_002BE910 inv; };
struct S_002BE910 { char pad0[0x48]; void* p48; Act_002BE910* p4C; char pad50[0x34]; void* p84; int f88; char pad8C[0x70]; int fFC; };
extern "C" {
extern int g_WeaponDatabase;
extern char D_004AC370[];
extern char D_004AC390[];
extern char D_004AC3A0[];
extern char D_004AC3B0[];
extern char D_004AC3D0[];
extern char D_004AC388[];
extern char D_004AC468[];
extern char D_004AC470[];
extern char D_004AC480[];
extern char D_004A7520[];
extern char* D_0048C0A8;
Wpn_002BE910* cWeaponDB_GetEntry(int db, int id);
void* GuiWidget_FindChild_charP(void* self, char* name);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(W_002BE910* w, char* s, int a);
void* cGameFrontEnd_GetConvertedWeaponFireRate(void* p);
void* cGameFrontEnd_GetConvertedWeaponDamage(void* p);
void cGameFrontEnd_ConvertIntToRomanNumeral(void* p, char* buf, int n);
void Libc_Strcpy(char* d, const char* s);
int sprintf(char* buf, const char* fmt, ...);
int cHuman_AdjustMaxClips(void* p, int a);
}
static inline W_002BE910* FindAs_002BE910(void* self, char* name, char* type)
{
    W_002BE910* w = (W_002BE910*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Clear_002BE910(void* self, char* name)
{
    W_002BE910* w = FindAs_002BE910(self, name, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, D_004AC388, 0);
}
extern "C" void GuiEquipmentModify_UpdateCurrent(S_002BE910* self)
{
    char buf[0x20];
    Wpn_002BE910* wp = 0;
    if (self->p84) {
        Inv_002BE910* inv = &self->p4C->inv;
        int k = self->f88;
        Item_002BE910* it = inv->slots[k];
        if (it) {
            wp = cWeaponDB_GetEntry(g_WeaponDatabase, it->h40A);
        } else if (self->fFC == k) {
            Item_002BE910* it2 = inv->slots[0];
            if (it2)
                wp = cWeaponDB_GetEntry(g_WeaponDatabase, it2->h40A);
        }
    }
    if (wp) {
        W_002BE910* w = FindAs_002BE910(self, D_004AC370, D_004A7520);
        char* t = nGlobalization_GetString_charP(wp->name);
        int n;
        if (w && t)
            GuiTextWidget_SetText(w, t, 0);
        else if (w)
            GuiTextWidget_SetText(w, wp->name, 0);
        w = FindAs_002BE910(self, D_004AC390, D_004A7520);
        if (wp->p60)
            cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponFireRate(wp->p60), buf, 0x20);
        else
            Libc_Strcpy(buf, D_0048C0A8);
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE910(self, D_004AC3A0, D_004A7520);
        if (wp->bBC == 7 && !wp->p64)
            sprintf(buf, D_004AC468, nGlobalization_GetString_charP(D_004AC470));
        else if (wp->p64)
            cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponDamage(wp->p64), buf, 0x20);
        else
            Libc_Strcpy(buf, D_0048C0A8);
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE910(self, D_004AC3B0, D_004A7520);
        if (wp->f70)
            sprintf(buf, D_004AC480, wp->f70);
        else
            Libc_Strcpy(buf, D_0048C0A8);
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE910(self, D_004AC3D0, D_004A7520);
        n = wp->f70 * cHuman_AdjustMaxClips(self->p48, wp->f74);
        if (n)
            sprintf(buf, D_004AC480, n);
        else
            Libc_Strcpy(buf, D_0048C0A8);
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
    } else {
        Clear_002BE910(self, D_004AC370);
        Clear_002BE910(self, D_004AC390);
        Clear_002BE910(self, D_004AC3A0);
        Clear_002BE910(self, D_004AC3B0);
        Clear_002BE910(self, D_004AC3D0);
    }
}