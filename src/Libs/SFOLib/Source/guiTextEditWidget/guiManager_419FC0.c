/*
 * main/guiManager: 2 files, 00419FC0-0041A060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "string_int_pair_copy_ctor.h"

/* Copy constructor of a string/int pair. */
DEFINE_STRING_INT_PAIR_COPY_CTOR(std_pair_cString_cFontPtr_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00419FC0 */

/* merge_units: begin func_0041A060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiTextEditWidget_GetClassName();
extern "C" void GuiTextEditWidget_IsClass();
extern "C" void GuiTextEditWidget_onRender();
extern "C" void GuiTextEditWidget_onAdvanceTime();
extern "C" void GuiTextEditWidget_UpdateText();
extern "C" void GuiTextEditWidget_onInput();
extern "C" void GuiTextEditWidget_Load();
extern "C" void GuiTextEditWidget_onWake();
extern "C" void GuiTextWidget_onSleep();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern void * const D_004E0A40[];
void* GuiTextWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiTextEditWidget_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0A40);
        GuiTextWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0A40[24] = { (void*)0x0, (void*)0x0, (void*)GuiTextEditWidget_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTextEditWidget_onWake, (void*)GuiTextWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiTextEditWidget_onInput, (void*)GuiTextEditWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiTextEditWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiTextEditWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiTextEditWidget_GetClassName, (void*)GuiTextEditWidget_IsClass, (void*)GuiTextEditWidget_UpdateText };
#pragma pop /* merge_units */
/* merge_units: end func_0041A060 */
