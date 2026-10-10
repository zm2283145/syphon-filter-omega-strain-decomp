#include "types.h"
static inline float clamp_B940(float a, float lo, float hi) { asm { max.s lo, a, lo
 min.s lo, lo, hi } return lo; }
typedef struct { char pad[8]; float f8; char pad2[0x38 - 0xC]; unsigned char b38; } Ch_B940;
extern float Math_FMod(float a, float b);void AnimChannel_ClampValue(Ch_B940* c) {
    float x = c->f8;
    float v;
    if (!c->b38) {
        v = clamp_B940(x, 0.0f, 1.0f);
    } else {
        v = Math_FMod(x, 1.0f);
        if (v < 0.0f) v += 1.0f;
    }
    c->f8 = v;
}