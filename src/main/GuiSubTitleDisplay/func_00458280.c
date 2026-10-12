#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_00219730(...);                         
int func_0041F370(...);                         
int func_004583B0(...);                         
int func_004593A0(...);                            
int operator_delete(...);                          
extern char D_004C1EB0;
extern "C" void GuiSubTitleDisplay_IsType();
extern "C" void func_00293950();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_0041F210();
extern "C" void func_00457AA0();
extern "C" void func_00457AE0();
extern "C" void func_00457FE0();
extern "C" void func_00458080();
extern "C" void func_00458140();
extern void * const D_004E1560[];
extern unsigned char D_00533880;
}
extern "C" char * func_00458280(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E1560));
        temp_s2 = F_(arg0, 0x50, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2, &D_004C1EB0, 0x14A);
            }
        }
        func_004593A0(arg0);
        temp_a0 = arg0 + 0x68;
        if (temp_a0 != NULL) {
            func_00219730(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0x58;
        if (temp_a0_2 != NULL) {
            func_004583B0(temp_a0_2, -1);
        }
        func_0041F370(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1560[24] = { (void*)0x0, (void*)0x0, (void*)func_00458280, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00458140, (void*)func_00458080, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_00457AE0, (void*)func_0041E230, (void*)func_00457FE0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00457AA0, (void*)GuiSubTitleDisplay_IsType, (void*)0x0 };
