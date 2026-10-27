#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0x10]; char m70[0x10]; char m80[0x20]; char mA0[0x10]; char mB0[0x10]; char mC0[0x10]; char mD0[4]; } O32ACD0;
extern void GuiKeyboard_GetClassName();
extern void GuiKeyboard_IsClass();
extern void GuiKeyboard_HandleInput();
extern void GuiKeyboard_HandleEvent();
extern void GuiKeyboard_Update();
extern void GuiKeyboard_Sleep();
extern void GuiKeyboard_Wake();
extern void GuiKeyboard_onAdd();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onRender();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void * const D_004DE790[];
extern void func_0013A040(void* p, int f);
extern void std_vector_GuiWidgetPtr_dtor(void* p, int f);
extern void GuiWidget_dtor(void* p, int f);
extern void operator_delete(void* p);
O32ACD0* GuiKeyboard_dtor_2(O32ACD0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DE790);
        if (self->mD0)
            func_0013A040(self->mD0, -1);
        if (self->mC0)
            func_0013A040(self->mC0, -1);
        if (self->mB0)
            func_0013A040(self->mB0, -1);
        if (self->mA0)
            func_0013A040(self->mA0, -1);
        if (self->m80)
            func_0013A040(self->m80, -1);
        if (self->m70)
            func_0013A040(self->m70, -1);
        if (self->m60)
            std_vector_GuiWidgetPtr_dtor(self->m60, -1);
        GuiWidget_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE790[24] = { (void*)0x0, (void*)0x0, (void*)GuiKeyboard_dtor_2, (void*)GuiKeyboard_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiKeyboard_Wake, (void*)GuiKeyboard_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiKeyboard_HandleInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiKeyboard_Update, (void*)GuiKeyboard_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiKeyboard_GetClassName, (void*)GuiKeyboard_IsClass, (void*)0x0 };
