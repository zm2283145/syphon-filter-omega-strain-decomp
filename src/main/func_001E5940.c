#include "types.h"
/* clamp helper: s - 2*max(0.5*(s-b-k), c*d) - b, k picked by flag */
extern float D_004A0340;
extern float D_004A0338;
static inline float fmax_(float a, float b) { float r; asm { .set noreorder; max.s r, a, b; .set reorder } return r; }
#pragma push
#pragma opt_propagation off
float ActorPhys_ResponseHeightDelta(int flag, float a, float b, float c, float d)
{
    float s;
    float t;
    float k;
    float u;
    float h;
    s = a + c;
    t = s - b;
    if (flag) k = D_004A0340; else k = D_004A0338;
    h = fmax_(0.5f * (t - k), c * d);
    u = s - h;
    return u - h - b;
}
#pragma pop
