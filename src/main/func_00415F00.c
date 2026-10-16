#pragma cplusplus on
#include "types.h"
class V415F00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24(int);
};
typedef struct { char pad[8]; int arg; } N415F00;
typedef struct { void* vt; char p0[0x24]; int count; N415F00* head; char p1[0x54 - 0x30]; char sub[4]; } T415F00;
extern "C" {
extern "C" void func_0029B350();
extern "C" void func_00414A50();
extern "C" void GuiCanvas_FinishDeferredPop();
extern "C" void GuiCanvas_PopScreen();
extern "C" void GuiCanvas_PushScreen();
extern "C" void GuiCanvas_Navigate();
extern "C" void GuiCanvas_DispatchInput();
extern "C" void GuiCanvas_UpdateStack();
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
extern void * const D_004E08D0[];
void func_002CCD80(void* p, int f);
void GuiWidget_Destroy(T415F00* p, int f);
void operator_delete(void* p);
}
extern "C" T415F00* GuiCanvas_PopAll(T415F00* self, short flag) {
    if (self) {
        self->vt = ((char*)D_004E08D0);
        while (self->count) ((V415F00*)self)->s24(self->head->arg);
        if (self->sub) func_002CCD80(self->sub, 0);
        GuiWidget_Destroy(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E08D0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCanvas_PopAll, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiCanvas_Navigate, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiCanvas_FinishDeferredPop, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_0029B350, (void*)func_00414A50, (void*)GuiFrontendCanvas_Draw, (void*)GuiCanvas_UpdateStack, (void*)GuiCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)GuiCanvas_DispatchInput };
