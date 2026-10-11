#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_001152B8();                       
int sprintf();                      
extern char D_004BC9A0;
extern char D_004BC9C0;
extern char D_004BC9F0;

int LibInit_LoadIrxModule(char *arg0, int arg1, int arg2, int arg3) {
    int spF0[8];
    int spB0[16];
    int sp60[20];
    int temp_v0;
    int var_s0;

    sprintf(spF0, &D_004BC9A0, arg0);
    var_s0 = 0;
loop_1:
    temp_v0 = func_001152B8(spF0, arg1, arg2);
    if (temp_v0 < 0) {
        var_s0 += 1;
        if (var_s0 >= 0x32) {

        } else {
            goto loop_1;
        }
    }
    if ((temp_v0 < 0) && (arg3 != 0)) {
        sprintf(spB0, &D_004BC9C0, spF0, -temp_v0);
    }
    if (var_s0 != 0) {
        sprintf(sp60, &D_004BC9F0, (char *) var_s0);
    }
    return temp_v0;
}
