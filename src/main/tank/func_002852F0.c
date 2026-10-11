#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_002852F0(int arg0) {
    return F_(F_(arg0, 0x60, int), 0x40, float);
}
