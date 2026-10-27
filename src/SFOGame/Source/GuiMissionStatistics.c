/*
 * SFOGame/Source/GuiMissionStatistics: 1 file, 0034F2D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034F2D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiMissionStatistics_GetClassName();
extern "C" void GuiPersonnelScreen_ItemGainFocus();
extern "C" void GuiPersonnelScreen_PopulateList();
extern "C" void GuiMissionStatistics_IsClass();
extern "C" void GuiMissionStatistics_ItemAction();
extern "C" void GuiMissionStatistics_onMessage();
extern "C" void GuiMissionStatistics_onInput();
extern "C" void GuiMissionStatistics_onSleep();
extern "C" void GuiMissionStatistics_onWake();
extern "C" void GuiMissionStatistics_onAdd();
extern "C" void GuiPersonnelScreen_PreviousScreen();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DEE70[];
extern char D_004DF0B0[];
void* std_vector_deleter_MissionStats_dtor(void* self, short deleteFlag);
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiMissionStatistics_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEE70);
        char* member = (char*)self + (0x70);
        if (member) {
            if (member) {
                if (member)
                    std_vector_deleter_MissionStats_dtor(member, 0);
            }
        }
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEE70[28] = { (void*)0x0, (void*)0x0, (void*)GuiMissionStatistics_dtor, (void*)GuiMissionStatistics_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMissionStatistics_onWake, (void*)GuiMissionStatistics_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMissionStatistics_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiMissionStatistics_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMissionStatistics_GetClassName, (void*)GuiMissionStatistics_IsClass, (void*)GuiPersonnelScreen_PopulateList, (void*)GuiPersonnelScreen_ItemGainFocus, (void*)GuiMissionStatistics_ItemAction, (void*)GuiPersonnelScreen_PreviousScreen, (void*)0x0 };
static inline void merge_flush_func_0034F2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F2D0 */
