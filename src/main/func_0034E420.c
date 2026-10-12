#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiRanks_GetClassName();
extern "C" void func_0034E4A0();
extern "C" void func_0034E4D0();
extern "C" void func_0034E5A0();
extern "C" void func_0034E770();
extern "C" void func_00356AD0();
extern "C" void func_00356B30();
extern "C" void func_00356BE0();
extern "C" void func_00356C70();
extern "C" void func_00356CD0();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DED50[];
extern char D_004DF0B0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_0034E420(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DED50);
        if (self) {
            self->vtable = D_004DF0B0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DED50[28] = { (void*)0x0, (void*)0x0, (void*)func_0034E420, (void*)func_00356CD0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00356C70, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00356BE0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00356B30, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiRanks_GetClassName, (void*)func_0034E4A0, (void*)func_0034E4D0, (void*)func_0034E770, (void*)func_0034E5A0, (void*)func_00356AD0, (void*)0x0 };
