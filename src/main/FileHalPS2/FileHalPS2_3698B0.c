#include "types.h"
long long SoftFloat_FloatToDouble(float f);
int func_0011C200(int a, long long b);
long long func_0011C268(long long a, long long b);
int func_0011C7A0(int v);
long long func_0011C858(int v);
extern int D_00572538;

/* Soft-float double helper chain on D_00572538 (constant 0x3FB0000000000000 = 0.0625). */
long long Time_GetMilliseconds(void) {
    int v = D_00572538;
    int n = func_0011C7A0(v);
    return (long long)(func_0011C858(func_0011C200(n, func_0011C268((long long)0x3FB00000 << 0x20, SoftFloat_FloatToDouble((float)v)))) << 0x20) >> 0x20;
}
