#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiOnlineOfflineSelect_IsType();
extern "C" void GuiOnlineOfflineSelect_GetClassName();
extern "C" void GuiOnlineOfflineSelect_HandleEvent();
extern "C" void GuiOnlineOfflineSelect_HandleInput();
extern "C" void GuiOnlineOfflineSelect_Update();
extern "C" void GuiOnlineOfflineSelect_Wake();
extern "C" void GuiOnlineOfflineSelect_Init();
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
extern "C" void GuiWidget_Load();
extern void * const D_004DD6B0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiOnlineOfflineSelect_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD6B0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD6B0[24] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineOfflineSelect_dtor, (void*)GuiOnlineOfflineSelect_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiOnlineOfflineSelect_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiOnlineOfflineSelect_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiOnlineOfflineSelect_Update, (void*)GuiOnlineOfflineSelect_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiOnlineOfflineSelect_GetClassName, (void*)GuiOnlineOfflineSelect_IsType, (void*)0x0 };
