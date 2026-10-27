#include "types.h"
extern void cSplinedMotion_Scalar0To1_opAssign(void* p, int a);
void func_002C3840(char* p, int n, int a)
{
    while (n != 0) {
        cSplinedMotion_Scalar0To1_opAssign(p, a);
        n--;
        p += 0x3C;
    }
}