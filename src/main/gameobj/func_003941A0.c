#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                         
int func_003A2BA0(...);                            
int func_003CE790(...);                         
extern unsigned char D_00533880;
}
#pragma opt_common_subs off
extern "C" void func_003941A0(char * arg0, int arg1) {
    int temp_s2;

    temp_s2 = F_(arg0, 0x64, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        func_003A2BA0(temp_s2, -1);
        Mem_Free(0, temp_s2, "gameobj.cc", 0x286);
        }
        F_(arg0, 0x64, int) = 0;
    }
    func_003CE790(arg0, arg1);
}
