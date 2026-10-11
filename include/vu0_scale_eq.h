#ifndef VU0_SCALE_EQ_H
#define VU0_SCALE_EQ_H
/* *v *= k on VU0 (mfc1/qmtc2.ni broadcast, vmulx.xyzw), emitted as written (vc1). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) VSE4;
static inline void VU0_ScaleEq(void* v, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(v)
        .set reorder
    }
}
/* Curve retime: scale two tangent segments by t*rate, store duration and 1/t.
 * Use under #pragma peephole off / opt_propagation off (0017D840 family).
 * The empty asm else-arm keeps retail's `b` over an empty else (barrier trick). */
typedef struct { VSE4 p; VSE4 v; } VSESeg;
typedef struct { char p0[0x40]; float len; } VSESrc;
typedef struct { char p0[0x60]; VSESeg a; VSESeg b; float dur; float rate; char p1[8]; VSESrc* src; float srclen; } VSECurve;
#define CURVE_RETIME_FUNC(NAME) \
void NAME(VSECurve* c, float t) { \
    float k; float r; \
    if (t < 0.0f) return; \
    k = t * c->rate; \
    { VSESeg* s = &c->a; VU0_ScaleEq(&s->v, k); } \
    { VSESeg* s = &c->b; VU0_ScaleEq(&s->v, k); } \
    c->dur = t; \
    r = 0.0f; if (t != 0.0f) r = 1.0f / t; else asm { .set reorder } c->rate = r; \
    c->srclen = c->src->len; \
}
#endif