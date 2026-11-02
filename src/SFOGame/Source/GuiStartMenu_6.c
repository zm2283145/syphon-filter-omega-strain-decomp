/*
 * SFOGame/Source/GuiStartMenu: 5 files, 00455260-00455550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00455260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x28]; int f28; } Itm_455260;
typedef struct { char pad[0x14]; unsigned short f14; } L_455260;
typedef struct { char pad[0x48]; void* f48; void* f4C; void* f50; L_455260* f54; } O_455260;
typedef struct { char pad[0x3528]; void* f3528; } A_455260;
extern "C" {
extern Itm_455260* D_00587FF8;
extern void* g_WeaponDatabase;
extern char D_004C1A38[];
extern char D_004C1A40[];
extern char D_004C1A50[];
int cInventory_GetShortName(int);
char* cInventory_GetLongName(int);
int cInventory_GetCount_int(void*, int);
void GuiWeaponDisplay_SetItem(void*, int, int, int);
void GuiWeaponDisplay_SetWeapon(void*, int);
void GuiTextArrayWidget_SetText(void*, int, int, char*);
char* nGlobalization_GetString_charP(char*);
int sprintf(char*, char*, ...);
char* cWeaponDB_GetEntry(void*, int);
char* strncpy(char*, char*, int);
int cWeapon_GetWeaponSlot(int);
void GuiWeaponStats_SetWeaponStats(void*, int);
void GuiMLTextWidget_Clear(void*);
void GuiMLTextWidget_AddText(void*, char*);
void GuiTextWidget_SetText(void*, char*, int);
void GuiEquipmentPane_SetWeapon(O_455260* o, A_455260* a, int id);
}

static inline void Zero(char* q, int n)
{
    if (q) {
        do {
            *q++ = 0;
        } while (--n);
    }
}

static inline void Fill(L_455260* p, int cnt)
{
    char buf[16];
    int i = 0;
    do {
        GuiTextArrayWidget_SetText(p, 0, i, D_004C1A38);
        GuiTextArrayWidget_SetText(p, 1, i, D_004C1A38);
        i++;
    } while (i < 3);
    GuiTextArrayWidget_SetText(p, 0, 2, nGlobalization_GetString_charP(D_004C1A40));
    sprintf(buf, D_004C1A50, cnt);
    GuiTextArrayWidget_SetText(p, 1, 2, buf);
}

void GuiEquipmentPane_SetWeapon(O_455260* o, A_455260* a, int id)
{
    void* inv = a->f3528;
    int item;
    item = -1; if (id >= 10000) item = id - 10000;
    if (o->f48) {
        if (item > -1) {
            Itm_455260* t = &D_00587FF8[item]; int x = t->f28;
            GuiWeaponDisplay_SetItem(o->f48, id, x, cInventory_GetShortName(item));
        } else {
            GuiWeaponDisplay_SetWeapon(o->f48, id);
        }
    }
    if (o->f50 && o->f4C && o->f54) {
        char* name = 0;
        char* desc = 0;
        bool flag = 0;
        if (item > -1) {
            name = cInventory_GetLongName(item);
            desc = (char*)cInventory_GetShortName(item);
            Fill(o->f54, cInventory_GetCount_int(inv, item));
            flag = 1;
        } else if (id > -1) {
            char* w = cWeaponDB_GetEntry(g_WeaponDatabase, id);
            char key[16] = {0};

            key[0] = 'D';
            key[1] = '_';
            strncpy(key + 2, w + 0x80, 13);
            name = nGlobalization_GetString_charP(key);
            desc = nGlobalization_GetString_charP(w + 0x80);
            if (!desc) desc = w + 0x80;
            if ((unsigned char)cWeapon_GetWeaponSlot(id) < 6) {
                GuiWeaponStats_SetWeaponStats(o->f54, id);
                flag = 1;
            }
        }
        {
            L_455260* l = o->f54;
            if (flag) l->f14 |= 2;
            else l->f14 &= ~2;
        }
        {
            void* t = o->f4C;
            GuiMLTextWidget_Clear(t);
            GuiMLTextWidget_AddText(t, name ? name : D_004C1A38);
        }
        GuiTextWidget_SetText(o->f50, desc ? desc : D_004C1A38, 0);
    }
}
static inline void merge_flush_func_00455260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455260 */

/* merge_units: begin func_00455550 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int type; } A_455550;
typedef struct { char pad[0x30]; A_455550* f30; } G_455550;
typedef struct { char pad[0x48]; void* f48; } O_455550;
extern G_455550* g_LocalPlayer;
extern int g_HumanActorClassKey;
extern void GuiWidget_onWake(O_455550*);
extern int cPlayer_GetActiveWeapon(G_455550*);
extern void GuiEquipmentPane_SelectNext(O_455550*, int);
#if 0 /* merge_units */
extern void GuiEquipmentPane_SetWeapon(O_455550*, A_455550*, int);
#endif /* merge_units */
#define GuiEquipmentPane_SetWeapon(a0, a1, a2) (GuiEquipmentPane_SetWeapon((O_455260 *)(a0), (A_455260 *)(a1), (a2))) /* merge_units */


void GuiEquipmentPane_onWake(O_455550* o)
{
    G_455550* g;
    GuiWidget_onWake(o);
    if (o->f48 && (g = g_LocalPlayer)) {
        if (cPlayer_GetActiveWeapon(g) == -1) {
            GuiEquipmentPane_SelectNext(o, 1);
        } else {
            A_455550* a = g->f30;
            a = (a && a->type == g_HumanActorClassKey) ? a : 0;
            GuiEquipmentPane_SetWeapon(o, a, cPlayer_GetActiveWeapon(g));
        }
    }
}
#undef GuiEquipmentPane_SetWeapon /* merge_units */
static inline void merge_flush_func_00455550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455550 */

