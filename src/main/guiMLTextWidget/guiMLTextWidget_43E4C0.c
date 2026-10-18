#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_00293950();
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
extern "C" void func_0041F210();
extern "C" void func_0043D720();
extern "C" void func_0043D730();
extern "C" void GuiMultiLineText_Draw();
extern "C" void MLTextWidget_Teardown();
extern "C" void MLTextWidget_Vt07();
extern "C" void MLTextWidget_Setup();
extern void * const D_004E1040[];
void MLTextWidget_Clear(void* self);
void func_0043E550(void* p, int flag);
void GuiWidget_Destroy(void* self, int flag);
void operator_delete(void* p);
}
typedef struct { void* vt; char pad[0x6C]; char m70[0xC]; int x7C; } S_E4C0;
extern "C" S_E4C0* MLTextWidget_dtor(S_E4C0* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004E1040);
        self->x7C = 0;
        MLTextWidget_Clear(self);
        {
            void* m = self->m70;
            if (m)
                func_0043E550(m, 0);
        }
        GuiWidget_Destroy(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1040[24] = { (void*)0x0, (void*)0x0, (void*)MLTextWidget_dtor, (void*)MLTextWidget_Setup, (void*)MLTextWidget_Teardown, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)MLTextWidget_Vt07, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_00293950, (void*)GuiMultiLineText_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_0043D720, (void*)func_0043D730, (void*)0x0 };
