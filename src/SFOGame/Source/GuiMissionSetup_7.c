/*
 * SFOGame/Source/GuiMissionSetup: 6 files, 002A1590-002A19C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1590 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x40]; void* list; } Owner40;
typedef struct { char pad[0xDC]; void* widget; char padE0[0xF4 - 0xE0]; Owner40* owner; } Obj2A;
extern void* GetNext(void* list, int a1, int a2, void* item);
#if 0 /* merge_units */
extern void GuiMissionSetup_UpdateTextLabels(Obj2A* self);
#endif /* merge_units */
void GuiMissionSetup_UpdateTextLabels(); /* merge_units */

extern void* Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* widget, void* ctx, int a2, int a3, int a4);

/* Adds item to the owner's list, refreshes self and pokes the widget with event 0x10. */
void GuiMissionSetup_CycleNumAgents(Obj2A* self, void* item)
{
    self->owner->list = GetNext(self->owner->list, 2, 4, item);
    GuiMissionSetup_UpdateTextLabels(self);
    GuiWidget_SendMessage(self->widget, Gui_Canvas(), 0x10, 0, 0);
}
static inline void merge_flush_func_002A1590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1590 */

/* merge_units: begin func_002A1600 */
#pragma push /* merge_units */
typedef struct State2A1 {
    char pad[0x45];
    unsigned char mode;
} State2A1;

typedef struct Obj2A1 {
    char pad[0xE0];
    int target;
    char pad2[0x10];
    State2A1* state;
} Obj2A1;

#if 0 /* merge_units */
extern int GetNext(int mode, int a, int b, int c);
#endif /* merge_units */
#define GetNext(a0, a1, a2, a3) ((int)GetNext((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */


#if 0 /* merge_units */
extern void GuiMissionSetup_UpdateTextLabels(Obj2A1* self);
#endif /* merge_units */
void GuiMissionSetup_UpdateTextLabels(); /* merge_units */


#if 0 /* merge_units */
extern int Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((int)Gui_Canvas()) /* merge_units */


#if 0 /* merge_units */
extern void GuiWidget_SendMessage(int target, int value, int a, int b, int c);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */



/* Advances the state's mode byte, refreshes, then notifies the target. */
void GuiMissionSetup_CycleJoinFilter(Obj2A1* self, int arg) {
    self->state->mode = GetNext(self->state->mode, 0, 2, arg);
    GuiMissionSetup_UpdateTextLabels(self);
    GuiWidget_SendMessage(self->target, Gui_Canvas(), 0x10, 0, 0);
}
#undef GetNext /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_002A1600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1600 */

