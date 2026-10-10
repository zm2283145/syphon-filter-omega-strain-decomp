#include "types.h"
typedef struct { char pad0[8]; float t; char pad1[0x38 - 0xC]; unsigned char wrap; } B4Obj3;
extern float Math_FMod(float, float);
static inline float b4clamp(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
void func_00365100(B4Obj3* p) {
    float t = p->t;
    float r;
    if (!p->wrap) {
        r = b4clamp(t, 0.0f, 1.0f);
    } else {
        r = Math_FMod(t, 1.0f);
        if (r < 0.0f) r += 1.0f;
    }
    p->t = r;
}