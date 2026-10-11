#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00329930(char * , char * );                    

#pragma opt_propagation off
char * func_004181C0(unsigned int arg0, unsigned int arg1, char * arg2) {
    unsigned int var_s1;
    char * var_s0;

    var_s1 = arg1;
    var_s0 = arg2;
    if (arg0 < var_s1) {
        do {
            var_s1 -= 0x18;
            var_s0 -= 0x18;
            func_00329930(var_s0, (char * ) var_s1);
            F_(var_s0, 0xC, signed char) = F_(var_s1, 0xC, signed char);
            F_(var_s0, 0x10, int) = F_(var_s1, 0x10, int);
            F_(var_s0, 0x14, int) = F_(var_s1, 0x14, int);
        } while (arg0 < var_s1);
    }
    return var_s0;
}
