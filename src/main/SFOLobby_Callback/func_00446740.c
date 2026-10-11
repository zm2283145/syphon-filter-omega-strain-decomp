#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char * );                         
int func_0044F470(char * , int *);                     
int func_004505C0();                                
int memset(int *, int, int);                              
extern char * D_00585E60;

void func_00446740(int d0, int d1, int d2, char * arg3) {
    struct { int f20[2]; int f28; int f2C[41]; } sl;

    if (func_004505C0() == 0) {
        if (F_(arg3, 0x44, signed char) != 0) {
            F_(D_00585E60, 0x22C, int) = 1;
        }
        if (F_(arg3, 0x18, int) == 0) {
            memset(sl.f20, 0, 0xAC);
            sl.f20[0] = 1;
            sl.f28 = F_(arg3, 0x1C, int);
            String_Copy(sl.f2C, arg3 + 0x20);
            func_0044F470(D_00585E60 + 0x1C, sl.f20);
        }
    }
}
