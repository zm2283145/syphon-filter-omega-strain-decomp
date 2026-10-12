#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
extern "C" {
extern "C" void GuiEndGameObjectives_IsType();
extern "C" void func_003680A0();
extern "C" void func_003688C0();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_00462270();
extern "C" void func_00462340();
extern "C" void func_00462380();
extern "C" void func_004624E0();
extern void * const D_004E17C0[];
extern char D_004DF5C0[];
void operator_delete(void* allocation);
void func_0036E220(void* self, int flags);
void func_00461DC0(void* self, int flags);
void func_0041F370(void* self, int flags);
}
struct O4621A0 { void* vtable; };
extern "C" O4621A0* func_004621A0(O4621A0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E17C0);
        {
            char* q = (char*)self + 0x90;
            if (q) {
                char* p = (char*)self + 0xB0;
                if (p) {
                    func_0036E220((char*)self + 0x194, -1);
                    func_0036E220((char*)self + 0xF8, -1);
                }
                {
                    char* a = (char*)self + 0x90;
                    if (a) {
                        if (a) {
                            if (a)
                                func_00461DC0(a, 0);
                        }
                    }
                }
            }
        }
        if (self) {
            self->vtable = D_004DF5C0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E17C0[24] = { (void*)0x0, (void*)0x0, (void*)func_004621A0, (void*)func_003688C0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_004624E0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00462380, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00462270, (void*)func_003680A0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00462340, (void*)GuiEndGameObjectives_IsType, (void*)0x0 };
