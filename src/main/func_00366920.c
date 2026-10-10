#include "types.h"
typedef struct { int a[4]; float f; } T_00366920;
typedef struct { T_00366920* t; float v; } D_00366920;
void func_00366920(D_00366920* d, T_00366920* t, float v) {
    d->t = t;
    if (v < 0.0f) v = t->f;
    d->v = v;
}