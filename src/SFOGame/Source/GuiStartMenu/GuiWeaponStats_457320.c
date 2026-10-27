#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiBriefingPane_onWake();
extern "C" void GuiBriefingPane_onRender();
extern "C" void GuiBriefingPane_onInput();
extern "C" void GuiBriefingPane_onAdd();
extern "C" void GuiBriefingPane_GetClassName();
extern "C" void GuiBriefingPane_IsClass();
extern void * const D_004E13D0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiBriefingPane_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E13D0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E13D0[24] = { (void*)0x0, (void*)0x0, (void*)GuiBriefingPane_dtor, (void*)GuiBriefingPane_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiBriefingPane_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiBriefingPane_onInput, (void*)GuiBriefingPane_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiBriefingPane_GetClassName, (void*)GuiBriefingPane_IsClass, (void*)0x0 };
