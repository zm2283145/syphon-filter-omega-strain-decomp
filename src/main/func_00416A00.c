#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int operator_delete(char * );                          
extern char D_004E0960;
extern char D_004E09B0;
extern int D_00572130;

char * func_00416A00(char * arg0, long long arg1) {
    char * temp_v0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&D_004E0960);
        temp_v0 = (char *)(F_(arg0, 0x4, int));
        if (temp_v0 != NULL) {
            F_(temp_v0, 0x44, int) = (int)(temp_v0);
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&D_004E09B0);
            D_00572130 -= 1;
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
