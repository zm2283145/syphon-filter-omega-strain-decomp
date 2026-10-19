#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293890();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Update();
extern "C" void GuiScreen_Sleep();
extern "C" void func_00346D20();
extern "C" void func_00346D30();
extern "C" void func_00346D60();
extern "C" void func_003473E0();
extern "C" void func_00347690();
extern "C" void func_003476B0();
extern "C" void func_003477D0();
extern "C" void func_00347820();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DEB10[];
void* func_0033D430(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00346CC0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEB10);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEB10[28] = { (void*)0x0, (void*)0x0, (void*)func_00346CC0, (void*)func_00347820, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)func_003477D0, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_003473E0, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiScreen_Update, (void*)func_00346D60, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00346D20, (void*)func_00346D30, (void*)func_00293890, (void*)GuiScreen_PollLobby, (void*)func_003476B0, (void*)func_00347690, (void*)0x0 };
