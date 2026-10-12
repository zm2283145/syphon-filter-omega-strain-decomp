#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiOmegaStrain_GetClassName();
extern "C" void GuiOmegaStrain_IsType();
extern "C" void func_0034EA00();
extern "C" void func_0034EC00();
extern "C" void func_0034EDF0();
extern "C" void func_0034EF00();
extern "C" void func_0034EF10();
extern "C" void func_00356AD0();
extern "C" void func_00356BE0();
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
extern void * const D_004DEDE0[];
extern char D_004DF0B0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_0034E950(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEDE0);
        if (self) {
            self->vtable = D_004DF0B0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DEDE0[28] = { (void*)0x0, (void*)0x0, (void*)func_0034E950, (void*)func_00356CD0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0034EF10, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00356BE0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0034EF00, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiOmegaStrain_GetClassName, (void*)GuiOmegaStrain_IsType, (void*)func_0034EDF0, (void*)func_0034EA00, (void*)func_0034EC00, (void*)func_00356AD0, (void*)0x0 };
