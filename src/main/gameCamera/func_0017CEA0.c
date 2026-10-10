#include "types.h"
typedef struct { char pad[0x40]; float f40; float f44; } A1_X;
typedef struct { A1_X* x; float t; } A1_P;
extern void func_0017CEE0(void* a, A1_X* x, float r);
void func_0017CEA0(void* a, A1_P* p) {
    A1_X* x = p->x;
    float d = x->f40 - p->t;
    float r;
    if (x->f40 != 0.0f) r = d * x->f44;
    else r = 1.0f;
    func_0017CEE0(a, x, r);
}