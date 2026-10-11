#include "types.h"
extern char D_0055A300[];
void func_0036A2B0(void* p);
void Pad_Construct(void* p, int a, int b, int c);
#pragma opt_propagation off
void func_00165DD0(void)
{
    float f;
    int v;
    func_0036A2B0(D_0055A300);
    f = 56.0f;
    v = (int)f;
    Pad_Construct(D_0055A300, 0, 0, v);
    Pad_Construct(D_0055A300, 1, 0, v);
}
#pragma opt_propagation reset