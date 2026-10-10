#include "types.h"
void func_001B87E0(float* p, float* ang) {
    float a = *ang;
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    p[1] += a;
    p[2] += a;
    p[4] += a;
    p[6] += a;
    p[8] += a;
}