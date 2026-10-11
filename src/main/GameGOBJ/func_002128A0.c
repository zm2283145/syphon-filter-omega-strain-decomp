#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Object_LookupById(int *);                     
int func_002EB650(void **);                         
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
void func_002128A0(void) {
    struct { char pad10[4]; int f14; int f18[2]; } sl;
    int temp_v0;
    int temp_v0_2;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(sl.f18) == 0) {
        temp_v0 = F_(sl.f18[0], 0x1C, int);
        sl.f14 = F_(temp_v0, 0x10, unsigned short) | (F_(temp_v0, 0xE, unsigned short) << 0x10);
        temp_v0_2 = Object_LookupById(&sl.f14);
        if (temp_v0_2 != NULL) {
            (void)*(volatile int*)((char*)temp_v0_2 + 0xD0); F_(temp_v0_2, 0xD0, int) = 0;
        }
    }
    D_005723C8 = 0;
}
#pragma pop
