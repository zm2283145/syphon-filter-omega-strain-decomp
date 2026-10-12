#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Free(int, int, char *, int);                         
int func_0012F530(char *, int);                            
int func_00136DA0(char *);                               
int func_001D8830(int, int);                            
extern int D_004F2D80;
extern int D_004F2D88;
extern unsigned char D_00533880;
extern int D_00533888;

void func_001D8730(void) {
    int sp28[2];
    int temp_s0;
    int temp_s0_2;

    temp_s0 = D_004F2D80;
    if (temp_s0 != 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        Mem_Free(0, temp_s0, "humanIk.cc", 0x27E);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_004F2D80 = 0;
        D_00533888 -= 1;
    }
    temp_s0_2 = D_004F2D88;
    if (temp_s0_2 != 0) {
        func_00136DA0(sp28);
        func_001D8830(temp_s0_2, -1);
        Mem_Free(0, temp_s0_2, "humanIk.cc", 0x283);
        func_0012F530(sp28, -1);
        D_004F2D88 = 0;
    }
}
