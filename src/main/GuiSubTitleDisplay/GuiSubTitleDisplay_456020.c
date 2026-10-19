/*
 * main/GuiSubTitleDisplay: 2 files, 00456020-00456100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Widget_456020 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};
typedef struct Panel_456020 {
    char pad0[0x14];
    unsigned short flags;      /* +0x14 */
    char pad16[0x60 - 0x16];
    int m60;                   /* +0x60 */
    char pad64[0x7C - 0x64];
    Widget_456020* m7C;        /* +0x7C */
} Panel_456020;
typedef struct Screen_456020 {
    char pad[0x48];
    Panel_456020* panel;       /* +0x48 */
} Screen_456020;
extern "C" char D_004C19A0[];
extern "C" char D_004C19B0[];
extern "C" char D_004C19C0[];
static void * const dat_00497980[1] = { (void*)D_004C19A0 };
static void * const dat_00497988[3] = { (void*)D_004C19B0, (void*)0x0, (void*)D_004C19C0 };
extern "C" char D_004AAE20[];
extern "C" char D_004AAE00[];
extern "C" void GuiWidget_Init(Screen_456020* self);
extern "C" Widget_456020* GuiWidget_FindChildByName(Screen_456020* self, int id);

extern "C" void GuiBriefingPane_Init(Screen_456020* self)
{
    Widget_456020* child;
    GuiWidget_Init(self);
    child = GuiWidget_FindChildByName(self, (*(int*)dat_00497980));
    child = (child && child->IsA(D_004AAE20)) ? child : 0;
    self->panel = (Panel_456020*)child;
    if (self->panel) {
        self->panel->m60 = 0;
        child = GuiWidget_FindChildByName(self, (*(int*)dat_00497988));
        child = (child && child->IsA(D_004AAE00)) ? child : 0;
        self->panel->m7C = child;
        self->panel->flags |= 0x80;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00456020 */

/* merge_units: begin func_00456100 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Manager {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Method68(void* obj); /* +0x68 */
};

extern void* g_Hud;
extern char g_Game[];
extern "C" Manager* Gui_GetScreenStack(void);
extern "C" void Hud_ClosePauseMenu(void* p);
extern "C" void Game_SetPaused(void* p, int n);

/* Hands self to the manager (virtual +0x68), then Hud_ClosePauseMenu(g_Hud) and Game_SetPaused(g_Game, 0). */
extern "C" void GuiStartMenu_CloseAll(void* self)
{
    Gui_GetScreenStack()->Method68(self);
    Hud_ClosePauseMenu(g_Hud);
    Game_SetPaused(g_Game, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456100 */
