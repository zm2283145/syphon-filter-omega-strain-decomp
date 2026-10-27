#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAccountLogin_IsClass();
extern "C" void GuiAccountLogin_GetClassName();
extern "C" void func_002891D0();
extern "C" void GuiAccountLogin_onInput();
extern "C" void GuiAccountLogin_onMessage();
extern "C" void GuiAccountLogin_Deactivate();
extern "C" void GuiAccountLogin_Activate();
extern "C" void GuiAccountLogin_Wake();
extern "C" void GuiAccountLogin_onAdd();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiLobbyScreen_onAdvanceTime();
extern "C" void GuiScreen_Sleep();
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
extern void * const D_004DD120[];
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiAccountLogin_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD120);
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD120[28] = { (void*)0x0, (void*)0x0, (void*)GuiAccountLogin_dtor, (void*)GuiAccountLogin_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiAccountLogin_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiAccountLogin_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiLobbyScreen_onAdvanceTime, (void*)GuiAccountLogin_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAccountLogin_GetClassName, (void*)GuiAccountLogin_IsClass, (void*)func_002891D0, (void*)GuiScreen_PollLobby, (void*)GuiAccountLogin_Activate, (void*)GuiAccountLogin_Deactivate, (void*)0x0 };
