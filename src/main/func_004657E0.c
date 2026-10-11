#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003A6650(int);                                 
int func_00465A40();                                  
extern unsigned char D_0051EEB0;

void func_004657E0(int d0, char * arg1) {
    int var_v1;

    if (D_0051EEB0 != 0) {
        var_v1 = F_(arg1, 0x0, unsigned short) == 1;
        if (var_v1 != 0) {
            var_v1 = F_(arg1, 0x2, unsigned short) == 0;
        }
        var_v1 = var_v1 ? F_(arg1, 0x8, unsigned short) == 0x10 : var_v1;
        if (var_v1 != 0) {
            var_v1 = F_(arg1, 0x6, unsigned short) == 0;
        }
        if (var_v1 != 0) {
            func_003A6650(1);
        }
        return;
    }
    func_00465A40();
}
