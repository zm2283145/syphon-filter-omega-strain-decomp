/*
 * main/GuiOnlineOfflineSelect: 3 files, 002A1670-002A1780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1670 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x40]; int value; char pad44; unsigned char id; } Info;
typedef struct { char pad[0xE8]; void* valueLabel; void* nameLabel; char pad2[4]; Info* info; } Panel;
extern char D_004AAFF0[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(const char* key);
extern void GuiTextWidget_SetText(void* label, const char* text, int flags);
/* Fills the panel's name (localised, with fallback) and value labels. */
void func_002A1670(Panel* p)
{
    char buf[0x20];
    char* text;
    sprintf(buf, "FilterType%d", p->info->id);
    text = Loc_LookupText(buf);
    GuiTextWidget_SetText(p->nameLabel, text ? text : D_004AAFF0, 0);
    sprintf(buf, "%d", p->info->value);
    GuiTextWidget_SetText(p->valueLabel, buf, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A1670 */

/* merge_units: begin func_002A1700 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; } M2A1700;
typedef struct {
    char pad0[0x80];
    unsigned char active;
    char pad81[7];
    M2A1700 m88;
    M2A1700 mA4;
    M2A1700 mC0;
    char padDC[0xF8 - 0xDC];
    unsigned char hasFx;
} S2A1700;
extern void* DME_GetLobby(void);
extern void func_00451610(void* p);
extern void LobbyArray_Free(M2A1700* m);
void func_002A1700(S2A1700* s)
{
    if (s->active) {
        if (s->hasFx) {
            void* p = DME_GetLobby();
            if (p)
                func_00451610(p);
            s->hasFx = 0;
        }
        LobbyArray_Free(&s->m88);
        LobbyArray_Free(&s->mA4);
        LobbyArray_Free(&s->mC0);
        s->active = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002A1700 */

/* merge_units: begin func_002A1780 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct Obj_002A1780 {
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
};
struct Game_002A1780 { char pad[0x255C]; volatile int state; };
struct Self_002A1780 {
    char pad0[0x80];
    unsigned char b80;
    char pad81[7];
    char s88[0x1C];
    char sA4[0x1C];
    char sC0[0x1C];
    Obj_002A1780* pDC;
    Obj_002A1780* pE0;
    Obj_002A1780* pE4;
    Obj_002A1780* pE8;
    Obj_002A1780* pEC;
    char padF0[8];
    unsigned char bF8;
};
extern "C" {
extern char* D_0048BA40;
extern char* D_0048BA48;
extern char* D_0048BA50;
extern char* D_0048BA58;
extern char* D_0048BA60;
extern char* D_0048BA68;
extern char D_004A7520[];
extern char* D_004FFC04;
extern char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;
void App_CardWaitPoll(void);
Obj_002A1780* GuiWidget_FindChildByName(Self_002A1780* self, char* name);
#if 0 /* merge_units */
void GuiTextWidget_SetText(void* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((a0), (const char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void func_002A1670(Self_002A1780* self);
#endif /* merge_units */
#define func_002A1670(a0) (func_002A1670((Panel *)(a0))) /* merge_units */

#if 0 /* merge_units */
Game_002A1780* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((Game_002A1780 *)DME_GetLobby()) /* merge_units */

void func_004426B0(Game_002A1780* g);
unsigned char func_004518F0(Game_002A1780* g, void* cb, void* a, void* b, void* c);
char* func_0033CE30(Self_002A1780* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, Self_002A1780* d, int e);
}

static inline Obj_002A1780* AsA(Obj_002A1780* obj) { return (obj && obj->IsA(D_004A7520)) ? obj : 0; }
#define CAST(p) p = AsA(p)
extern "C" void func_002A1780(Self_002A1780* self)
{
    Obj_002A1780* p;
    Game_002A1780* g;
    if (self->b80)
        return;
    self->pDC = GuiWidget_FindChildByName(self, D_0048BA40);
    self->pE0 = GuiWidget_FindChildByName(self, D_0048BA48);
    self->pE4 = GuiWidget_FindChildByName(self, D_0048BA60);
    p = GuiWidget_FindChildByName(self, D_0048BA50);
    CAST(p);
    self->pE8 = p;
    p = GuiWidget_FindChildByName(self, D_0048BA58);
    CAST(p);
    self->pEC = p;
    p = GuiWidget_FindChildByName(self, D_0048BA68);
    CAST(p);
    if (p) {
        asm { .set reorder }
        GuiTextWidget_SetText(p, D_004FFC04 + 0x1C8, 0);
    }
    func_002A1670(self);
    self->bF8 = 0;
    g = DME_GetLobby();
    if (g) {
        if (g->state == 4) {
            asm { .set reorder }
            func_004426B0(g);
        } else {
            asm { .set reorder }
            if (g->state != 5) {
                self->bF8 = func_004518F0(g, (void*)App_CardWaitPoll, self->s88, self->sA4, self->sC0);
                if (!self->bF8) {
                    asm { .set reorder }
                    char* ui = D_004FFC04;
                    FrontEnd_OpenPopup(ui, 2, D_004AAFF0, func_0033CE30(self, 0x5A, 0, 0, 0, 0), self, 0xB);
                }
            }
        }
    }
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
    self->b80 = 1;
}
#undef GuiTextWidget_SetText /* merge_units */
#undef func_002A1670 /* merge_units */
#undef DME_GetLobby /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1780 */
