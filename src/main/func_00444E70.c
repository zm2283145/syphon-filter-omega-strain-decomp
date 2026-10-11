#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_002CF3A8();                                
extern unsigned char D_00584518;

int func_00444E70(void) {
    int temp_v0;

    if (D_00584518 == 0) {
        return 0;
    }
    temp_v0 = func_002CF3A8();
    if (temp_v0 == 0) {
        D_00584518 = 0;
    }
    return temp_v0;
}
