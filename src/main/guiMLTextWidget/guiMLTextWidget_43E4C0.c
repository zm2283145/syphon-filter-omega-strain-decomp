#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_Load();
extern "C" void GuiMLTextWidget_GetClassName();
extern "C" void GuiMLTextWidget_IsClass();
extern "C" void GuiMLTextWidget_onRender();
extern "C" void GuiMLTextWidget_onRemove();
extern "C" void GuiMLTextWidget_onWake();
extern "C" void GuiMLTextWidget_onAdd();
extern void * const D_004E1040[];
void GuiMLTextWidget_Clear(void* self);
void std_list_charPtr_dtor(void* p, int flag);
void GuiWidget_dtor(void* self, int flag);
void operator_delete(void* p);
}
typedef struct { void* vt; char pad[0x6C]; char m70[0xC]; int x7C; } S_E4C0;
extern "C" S_E4C0* GuiMLTextWidget_dtor(S_E4C0* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004E1040);
        self->x7C = 0;
        GuiMLTextWidget_Clear(self);
        {
            void* m = self->m70;
            if (m)
                std_list_charPtr_dtor(m, 0);
        }
        GuiWidget_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1040[24] = { (void*)0x0, (void*)0x0, (void*)GuiMLTextWidget_dtor, (void*)GuiMLTextWidget_onAdd, (void*)GuiMLTextWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMLTextWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiMLTextWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMLTextWidget_GetClassName, (void*)GuiMLTextWidget_IsClass, (void*)0x0 };
