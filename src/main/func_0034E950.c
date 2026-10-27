#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiOmegaStrain_GetClassName();
extern "C" void GuiOmegaStrain_IsClass();
extern "C" void GuiOmegaStrain_ItemGainFocus();
extern "C" void GuiOmegaStrain_ItemAction();
extern "C" void GuiOmegaStrain_PopulateList();
extern "C" void GuiOmegaStrain_onMessage();
extern "C" void GuiOmegaStrain_onWake();
extern "C" void GuiPersonnelScreen_PreviousScreen();
extern "C" void GuiPersonnelScreen_onInput();
extern "C" void GuiPersonnelScreen_onAdd();
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
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DEDE0[];
extern char D_004DF0B0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiOmegaStrain_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEDE0);
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEDE0[28] = { (void*)0x0, (void*)0x0, (void*)GuiOmegaStrain_dtor, (void*)GuiPersonnelScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiOmegaStrain_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiPersonnelScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiOmegaStrain_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiOmegaStrain_GetClassName, (void*)GuiOmegaStrain_IsClass, (void*)GuiOmegaStrain_PopulateList, (void*)GuiOmegaStrain_ItemGainFocus, (void*)GuiOmegaStrain_ItemAction, (void*)GuiPersonnelScreen_PreviousScreen, (void*)0x0 };
