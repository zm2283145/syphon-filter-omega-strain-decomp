#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiOnlineOptions_GetClassName();
extern "C" void GuiOnlineOptions_IsType();
extern "C" void func_002A97E0();
extern "C" void GuiOnlineOptions_HandleEvent();
extern "C" void GuiOnlineOptions_HandleInput();
extern "C" void GuiOnlineOptions_Deactivate();
extern "C" void GuiOnlineOptions_Activate();
extern "C" void GuiOnlineOptions_Init();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Update();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
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
extern void * const D_004DDAF0[];
void* LobbyArray_dtor(void* self, short deleteFlag);
void* GuiScreen_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O2A95F0 { void* vtable; char pad[0x9C]; char member[4]; };
extern "C" O2A95F0* GuiOnlineOptions_dtor(O2A95F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DDAF0);
        LobbyArray_dtor(self->member, -1);
        GuiScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDAF0[28] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineOptions_dtor, (void*)GuiOnlineOptions_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiOnlineOptions_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiScreen_Update, (void*)GuiOnlineOptions_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiOnlineOptions_GetClassName, (void*)GuiOnlineOptions_IsType, (void*)func_002A97E0, (void*)GuiScreen_PollLobby, (void*)GuiOnlineOptions_Activate, (void*)GuiOnlineOptions_Deactivate, (void*)0x0 };
