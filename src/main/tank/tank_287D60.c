#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiTitleScreen_GetClassName();
extern "C" void func_00287DD0();
extern "C" void GuiTitleScreen_HandleEvent();
extern "C" void GuiTitleScreen_Update();
extern "C" void GuiTitleScreen_HandleInput();
extern "C" void GuiTitleScreen_Wake();
extern "C" void func_002888E0();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DD0A0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00287D60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD0A0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD0A0[24] = { (void*)0x0, (void*)0x0, (void*)func_00287D60, (void*)func_002888E0, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiTitleScreen_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiTitleScreen_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiTitleScreen_Update, (void*)GuiTitleScreen_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiTitleScreen_GetClassName, (void*)func_00287DD0, (void*)0x0 };
