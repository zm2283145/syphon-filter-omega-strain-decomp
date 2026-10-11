#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                        
int func_003A2DD0(int, int, char*, float);             
extern char D_004A6E38;
extern unsigned char D_00533880;
}
extern "C" void func_00236DE0(char * arg0) {
    int var_s1;

    {
        AllocGuard g;
    var_s1 = Mem_Alloc(0, 0x70, &D_004A6E38, 0x125);
    }
    if (var_s1 != 0) {
        var_s1 = func_003A2DD0(var_s1, F_(arg0, 0x8, int), arg0 + 0x10, 1.0f);
    }
    F_(arg0, 0xC, int) = var_s1;
}
