/*
 * SFOGame/Source/GuiAgentLoad: 1 file, 00292760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_292760 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAgentSave_GetClassName();
extern "C" void GuiAgentSave_IsClass();
extern "C" void GuiAgentSave_onInput();
extern "C" void GuiAgentSave_SaveDone();
extern "C" void GuiAgentSave_onMessage();
extern "C" void GuiAgentSave_onWake();
extern "C" void GuiAgentDirectoryWidget_onAdvanceTime();
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
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern void * const D_004DD3A0[];
extern char D_004DD460[];
extern char D_004E1220[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable3Object* GuiAgentSave_dtor(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD3A0);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                GuiWidget_dtor(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD3A0[24] = { (void*)0x0, (void*)0x0, (void*)GuiAgentSave_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiAgentSave_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiAgentSave_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiAgentDirectoryWidget_onAdvanceTime, (void*)GuiAgentSave_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAgentSave_GetClassName, (void*)GuiAgentSave_IsClass, (void*)GuiAgentSave_SaveDone };
static inline void merge_flush_GuiSaveAgentWidget_292760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_292760 */
