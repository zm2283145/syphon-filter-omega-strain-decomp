#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
int Mem_Free(int, int, char *, int);                         
int String_Dtor(int, int);                            
int func_0038CC70(int);                               
int func_0041F090();                                  
extern unsigned char D_00533880;
}
extern "C" void func_0045DE80(char * arg0) {
    int temp_a0;
    int temp_a0_2;
    int temp_s1;
    int temp_s1_2;

    func_0041F090();
    temp_s1 = F_(arg0, 0x48, int);
    {
        AllocGuard g;
    if (temp_s1 != 0) {
        temp_a0 = temp_s1 + 0x14;
        if (temp_a0 != 0) {
            String_Dtor(temp_a0, 0);
        }
    }
    Mem_Free(0, temp_s1, "GuiGameScreen.cc", 0x152);
    }
    temp_a0_2 = F_(arg0, 0xD8, int);
    if (temp_a0_2 != 0) {
        func_0038CC70(temp_a0_2);
        temp_s1_2 = F_(arg0, 0xD8, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s1_2, "GuiGameScreen.cc", 0x157);
        }
        F_(arg0, 0xD8, int) = 0;
    }
}
