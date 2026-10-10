#include "types.h"
extern unsigned char D_004912E8;
extern int* D_004912F0;
extern unsigned int* D_004912F4;
extern unsigned int D_0052980C;
extern unsigned int D_00529808;
#pragma optimization_level 3
int NetMsg_RegisterTypeCore(unsigned int* out, unsigned int type, int value)
{
    int r = 3;
    if (D_004912E8 == 1 && D_004912F0 != 0 && D_004912F4 != 0) {
        r = 2;
        if (out != 0 && type < D_0052980C) {
            unsigned int n = D_004912F4[type];
            r = 5;
            if (n <= D_00529808) {
                D_004912F4[type] = n + 1;
                r = 0;
                *out = n;
                D_004912F0[type * D_00529808 + n] = value;
            }
        }
    }
    return r;
}
#pragma optimization_level reset