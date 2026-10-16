#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0x10]; char m70[0x10]; char m80[0x20]; char mA0[0x10]; char mB0[0x10]; char mC0[0x10]; char mD0[4]; } O32ACD0;
extern void GuiKeyboard_GetClassName();
extern void GuiKeyboard_IsType();
extern void func_0032BA10();
extern void GuiKeyboard_HandleEvent();
extern void GuiKeyboard_Update();
extern void func_0032C9A0();
extern void GuiKeyboard_Wake();
extern void func_0032CB40();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041D8C0();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E470();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void * const D_004DE790[];
extern void func_0013A040(void* p, int f);
extern void GuiKeyboard_dtor(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
O32ACD0* func_0032ACD0(O32ACD0* self, short del)
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
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE790[24] = { (void*)0x0, (void*)0x0, (void*)func_0032ACD0, (void*)func_0032CB40, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiKeyboard_Wake, (void*)func_0032C9A0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0032BA10, (void*)func_0041E470, (void*)func_0041E230, (void*)GuiKeyboard_Update, (void*)GuiKeyboard_HandleEvent, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiKeyboard_GetClassName, (void*)GuiKeyboard_IsType, (void*)0x0 };
