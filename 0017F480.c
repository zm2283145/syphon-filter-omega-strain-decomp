#pragma exceptions on
#pragma cplusplus on
#include "types.h"
struct C5Key { float t; float v; C5Key() {} };
struct C5Curve {
    C5Key k[2]; int a; int b;
    C5Curve(float t, float v) { k[0].t = t; k[0].v = v; k[1].t = t; k[1].v = v; a = 0; b = 0; }
};
struct C5PhysBase {
    void* vt; float cur; float prev; float rate; float target; int flags;
    C5Curve curve; C5Curve* pcurve; int n;
};
extern "C" char D_004DA380[];
extern "C" C5PhysBase* PhysicalBase_Construct(C5PhysBase* p, const float* a, const float* b);
inline void* operator new(unsigned int, void* q) { return q; }
extern "C" C5PhysBase* PhysicalBase_Construct(C5PhysBase* p, const float* a, const float* b) {
    p->vt = D_004DA380;
    p->cur = *a;
    p->prev = *a;
    p->rate = *b;
    p->target = *a;
    p->flags = 0;
    new (&p->curve) C5Curve(*a, *b * 0.0f);
    p->pcurve = &p->curve;
    p->n = 0;
    return p;
}