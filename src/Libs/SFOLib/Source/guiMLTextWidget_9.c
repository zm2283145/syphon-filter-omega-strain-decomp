/*
 * Libs/SFOLib/Source/guiMLTextWidget: 1 file, 0043EE60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043EE60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiSliderWidget_IsClass();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onWake();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiSliderWidget_GetClassName();
extern "C" void GuiSliderWidget_onInput();
extern "C" void GuiSliderWidget_onLoseFocus();
extern "C" void GuiSliderWidget_onGainFocus();
extern "C" void GuiSliderWidget_onAdd();
extern void * const D_004E10C0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiSliderWidget_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E10C0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E10C0[24] = { (void*)0x0, (void*)0x0, (void*)GuiSliderWidget_dtor, (void*)GuiSliderWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiSliderWidget_onGainFocus, (void*)GuiSliderWidget_onLoseFocus, (void*)GuiSliderWidget_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiSliderWidget_GetClassName, (void*)GuiSliderWidget_IsClass, (void*)0x0 };
static inline void merge_flush_func_0043EE60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043EE60 */