/* merge_units: begin func_002A1670 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int value; char pad44; unsigned char id; } Info;
typedef struct { char pad[0xE8]; void* valueLabel; void* nameLabel; char pad2[4]; Info* info; } Panel;
extern char D_004AAFF0[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* nGlobalization_GetString_charP(const char* key);
extern void GuiTextWidget_SetText(void* label, const char* text, int flags);
/* Fills the panel's name (localised, with fallback) and value labels. */
void GuiMissionSetup_UpdateTextLabels(Panel* p)
{
    char buf[0x20];
    char* text;
    sprintf(buf, "FilterType%d", p->info->id);
    text = nGlobalization_GetString_charP(buf);
    GuiTextWidget_SetText(p->nameLabel, text ? text : D_004AAFF0, 0);
    sprintf(buf, "%d", p->info->value);
    GuiTextWidget_SetText(p->valueLabel, buf, 0);
}
static inline void merge_flush_func_002A1670(void) {} /* merge_units */
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
extern void* cDME_GetLobby(void);
extern void SFOLobby_LobbyScreenExit(void* p);
extern void SFOLobbyList_ClearAndCompactList(M2A1700* m);
void GuiMissionSetup_Deactivate(S2A1700* s)
{
    if (s->active) {
        if (s->hasFx) {
            void* p = cDME_GetLobby();
            if (p)
                SFOLobby_LobbyScreenExit(p);
            s->hasFx = 0;
        }
        SFOLobbyList_ClearAndCompactList(&s->m88);
        SFOLobbyList_ClearAndCompactList(&s->mA4);
        SFOLobbyList_ClearAndCompactList(&s->mC0);
        s->active = 0;
    }
}
static inline void merge_flush_func_002A1700(void) {} /* merge_units */
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
void cGameFrontEnd_LobbyCallback(void);
Obj_002A1780* GuiWidget_FindChild_charP(Self_002A1780* self, char* name);
#if 0 /* merge_units */
void GuiTextWidget_SetText(void* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((a0), (const char *)(a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void GuiMissionSetup_UpdateTextLabels(Self_002A1780* self);
#endif /* merge_units */
#define GuiMissionSetup_UpdateTextLabels(a0) (GuiMissionSetup_UpdateTextLabels((Panel *)(a0))) /* merge_units */


#if 0 /* merge_units */
Game_002A1780* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((Game_002A1780 *)cDME_GetLobby()) /* merge_units */


void SFOLobby_MissionScreenExit(Game_002A1780* g);
unsigned char SFOLobby_LobbyScreenStart(Game_002A1780* g, void* cb, void* a, void* b, void* c);
char* GuiLobbyScreen_GetLobbyString(Self_002A1780* self, int a, int b, int c, int d, int e);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, Self_002A1780* d, int e);
}

static inline Obj_002A1780* AsA(Obj_002A1780* obj) { return (obj && obj->IsA(D_004A7520)) ? obj : 0; }
#define CAST(p) p = AsA(p)
extern "C" void GuiMissionSetup_Activate(Self_002A1780* self)
{
    Obj_002A1780* p;
    Game_002A1780* g;
    if (self->b80)
        return;
    self->pDC = GuiWidget_FindChild_charP(self, D_0048BA40);
    self->pE0 = GuiWidget_FindChild_charP(self, D_0048BA48);
    self->pE4 = GuiWidget_FindChild_charP(self, D_0048BA60);
    p = GuiWidget_FindChild_charP(self, D_0048BA50);
    CAST(p);
    self->pE8 = p;
    p = GuiWidget_FindChild_charP(self, D_0048BA58);
    CAST(p);
    self->pEC = p;
    p = GuiWidget_FindChild_charP(self, D_0048BA68);
    CAST(p);
    if (p) {
        asm { .set reorder }
        GuiTextWidget_SetText(p, D_004FFC04 + 0x1C8, 0);
    }
    GuiMissionSetup_UpdateTextLabels(self);
    self->bF8 = 0;
    g = cDME_GetLobby();
    if (g) {
        if (g->state == 4) {
            asm { .set reorder }
            SFOLobby_MissionScreenExit(g);
        } else {
            asm { .set reorder }
            if (g->state != 5) {
                self->bF8 = SFOLobby_LobbyScreenStart(g, (void*)cGameFrontEnd_LobbyCallback, self->s88, self->sA4, self->sC0);
                if (!self->bF8) {
                    asm { .set reorder }
                    char* ui = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(ui, 2, D_004AAFF0, GuiLobbyScreen_GetLobbyString(self, 0x5A, 0, 0, 0, 0), self, 0xB);
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
#undef GuiMissionSetup_UpdateTextLabels /* merge_units */
#undef cDME_GetLobby /* merge_units */
static inline void merge_flush_func_002A1780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1780 */

/* merge_units: begin GuiMissionSetup_2A19C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char GuiMissionSetup_vtable[];   /* GuiMissionSetup vtable */
#if 0 /* merge_units */
extern GameMachine* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(GameMachine **)&D_004FFC04) /* merge_units */

extern GuiScreen* GuiLobbyScreen_ctor(GuiScreen* self);
extern GuiSlot* SFOLobbyList_ctor(GuiSlot* slot);

/* GuiMissionSetup constructor. */
GuiMissionSetup* GuiMissionSetup_ctor(GuiMissionSetup* self) {
    GuiLobbyScreen_ctor(&self->base);
    self->base.base.base.vtable = GuiMissionSetup_vtable;
    SFOLobbyList_ctor(&self->slots[0]);
    SFOLobbyList_ctor(&self->slots[1]);
    SFOLobbyList_ctor(&self->slots[2]);
    self->base.screenId = 6;
    self->unkDC = 0;
    self->unkE0 = 0;
    self->unkE4 = 0;
    self->unkE8 = 0;
    self->unkEC = 0;
    self->machine = 0;
    self->machineData = 0;
    self->unkF8 = 0;
    self->machine = D_004FFC04;
    self->machineData = self->machine->data140;
    return self;
}
#undef D_004FFC04 /* merge_units */
static inline void merge_flush_GuiMissionSetup_2A19C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMissionSetup_2A19C0 */
