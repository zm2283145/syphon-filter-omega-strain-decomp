#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string at +0x80, nested member at +0x6C, base GuiWidget_dtor. */
extern "C" {
extern "C" void GuiAchievementScreen_GetClassName();
extern "C" void GuiAchievementScreen_IsClass();
extern "C" void GuiAchievementScreen_ItemAction();
extern "C" void GuiAchievementScreen_ItemGainFocus();
extern "C" void GuiAchievementScreen_PopulateList();
extern "C" void GuiAchievementScreen_onWake();
extern "C" void GuiAchievementScreen_onAdd();
extern "C" void GuiPersonnelScreen_PreviousScreen();
extern "C" void GuiPersonnelScreen_onMessage();
extern "C" void GuiPersonnelScreen_onInput();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DEF90[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* func_00299360(void* self, short deleteFlag);
void* GuiWidget_dtor(void* self, short deleteFlag);
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
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEF90[28] = { (void*)0x0, (void*)0x0, (void*)GuiAchievementScreen_dtor, (void*)GuiAchievementScreen_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiAchievementScreen_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiPersonnelScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiPersonnelScreen_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAchievementScreen_GetClassName, (void*)GuiAchievementScreen_IsClass, (void*)GuiAchievementScreen_PopulateList, (void*)GuiAchievementScreen_ItemGainFocus, (void*)GuiAchievementScreen_ItemAction, (void*)GuiPersonnelScreen_PreviousScreen, (void*)0x0 };
