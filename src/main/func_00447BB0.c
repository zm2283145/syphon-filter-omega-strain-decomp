#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00121BC8(char * );                          
int func_0044F470(int, int *);                        
int func_004505C0();                                
int memset(int *, int, int);                              
int strncpy(char *, char * , int);                          
extern char * D_00585E60;

void func_00447BB0(int d0, int d1, int d2, char * arg3) {
    struct { int f40; int f44[8]; int f64[16]; signed char fA4[12]; } sl;
    int temp_s0;
    int temp_a0;
    int temp_s2;

    if (func_004505C0() == 0) {
        temp_s0 = F_(D_00585E60, 0x23EC, int);
        if ((temp_s0 != 0) && ((temp_a0 = F_(arg3, 0x58, int), (temp_a0 == 0)) || (temp_a0 == 4))) {
            temp_s2 = func_00121BC8(arg3);
            memset(&sl.f40, 0, 0x68);
            sl.fA4[0] = temp_s2 != 0;
            sl.f40 = temp_s2;
            strncpy(sl.f44, D_00585E60 + 0x243D, 0x1F);
            strncpy(sl.f64, arg3 + 0x15, 0x3F);
            func_0044F470(temp_s0, &sl.f40);
        }
    }
}
