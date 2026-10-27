/*
 * SFOGame/Source/GuiRanks: 1 file, 0034E420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034E420 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiRanks_GetClassName();
extern "C" void GuiRanks_IsClass();
extern "C" void GuiRanks_PopulateList();
extern "C" void GuiRanks_ItemAction();
extern "C" void GuiRanks_ItemGainFocus();
extern "C" void GuiPersonnelScreen_PreviousScreen();
extern "C" void GuiPersonnelScreen_onMessage();
extern "C" void GuiPersonnelScreen_onInput();
extern "C" void GuiPersonnelScreen_onWake();
extern "C" void GuiPersonnelScreen_onAdd();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DED50[];
extern char D_004DF0B0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiRanks_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DED50);
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DED50[28] = { (void*)0x0, (void*)0x0, (void*)GuiRanks_dtor, (void*)GuiPersonnelScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiPersonnelScreen_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiPersonnelScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiPersonnelScreen_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiRanks_GetClassName, (void*)GuiRanks_IsClass, (void*)GuiRanks_PopulateList, (void*)GuiRanks_ItemGainFocus, (void*)GuiRanks_ItemAction, (void*)GuiPersonnelScreen_PreviousScreen, (void*)0x0 };
static inline void merge_flush_func_0034E420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E420 */
