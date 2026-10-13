#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string at +0x80, nested member at +0x6C, base func_0041F370. */
extern "C" {
extern "C" void GuiAchievementScreen_GetClassName();
extern "C" void func_00353470();
extern "C" void func_003535D0();
extern "C" void func_003536A0();
extern "C" void func_00353700();
extern "C" void func_00353800();
extern "C" void func_00353850();
extern "C" void func_00356AD0();
extern "C" void func_00356B30();
extern "C" void func_00356BE0();
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
extern void * const D_004DEF90[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* func_00299360(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3533B0 { void* vtable; };
extern "C" O3533B0* func_003533B0(O3533B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEF90);
        char* a = (char*)self + 0x80;
        if (a)
            String_Dtor(a, 0);
        char* m = (char*)self + 0x6C;
        if (m) {
            if (m) {
                if (m)
                    func_00299360(m, 0);
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
void * const D_004DEF90[28] = { (void*)0x0, (void*)0x0, (void*)func_003533B0, (void*)func_00353850, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00353800, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00356BE0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00356B30, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiAchievementScreen_GetClassName, (void*)func_00353470, (void*)func_00353700, (void*)func_003536A0, (void*)func_003535D0, (void*)func_00356AD0, (void*)0x0 };
