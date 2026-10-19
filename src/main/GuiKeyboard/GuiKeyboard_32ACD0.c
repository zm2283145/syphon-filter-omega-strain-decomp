#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0x10]; char m70[0x10]; char m80[0x20]; char mA0[0x10]; char mB0[0x10]; char mC0[0x10]; char mD0[4]; } O32ACD0;
extern void GuiKeyboard_GetClassName();
extern void GuiKeyboard_IsType();
extern void GuiKeyboard_HandleInput();
extern void GuiKeyboard_HandleEvent();
extern void GuiKeyboard_Update();
extern void GuiKeyboard_Sleep();
extern void GuiKeyboard_Wake();
extern void GuiKeyboard_Init();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_Draw();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void GuiWidget_Load();
extern void * const D_004DE790[];
extern void func_0013A040(void* p, int f);
extern void GuiKeyboard_dtor(void* p, int f);
extern void GuiWidget_Destroy(void* p, int f);
extern void operator_delete(void* p);
O32ACD0* GuiKeyboard_VirtualDtor(O32ACD0* self, short del)
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
            GuiKeyboard_dtor(self->m60, -1);
        GuiWidget_Destroy(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE790[24] = { (void*)0x0, (void*)0x0, (void*)GuiKeyboard_VirtualDtor, (void*)GuiKeyboard_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiKeyboard_Wake, (void*)GuiKeyboard_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiKeyboard_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiKeyboard_Update, (void*)GuiKeyboard_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiKeyboard_GetClassName, (void*)GuiKeyboard_IsType, (void*)0x0 };