/* merge_units: begin func_00455610 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gui_widget_vslots.h"
struct W_455610 : GuiWidgetV { char pad4[0x10]; unsigned short f14; char pad16[0x4A]; int f60; char pad64[0x18]; GuiWidgetV* f7C; };
struct S_455610 { char pad0[0x48]; GuiWidgetV* f48; W_455610* f4C; GuiWidgetV* f50; GuiWidgetV* f54; };
extern "C" {
extern char* D_00497998;
extern char D_004C1A60[];
extern char D_004C19C0[];
extern char D_004C1A78[];
extern char D_004C19B0[];
extern char D_004BB3D0[];
extern char D_004A7520[];
extern char D_004C1D88[];
extern char D_004AAE20[];
extern char D_004AAE00[];
void GuiWidget_onAdd(S_455610* s);
}
extern "C" void GuiEquipmentPane_onAdd(S_455610* s)
{
    GuiWidget_onAdd(s);
    s->f48 = GuiFindAs(s, D_00497998, D_004BB3D0);
    s->f50 = GuiFindAs(s, D_004C1A60, D_004A7520);
    s->f54 = GuiFindAs(s, D_004C19C0, D_004C1D88);
    s->f4C = (W_455610*)GuiFindAs(s, D_004C1A78, D_004AAE20);
    if (s->f4C) {
        s->f4C->f60 = 0;
        s->f4C->f7C = GuiFindAs(s, D_004C19B0, D_004AAE00);
        s->f4C->f14 |= 0x80;
    }
}
static inline void merge_flush_func_00455610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455610 */

/* merge_units: begin func_004557C0 */
#pragma push /* merge_units */
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E4557C0;
extern int GuiStartMenu_ReturnToMenu(void* self, E4557C0* e);
extern int GuiArrayWidget_onInput(void* self, E4557C0* e);
int GuiWeaponStats_HandleInput(void* self, E4557C0* e)
{
    int b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        GuiStartMenu_ReturnToMenu(self, e);
        return 1;
    }
    return GuiArrayWidget_onInput(self, e);
}
static inline void merge_flush_func_004557C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004557C0 */

/* merge_units: begin func_00455840 */
#pragma push /* merge_units */
typedef struct { char pad0[0x60]; int f60; int f64; char pad68[8]; int f70; int f74; } Wpn_00455840;
typedef struct { char pad0[0x30]; int f30; } G_00455840;
#if 0 /* merge_units */
extern G_00455840* g_LocalPlayer;
#endif /* merge_units */
#define g_LocalPlayer (*(G_00455840 **)&g_LocalPlayer) /* merge_units */


#if 0 /* merge_units */
extern int g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(int*)&g_WeaponDatabase) /* merge_units */

extern char D_004C1A88[];
extern char D_004C1A98[];
#if 0 /* merge_units */
int sprintf(char* d, const char* f, ...);
#endif /* merge_units */

#if 0 /* merge_units */
char* nGlobalization_GetString_charP(char* key);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) (nGlobalization_GetString_charP((a0))) /* merge_units */

#if 0 /* merge_units */
void GuiTextArrayWidget_SetText(void* list, int col, int row, char* text);
#endif /* merge_units */
#define GuiTextArrayWidget_SetText(a0, a1, a2, a3) (GuiTextArrayWidget_SetText((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
Wpn_00455840* cWeaponDB_GetEntry(int db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((Wpn_00455840 *)cWeaponDB_GetEntry((void *)(a0), (a1))) /* merge_units */

void Libc_Strcpy(char* d, char* s);
int cGameFrontEnd_GetConvertedWeaponFireRate(int a);
int cGameFrontEnd_GetConvertedWeaponDamage(int a);
void cGameFrontEnd_ConvertIntToRomanNumeral(int a, char* buf, int n);
int cHuman_AdjustMaxClips(int actor, int a);
void GuiWeaponStats_SetWeaponStats(void* list, int id)
{
    char key[0x10];
    char buf[0x20];
    int i;
    Wpn_00455840* w;
    for (i = 0; i < 4; i++) {
        char* t;
        sprintf(key, D_004C1A88, i);
        t = nGlobalization_GetString_charP(key);
        GuiTextArrayWidget_SetText(list, 0, i, t ? t : D_004C1A38);
    }
    w = cWeaponDB_GetEntry(g_WeaponDatabase, id);
    if (w) {
        int actor = g_LocalPlayer->f30;
        for (i = 0; i < 4; i++) {
            Libc_Strcpy(buf, D_004C1A98);
            switch (i) {
            case 0:
                if (w->f60)
                    cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponFireRate(w->f60), buf, 0x20);
                break;
            case 1:
                if (w->f64)
                    cGameFrontEnd_ConvertIntToRomanNumeral(cGameFrontEnd_GetConvertedWeaponDamage(w->f64), buf, 0x20);
                break;
            case 2:
                if (w->f70)
                    sprintf(buf, D_004C1A50, w->f70);
                break;
            case 3: {
                int n = w->f70 * cHuman_AdjustMaxClips(actor, w->f74);
                if (n)
                    sprintf(buf, D_004C1A50, n);
                break;
            }
            }
            GuiTextArrayWidget_SetText(list, 1, i, buf);
        }
    }
}
#undef g_LocalPlayer /* merge_units */
#undef g_WeaponDatabase /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
#undef GuiTextArrayWidget_SetText /* merge_units */
#undef cWeaponDB_GetEntry /* merge_units */
static inline void merge_flush_func_00455840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455840 */
