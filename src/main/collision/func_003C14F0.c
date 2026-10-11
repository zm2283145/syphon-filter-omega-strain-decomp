
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_C14;
typedef struct { char pad[0x40]; V4_C14 n; } C14_P;
static inline float Abs_C14(float x) { float r; asm { abs.s r, x } return r; }
static inline float Dot_C14(void* b, void* a) {
    void* pa = a; void* pb = b;
    int t;
    float r;
    asm {
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
int func_003C14F0(C14_P* a, C14_P* b, float eps) {
    float d = Dot_C14(&b->n, &a->n);
    int r = 1;
    if (Abs_C14(d) < eps) r = 0;
    return r;
}
