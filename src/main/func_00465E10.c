#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiFrontendCanvas_IsType();
extern "C" void GuiCanvas_PopScreen();
extern "C" void GuiFrontendCanvas_Draw();
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
extern "C" void GuiWidget_BaseWake();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void GuiWidget_Load();
extern "C" void GuiCanvas_Update();
extern "C" void GuiGameCanvas_PushScreen();
extern "C" void GuiFrontendCanvas_HandleInput();
extern "C" void GuiFrontendCanvas_OnEvent();
extern "C" void GuiCanvas_HandlePad();
extern "C" void GuiFrontendCanvas_GetClassName();
extern void * const D_004E19B0[];
extern char D_004E1A20[];
void* GuiCanvas_PopAll(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiFrontendCanvas_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E19B0);
        if (self) {
            self->vtable = D_004E1A20;
            GuiCanvas_PopAll(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E19B0[28] = { (void*)0x0, (void*)0x0, (void*)GuiFrontendCanvas_dtor, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiFrontendCanvas_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiFrontendCanvas_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiFrontendCanvas_GetClassName, (void*)GuiFrontendCanvas_IsType, (void*)GuiFrontendCanvas_Draw, (void*)GuiCanvas_Update, (void*)GuiGameCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)GuiCanvas_HandlePad };
