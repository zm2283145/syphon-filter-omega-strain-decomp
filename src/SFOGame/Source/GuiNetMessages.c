/*
 * SFOGame/Source/GuiNetMessages: 1 file, 00346CC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346CC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiLobbyScreen_onAdvanceTime();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiNetMessages_GetClassName();
extern "C" void GuiNetMessages_IsClass();
extern "C" void GuiNetMessages_onMessage();
extern "C" void GuiNetMessages_onInput();
extern "C" void func_00347690();
extern "C" void func_003476B0();
extern "C" void GuiNetMessages_onWake();
extern "C" void GuiNetMessages_Init();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DEB10[];
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiNetMessages_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEB10);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEB10[28] = { (void*)0x0, (void*)0x0, (void*)GuiNetMessages_dtor, (void*)GuiNetMessages_Init, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiNetMessages_onWake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiNetMessages_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiLobbyScreen_onAdvanceTime, (void*)GuiNetMessages_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiNetMessages_GetClassName, (void*)GuiNetMessages_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)func_003476B0, (void*)func_00347690, (void*)0x0 };
static inline void merge_flush_func_00346CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346CC0 */
