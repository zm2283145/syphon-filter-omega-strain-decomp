/*
 * SFOGame/Source/GuiRatings: 1 file, 0034D1D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034D1D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiPersonnelScreen_ItemGainFocus();
extern "C" void GuiRatings_GetClassName();
extern "C" void GuiRatings_IsClass();
extern "C" void GuiPersonnelScreen_PopulateList();
extern "C" void GuiPersonnelScreen_ItemAction();
extern "C" void GuiRatings_onInput();
extern "C" void GuiRatings_onMessage();
extern "C" void GuiRatings_onRender();
extern "C" void GuiRatings_onSleep();
extern "C" void GuiRatings_FindFirstFocus();
extern "C" void GuiRatings_onWake();
extern "C" void GuiRatings_onAdd();
extern "C" void GuiPersonnelScreen_PreviousScreen();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DECC0[];
extern char D_004DF0B0[];
void* func_00299360(void* self, short deleteFlag);
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiRatings_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DECC0);
        char* member = (char*)self + (0xCC);
        if (member) {
            if (member) {
                if (member)
                    func_00299360(member, 0);
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
void * const D_004DECC0[28] = { (void*)0x0, (void*)0x0, (void*)GuiRatings_dtor, (void*)GuiRatings_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiRatings_onWake, (void*)GuiRatings_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiRatings_onInput, (void*)GuiRatings_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiRatings_onMessage, (void*)GuiWidget_Load, (void*)GuiRatings_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiRatings_GetClassName, (void*)GuiRatings_IsClass, (void*)GuiPersonnelScreen_PopulateList, (void*)GuiPersonnelScreen_ItemGainFocus, (void*)GuiPersonnelScreen_ItemAction, (void*)GuiPersonnelScreen_PreviousScreen, (void*)0x0 };
static inline void merge_flush_func_0034D1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034D1D0 */
