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
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void func_0041EFA0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern "C" void GuiCanvas_Update();
extern "C" void GuiGameCanvas_PushScreen();
extern "C" void func_00465600();
extern "C" void GuiFrontendCanvas_OnEvent();
extern "C" void GuiCanvas_HandlePad();
extern "C" void func_00465E80();
extern void * const D_004E19B0[];
extern char D_004E1A20[];
void* GuiCanvas_PopAll(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_00465E10(Vtable2Object* self, short deleteFlag)
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
void * const D_004E19B0[28] = { (void*)0x0, (void*)0x0, (void*)func_00465E10, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00465600, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiFrontendCanvas_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00465E80, (void*)GuiFrontendCanvas_IsType, (void*)GuiFrontendCanvas_Draw, (void*)GuiCanvas_Update, (void*)GuiGameCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)GuiCanvas_HandlePad };
