#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiFrontendCanvas_IsClass();
extern "C" void GuiCanvas_PopGui();
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
extern "C" void GuiFrontendCanvas_NextFrame();
extern "C" void GuiFrontendCanvas_PushGui();
extern "C" void GuiFrontendCanvas_HandleInput();
extern "C" void GuiFrontendCanvas_onMessage();
extern "C" void GuiFrontendCanvas_ProcessInputEvent();
extern "C" void GuiFrontendCanvas_GetClassName();
extern void * const D_004E19B0[];
extern char D_004E1A20[];
void* GuiCanvas_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiFrontendCanvas_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E19B0);
        if (self) {
            self->vtable = D_004E1A20;
            GuiCanvas_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E19B0[28] = { (void*)0x0, (void*)0x0, (void*)GuiFrontendCanvas_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiFrontendCanvas_HandleInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiFrontendCanvas_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiFrontendCanvas_GetClassName, (void*)GuiFrontendCanvas_IsClass, (void*)GuiCanvas_Render, (void*)GuiFrontendCanvas_NextFrame, (void*)GuiFrontendCanvas_PushGui, (void*)GuiCanvas_PopGui, (void*)GuiFrontendCanvas_ProcessInputEvent };
