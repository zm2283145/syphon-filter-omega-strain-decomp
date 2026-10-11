#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int String_Copy();                         
int func_0044F470(int, int *);                        
int func_004505C0();                                
int memcpy(char * , char * , int);                        
extern char * D_00585E60;

void func_00446EA0(int d0, int d1, int d2, char * arg3) {
    struct { int f20; int f24[19]; } sl;
    int temp_v0;

    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x1AC, int) = 1;
        temp_v0 = F_(arg3, 0x5C, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            sl.f20 = F_(arg3, 0x18, int);
            String_Copy(sl.f24, arg3 + 0x1C);
            func_0044F470(F_(D_00585E60, 0x23E0, int), &sl.f20);
        }
        memcpy(D_00585E60 + 0x39C, arg3, 0x64);
    }
}
