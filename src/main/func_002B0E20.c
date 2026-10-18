#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_002B0E80();
extern "C" void func_002B0E90();
extern "C" void GuiQuickChat_HandleInput();
extern "C" void GuiQuickChat_Init();
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
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_BaseWake();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DDE60[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_002B0E20(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DDE60);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDE60[24] = { (void*)0x0, (void*)0x0, (void*)func_002B0E20, (void*)GuiQuickChat_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiQuickChat_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_002B0E80, (void*)func_002B0E90, (void*)0x0 };
