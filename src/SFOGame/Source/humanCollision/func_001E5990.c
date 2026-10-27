#include "types.h"
extern float D_004A0340;
extern float D_004A0338;
static inline float fmax_(float a, float b) { float r; asm { max.s r, a, b } return r; }
void ActorBody_CalcQueryHeight(float* outTop, float* outRatio, int flag, float base, float floor, float height, float scale)
{
    float top = base + height;
    float d = top - floor;
    float c;
    float m;
    float r;
    c = flag ? D_004A0340 : D_004A0338;
    m = fmax_(0.5f * (d - c), height * scale);
    *outTop = top - m;
    if (m != height) r = m / height; else r = 1.0f;
    *outRatio = r;
}