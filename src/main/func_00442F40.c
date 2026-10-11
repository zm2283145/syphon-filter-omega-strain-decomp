#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0044F880(int, int, int, int);                      
int func_00452FC0();                                  

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
int func_00442F40(char * arg0, int d1, int arg2) {
    if (F_(arg0, 0x255C, int) != 9) {
        return 0;
    }
    F_(arg0, 0x255C, int) = 2;
    func_00452FC0();
    F_(arg0, 0x23E0, int) = arg2;
    { int w = 0x20; func_0044F880(F_(arg0, 0x23E0, int), w, w, 0x44); }
    return 1;
}

#pragma pop
