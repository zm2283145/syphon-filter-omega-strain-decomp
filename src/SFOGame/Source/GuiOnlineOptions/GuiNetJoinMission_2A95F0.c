#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiOnlineOptions_GetClassName();
extern "C" void GuiOnlineOptions_IsClass();
extern "C" void GuiOnlineOptions_SaveDone();
extern "C" void GuiOnlineOptions_onMessage();
extern "C" void GuiOnlineOptions_HandleInput();
extern "C" void GuiOnlineOptions_Deactivate();
extern "C" void GuiOnlineOptions_Activate();
extern "C" void GuiOnlineOptions_onAdd();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiLobbyScreen_onAdvanceTime();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
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
extern void * const D_004DDAF0[];
void* SFOLobbyList_dtor(void* self, short deleteFlag);
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O2A95F0 { void* vtable; char pad[0x9C]; char member[4]; };
extern "C" O2A95F0* GuiOnlineOptions_dtor(O2A95F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DDAF0);
        SFOLobbyList_dtor(self->member, -1);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDAF0[28] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineOptions_dtor, (void*)GuiOnlineOptions_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiOnlineOptions_HandleInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiLobbyScreen_onAdvanceTime, (void*)GuiOnlineOptions_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiOnlineOptions_GetClassName, (void*)GuiOnlineOptions_IsClass, (void*)GuiOnlineOptions_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiOnlineOptions_Activate, (void*)GuiOnlineOptions_Deactivate, (void*)0x0 };
