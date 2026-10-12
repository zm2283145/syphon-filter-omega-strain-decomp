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
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DECC0[];
extern char D_004DF0B0[];
void* func_00299360(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
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
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DECC0[28] = { (void*)0x0, (void*)0x0, (void*)func_0034D1D0, (void*)func_0034DD20, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0034DC20, (void*)func_0034DB10, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0034D2D0, (void*)func_0034D8C0, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0034D600, (void*)func_0041F210, (void*)func_0034DBE0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0034D270, (void*)func_0034D280, (void*)func_0034D2B0, (void*)func_00349ED0, (void*)func_0034D2C0, (void*)func_00356AD0, (void*)0x0 };
