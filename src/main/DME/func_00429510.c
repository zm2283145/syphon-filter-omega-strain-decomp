#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);                        
int func_00453E20(int);                             
extern unsigned char D_00533880;
extern int D_00572480;
extern signed char D_00572488;
}
extern "C" void func_00429510(void) {
    int var_s0;

    if (D_00572480 == 0) {
        {
            AllocGuard g;
        var_s0 = Mem_Alloc(0, 0x26B0, "DME.cc", 0x75D);
        }
        if (var_s0 != 0) {
            var_s0 = func_00453E20(var_s0);
        }
        D_00572480 = var_s0;
    }
    D_00572488 = 1;
}
