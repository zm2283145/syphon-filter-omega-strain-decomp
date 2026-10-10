#include "types.h"
typedef struct { int a[4]; float f; } T_001BED50;
typedef struct { T_001BED50* t; float v; } D_001BED50;
void func_001BED50(D_001BED50* d, T_001BED50* t, float v) {
    d->t = t;
    if (v < 0.0f) v = t->f;
    d->v = v;
}