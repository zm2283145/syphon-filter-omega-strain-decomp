/*
 * SFOGame/Source/GuiEquipmentModify: 1 file, 002BE380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002BE380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct W_002BE380 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct Wpn_002BE380 { char pad0[0x60]; void* p60; void* p64; char pad68[8]; int f70; int f74; char pad78[8]; char name[0x3C]; unsigned char bBC; };
struct S_002BE380 { char pad0[0x48]; void* p48; char pad4C[0x40]; void* p8C; char pad90[0x74]; int f104; int f108; short h10C[8]; };
extern "C" {
extern int g_WeaponDatabase;
extern char D_004AC3F0[];
extern char D_004AC410[];
extern char D_004AC420[];
extern char D_004AC430[];
extern char D_004AC450[];
extern char D_004AC388[];
extern char D_004AC468[];
extern char D_004AC470[];
extern char D_004AC480[];
extern char D_004A7520[];
extern "C" char D_004AC280[];
void * const D_0048C0A8[2] = { (void*)D_004AC280, (void*)0x0 };
Wpn_002BE380* cWeaponDB_GetEntry(int db, int id);
void* GuiWidget_FindChild_charP(void* self, char* name);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(W_002BE380* w, char* s, int a);
void* cGameFrontEnd_GetConvertedWeaponFireRate(void* p);
void* cGameFrontEnd_GetConvertedWeaponDamage(void* p);
void cGameFrontEnd_ConvertIntToRomanNumeral(void* p, char* buf, int n);
void Libc_Strcpy(char* d, const char* s);
int sprintf(char* buf, const char* fmt, ...);
int cHuman_AdjustMaxClips(void* p, int a);
}
static inline W_002BE380* FindAs_002BE380(void* self, char* name, char* type)
{
    W_002BE380* w = (W_002BE380*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Clear_002BE380(void* self, char* name)
{
    W_002BE380* w = FindAs_002BE380(self, name, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, D_004AC388, 0);
}
extern "C" void GuiEquipmentModify_UpdateSelection(S_002BE380* self)
{
    char buf[0x20];
    if (self->f108 < self->f104 && self->p8C) {
        Wpn_002BE380* wp = cWeaponDB_GetEntry(g_WeaponDatabase, self->h10C[self->f108]);
        W_002BE380* w = FindAs_002BE380(self, D_004AC3F0, D_004A7520);
        char* t = nGlobalization_GetString_charP(wp->name);
        int n;
        if (w && t)
            GuiTextWidget_SetText(w, t, 0);
        else if (w)
            GuiTextWidget_SetText(w, wp->name, 0);
        w = FindAs_002BE380(self, D_004AC410, D_004A7520);
        if (wp->p60)
            cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponFireRate(wp->p60), buf, 0x20);
        else
            Libc_Strcpy(buf, (*(char**)D_0048C0A8));
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE380(self, D_004AC420, D_004A7520);
        if (wp->bBC == 7 && !wp->p64)
            sprintf(buf, D_004AC468, nGlobalization_GetString_charP(D_004AC470));
        else if (wp->p64)
            cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponDamage(wp->p64), buf, 0x20);
        else
            Libc_Strcpy(buf, (*(char**)D_0048C0A8));
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE380(self, D_004AC430, D_004A7520);
        if (wp->f70)
            sprintf(buf, D_004AC480, wp->f70);
        else
            Libc_Strcpy(buf, (*(char**)D_0048C0A8));
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
        w = FindAs_002BE380(self, D_004AC450, D_004A7520);
        n = wp->f70 * cHuman_AdjustMaxClips(self->p48, wp->f74);
        if (n)
            sprintf(buf, D_004AC480, n);
        else
            Libc_Strcpy(buf, (*(char**)D_0048C0A8));
        if (w)
            GuiTextWidget_SetText(w, buf, 0);
    } else {
        Clear_002BE380(self, D_004AC3F0);
        Clear_002BE380(self, D_004AC410);
        Clear_002BE380(self, D_004AC420);
        Clear_002BE380(self, D_004AC430);
        Clear_002BE380(self, D_004AC450);
    }
}
static inline void merge_flush_func_002BE380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BE380 */
