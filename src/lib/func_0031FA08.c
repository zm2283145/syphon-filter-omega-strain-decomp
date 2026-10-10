#include "types.h"
extern float D_004E1BE0;
float func_0031FA08(float a, float b, float c, float d)
{
    float r, m;
    if (b <= a * 1.25f && a * D_004E1BE0 <= b) {
        r = (a + b) * 0.5f;
    } else {
        if (c > d) { m = c; r = a; } else { m = d; r = b; }
        if (r < 30.0f) {
            if (m * r * 0.5f < 1.0f) {
                r = (a < b) ? b : a;
            }
        }
    }
    return r;
}