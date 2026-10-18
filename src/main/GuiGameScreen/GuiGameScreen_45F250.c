#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
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
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern "C" void GuiSaveAgentWidget_OnEvent();
extern "C" void GuiAutoSaver_GetClassName();
extern "C" void func_0045F2D0();
extern "C" void GuiAutoSaver_SaveDone();
extern "C" void GuiAutoSaver_Wake();
extern void * const D_004E16D0[];
extern char D_004E1220[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_0045F250(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E16D0);
        if (self) {
            self->vtable = D_004E1220;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E16D0[24] = { (void*)0x0, (void*)0x0, (void*)func_0045F250, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiAutoSaver_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_00293950, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiSaveAgentWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAutoSaver_GetClassName, (void*)func_0045F2D0, (void*)GuiAutoSaver_SaveDone };
