#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char * );                         
int func_0044F470(int, char *);                          
int func_004505C0();                                
int memcpy(char * , char * , int);                        
extern char * D_00585E60;

void func_00447070(int d0, int d1, int d2, char * arg3) {
    struct { int f20[32]; int fA0[32]; int f120; int f124[64]; int f224; int f228; int f22C; } sl;
    int temp_v0;

    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x1A0, int) = 1;
        temp_v0 = F_(arg3, 0x18, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            String_Copy(sl.f20, arg3 + 0x1C);
            String_Copy(sl.fA0, arg3 + 0x9C);
            String_Copy(sl.f124, arg3 + 0x120);
            sl.f120 = F_(arg3, 0x11C, int);
            sl.f224 = F_(arg3, 0x220, int);
            sl.f228 = F_(arg3, 0x224, int);
            sl.f22C = F_(arg3, 0x228, int);
            func_0044F470(F_(D_00585E60, 0x23DC, int), sl.f20);
        }
        memcpy(D_00585E60 + 0x18EC, arg3, 0x230);
    }
}
