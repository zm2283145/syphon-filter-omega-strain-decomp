/*
 * SFOGame/Source/GuiMissionLobbyScreen: 3 files, 0033EE40-0033F050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033EE40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xA8]; int fa8; char pad2[0x54]; int f100; } O33E;
extern int cDME_GetLobby(void);
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern char* GuiLobbyScreen_GetLobbyString(O33E*, int, int, int, int, int);
extern void GuiKeyboard_Display(void*, char*, char*, O33E*, int, int, int);
extern char D_004B9C60[];
void GuiMissionLobbyScreen_SelectAgentChat(O33E* o, int* p) {
    void* w;
    if (!o->fa8 || !cDME_GetLobby()) return;
    o->f100 = p ? *p : 0;
    w = GuiManager_OpenGui(Gui_Manager(), "GuiKeyboard", "KEYBOARD");
    if (w) GuiKeyboard_Display(w, GuiLobbyScreen_GetLobbyString(o, 0x64, 0, 0, 0, 0), D_004B9C60, o, 0x40, 0x1D, 0);
}
static inline void merge_flush_func_0033EE40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033EE40 */

/* merge_units: begin func_0033EF10 */
#pragma push /* merge_units */
typedef struct { char pad[0x110]; int busy; } UI;
typedef struct O { char pad[0x88]; UI *ui; int pad8C; int mode; } O;
extern void *D_004FFC04;
extern void GuiMissionList_SetSelectMode(UI *ui);
extern void *Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void *mgr, UI *ui);
#if 0 /* merge_units */
extern char *GuiLobbyScreen_GetLobbyString(O *o, int a, char *b, char *c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((O33E *)(a0), (a1), (int)(a2), (int)(a3), (a4), (a5))) /* merge_units */

extern int cGameFrontEnd_PushMessageBox(void *ui, int a, char *b, char *c, void *d, int e);

int GuiMissionLobbyScreen_SelectAgent(O *o, unsigned char mode, int flag)
{
    o->mode = mode;
    if (o->ui) {
        int id;
        void *dlg;
        GuiMissionList_SetSelectMode(o->ui);
        if (o->ui->busy) {
            if (flag)
                GuiCanvas_SetFocus(Gui_Canvas(), o->ui);
            return 1;
        }
        switch (mode) {
        case 0: id = 0x11; break;
        case 1: id = 0x12; break;
        case 2: id = 0x10; break;
        case 3: id = 0x13; break;
        default: return 1;
        }        dlg = D_004FFC04;
        cGameFrontEnd_PushMessageBox(dlg, 2, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, id, 0, 0, 0, 0), 0, 0);
    }
    return 0;
}
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
static inline void merge_flush_func_0033EF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033EF10 */

/* merge_units: begin func_0033F050 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; unsigned int flags; } G3F050;
typedef struct { char d[0x1C]; } L3F050;
typedef struct {
    char p0[0x78]; unsigned char b78; char p79[0x88 - 0x79];
    void* p88; char p8c[0xA8 - 0x8C]; int fA8;
    L3F050 l0, l1, l2;
} T3F050;
extern void GuiScreen_Sleep(T3F050* self);
extern void func_002ACC80(void* p, int f);
extern void SFOLobbyList_ClearAndCompactList(L3F050* l);
#if 0 /* merge_units */
extern G3F050* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((G3F050 *)Gui_Canvas()) /* merge_units */

void GuiMissionLobbyScreen_onSleep(T3F050* self)
{
    GuiScreen_Sleep(self);
    self->fA8 = 0;
    if (self->p88)
        func_002ACC80(self->p88, 0);
    SFOLobbyList_ClearAndCompactList(&self->l0);
    SFOLobbyList_ClearAndCompactList(&self->l1);
    SFOLobbyList_ClearAndCompactList(&self->l2);
    self->b78 = 0;
    Gui_Canvas()->flags &= ~3;
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_0033F050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033F050 */
