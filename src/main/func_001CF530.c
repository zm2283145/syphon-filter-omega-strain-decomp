#include "types.h"
#include "vu0_scale_eq.h"
typedef struct { VSESeg a; VSESeg b; float dur; float rate; } C_F530;
#pragma push
#pragma peephole off
#pragma opt_propagation off
void func_001CF530(C_F530* c, float t) {
    float k; float r;
    k = t * c->rate;
    { VSESeg* s = &c->a; VU0_ScaleEq(&s->v, k); }
    { VSESeg* s = &c->b; VU0_ScaleEq(&s->v, k); }
    c->dur = t;
    r = 0.0f; if (t != 0.0f) r = 1.0f / t; else asm { .set reorder } c->rate = r;
}
#pragma pop