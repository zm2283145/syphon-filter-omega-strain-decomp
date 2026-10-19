#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAccountLogin_IsType();
extern "C" void GuiAccountLogin_GetClassName();
extern "C" void func_002891D0();
extern "C" void GuiAccountLogin_HandleInput();
extern "C" void GuiAccountLogin_HandleEvent();
extern "C" void GuiAccountLogin_Deactivate();
extern "C" void GuiAccountLogin_Activate();
extern "C" void GuiAccountLogin_Wake();
extern "C" void GuiAccountLogin_Init();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Update();
extern "C" void GuiScreen_Sleep();
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
extern "C" void GuiWidget_Load();
extern void * const D_004DD120[];
void* GuiScreen_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiAccountLogin_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD120);
        GuiScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD120[28] = { (void*)0x0, (void*)0x0, (void*)GuiAccountLogin_dtor, (void*)GuiAccountLogin_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiAccountLogin_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiAccountLogin_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiScreen_Update, (void*)GuiAccountLogin_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAccountLogin_GetClassName, (void*)GuiAccountLogin_IsType, (void*)func_002891D0, (void*)GuiScreen_PollLobby, (void*)GuiAccountLogin_Activate, (void*)GuiAccountLogin_Deactivate, (void*)0x0 };
