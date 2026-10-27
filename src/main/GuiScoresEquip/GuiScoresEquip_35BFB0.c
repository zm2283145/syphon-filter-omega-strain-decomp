/*
 * main/GuiScoresEquip: range (3 files, 0035BFB0-0035CBF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_0035BFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_35BFB0 { char pad0[0x14]; unsigned short flags; };
struct Ctl_35BFB0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsActive();
};
struct Player_35BFB0 {
    char pad0[0xC];
    unsigned int fC;
    char pad10[0x14 - 0x10];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Ctl_35BFB0* f58;
    char pad5C[4];
    char m60[4];
};
struct Item_35BFB0 { char pad0[0x40A]; short id; };
struct WDef_35BFB0 { char pad0[0x30]; unsigned char slot; char pad31[0x80 - 0x31]; char name[1]; };
struct Inv_35BFB0 { char pad0[0x2410]; Item_35BFB0* arr[13]; void Set(int i, Item_35BFB0* it) { arr[i] = it; } Item_35BFB0*& Slot(int i) { return arr[i]; } Item_35BFB0** PSlot(int i) { return &arr[i]; } };
struct Skel_35BFB0 {
    char pad0[0x60];
    Inv_35BFB0 inv;
    char pad24A4[0x2C3A - 0x24A4];
    signed char b2C3A;
    char pad2C3B[0x2C71 - 0x2C3B];
    unsigned char b2C71;
};
struct Agent_35BFB0 { char pad0[0xB70]; unsigned char bB70; };
struct Screen_35BFB0 {
    char pad0[0x48];
    W_35BFB0* f48[4];
    int f58;
    int f5C;
    unsigned char b60;
    W_35BFB0* rows[4][20];
    Skel_35BFB0* skel[4];
    float f1B4[5];
    float f1C8;
    char pad1CC[0x220 - 0x1CC];
    unsigned char f220[4];
    char pad224[0x228 - 0x224];
    float f228;
    char pad22C[0x230 - 0x22C];
    W_35BFB0* f230[4][2];
};
struct Top_35BFB0 { char pad0[8]; void* f8; };
struct Stack_35BFB0 { char pad0[0x2C]; Top_35BFB0* f2C; };
extern "C" {
extern char D_004BB530[];
extern char D_004BB558[];
extern char D_004BB568[];
extern char D_004BB578[];
extern char D_004BB580[];
extern char D_004BB588[];
extern void* g_WeaponDatabase;
extern char D_00533790[];
extern unsigned char g_IsMultiplayer;
Stack_35BFB0* Gui_Canvas(void);
char* nGlobalization_GetString_charP(char* key);
Player_35BFB0* cNetObj_GetPlayer(int i);
void cSKM_GOBJ_CloneMan(Skel_35BFB0* s, void* p);
WDef_35BFB0* cWeaponDB_GetEntry(void* table, int id);
int cAgentData_GetStat(Agent_35BFB0* a, int stat);
char Libc_Toupper(char c);
Agent_35BFB0* cHuman_GetAgentData(Player_35BFB0* p, unsigned char* flag);
char* cAgentData_GetUserName(Agent_35BFB0* a);
void GuiTextWidget_SetText(W_35BFB0* w, char* text, int flags);
void GuiWidget_SendMessage(Screen_35BFB0* s, W_35BFB0* w, int a, int b, int c);
void GuiWidget_onAdvanceTime(Screen_35BFB0* s, float dt);
float cDME_GetConnectionStatus(int i);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
}

static inline int Slot_35BFB0(Player_35BFB0* p) { return ((p->fC & 0x7F000000) >> 24) - 1; }

static inline void SetLoc_35BFB0(W_35BFB0* w, char* key)
{
    char* t = nGlobalization_GetString_charP(key);
    if (t)
        GuiTextWidget_SetText(w, t, 0);
    else
        GuiTextWidget_SetText(w, key, 0);
}

static inline void ShowItem_35BFB0(W_35BFB0* w, Item_35BFB0* it)
{
    if (it) {
        WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, it->id);
        SetLoc_35BFB0(w, d->name);
    } else {
        GuiTextWidget_SetText(w, D_004BB530, 0);
    }
}

#define SHOW_ITEM(W, IT) \
    if (IT) { \
        WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, (IT)->id); \
        char* t = nGlobalization_GetString_charP(d->name); \
        if (t) \
            GuiTextWidget_SetText(W, t, 0); \
        else \
            GuiTextWidget_SetText(W, d->name, 0); \
    } else { \
        GuiTextWidget_SetText(W, D_004BB530, 0); \
    }

static const float kPi_35BFB0 = 3.1415927f;
extern "C" void GuiScoresEquip_onAdvanceTime(Screen_35BFB0* s, float dt)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (s->rows[i][0]) {
            GuiTextWidget_SetText(s->rows[i][0], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][1], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][13], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][14], D_004BB530, 0);
        }
    }
    {
    int n;
    for (n = 0; n < 4; n++) {
        Player_35BFB0* p = cNetObj_GetPlayer(n);
        if (p) {
            int slot = Slot_35BFB0(p);
            Agent_35BFB0* a;
            if (slot < 0) slot = 0;
            cSKM_GOBJ_CloneMan(s->skel[slot], p->m60);
            s->skel[slot]->b2C71 = 1;
            if (!s->f220[slot]) s->f220[slot] = 1;
            a = cHuman_GetAgentData(p, &s->f220[slot]);
            if (a->bB70) {
                char buf[0x10];
                char key[0x20];
                unsigned int k;
                int d;
                GuiTextWidget_SetText(s->rows[slot][0], cAgentData_GetUserName(a), 0);
                GuiTextWidget_SetText(s->rows[slot][13], cAgentData_GetUserName(a), 0);
                sprintf(key, D_004BB558, slot);
                sprintf(D_00533790, D_004BB568, 0x11, nGlobalization_GetString_charP(key), 0x10);
                for (k = 0; k < strlen(D_00533790); k++)
                    D_00533790[k] = Libc_Toupper(D_00533790[k]);
                GuiTextWidget_SetText(s->rows[slot][1], D_00533790, 0);
                GuiTextWidget_SetText(s->rows[slot][14], D_00533790, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1B));
                GuiTextWidget_SetText(s->rows[slot][2], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1C));
                GuiTextWidget_SetText(s->rows[slot][3], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x14));
                GuiTextWidget_SetText(s->rows[slot][4], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x13));
                GuiTextWidget_SetText(s->rows[slot][5], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x16));
                GuiTextWidget_SetText(s->rows[slot][6], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x12));
                GuiTextWidget_SetText(s->rows[slot][7], buf, 0);
                d = cAgentData_GetStat(a, 0x1B);
                if (d == 0) d = 1;
                sprintf(buf, D_004BB580, cAgentData_GetStat(a, 0x1C) * 100 / d);
                GuiTextWidget_SetText(s->rows[slot][9], buf, 0);
                d = cAgentData_GetStat(a, 0x1D);
                if (d == 0) d = 1;
                sprintf(buf, D_004BB580, cAgentData_GetStat(a, 0x1E) * 100 / d);
                GuiTextWidget_SetText(s->rows[slot][8], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x18));
                GuiTextWidget_SetText(s->rows[slot][10], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x19));
                GuiTextWidget_SetText(s->rows[slot][11], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1A));
                GuiTextWidget_SetText(s->rows[slot][12], buf, 0);
            } else {
                int j;
                GuiTextWidget_SetText(s->rows[slot][0], D_004BB530, 0);
                for (j = 2; j < 13; j++) GuiTextWidget_SetText(s->rows[slot][j], D_004BB588, 0);
                for (j = 15; j < 20; j++) GuiTextWidget_SetText(s->rows[slot][j], D_004BB530, 0);
            }
            if (s->skel[slot]->inv.arr[0]) {
                WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, s->skel[slot]->inv.arr[0]->id);
                s->skel[slot]->inv.Slot(d->slot) = s->skel[slot]->inv.Slot(0);
            }
            SHOW_ITEM(s->rows[slot][15], s->skel[slot]->inv.arr[3])
            SHOW_ITEM(s->rows[slot][16], s->skel[slot]->inv.arr[2])
            SHOW_ITEM(s->rows[slot][17], s->skel[slot]->inv.arr[5])
            SHOW_ITEM(s->rows[slot][18], s->skel[slot]->inv.arr[8])
            SHOW_ITEM(s->rows[slot][19], s->skel[slot]->inv.arr[9])
            if (s->skel[slot]->inv.arr[0]) {
                WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, s->skel[slot]->inv.arr[0]->id);
                s->skel[slot]->inv.Slot(d->slot) = 0;
            }
        } else {
            s->skel[n]->b2C3A = -1;
            if (s->rows[n][0]) {
                GuiTextWidget_SetText(s->rows[n][0], D_004BB530, 0);
                for (i = 2; i < 13; i++) GuiTextWidget_SetText(s->rows[n][i], D_004BB588, 0);
                for (i = 15; i < 20; i++) GuiTextWidget_SetText(s->rows[n][i], D_004BB530, 0);
            }
        }
        if (s->f230[n][0]) {
            if (p) s->f230[n][0]->flags |= 2;
            else s->f230[n][0]->flags &= ~2;
        }
        if (s->f230[n][1]) {
            if (p) s->f230[n][1]->flags |= 2;
            else s->f230[n][1]->flags &= ~2;
        }
    }
    }
    if (s->b60) {
        int m;
        for (m = 0; m < 4; m++) {
            if (s->f48[m]) {
                Player_35BFB0* p = cNetObj_GetPlayer(m);
                if (p) {
                    if (p->b14) {
                        s->f48[m]->flags &= ~2;
                    } else {
                        int idx;
                        s->f48[m]->flags |= 2;
                        if (g_IsMultiplayer) {
                            bool ok = false;
                            if (p->f58 && p->f58->IsActive()) ok = true;
                            if (ok) idx = Slot_35BFB0(p);
                            else idx = -1;
                        } else {
                            idx = 0;
                        }
                        GuiWidget_SendMessage(s, s->f48[m], 0xB, s->f58 + (int)((float)(s->f5C - s->f58) * (1.0f - cDME_GetConnectionStatus(idx))), 0);
                    }
                } else {
                    s->f48[m]->flags &= ~2;
                }
            }
        }
    }
    if (Gui_Canvas()->f2C->f8 != s) {
        s->f228 = 0.0f;
    } else {
        float k = kPi_35BFB0 * (dt / 30.0f); s->f1C8 += k * s->f228;
        if (s->f1C8 > 3.1415927f)
            s->f1C8 -= 6.2831855f;
        else if (s->f1C8 < -3.1415927f)
            s->f1C8 += 6.2831855f;
    }
    GuiWidget_onAdvanceTime(s, dt);
}
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035BFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035BFB0 */

