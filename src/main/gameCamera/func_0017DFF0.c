#include "types.h"
#pragma cplusplus on
typedef struct { float p0, m0, p1, m1, t1, inv; } SSeg;
class SCurve {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(float, float);
    float f4; float f8; float fC; float f10; float f14;
    float f18; float f1C; float f20; float f24; float f28; float f2C;
    SSeg* seg; float t;
};
static inline float SC_Max(float a, float b) {
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}
static inline bool SC_CountDown(SCurve* p, float dt) {
    float old = p->t;
    p->t -= dt;
    p->t = SC_Max(p->t, 0.0f);
    return old > 0.0f && p->t == 0.0f;
}
static inline bool SC_HasRemaining(SCurve* c) { return !(c->t == 0.0f); }
static inline float SC_Hermite(SCurve* c) {
    SSeg* s = c->seg;
    float t2, t3, t;
    float h0, h1, h2, h3;
    float d = s->t1 - c->t;
    if (0.0f != s->t1) {
        t = d * s->inv;
    } else {
        t = 1.0f;
    }
    t2 = t * t;
    t3 = t2 * t;
    h0 = 1.0f + (2.0f * t3 - 3.0f * t2);
    h1 = -2.0f * t3 + 3.0f * t2;
    h2 = t + (t3 - 2.0f * t2);
    h3 = t3 - t2;
    return h0 * s->p0 + h1 * s->p1 + h2 * s->m0 + h3 * s->m1;
}
extern "C" bool ScalarCurve_Advance(SCurve* p, float dt, float b) {
    bool done;
    p->f4 = p->f8;
    p->v4();
    done = SC_CountDown(p, dt);
    if (SC_HasRemaining(p)) {
        p->f8 = SC_Hermite(p);
        p->v5();
    } else {
        p->f8 = p->f10;
    }
    p->v6(dt, b);
    return done;
}
