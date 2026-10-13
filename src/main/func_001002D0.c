#include "types.h"
extern float SoftFloat_S64ToFloat(long long);
float SoftFloat_U64ToFloat(unsigned long long x) {
    float f;
    if ((long long)x > 0) return SoftFloat_S64ToFloat(x);
    f = SoftFloat_S64ToFloat((x >> 1) | (x & 1));
    return f + f;
}