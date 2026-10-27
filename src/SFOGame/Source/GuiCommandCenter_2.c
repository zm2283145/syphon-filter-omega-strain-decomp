/*
 * SFOGame/Source/GuiCommandCenter: 1 file, 00294190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_294190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiCommandCenter_GetClassName();
extern "C" void GuiCommandCenter_IsClass();
extern "C" void GuiCommandCenter_FindFirstFocus();
extern "C" void GuiCommandCenter_SaveDone();
extern "C" void GuiCommandCenter_onInput();
extern "C" void GuiCommandCenter_onMessage();
extern "C" void GuiCommandCenter_onAdvanceTime();
extern "C" void GuiCommandCenter_Deactivate();
extern "C" void GuiCommandCenter_Activate();
extern "C" void GuiCommandCenter_Wake();
extern "C" void GuiCommandCenter_onAdd();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DD4F0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* String_Dtor_138350(void* self, short deleteFlag);
void GuiLobbyScreen_dtor(void* self, int flags);
void operator_delete(void* p);
}
struct O294190 { void* vtable; char pad[0x200]; char items[0x11][0xC]; };
extern "C" O294190* GuiCommandCenter_dtor(O294190* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD4F0);
        __destroy_array(self->items, (void*)String_Dtor_138350, 0xC, 0x11);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DD4F0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCommandCenter_dtor, (void*)GuiCommandCenter_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiCommandCenter_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiCommandCenter_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiCommandCenter_onAdvanceTime, (void*)GuiCommandCenter_onMessage, (void*)GuiWidget_Load, (void*)GuiCommandCenter_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiCommandCenter_GetClassName, (void*)GuiCommandCenter_IsClass, (void*)GuiCommandCenter_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiCommandCenter_Activate, (void*)GuiCommandCenter_Deactivate, (void*)0x0 };
static inline void merge_flush_GuiSaveAgentWidget_294190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_294190 */
