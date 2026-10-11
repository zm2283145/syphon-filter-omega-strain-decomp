#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_002CA350(int);                               
extern int D_004FFC04;

#pragma opt_common_subs off
void func_0028A470(int arg0) {
    if (F_(arg0, 0x80, unsigned char) == 0) {
        func_002CA350(D_004FFC04);
        F_(arg0, 0x80, unsigned char) = 1U;
    }
}
