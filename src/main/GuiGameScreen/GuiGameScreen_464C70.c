#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiCanvas_PopScreen();
extern "C" void GuiCanvas_PushScreen();
extern "C" void GuiCanvas_Navigate();
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
extern "C" void func_00464CE0();
extern "C" void func_00464CF0();
extern "C" void func_00464D20();
extern "C" void func_004650C0();
extern "C" void GuiGameCanvas_OnEvent();
extern void * const D_004E1940[];
extern char D_004E1A20[];
void* GuiCanvas_PopAll(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_00464C70(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1940);
        if (self) {
            self->vtable = D_004E1A20;
            GuiCanvas_PopAll(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1940[28] = { (void*)0x0, (void*)0x0, (void*)func_00464C70, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiCanvas_Navigate, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiGameCanvas_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00464CE0, (void*)func_00464CF0, (void*)GuiFrontendCanvas_Draw, (void*)func_00464D20, (void*)GuiCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)func_004650C0 };
