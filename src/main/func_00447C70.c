#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_Copy();                         
int func_0044F470();                     
int func_004505C0();                                
int memset();                              
extern char * D_00585E60;

#pragma push
#pragma opt_common_subs off
void func_00447C70(int d0, int d1, int d2, char * arg3) {
    struct { int f30; int f34[8]; int f54[16]; signed char f94[12]; int fA0[2]; int fA8; int fAC[8]; int fCC[33]; } sl;
    char * temp_s1;

    if (func_004505C0() == 0) {
        temp_s1 = (char *)(F_(D_00585E60, 0x23EC, int));
        if (temp_s1 == NULL) {
            if (F_(arg3, 0x3C, int) == 1) {
                memset(sl.fA0, 0, 0xAC);
                sl.fA0[0] = 9;
                sl.fA8 = F_(arg3, 0x18, int);
                String_Copy(sl.fAC, arg3 + 0x1C);
                String_Copy(sl.fCC, arg3 + 0x40);
                func_0044F470(D_00585E60 + 0x1C, sl.fA0);
            }
            return;
        }
        memset(&sl.f30, 0, 0x68);
        sl.f30 = F_(arg3, 0x18, int);
        String_Copy(sl.f34, arg3 + 0x1C);
        String_Copy(sl.f54, arg3 + 0x40);
        sl.f94[0] = F_(arg3, 0x3C, int) == 1;
        func_0044F470(temp_s1, &sl.f30);
    }
}
#pragma pop
