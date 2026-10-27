/*
 * SFOGame/Source/GuiMissionStatistics: 11 files, 0034F720-0034F900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034F720 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: nested member at 0x4C, then the base destructor. */
extern "C" {
void operator_delete(void* allocation);
void* std_vector_deleter_StatsRequirement_dtor(void* self, short deleteFlag);
void* String_Dtor(void* self, short deleteFlag);
void* MissionStats_dtor(void* self, short deleteFlag);
}
void* MissionStats_dtor(void* self, short deleteFlag)
{
    if (self) {
        char* m = (char*)self + 0x4C;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_StatsRequirement_dtor(m, 0);
            }
        }
        if (self)
            String_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0034F720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F720 */

/* merge_units: begin func_0034F7A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

DEFINE_MEMBER_DTOR_CHAIN(cArray_StatsRequirement_dtor, std_vector_deleter_StatsRequirement_dtor)
static inline void merge_flush_func_0034F7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F7A0 */

/* merge_units: begin func_0034F810 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern int std_vector_imp_StatsRequirement_ctor(FlaggedRel*);
#endif /* merge_units */
Rel * std_vector_imp_StatsRequirement_ctor(); /* merge_units */


/* FlaggedRel constructor. */
FlaggedRel* cArray_StatsRequirement_ctor(FlaggedRel* self) {
    std_vector_imp_StatsRequirement_ctor(self);
    self->unk0C = 1;
    return self;
}
static inline void merge_flush_func_0034F810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F810 */

/* merge_units: begin func_0034F840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(std_vector_StatsRequirement_dtor, std_vector_deleter_StatsRequirement_dtor)
static inline void merge_flush_func_0034F840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F840 */

/* merge_units: begin func_0034F8A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

DEFINE_DIRECT_BASE_DTOR(std_vector_imp_StatsRequirement_dtor, std_vector_deleter_StatsRequirement_dtor)
static inline void merge_flush_func_0034F8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F8A0 */

/* merge_units: begin func_0034F900 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0034F900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F900 */

/* merge_units: begin func_0034F940 */
#pragma push /* merge_units */
extern void* D_0048C160[];
extern char g_Game[];
extern void* cGameSystem_GetAgentData(void* list, int idx);
extern __int128 nGlobalization_MakeTag(void* p);
extern int HasBonusLevel__10cAgentDataF1(void* agent, __int128 v);
extern void* Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* self, void* mgr, int a, int b, int c);
extern void GuiPersonnelScreen_OpenSubMenu(void* self, char* s, int a, int idx, int b, int c);
void GuiMissionStatistics_ItemAction(void* self, int idx)
{
    void* p = idx <= 16 ? D_0048C160[idx] : 0;
    if (p) {
        void* ag = cGameSystem_GetAgentData(g_Game, -1);
        if (HasBonusLevel__10cAgentDataF1(ag, nGlobalization_MakeTag(p))) {
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 1, 0);
            GuiPersonnelScreen_OpenSubMenu(self, "CSUBMENU", 6, idx, 0, 0);
            return;
        }
    }
    GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 4, 0);
}
static inline void merge_flush_func_0034F940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F940 */

/* merge_units: begin func_0034FA40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics message handler (vtable D_004DEE70 slot 13).
 */


extern int GuiPersonnelScreen_onMessage(GuiMissionStatistics* self, int a1, int msg, int value);

/* GuiMissionStatistics message handler (vtable slot 13): 0x3000 stores `value`, everything else goes to GuiPersonnelScreen_onMessage. */
int GuiMissionStatistics_onMessage(GuiMissionStatistics* self, int a1, int msg, int value) {
    if ((msg & 0xFFFF) == 0x3000) {
        self->unk80 = value;
        return 1;
    }
    return GuiPersonnelScreen_onMessage(self, a1, msg, value);
}
static inline void merge_flush_func_0034FA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034FA40 */

/* merge_units: begin func_0034FA80 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E34FA80;
extern "C" {
void* Gui_Manager(void);
void* Gui_Canvas(void);
int GuiManager_OpenGui(void* mgr, char* a, char* b);
void GuiCanvas_Transition(void* mgr, void* self, int snd);
bool GuiPersonnelScreen_onInput(void* self, E34FA80* e);
bool GuiMissionStatistics_onInput(void* self, E34FA80* e);
}
bool GuiMissionStatistics_onInput(void* self, E34FA80* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        int s = GuiManager_OpenGui(Gui_Manager(), "GuiCommandCenter", "cmdcentr");
        GuiCanvas_Transition(Gui_Canvas(), self, s);
        return 1;
    }
    return GuiPersonnelScreen_onInput(self, e);
}
static inline void merge_flush_func_0034FA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034FA80 */

/* merge_units: begin func_0034FB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics virtual (vtable D_004DEE70 slot 6).
 */


extern int GuiWidget_onSleep(GuiMissionStatistics*);   /* GuiWidget implementation */

int GuiMissionStatistics_onSleep(GuiMissionStatistics* self) {
    return GuiWidget_onSleep(self);
}
static inline void merge_flush_func_0034FB40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034FB40 */

/* merge_units: begin func_0034FB50 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; void* a6C; char pad70[0x10]; int a80; } S34FB50;
extern void GuiMissionStatistics_UpdateMissionStats(S34FB50* o);
extern void GuiPersonnelScreen_onWake(S34FB50* o);
extern void GuiArrayWidget_SetSelected(void* p, int a, int b);
void GuiMissionStatistics_onWake(S34FB50* o)
{
    GuiMissionStatistics_UpdateMissionStats(o);
    GuiPersonnelScreen_onWake(o);
    if (o->a6C) GuiArrayWidget_SetSelected(o->a6C, 0, o->a80);
}
static inline void merge_flush_func_0034FB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034FB50 */
