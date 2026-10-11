#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma push
#pragma optimization_level 3
int func_0013EEB0(char * arg0, char * arg1) {
    unsigned int b = F_(arg1, 0x68, int);
    unsigned int a = F_(arg0, 0x68, int);
    if (a < b) return -1; asm { .set reorder } /* barrier: keeps retail label padding */ return b < a;
}
#pragma pop