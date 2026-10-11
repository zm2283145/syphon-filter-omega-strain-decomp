#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern float D_005723D8;
extern float D_005723E0;
extern int D_005723E8;

void func_00429CB0(int arg0) {
    if (arg0 < 0x3E8 && 0 <= arg0) {
        D_005723E8 += 1;
        D_005723E0 += 0.001f * (float) arg0;
        D_005723D8 = D_005723E0 / (float) D_005723E8;
    }
}
