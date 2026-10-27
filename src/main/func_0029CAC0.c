#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiOnlineConnect_GetClassName();
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiOnlineConnect_IsClass();
extern "C" void GuiLobbyScreen_StartLobbyScreen();
extern "C" void GuiLobbyScreen_ExitLobbyScreen();
extern "C" void GuiOnlineConnect_Update();
extern "C" void GuiOnlineConnect_HandleEvent();
extern "C" void GuiOnlineConnect_onInput();
extern "C" void GuiOnlineConnect_onSleep();
extern "C" void GuiOnlineConnect_onWake();
extern "C" void GuiOnlineConnect_onRemove();
extern "C" void GuiOnlineConnect_onAdd();
extern "C" void GuiScreen_PollLobby();
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
extern "C" void GuiWidget_Load();
extern void * const GuiOnlineConnect_vtable[];
void* SFOLobbyList_dtor(void* self, short deleteFlag);
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O0029CAC0 { void* vtable; char pad[0x94]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O0029CAC0* GuiOnlineConnect_dtor(O0029CAC0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)GuiOnlineConnect_vtable);
        SFOLobbyList_dtor(self->m2, -1);
        SFOLobbyList_dtor(self->m1, -1);
        SFOLobbyList_dtor(self->m0, -1);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiOnlineConnect_vtable[28] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineConnect_dtor, (void*)GuiOnlineConnect_onAdd, (void*)GuiOnlineConnect_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiOnlineConnect_onWake, (void*)GuiOnlineConnect_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiOnlineConnect_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiOnlineConnect_Update, (void*)GuiOnlineConnect_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiOnlineConnect_GetClassName, (void*)GuiOnlineConnect_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiLobbyScreen_StartLobbyScreen, (void*)GuiLobbyScreen_ExitLobbyScreen, (void*)0x0 };
