#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiMissionStatistics_GetClassName();
extern "C" void func_00349ED0();
extern "C" void func_0034D2B0();
extern "C" void GuiMissionStatistics_IsType();
extern "C" void GuiMissionStatistics_Select();
extern "C" void GuiMissionStatistics_HandleEvent();
extern "C" void GuiMissionStatistics_HandleInput();
extern "C" void GuiMissionStatistics_Sleep();
extern "C" void GuiMissionStatistics_Wake();
extern "C" void GuiMissionStatistics_Init();
extern "C" void GuiPersonnelScreen_Back();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern void * const D_004DEE70[];
extern char D_004DF0B0[];
void* func_003513B0(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiMissionStatistics_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEE70);
        char* member = (char*)self + (0x70);
        if (member) {
            if (member) {
                if (member)
                    func_003513B0(member, 0);
            }
        }
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEE70[28] = { (void*)0x0, (void*)0x0, (void*)GuiMissionStatistics_dtor, (void*)GuiMissionStatistics_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiMissionStatistics_Wake, (void*)GuiMissionStatistics_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiMissionStatistics_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiMissionStatistics_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMissionStatistics_GetClassName, (void*)GuiMissionStatistics_IsType, (void*)func_0034D2B0, (void*)func_00349ED0, (void*)GuiMissionStatistics_Select, (void*)GuiPersonnelScreen_Back, (void*)0x0 };