/* merge_units: begin func_0035CB30 */
#pragma push /* merge_units */
extern char* nGlobalization_GetString_charP(char* key);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
#if 0 /* merge_units */
extern char Libc_Toupper(int c);
#endif /* merge_units */
#define Libc_Toupper(a0) (Libc_Toupper((char)(a0))) /* merge_units */

char* GetCodename(int n)
{
    char buf[32];
    unsigned int i;
    sprintf(buf, D_004BB558, n);
    sprintf(D_00533790, D_004BB568, 0x11, nGlobalization_GetString_charP(buf), 0x10);
    for (i = 0; i < strlen(D_00533790); i++) D_00533790[i] = Libc_Toupper(D_00533790[i]);
    return D_00533790;
}
#undef strlen /* merge_units */
#undef Libc_Toupper /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035CB30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035CB30 */

/* merge_units: begin func_0035CBF0 */
#pragma push /* merge_units */
#pragma cplusplus on
class W35CBF0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35CBF0 { char pad[0x224]; int a224; char pad228[4]; unsigned char a22C; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004A9870[];
void GuiWidget_onWake(S35CBF0* o);
W35CBF0* GuiWidget_FindChild_charP(void* self, char* name);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W35CBF0* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_35BFB0 *)(a0), (a1), (a2))) /* merge_units */

void GuiScoresEquip_onWake(S35CBF0* o);
}
static inline W35CBF0* cast35CBF0(W35CBF0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void GuiScoresEquip_onWake(S35CBF0* o)
{
    W35CBF0* a;
    W35CBF0* b;
    W35CBF0* c;
    GuiWidget_onWake(o);
    o->a224 = 0;
    a = GuiWidget_FindChild_charP(o, D_004BB4D8);
    b = GuiWidget_FindChild_charP(o, D_004BB4E8);
    if (a) a->a14 |= 2;
    if (b) b->a14 &= ~2;
    c = cast35CBF0(GuiWidget_FindChild_charP(o, D_004BB500));
    if (c) {
        char* t = nGlobalization_GetString_charP(D_004BB520);
        GuiTextWidget_SetText(c, t ? t : D_004BB530, 0);
    }
    o->a22C = 1;
}
#undef GuiTextWidget_SetText /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035CBF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035CBF0 */
