#include "types.h"
extern float Math_FMod(float, float);
static inline float fmax_(float a, float b) { float r; asm { max.s r, a, b } return r; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    char pad18[0x20];
    unsigned char b38;
} B7_AnimCh;
static inline float B7_Wrap(B7_AnimCh* p, float d)
{
    float r;
    if (!p->b38) {
        return d;
    }
    r = Math_FMod(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}
void AnimChannel_UpdateRate(B7_AnimCh* p, float dt, float speed)
{
    float d = B7_Wrap(p, p->f8 - p->f4);
    p->fC = speed * d;
    p->fC *= fmax_(0.0f, 1.0f - p->f14 * dt);
}