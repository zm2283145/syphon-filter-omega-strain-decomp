#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_00442C20();             
int func_00442D80();                          
int func_0044CA30();                          
int func_0044CA90();                                
int func_0044D510();                          
char * func_0044F290(int, int);                        

int func_00442B50(char * arg0, int arg1) {
    char * temp_v0;

    if (F_(arg0, 0x180, int) > 0) {
        if (func_0044CA90() == 0) {
            return 0;
        }
        if (func_0044CA30(arg0) == 0) {
            return 0;
        }
        goto block_5;
    }
block_5:
    if (F_(arg0, 0x2184, unsigned char) == 0) {
        temp_v0 = (char *)(func_0044F290(F_(arg0, 0x23DC, int), arg1));
        if (func_00442C20(arg0, temp_v0 + 0x80, arg0 + 0x1FFC) == 0) {
            return 0;
        }
        F_(arg0, 0x207C, int) = F_(temp_v0, 0x100, int);
        goto block_10;
    }
block_10:
    if (func_0044D510(arg0) == 0) {
        return 0;
    }
    return func_00442D80(arg0);
}
