#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int String_Dtor(...);                         
int func_0041F370(...);                         
int operator_delete(...);                          
extern char D_004BF2D0;
extern "C" void GuiTextWidget_IsType();
extern "C" void func_00293950();
extern "C" void func_0041BE10();
extern "C" void func_0041BE50();
extern "C" void func_0041C150();
extern "C" void func_0041C310();
extern "C" void func_0041C3E0();
extern "C" void func_0041C560();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern void * const D_004E0AC0[];
extern unsigned char D_00533880;
}
extern "C" char * func_0041C6A0(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E0AC0));
        temp_s2 = F_(arg0, 0x78, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            if (temp_s2 != 0) {
                temp_a0 = (char *)(temp_s2 + 0x14);
                if (temp_a0 != NULL) {
                    String_Dtor(temp_a0, 0);
                }
            }
            Mem_Free(0, temp_s2, &D_004BF2D0, 0x23);
            }
        }
        temp_a0_2 = arg0 + 0x48;
        if (temp_a0_2 != NULL) {
            String_Dtor(temp_a0_2, 0);
        }
        func_0041F370(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E0AC0[24] = { (void*)0x0, (void*)0x0, (void*)func_0041C6A0, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041C3E0, (void*)func_0041C310, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0041C150, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041C560, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0041BE10, (void*)GuiTextWidget_IsType, (void*)func_0041BE50 };
