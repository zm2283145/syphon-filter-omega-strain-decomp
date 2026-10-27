#pragma cplusplus on
#pragma exceptions off
#include "types.h"
struct V4C4 { float x, y, z, w; V4C4() {} };
struct VecCurveBaseD4 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual V4C4 get();
};
struct VecCurveD4 : VecCurveBaseD4 { char pad[0x1C]; V4C4 start; V4C4 cur; V4C4 rate; V4C4 x50; char x60[0x10]; };
extern "C" void cVector_opAssign(V4C4* d, V4C4* s);
extern "C" void cHermiteSplineWithScaledDuration_cVector_Reset(void* a, V4C4* b, V4C4* c, V4C4* d, V4C4* e);
extern "C" void cSplinedMotion_cVector_ResetCurrValAndZeroOutCurrVelocity(VecCurveD4* c, V4C4* v)
{
    V4C4 a = c->get();
    cVector_opAssign(&c->start, v);
    cVector_opAssign(&c->cur, &a);
    V4C4 b = c->get();
    cHermiteSplineWithScaledDuration_cVector_Reset(c->x60, &c->start, &c->cur, &c->rate, &b);
}