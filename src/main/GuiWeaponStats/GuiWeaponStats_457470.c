#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern "C" void GuiStartMenuBackdrop_OnSleep();
extern "C" void GuiStartMenuBackdrop_OnWake();
extern "C" void GuiStartMenuBackdrop_OnEvent();
extern "C" void GuiStartMenuBackdrop_Init();
extern "C" void GuiStartMenuBackdrop_GetClassName();
extern "C" void GuiStartMenuBackdrop_IsType();
extern void * const D_004E1490[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiStartMenuBackdrop_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1490);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1490[24] = { (void*)0x0, (void*)0x0, (void*)GuiStartMenuBackdrop_dtor, (void*)GuiStartMenuBackdrop_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiStartMenuBackdrop_OnWake, (void*)GuiStartMenuBackdrop_OnSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiWidget_onInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiStartMenuBackdrop_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiStartMenuBackdrop_GetClassName, (void*)GuiStartMenuBackdrop_IsType, (void*)0x0 };
