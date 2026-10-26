#include "types.h"
typedef struct { char pad[0x3C]; } G4_E3C;
extern void cSplinedMotion_Scalar0To1_opAssign(G4_E3C* d, void* v);
void func_0035EDD0(G4_E3C* p, unsigned int n, void* v)
{
    for (; n != 0; n--, p++) {
        cSplinedMotion_Scalar0To1_opAssign(p, v);
    }
}