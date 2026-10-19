#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                      
int func_003D6010(...);                            
int memcpy(...);                            
int strlen(...);                                    
extern char D_004BD3B0;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * func_003D6030(char * arg0, int arg1, int arg2, signed char arg3) {
    int temp_v1;
    int var_v0;
    int var_s1;
    char * temp_s0;
    int temp_s0_2;

    temp_s0 = arg0 + 8;
    func_003D6010(temp_s0);
    var_s1 = 0;
    F_(temp_s0, 0xC, signed char) = 1;
    if (arg1 != 0) {
        temp_v1 = strlen(arg1) + 1; temp_s0_2 = (temp_v1 + 0x1F) / 32 * 32;
        {
            AllocGuard g;
        var_s1 = Mem_Alloc(0, temp_s0_2, &D_004BD3B0, 0x130);
        }
        memcpy(var_s1, arg1, temp_s0_2);
    }
    F_(arg0, 0x0, int) = var_s1;
    F_(arg0, 0x18, int) = 0;
    F_(arg0, 0x1C, int) = arg2;
    F_(arg0, 0x20, int) = 0;
    F_(arg0, 0x34, signed char) = 1;
    F_(arg0, 0x28, int) = -1;
    F_(arg0, 0x2C, int) = 0;
    F_(arg0, 0x24, int) = 0;
    F_(arg0, 0x30, int) = 0;
    F_(arg0, 0x35, signed char) = arg3;
    F_(arg0, 0x38, int) = 0;
    F_(arg0, 0x40, signed char) = 0;
    F_(arg0, 0x41, signed char) = 0;
    return arg0;
}