extern float D_004B3968[];
extern float D_004E1C88; /* 1.333f in .lit4 */

int func_0031CB78(float f, float *spec, float *out, float thr)
{
    float hi = f * D_004E1C88;
    float lo = f * 0.75f;
    int i = 0;
    int best;
    float m;
    while (D_004B3968[i] < lo) i++;
    m = spec[i];
    best = i;
    do {
        if (m < spec[i]) {
            m = spec[i];
            best = i;
        }
        i++;
    } while (i < 74 && D_004B3968[i] <= hi);
    if (m < thr)
        *out = (thr + m) * 0.5f;
    else
        *out = m;
    return best;
}




