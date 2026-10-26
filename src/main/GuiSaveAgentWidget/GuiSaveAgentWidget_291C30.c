#include "types.h"
extern void cSplinedMotion_Scalar0To1_opAssign(void* p, int x);
void func_00291C30(char* p, int n, int x)
{
    for (; n != 0; n--) {
        cSplinedMotion_Scalar0To1_opAssign(p, x);
        p += 0x3C;
    }
}