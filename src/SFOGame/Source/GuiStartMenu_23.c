/*
 * SFOGame/Source/GuiStartMenu: 1 file, 00457280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00457280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWeaponStats_IsClass();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiArrayWidget_onElementLoseFocus();
extern "C" void GuiArrayWidget_onElementGainFocus();
extern "C" void GuiArrayWidget_onRowRender();
extern "C" void GuiArrayWidget_onColumnRender();
extern "C" void GuiArrayWidget_onRender();
extern "C" void GuiArrayWidget_onLoseFocus();
extern "C" void GuiArrayWidget_onGainFocus();
extern "C" void GuiTextArrayWidget_onSleep();
extern "C" void GuiTextArrayWidget_onWake();
extern "C" void GuiTextArrayWidget_SetSize();
extern "C" void GuiWeaponStats_HandleInput();
extern "C" void GuiWeaponStats_onElementRender();
extern "C" void GuiWeaponStats_onAdd();
extern "C" void GuiWeaponStats_GetClassName();
extern void * const D_004E1350[];
void* GuiTextArrayWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiWeaponStats_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1350);
        GuiTextArrayWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1350[32] = { (void*)0x0, (void*)0x0, (void*)GuiWeaponStats_dtor, (void*)GuiWeaponStats_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTextArrayWidget_onWake, (void*)GuiTextArrayWidget_onSleep, (void*)GuiArrayWidget_onGainFocus, (void*)GuiArrayWidget_onLoseFocus, (void*)GuiWeaponStats_HandleInput, (void*)GuiArrayWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiWeaponStats_GetClassName, (void*)GuiWeaponStats_IsClass, (void*)GuiTextArrayWidget_SetSize, (void*)GuiArrayWidget_onColumnRender, (void*)GuiArrayWidget_onRowRender, (void*)GuiWeaponStats_onElementRender, (void*)GuiArrayWidget_onElementGainFocus, (void*)GuiArrayWidget_onElementLoseFocus, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00457280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00457280 */
