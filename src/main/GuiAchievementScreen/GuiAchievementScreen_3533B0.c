#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string at +0x80, nested member at +0x6C, base GuiWidget_Destroy. */
extern "C" {
extern "C" void GuiAchievementScreen_GetClassName();
extern "C" void GuiAchievementScreen_IsType();
extern "C" void GuiAchievementScreen_Select();
extern "C" void GuiAchievementScreen_Show();
extern "C" void GuiAchievementScreen_Fill();
extern "C" void GuiAchievementScreen_Wake();
extern "C" void GuiAchievementScreen_Init();
extern "C" void GuiPersonnelScreen_Back();
extern "C" void GuiPersonnelScreen_HandleEvent();
extern "C" void GuiPersonnelScreen_HandleInput();
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
extern "C" void GuiWidget_Load();
extern void * const D_004DEF90[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* func_00299360(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
struct O3533B0 { void* vtable; };
extern "C" O3533B0* GuiAchievementScreen_dtor(O3533B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEF90);
        char* a = (char*)self + 0x80;
        if (a)
            String_Dtor(a, 0);
        char* m = (char*)self + 0x6C;
        if (m) {
            if (m) {
                if (m)
                    func_00299360(m, 0);
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
void * const D_004DEF90[28] = { (void*)0x0, (void*)0x0, (void*)GuiAchievementScreen_dtor, (void*)GuiAchievementScreen_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiAchievementScreen_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiPersonnelScreen_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiPersonnelScreen_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAchievementScreen_GetClassName, (void*)GuiAchievementScreen_IsType, (void*)GuiAchievementScreen_Fill, (void*)GuiAchievementScreen_Show, (void*)GuiAchievementScreen_Select, (void*)GuiPersonnelScreen_Back, (void*)0x0 };
