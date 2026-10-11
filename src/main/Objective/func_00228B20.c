#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
int Mem_Alloc(int, int, char *, int);                      
int String_Copy(int, int);                              
int strlen(int);                                      
extern char D_004A5D88;
extern unsigned char D_00533880;
}
extern "C" int func_00228B20(int d0, int arg1) {
    int temp_s0;
    int temp_s0_2;

    temp_s0_2 = strlen(arg1) + 1;
    {
        AllocGuard g;
    temp_s0 = Mem_Alloc(0, temp_s0_2, &D_004A5D88, 0x18C);
    }
    String_Copy(temp_s0, arg1);
    return temp_s0;
}
