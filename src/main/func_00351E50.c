#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0013BCB0();                                  
int func_00351EE0(char * , char * );                    

char * func_00351E50(char * arg0, char * arg1) {
    char * var_a0;
    char * var_v1;
    char * temp_s2;

    func_0013BCB0();
    var_a0 = arg0 + 0x10;
    var_v1 = arg1 + 0x10;
    F_(arg0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
    do {
        F_(var_a0, 0x0, unsigned char) = F_(var_v1, 0x0, unsigned char);
        F_(var_a0, 0x4, int) = F_(var_v1, 0x4, int);
        F_(var_a0, 0x8, int) = F_(var_v1, 0x8, int);
        var_a0 += 0xC;
        var_v1 += 0xC;
    } while (var_a0 != arg0 + 0x4C);
    temp_s2 = arg0 + 0x4C;
    func_00351EE0(temp_s2, arg1 + 0x4C);
    F_(temp_s2, 0xC, unsigned char) = F_(arg1, 0x58, unsigned char);
    return arg0;
}
