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
void * const D_004E1940[28] = { (void*)0x0, (void*)0x0, (void*)func_00464C70, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiCanvas_Navigate, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiGameCanvas_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00464CE0, (void*)func_00464CF0, (void*)GuiFrontendCanvas_Draw, (void*)func_00464D20, (void*)GuiCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)func_004650C0 };
