#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);                      
int memset(int, int, int);                              
extern char D_004C0B20;
extern unsigned char D_00533880;
}
extern "C" int func_00443F40(int arg0) {
    int temp_s1;

    if (arg0 <= 0) {
        return 0;
    }
    {
        AllocGuard g;
    temp_s1 = Mem_Alloc(0, arg0, &D_004C0B20, 0x1D);
    }
    if (temp_s1 == 0) {
        return 0;
    }
    memset(temp_s1, 0, arg0);
    return temp_s1;
}
