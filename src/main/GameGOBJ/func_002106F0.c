#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Object_LookupById(int *);                     
int func_002EB650(void **, int);                    
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
void func_002106F0(int d0, int arg1) {
    struct { char pad30[4]; int f34; int f38[2]; } sl;
    int temp_s0;
    int temp_v0;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(sl.f38, arg1) == 0) {
        temp_s0 = F_(sl.f38[0], 0x1C, int);
        sl.f34 = F_(temp_s0, 0x0, int);
        temp_v0 = Object_LookupById(&sl.f34);
        if (temp_v0 != NULL) {
            F_(temp_v0, 0x790, int) = temp_s0;
            F_(temp_s0, 0x4, int) = arg1;
        }
    }
    D_005723C8 = 0;
}

#pragma pop
