#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Unlock(int);                                  
int func_0010CE40(int, char *, int);                       
extern int D_00572518;
extern char func_004292B0;

unsigned char func_00429430(void) {
    unsigned char var_s0 = 0;

    *(volatile int *)0x10000010 = 0xC00;
    *(volatile int *)0x10000020 = 0x24A;
    *(volatile int *)0x10000000 = 0;
    *(volatile int *)0x10000010 = 0x382;
    D_00572518 = func_0010CE40(9, &func_004292B0, 0);
    if (D_00572518 != -1) {
        Alloc_Unlock(9);
        var_s0 = 1;
    }
    return var_s0;
}
