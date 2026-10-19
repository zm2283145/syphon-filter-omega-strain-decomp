#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
int Mem_Alloc(int, int, char *, int);                      
int Mem_Free(int, int, char *, int);                         
int String_Copy(int, int);                            
int strlen(int);                                    
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void func_0012F3D0(char * arg0, int arg1) {
    int temp_s2;
    int temp_s2_2;
    int temp_s2_3;

    temp_s2 = F_(arg0, 0x1C0, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, "game.cc", 0xC1A);
        }
        F_(arg0, 0x1C0, int) = 0;
    }
    if (arg1 != 0) {
        temp_s2_2 = strlen(arg1) + 1;
        {
            AllocGuard g;
        temp_s2_3 = Mem_Alloc(0, temp_s2_2, "game.cc", 0xC20);
        }
        F_(arg0, 0x1C0, int) = temp_s2_3;
        String_Copy(F_(arg0, 0x1C0, int), arg1);
    }
}
