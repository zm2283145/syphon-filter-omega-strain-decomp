#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0041C3E0();                                  

void func_00420BE0(int arg0) {
    int temp_a0;

    func_0041C3E0();
    temp_a0 = F_(arg0, 0x78, int);
    if (temp_a0 != NULL) {
        F_(temp_a0, 0x58, signed char) = 1;
    }
}
