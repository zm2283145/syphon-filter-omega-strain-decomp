/*
 * main/GuiMissionStatistics: 6 files, 0034F900-0034FB50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034F900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Rel* std_vector_imp_StatsRequirement_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rec34F920* MissionStats_StatData_ctor(Rec34F920* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034F900 */

/* merge_units: begin func_0034F940 */
#pragma push /* merge_units */
#include "types.h"
extern void* D_0048C160[];
extern char g_Game[];
extern void* Agent_GetSelected(void* list, int idx);
extern __int128 StringPool_MakeKey(void* p);
extern int AgentData_IsLevelDone(void* agent, __int128 v);
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* self, void* mgr, int a, int b, int c);
extern void GuiPersonnelScreen_OpenMenu(void* self, char* s, int a, int idx, int b, int c);
void GuiMissionStatistics_Select(void* self, int idx)
{
    void* p = idx <= 16 ? D_0048C160[idx] : 0;
    if (p) {
        void* ag = Agent_GetSelected(g_Game, -1);
        if (AgentData_IsLevelDone(ag, StringPool_MakeKey(p))) {
            GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 1, 0);
            GuiPersonnelScreen_OpenMenu(self, "CSUBMENU", 6, idx, 0, 0);
            return;
        }
    }
    GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 4, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034F940 */

/* merge_units: begin func_0034FA40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics message handler (vtable D_004DEE70 slot 13).
 */


extern int GuiPersonnelScreen_HandleEvent(GuiMissionStatistics* self, int a1, int msg, int value);

/* GuiMissionStatistics message handler (vtable slot 13): 0x3000 stores `value`, everything else goes to GuiPersonnelScreen_HandleEvent. */
int GuiMissionStatistics_HandleEvent(GuiMissionStatistics* self, int a1, int msg, int value) {
    if ((msg & 0xFFFF) == 0x3000) {
        self->unk80 = value;
        return 1;
    }
    return GuiPersonnelScreen_HandleEvent(self, a1, msg, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FA40 */

/* merge_units: begin func_0034FA80 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E34FA80;
extern "C" {
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
int GuiManager_FindOrLoad(void* mgr, char* a, char* b);
void GuiStack_SwapScreens(void* mgr, void* self, int snd);
bool GuiPersonnelScreen_HandleInput(void* self, E34FA80* e);
bool GuiMissionStatistics_HandleInput(void* self, E34FA80* e);
}
bool GuiMissionStatistics_HandleInput(void* self, E34FA80* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        int s = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "cmdcentr");
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, s);
        return 1;
    }
    return GuiPersonnelScreen_HandleInput(self, e);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FA80 */

/* merge_units: begin func_0034FB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics virtual (vtable D_004DEE70 slot 6).
 */


extern int GuiWidget_BaseSleep(GuiMissionStatistics*);   /* GuiWidget implementation */

int GuiMissionStatistics_Sleep(GuiMissionStatistics* self) {
    return GuiWidget_BaseSleep(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FB40 */

/* merge_units: begin func_0034FB50 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; void* a6C; char pad70[0x10]; int a80; } S34FB50;
extern void GuiMissionStatistics_Refresh(S34FB50* o);
extern void GuiPersonnelScreen_Wake(S34FB50* o);
extern void GuiArrayWidget_Select(void* p, int a, int b);
void GuiMissionStatistics_Wake(S34FB50* o)
{
    GuiMissionStatistics_Refresh(o);
    GuiPersonnelScreen_Wake(o);
    if (o->a6C) GuiArrayWidget_Select(o->a6C, 0, o->a80);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FB50 */
