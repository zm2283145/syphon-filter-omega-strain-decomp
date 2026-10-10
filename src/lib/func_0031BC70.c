extern float D_004E1BEC;
extern float D_004E1BF0;
extern volatile float D_004E1BF4;
float func_0031BC70(float* prev, float a, float b, float cur, float d)
{
    float r;
    float lo = D_004E1BEC;
    if (*prev < lo) *prev = lo;
    if (cur < lo) cur = lo;
    if (__builtin_fabsf(b - a) < D_004E1BF0) {
        r = (b + a) * 0.5f;
    } else if (d < D_004E1BF4) {
        if (a < b) r = a * d / *prev;
        else r = b * d / cur;
    } else {
        if (a < b) r = b * d / cur;
        else r = a * d / *prev;
    }
    if (r < 0.0f) r = 0.0f;
    if (1.0f < r) r = 1.0f;
    *prev = cur;
    return r;
}