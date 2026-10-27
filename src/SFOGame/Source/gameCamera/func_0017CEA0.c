#include "types.h"
typedef struct { char pad[0x40]; float f40; float f44; } A1_X;
typedef struct { A1_X* x; float t; } A1_P;
extern void cHermiteSpline_cVector_Evaluate(void* a, A1_X* x, float r);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(void* a, A1_P* p) {
    A1_X* x = p->x;
    float d = x->f40 - p->t;
    float r;
    if (x->f40 != 0.0f) r = d * x->f44;
    else r = 1.0f;
    cHermiteSpline_cVector_Evaluate(a, x, r);
}