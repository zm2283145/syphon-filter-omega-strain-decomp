#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiOnlineOfflineSelect_IsType();
extern "C" void func_002A0180();
extern "C" void GuiOnlineOfflineSelect_HandleEvent();
extern "C" void GuiOnlineOfflineSelect_HandleInput();
extern "C" void GuiOnlineOfflineSelect_Update();
extern "C" void GuiOnlineOfflineSelect_Wake();
extern "C" void GuiOnlineOfflineSelect_Init();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DD6B0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_002A0120(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD6B0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD6B0[24] = { (void*)0x0, (void*)0x0, (void*)func_002A0120, (void*)GuiOnlineOfflineSelect_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiOnlineOfflineSelect_Wake, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiOnlineOfflineSelect_HandleInput, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiOnlineOfflineSelect_Update, (void*)GuiOnlineOfflineSelect_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_002A0180, (void*)GuiOnlineOfflineSelect_IsType, (void*)0x0 };
