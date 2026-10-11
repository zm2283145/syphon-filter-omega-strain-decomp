#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int func_003960F0(int, int);                            
int func_003A94C0(int );                            

void func_003A9450(int arg0) {
    int temp_a0;
    int temp_s0;

    temp_a0 = arg0 + 0x18;
    if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
        func_003960F0(temp_a0, 0);
    }
    temp_s0 = arg0 + 0x18;
    if (temp_s0 != NULL) {
        func_003A94C0(temp_s0);
        F_(temp_s0, 0xC, signed char) = 1;
    }
}
