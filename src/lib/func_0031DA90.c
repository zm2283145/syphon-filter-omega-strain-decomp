#include "types.h"
extern volatile float D_004E1C48;
extern volatile float D_004E1C5C;
extern volatile float D_004E1CF0;
extern volatile float D_004E1BE0;
extern volatile float D_004E1C50;
extern volatile float D_004E1C4C;
float func_0031DA90(float a, float b, float c, float d, float e)
{
    float k;
    if (a <= D_004E1C48) b = 0.0f;
    k = D_004E1C5C;
    if (k <= a) {
        a -= k;
        if (a * (d * 0.5f) < 1.0f) a += D_004E1CF0;
        if (b < a) b = a;
    }
    if (b < c && D_004E1CF0 <= c) {
        if (d < e * 1.25f && e * D_004E1BE0 < d) b = b * D_004E1C50 + c * D_004E1C4C;
        {
            float m = D_004E1CF0;
            if (b < m) b += m;
        }
    }
    return b;
}

