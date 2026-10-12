#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Loc_LookupText(signed char *);                           
signed char *func_001692D0(int);                             
int func_00274A60();                                
int sprintf(int, int *, int, int);                      

int func_002749B0(int arg0, int arg1) {
    int temp_v0;
    int var_a3;
    signed char *temp_v0_2;

    if (arg1 == 0) {
        return 0;
    }
    temp_v0 = func_00274A60();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0_2 = func_001692D0(arg0 + 0x28);
    var_a3 = 0;
    if ((temp_v0_2 != NULL) && (*temp_v0_2 != 0)) {
        var_a3 = Loc_LookupText(temp_v0_2);
    }
    if (var_a3 != 0) {
        sprintf(arg1, ((int*)"%s %s"), temp_v0, var_a3);
        return arg1;
    }
    return temp_v0;
}
