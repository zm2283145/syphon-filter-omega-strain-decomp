#include "types.h"
extern void func_003781B0(void* a, void* b, void* c, int* d, int* zero, float* one, int flag, int e, int f);
/* Calls func_003781B0 with default zero / 1.0 parameters and the flag set. */
void func_00378170(void* a, void* b, void* c, int d, int e, int f)
{
    int dv = d;
    float one = 1.0f;
    int zero = 0;
    func_003781B0(a, b, c, &dv, &zero, &one, 1, e, f);
}
