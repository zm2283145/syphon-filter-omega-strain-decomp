#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int D_0049D010;
#pragma push

int func_0029BD70(int arg0) {
    int v = F_(arg0, 0x30, int); return (v && F_(v, 0x4C, int) == D_0049D010) ? v : 0;
}
#pragma pop