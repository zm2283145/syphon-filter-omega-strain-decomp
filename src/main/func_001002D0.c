#include "types.h"
extern float func_0011B888(long long);
float func_001002D0(unsigned long long x) {
    float f;
    if ((long long)x > 0) return func_0011B888(x);
    f = func_0011B888((x >> 1) | (x & 1));
    return f + f;
}