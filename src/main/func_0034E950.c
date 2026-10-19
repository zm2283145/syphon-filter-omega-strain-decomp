#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiOmegaStrain_GetClassName();
extern "C" void GuiOmegaStrain_IsType();
extern "C" void GuiOmegaStrain_Show();
extern "C" void GuiOmegaStrain_Select();
extern "C" void GuiOmegaStrain_Fill();
extern "C" void GuiOmegaStrain_HandleEvent();
extern "C" void GuiOmegaStrain_Wake();
extern "C" void GuiPersonnelScreen_Back();
extern "C" void GuiPersonnelScreen_HandleInput();
extern "C" void GuiPersonnelScreen_Init();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern void * const D_004DEDE0[];
extern char D_004DF0B0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiOmegaStrain_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEDE0);
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEDE0[28] = { (void*)0x0, (void*)0x0, (void*)GuiOmegaStrain_dtor, (void*)GuiPersonnelScreen_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiOmegaStrain_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiPersonnelScreen_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiOmegaStrain_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiOmegaStrain_GetClassName, (void*)GuiOmegaStrain_IsType, (void*)GuiOmegaStrain_Fill, (void*)GuiOmegaStrain_Show, (void*)GuiOmegaStrain_Select, (void*)GuiPersonnelScreen_Back, (void*)0x0 };
