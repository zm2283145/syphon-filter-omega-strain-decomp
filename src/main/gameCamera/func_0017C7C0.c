#include "types.h"
typedef struct { float p0, m0, p1, m1, t1, inv; } B5dSeg;
typedef struct { B5dSeg* seg; float t; } B5dCurve;
float Curve_Hermite(B5dCurve* c) {
    B5dSeg* s = c->seg;
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