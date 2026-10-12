#include "types.h"
extern void Corona_Draw(void* a, void* b, void* c, int* d, int* zero, float* one, int flag, int e, int f);
/* Calls Corona_Draw with default zero / 1.0 parameters and the flag set. */
void func_00378170(void* a, void* b, void* c, int d, int e, int f)
{
    int dv = d;
    float one = 1.0f;
    int zero = 0;
    Corona_Draw(a, b, c, &dv, &zero, &one, 1, e, f);
}
