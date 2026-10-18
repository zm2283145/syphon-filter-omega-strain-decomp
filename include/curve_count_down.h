#ifndef CURVE_COUNT_DOWN_H
#define CURVE_COUNT_DOWN_H

/*
 * Curve count-down (same body as the matched QuatCurve_Timer): subtract dt
 * from the remaining time at +4, clamp at 0 with max.s, and report whether
 * it was running and has just reached 0. Plain C.
 */
typedef struct CurveCountDown { int pad0; float remaining; } CurveCountDown;

static inline float CurveCountDown_Max(float a, float b)
{
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}

#define DEFINE_CURVE_COUNT_DOWN(name)                                     \
    int name(CurveCountDown* p, float dt)                                 \
    {                                                                     \
        float old = p->remaining;                                         \
        p->remaining -= dt;                                               \
        p->remaining = CurveCountDown_Max(p->remaining, 0.0f);            \
        return old > 0.0f && p->remaining == 0.0f;                        \
    }

#endif /* CURVE_COUNT_DOWN_H */