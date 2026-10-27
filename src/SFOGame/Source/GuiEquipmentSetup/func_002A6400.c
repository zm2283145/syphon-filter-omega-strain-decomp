#include "types.h"
typedef struct { char pad[0x3C]; } E2A64;
extern void cSplinedMotion_Scalar0To1_opAssign(E2A64* e, int a);
void func_002A6400(E2A64* p, int n, int a)
{
    while (n != 0) {
        cSplinedMotion_Scalar0To1_opAssign(p, a);
        n--;
        p++;
    }
}