#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiOnlineOfflineSelect_IsClass();
extern "C" void GuiOnlineOfflineSelect_GetClassName();
extern "C" void GuiOnlineOfflineSelect_onMessage();
extern "C" void GuiOnlineOfflineSelect_onInput();
extern "C" void GuiOnlineOfflineSelect_onAdvanceTime();
extern "C" void GuiOnlineOfflineSelect_onWake();
extern "C" void GuiOnlineOfflineSelect_onAdd();
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
extern void * const D_004DD6B0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiOnlineOfflineSelect_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD6B0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD6B0[24] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineOfflineSelect_dtor, (void*)GuiOnlineOfflineSelect_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiOnlineOfflineSelect_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiOnlineOfflineSelect_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiOnlineOfflineSelect_onAdvanceTime, (void*)GuiOnlineOfflineSelect_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiOnlineOfflineSelect_GetClassName, (void*)GuiOnlineOfflineSelect_IsClass, (void*)0x0 };
