#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_00294210();
extern "C" void func_00294220();
extern "C" void func_00294250();
extern "C" void GuiCommandCenter_Leave();
extern "C" void GuiCommandCenter_HandleInput();
extern "C" void func_002958B0();
extern "C" void GuiCommandCenter_Update();
extern "C" void GuiCommandCenter_Deactivate();
extern "C" void GuiCommandCenter_Activate();
extern "C" void GuiCommandCenter_Wake();
extern "C" void GuiCommandCenter_Init();
extern "C" void func_0033CCA0();
extern "C" void GuiScreen_Sleep();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DD4F0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_00138350(void* self, short deleteFlag);
void func_0033D430(void* self, int flags);
void operator_delete(void* p);
}
struct O294190 { void* vtable; char pad[0x200]; char items[0x11][0xC]; };
extern "C" O294190* GuiCommandCenter_dtor(O294190* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD4F0);
        __destroy_array(self->items, (void*)func_00138350, 0xC, 0x11);
        func_0033D430(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DD4F0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCommandCenter_dtor, (void*)GuiCommandCenter_Init, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiCommandCenter_Wake, (void*)GuiScreen_Sleep, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiCommandCenter_HandleInput, (void*)func_0041E470, (void*)func_0041E230, (void*)GuiCommandCenter_Update, (void*)func_002958B0, (void*)func_0041F210, (void*)func_00294250, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00294210, (void*)func_00294220, (void*)GuiCommandCenter_Leave, (void*)func_0033CCA0, (void*)GuiCommandCenter_Activate, (void*)GuiCommandCenter_Deactivate, (void*)0x0 };
