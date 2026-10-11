#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Object_LookupById(int *);
int func_002EB650(void **);
extern unsigned char D_005723C8;
#define CLR_(b, o) { (void)*(volatile int*)((char*)(b) + (o)); F_(b, o, int) = 0; }
#pragma push
#pragma opt_common_subs off
void func_00212040(void) {
    struct { char pad[0x14]; int id[1]; int buf[2]; } sl;
    int temp_v0;
    int temp_v0_2;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650((void**)sl.buf) == 0) {
        temp_v0 = F_(sl.buf[0], 0x1C, int);
        sl.id[0] = F_(temp_v0, 0x10, unsigned short) | (F_(temp_v0, 0xE, unsigned short) << 0x10);
        temp_v0_2 = Object_LookupById(sl.id);
        if (temp_v0_2 != 0) {
            CLR_(temp_v0_2, 0xD0);
            CLR_(temp_v0_2, 0x128);
        }
    }
    D_005723C8 = 0;
}
#pragma pop
