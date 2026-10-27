/*
 * SFOGame/Source/GuiTitleScreen: 1 file, 00287D60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin tank_287D60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiTitleScreen_GetClassName();
extern "C" void GuiTitleScreen_IsClass();
extern "C" void GuiTitleScreen_onMessage();
extern "C" void GuiTitleScreen_onAdvanceTime();
extern "C" void GuiTitleScreen_onInput();
extern "C" void GuiTitleScreen_onWake();
extern "C" void GuiTitleScreen_onAdd();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DD0A0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiTitleScreen_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD0A0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD0A0[24] = { (void*)0x0, (void*)0x0, (void*)GuiTitleScreen_dtor, (void*)GuiTitleScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTitleScreen_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiTitleScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiTitleScreen_onAdvanceTime, (void*)GuiTitleScreen_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiTitleScreen_GetClassName, (void*)GuiTitleScreen_IsClass, (void*)0x0 };
static inline void merge_flush_tank_287D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end tank_287D60 */
