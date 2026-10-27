/*
 * SFOGame/Source/GuiStartMenu: 1 file, 00455260
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
