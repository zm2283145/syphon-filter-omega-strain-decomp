#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void func_003D0810(int arg0, int arg1) {
    if (F_(arg0, 0x59, unsigned char) == 0) {
        F_(arg0, 0x30, float) = F_(arg1, 0x0, float);
        F_(arg0, 0x34, float) = F_(arg1, 0x4, float);
        F_(arg0, 0x38, float) = F_(arg1, 0x8, float);
        F_(arg0, 0x3C, float) = F_(arg1, 0xC, float);
    }
}
