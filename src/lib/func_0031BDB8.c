#include "types.h"
extern float D_004E1BE0;
float func_0031BDB8(float a, float b, float c, float d)
{
    float r, hi;
    if (b <= a * 1.25f && a * D_004E1BE0 <= b) {
        r = (a + b) * 0.5f;
    } else {
        if (d < c) { hi = c; r = a; }
        else { hi = d; r = b; }
        if (r < 30.0f && hi * r * 0.5f < 1.0f) {
            r = b;
            if (!(a < b)) r = a;
        }
    }
    return r;
}