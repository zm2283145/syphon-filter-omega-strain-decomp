#include "types.h"
extern void func_0031B898(float* data, int bits);
extern void func_0031B9C0(float* data, int n);
extern void func_0031B4E0(float* data, int bits);
void func_0031B190(float* data, int bits, int flags)
{
    int n = 1 << bits;
    int i;
    float s;
    func_0031B898(data, bits);
    func_0031B9C0(data, n >> 1);
    func_0031B4E0(data, bits - 1);
    if (!(flags & 8)) {
        s = 1.0f / n;
        for (i = 0; i < n; i++) data[i] *= s;
    }
}