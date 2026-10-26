/*
 * main/GuiSubTitleDisplay: 2 files, 00456600-004566D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00456600 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int Loc_LookupText(...);                             
int GuiTextWidget_SetText(...);                   
void **GuiWidget_FindChildByName(...);                          
int sprintf(...);                           
extern int D_004A7520;
extern int D_004C1A38;
}
extern "C" void GuiStartMenu_SetCurrentOption(int arg0, int arg1) {
    int sp30[4];
    int temp_v0;
    void **var_s0;

    F_(arg0, 0xB0, int) = arg1;
    var_s0 = GuiWidget_FindChildByName(arg0, ((int*)"label_to_map"));
    var_s0 = ((var_s0 != NULL) && (((VC00456600 *)(var_s0))->v20(&D_004A7520) != 0)) ? var_s0 : NULL;
    if (var_s0 != NULL) {
        sprintf(sp30, ((int*)"StartMenuOpt%d"), arg1);
        temp_v0 = Loc_LookupText(sp30);
        if (temp_v0 != NULL) {
            GuiTextWidget_SetText(var_s0, temp_v0, 0);
            return;
        }
        GuiTextWidget_SetText(var_s0, &D_004C1A38, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00456600 */

/* merge_units: begin func_004566D0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_4566D0;
typedef struct { char pad[0x1C]; void* f1C; } Sel_4566D0;
typedef struct { char pad[0x20]; Sel_4566D0* sel; } Mgr_4566D0;
typedef struct { char pad[0xAC]; void* fAC; } O_4566D0;
extern "C" {
extern void* g_Hud;
extern unsigned char D_004FFBB7;
extern char g_Game[];
Mgr_4566D0* Gui_GetScreenStack(void);
void Hud_ClosePauseMenu(void* p);
void Game_SetPaused(void* p, int v);
int GuiObjectives_HandleInput(O_4566D0* o, Ev_4566D0* ev);
int GuiStartMenu_OnInput(O_4566D0* o, Ev_4566D0* ev);
}
static inline bool Down2_4566D0(Ev_4566D0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_4566D0(Ev_4566D0* e, int b) { return Down2_4566D0(e) && e->btn == b; }
static inline bool Plain2_4566D0(Ev_4566D0* e, int b) { return Btn2_4566D0(e, b) && e->b6 == 0; }

int GuiStartMenu_OnInput(O_4566D0* o, Ev_4566D0* ev)
{
    if (Plain2_4566D0(ev, 0x10) && Gui_GetScreenStack()->sel->f1C == o->fAC) {
        Hud_ClosePauseMenu(g_Hud);
        if (D_004FFBB7)
            Game_SetPaused(g_Game, 0);
        return 1;
    }
    if (Plain2_4566D0(ev, 0x800)) {
        Hud_ClosePauseMenu(g_Hud);
        if (D_004FFBB7)
            Game_SetPaused(g_Game, 0);
        return 1;
    }
    return GuiObjectives_HandleInput(o, ev);
}
#pragma pop /* merge_units */
/* merge_units: end func_004566D0 */
