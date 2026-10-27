#pragma cplusplus on
#include "vtable_base_dtor.h"

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
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiStartMenuBackdrop_OnSleep();
extern "C" void GuiStartMenuBackdrop_OnWake();
extern "C" void GuiStartMenuBackdrop_OnEvent();
extern "C" void GuiStartMenuBackdrop_onAdd();
extern "C" void GuiStartMenuBackdrop_GetClassName();
extern "C" void GuiStartMenuBackdrop_IsClass();
extern void * const D_004E1490[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiStartMenuBackdrop_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1490);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1490[24] = { (void*)0x0, (void*)0x0, (void*)GuiStartMenuBackdrop_dtor, (void*)GuiStartMenuBackdrop_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiStartMenuBackdrop_OnWake, (void*)GuiStartMenuBackdrop_OnSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiStartMenuBackdrop_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiStartMenuBackdrop_GetClassName, (void*)GuiStartMenuBackdrop_IsClass, (void*)0x0 };
