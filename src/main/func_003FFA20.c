#include "types.h"
float func_003FFA20(float* p, float a, float b) {
    float d = (a - b) / 8.0f;
    float r = b + d;
    if (d < 0.0f) {
        d = -d;
    }
    if (d > *p) {
        *p = d;
    }
    return r;
}