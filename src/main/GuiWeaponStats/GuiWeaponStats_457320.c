#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void GuiBriefingPane_Wake();
extern "C" void GuiBriefingPane_Draw();
extern "C" void GuiBriefingPane_HandleInput();
extern "C" void GuiBriefingPane_Init();
extern "C" void func_00457380();
extern "C" void func_00457390();
extern void * const D_004E13D0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00457320(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E13D0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E13D0[24] = { (void*)0x0, (void*)0x0, (void*)func_00457320, (void*)GuiBriefingPane_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiBriefingPane_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiBriefingPane_HandleInput, (void*)GuiBriefingPane_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00457380, (void*)func_00457390, (void*)0x0 };
