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
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void GuiMapScreen_GetClassName();
extern "C" void func_00464890();
extern "C" void GuiMapScreen_HandleInput();
extern "C" void GuiMapScreen_Draw();
extern "C" void GuiMapScreen_Sleep();
extern "C" void GuiMapScreen_Wake();
extern "C" void GuiMapScreen_Init();
extern void * const D_004E18C0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00464820(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E18C0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E18C0[24] = { (void*)0x0, (void*)0x0, (void*)func_00464820, (void*)GuiMapScreen_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiMapScreen_Wake, (void*)GuiMapScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiMapScreen_HandleInput, (void*)GuiMapScreen_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMapScreen_GetClassName, (void*)func_00464890, (void*)0x0 };
