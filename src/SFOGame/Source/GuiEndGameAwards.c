/*
 * SFOGame/Source/GuiEndGameAwards: 1 file, 0045F250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_45F250 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiWidget_onInput();
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
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern "C" void GuiSaveAgentWidget_OnEvent();
extern "C" void GuiAutoSaver_GetClassName();
extern "C" void GuiAutoSaver_IsType();
extern "C" void GuiAutoSaver_SaveDone();
extern "C" void GuiAutoSaver_Wake();
extern void * const D_004E16D0[];
extern char D_004E1220[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiAutoSaver_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E16D0);
        if (self) {
            self->vtable = D_004E1220;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E16D0[24] = { (void*)0x0, (void*)0x0, (void*)GuiAutoSaver_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiAutoSaver_Wake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiSaveAgentWidget_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAutoSaver_GetClassName, (void*)GuiAutoSaver_IsType, (void*)GuiAutoSaver_SaveDone };
static inline void merge_flush_GuiGameScreen_45F250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_45F250 */
