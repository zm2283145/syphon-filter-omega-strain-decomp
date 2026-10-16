#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void func_00349ED0();
extern "C" void func_0034D270();
extern "C" void func_0034D280();
extern "C" void func_0034D2B0();
extern "C" void func_0034D2C0();
extern "C" void func_0034D2D0();
extern "C" void func_0034D600();
extern "C" void func_0034D8C0();
extern "C" void func_0034DB10();
extern "C" void func_0034DBE0();
extern "C" void func_0034DC20();
extern "C" void func_0034DD20();
extern "C" void func_00356AD0();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DECC0[];
extern char D_004DF0B0[];
void* func_00299360(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_0034D1D0(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DECC0);
        char* member = (char*)self + (0xCC);
        if (member) {
            if (member) {
                if (member)
                    func_00299360(member, 0);
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
void * const D_004DECC0[28] = { (void*)0x0, (void*)0x0, (void*)func_0034D1D0, (void*)func_0034DD20, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0034DC20, (void*)func_0034DB10, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0034D2D0, (void*)func_0034D8C0, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)func_0034D600, (void*)func_0041F210, (void*)func_0034DBE0, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_0034D270, (void*)func_0034D280, (void*)func_0034D2B0, (void*)func_00349ED0, (void*)func_0034D2C0, (void*)func_00356AD0, (void*)0x0 };
