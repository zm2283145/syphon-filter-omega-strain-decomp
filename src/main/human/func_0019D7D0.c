#pragma cplusplus on
#include "types.h"
class Chan_b6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float Eval();
    float a4; float cur; float cC; float c10; unsigned char pad[0x3C - 0x14];
};
typedef struct { unsigned char pad[0x80]; Chan_b6* ch; } Anim_b6;
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_b6(float a, float b) { float r; asm { min.s r, a, b } return r; }
extern "C" void AnimChannel_Approach(Anim_b6* a, int idx, int wrap, float target, float step)
{
    Chan_b6* c = &a->ch[idx];
    float v = c->cur;
    float d = target - v;
    if (wrap) {
        if (d < -0.5f) {
            d += 1.0f;
        } else if (!(d <= 0.5f)) {
            d += -1.0f;
        }
    }
    v += fmin_b6(fmax_b6(d, -step), step);
    if (wrap) {
        if (v < 0.0f) {
            v += 1.0f;
        } else if (!(v <= 1.0f)) {
            v += -1.0f;
        }
    }
    c->c10 = v;
    c->cur = v;
    c->a4 = v;
    c->cC = c->Eval();
}