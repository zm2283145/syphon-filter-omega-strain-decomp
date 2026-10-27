#pragma cplusplus on
#include "types.h"
struct V2BE { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual void v21(int, int); };
typedef struct { char pad[0x14]; unsigned short flags; } W2BE;
typedef struct { void* vt; char pad[0x10]; unsigned short flags; char pad2[0x6B]; unsigned char b81; char p82[6]; W2BE* f88; } L2BE;
typedef struct { char pad[0x94]; L2BE* f94; char p98[0x10]; int fa8; char pad2[0x20]; W2BE* fcc; char pad3[0x34]; int f104; int f108; short h10c[1]; } O2BE;
typedef struct { char pad[0x80]; char name[4]; } WD2BE;
extern "C" {
extern void GuiTextListWidget_Clear(L2BE*);
extern void GuiArrayWidget_SetVisibleSize(L2BE*, int, int);
extern void GuiArrayWidget_SetSelected(L2BE*, int, int);
extern int g_WeaponDatabase;
extern WD2BE* cWeaponDB_GetEntry(int, int);
extern char* nGlobalization_GetString_charP(char*);
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
