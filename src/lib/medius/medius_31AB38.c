#include "types.h"
float QuadraticPeak(float* out, float y0, float y1, float y2) {
    float a, b, t;
    a = (y0 + y2) * 0.5f - y1;
    b = (y2 - y0) * 0.5f;
    t = a != 0.0f ? -b / (a + a) : 0.0f;
    *out = (a * t + b) * t + y1;
    return t;
}