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
int ItemTable_GetName(int);
char* ItemTable_GetDesc(int);
int ItemInv_Count(void*, int);
void GuiWeaponDisplay_SetItem(void*, int, int, int);
void GuiWeaponDisplay_Set(void*, int);
void GuiTextArrayWidget_SetCellText(void*, int, int, char*);
char* Loc_LookupText(char*);
int sprintf(char*, char*, ...);
char* WeaponDb_Get(void*, int);
char* strncpy(char*, char*, int);
int WeaponInv_SlotOfItem(int);
void GuiWeaponStats_Fill(void*, int);
void MLTextWidget_Clear(void*);
void MLTextWidget_AddText(void*, char*);
void GuiTextWidget_SetText(void*, char*, int);
void GuiEquipmentPane_SetItem(O_455260* o, A_455260* a, int id);
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
        GuiTextArrayWidget_SetCellText(p, 0, i, D_004C1A38);
        GuiTextArrayWidget_SetCellText(p, 1, i, D_004C1A38);
        i++;
    } while (i < 3);
    GuiTextArrayWidget_SetCellText(p, 0, 2, Loc_LookupText(D_004C1A40));
    sprintf(buf, D_004C1A50, cnt);
    GuiTextArrayWidget_SetCellText(p, 1, 2, buf);
}

void GuiEquipmentPane_SetItem(O_455260* o, A_455260* a, int id)
{
    void* inv = a->f3528;
    int item;
    item = -1; if (id >= 10000) item = id - 10000;
    if (o->f48) {
        if (item > -1) {
            Itm_455260* t = &D_00587FF8[item]; int x = t->f28;
            GuiWeaponDisplay_SetItem(o->f48, id, x, ItemTable_GetName(item));
        } else {
            GuiWeaponDisplay_Set(o->f48, id);
        }
    }
    if (o->f50 && o->f4C && o->f54) {
        char* name = 0;
        char* desc = 0;
        bool flag = 0;
        if (item > -1) {
            name = ItemTable_GetDesc(item);
            desc = (char*)ItemTable_GetName(item);
            Fill(o->f54, ItemInv_Count(inv, item));
            flag = 1;
        } else if (id > -1) {
            char* w = WeaponDb_Get(g_WeaponDatabase, id);
            char key[16] = {0};

            key[0] = 'D';
            key[1] = '_';
            strncpy(key + 2, w + 0x80, 13);
            name = Loc_LookupText(key);
            desc = Loc_LookupText(w + 0x80);
            if (!desc) desc = w + 0x80;
            if ((unsigned char)WeaponInv_SlotOfItem(id) < 6) {
                GuiWeaponStats_Fill(o->f54, id);
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
            MLTextWidget_Clear(t);
            MLTextWidget_AddText(t, name ? name : D_004C1A38);
        }
        GuiTextWidget_SetText(o->f50, desc ? desc : D_004C1A38, 0);
    }
}
