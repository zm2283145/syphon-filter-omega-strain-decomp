/*
 * SFOGame/Source/GuiMapScreen: 1 file, 00464820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00464820 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiMapScreen_GetClassName();
extern "C" void GuiMapScreen_IsClass();
extern "C" void GuiMapScreen_onInput();
extern "C" void GuiMapScreen_onRender();
extern "C" void GuiMapScreen_onSleep();
extern "C" void GuiMapScreen_onWake();
extern "C" void GuiMapScreen_onAdd();
extern void * const D_004E18C0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiMapScreen_dtor_void_2(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E18C0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E18C0[24] = { (void*)0x0, (void*)0x0, (void*)GuiMapScreen_dtor_void_2, (void*)GuiMapScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMapScreen_onWake, (void*)GuiMapScreen_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMapScreen_onInput, (void*)GuiMapScreen_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMapScreen_GetClassName, (void*)GuiMapScreen_IsClass, (void*)0x0 };
static inline void merge_flush_func_00464820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00464820 */
