/*
 * SFOGame/Source/GuiMissionSetup: 1 file, 002A0CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiOnlineOfflineSelect_2A0CF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiMissionSetup_GetClassName();
extern "C" void GuiMissionSetup_IsClass();
extern "C" void GuiMissionSetup_onMessage();
extern "C" void GuiMissionSetup_onInput();
extern "C" void GuiMissionSetup_Deactivate();
extern "C" void GuiMissionSetup_Activate();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiLobbyScreen_onAdvanceTime();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
extern "C" void GuiLobbyScreen_onAdd();
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
extern void * const GuiMissionSetup_vtable[];
void* SFOLobbyList_dtor(void* self, short deleteFlag);
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O002A0CF0 { void* vtable; char pad[0x84]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O002A0CF0* GuiMissionSetup_dtor(O002A0CF0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)GuiMissionSetup_vtable);
        SFOLobbyList_dtor(self->m2, -1);
        SFOLobbyList_dtor(self->m1, -1);
        SFOLobbyList_dtor(self->m0, -1);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiMissionSetup_vtable[28] = { (void*)0x0, (void*)0x0, (void*)GuiMissionSetup_dtor, (void*)GuiLobbyScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMissionSetup_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiLobbyScreen_onAdvanceTime, (void*)GuiMissionSetup_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMissionSetup_GetClassName, (void*)GuiMissionSetup_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiMissionSetup_Activate, (void*)GuiMissionSetup_Deactivate, (void*)0x0 };
static inline void merge_flush_GuiOnlineOfflineSelect_2A0CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiOnlineOfflineSelect_2A0CF0 */
