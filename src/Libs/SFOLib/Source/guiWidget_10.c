/*
 * Libs/SFOLib/Source/guiWidget: 1 file, 00420B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiWidget_420B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiTextWidget_UpdateText();
extern "C" void GuiTextWidget_onRender();
extern "C" void GuiTextWidget_onSleep();
extern "C" void GuiTextWidget_Load();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiButtonWidget_GetClassName();
extern "C" void GuiButtonWidget_IsClass();
extern "C" void GuiButtonWidget_onWake();
extern "C" void GuiButtonWidget_onMessage();
extern "C" void GuiButtonWidget_onInput();
extern void * const D_004E0C00[];
void* GuiTextWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiButtonWidget_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0C00);
        GuiTextWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0C00[24] = { (void*)0x0, (void*)0x0, (void*)GuiButtonWidget_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiButtonWidget_onWake, (void*)GuiTextWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiButtonWidget_onInput, (void*)GuiTextWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiButtonWidget_onMessage, (void*)GuiTextWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiButtonWidget_GetClassName, (void*)GuiButtonWidget_IsClass, (void*)GuiTextWidget_UpdateText };
static inline void merge_flush_guiWidget_420B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiWidget_420B40 */
