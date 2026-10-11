#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004133B0(char *, int *, signed char *);                
int func_00419110(int, int, signed char *, int);               
extern char D_00571DC0;

int func_004191D0(int arg0, signed char *arg1, int arg2) {
    int sp4C;
    int var_v0;

    if ((arg1 == NULL) || (*arg1 == 0)) {
        return 0;
    }
    if (func_004133B0(&D_00571DC0, &sp4C, arg1) != 0) {
        var_v0 = func_00419110(arg0, sp4C, arg1, arg2);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
