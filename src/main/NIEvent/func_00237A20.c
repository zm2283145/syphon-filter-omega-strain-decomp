#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00239A90(float, char * );                       
int func_0023E5D0(char * );                            

void cNIEventLight_v48(char * arg0) {
    F_(arg0, 0x18C, signed char) = 1;
    if (F_(arg0, 0x184, int) == -1) {
        func_00239A90(*(float *)((char *)F_(arg0, 0x17C, int) + ((F_(arg0, 0x178, int) - 1) * 0x10)) - F_(arg0, 0x188, float), arg0 + 0x170);
    }
    F_(arg0, 0x1AC, signed char) = 1;
    if (F_(arg0, 0x1A4, int) == -1) {
        func_00239A90(*(float *)((char *)F_(arg0, 0x19C, int) + ((F_(arg0, 0x198, int) - 1) * 0x10)) - F_(arg0, 0x1A8, float), arg0 + 0x190);
    }
    func_0023E5D0(arg0);
}
