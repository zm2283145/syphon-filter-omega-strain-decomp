#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int operator_delete(char * );                          
extern void func_00416820();
extern void func_00416830();
extern void func_00416AD0();
extern void * const D_004E0960[];
extern void * const D_004E09B0[];
extern int D_00572130;

char * func_00416A00(char * arg0, long long arg1) {
    char * temp_v0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E0960));
        temp_v0 = (char *)(F_(arg0, 0x4, int));
        if (temp_v0 != NULL) {
            F_(temp_v0, 0x44, int) = (int)(temp_v0);
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09B0));
            D_00572130 -= 1;
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E0960[20] = { (void*)0x0, (void*)0x0, (void*)func_00416A00, (void*)func_00416830, (void*)0x416850, (void*)0x4168B0, (void*)0x4168D0, (void*)0x416870, (void*)0x416890, (void*)0x4168F0, (void*)0x416910, (void*)0x416930, (void*)0x416950, (void*)0x416970, (void*)0x4169B0, (void*)0x416990, (void*)func_00416820, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004E09B0[16] = { (void*)0x0, (void*)0x0, (void*)func_00416AD0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
