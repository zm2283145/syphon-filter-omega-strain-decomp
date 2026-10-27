#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiCanvas_PopGui();
extern "C" void GuiCanvas_PushGui();
extern "C" void GuiCanvas_onInput();
extern "C" void GuiCanvas_Render();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onWake();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern "C" void GuiGameCanvas_GetClassName();
extern "C" void GuiGameCanvas_IsClass();
extern "C" void func_00464D20();
extern "C" void GuiGameCanvas_DispatchInput();
extern "C" void GuiGameCanvas_onMessage();
extern void * const D_004E1940[];
extern char D_004E1A20[];
void* GuiCanvas_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiGameCanvas_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1940);
        if (self) {
            self->vtable = D_004E1A20;
            GuiCanvas_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1940[28] = { (void*)0x0, (void*)0x0, (void*)GuiGameCanvas_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiCanvas_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiGameCanvas_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiGameCanvas_GetClassName, (void*)GuiGameCanvas_IsClass, (void*)GuiCanvas_Render, (void*)func_00464D20, (void*)GuiCanvas_PushGui, (void*)GuiCanvas_PopGui, (void*)GuiGameCanvas_DispatchInput };
