#pragma cplusplus on

#include "types.h"

/* Deleting destructor: payload at +0xB0 (two members), strings at +0x78/+0x6C, base func_0041F370. */
extern "C" {
extern "C" void GuiPersonnelMenu_GetClassName();
extern "C" void GuiPersonnelMenu_IsType();
extern "C" void func_00349ED0();
extern "C" void func_0034D2C0();
extern "C" void func_003549C0();
extern "C" void func_00354A70();
extern "C" void func_00354B50();
extern "C" void func_003556F0();
extern "C" void func_00355790();
extern "C" void func_003557D0();
extern "C" void func_00356B30();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041E470();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DF020[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void func_0036E220(void* self, int flags);
void* func_00138B70(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3548B0 { void* vtable; };
extern "C" O3548B0* func_003548B0(O3548B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF020);
        char* p = (char*)self + 0xB0;
        if (p) {
            func_0036E220((char*)self + 0x194, -1);
            func_0036E220((char*)self + 0xF8, -1);
        }
        char* a = (char*)self + 0x78;
        if (a)
            func_00138B70(a, 0);
        char* b = (char*)self + 0x6C;
        if (b)
            func_00138B70(b, 0);
        if (self) {
            self->vtable = D_004DF0B0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF020[28] = { (void*)0x0, (void*)0x0, (void*)func_003548B0, (void*)func_003557D0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00355790, (void*)func_003556F0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00354A70, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00356B30, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiPersonnelMenu_GetClassName, (void*)GuiPersonnelMenu_IsType, (void*)func_00354B50, (void*)func_00349ED0, (void*)func_0034D2C0, (void*)func_003549C0, (void*)0x0 };
