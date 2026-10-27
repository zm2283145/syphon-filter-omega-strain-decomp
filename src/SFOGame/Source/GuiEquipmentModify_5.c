/*
 * SFOGame/Source/GuiEquipmentModify: 2 files, 002BE910-002BEEE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002BE910 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_002BE910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BE910 */

/* merge_units: begin func_002BEEE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2BE { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual void v21(int, int); };
typedef struct { char pad[0x14]; unsigned short flags; } W2BE;
typedef struct { void* vt; char pad[0x10]; unsigned short flags; char pad2[0x6B]; unsigned char b81; char p82[6]; W2BE* f88; } L2BE;
typedef struct { char pad[0x94]; L2BE* f94; char p98[0x10]; int fa8; char pad2[0x20]; W2BE* fcc; char pad3[0x34]; int f104; int f108; short h10c[1]; } O2BE;
typedef struct { char pad[0x80]; char name[4]; } WD2BE;
extern "C" {
extern void GuiTextListWidget_Clear(L2BE*);
extern void GuiArrayWidget_SetVisibleSize(L2BE*, int, int);
extern void GuiArrayWidget_SetSelected(L2BE*, int, int);
#if 0 /* merge_units */
extern WD2BE* cWeaponDB_GetEntry(int, int);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((WD2BE *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char* nGlobalization_GetString_charP(char*);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) (nGlobalization_GetString_charP((a0))) /* merge_units */

extern void GuiTextListWidget_AddItem(L2BE*, char*, int, int);
}
extern "C" void GuiEquipmentModify_UpdateList(O2BE* o) {
    int i;
    GuiTextListWidget_Clear(o->f94);
    ((V2BE*)o->f94)->v21(1, o->f104 + 1);
    if (o->f104 >= o->fa8) GuiArrayWidget_SetVisibleSize(o->f94, 1, o->fa8);
    else GuiArrayWidget_SetVisibleSize(o->f94, 1, o->f104 + 1);
    GuiArrayWidget_SetSelected(o->f94, 0, (int)(void*)o->f108);
    o->f94->b81 = 1;
    o->f94->f88 = o->fcc;
    o->fcc->flags &= ~2;
    for (i = 0; i < o->f104; i++) {
        WD2BE* w = cWeaponDB_GetEntry(g_WeaponDatabase, o->h10c[i]);
        char* t = nGlobalization_GetString_charP(w->name);
        if (t) GuiTextListWidget_AddItem(o->f94, t, i, 0);
        else GuiTextListWidget_AddItem(o->f94, w->name, i, 0);
    }
    GuiTextListWidget_AddItem(o->f94, nGlobalization_GetString_charP("NoneOption"), i, 0);
    GuiArrayWidget_SetSelected(o->f94, 0, (int)(void*)o->f108);
    o->fcc->flags &= ~0x80;
    o->f94->flags &= ~0x80;
}
#undef cWeaponDB_GetEntry /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
static inline void merge_flush_func_002BEEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BEEE0 */
