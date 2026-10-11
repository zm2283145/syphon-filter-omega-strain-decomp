#include "types.h"
typedef struct { float x, y, z, w; } V_190880;
V_190880* func_00190880(V_190880* v, unsigned char axis, float w)
{
    v->w = w;
    switch (axis) {
    case 0: v->x = 1.0f; v->y = 0.0f; v->z = 0.0f; break;
    case 1: v->x = 0.0f; v->y = 1.0f; v->z = 0.0f; break;
    case 2: v->x = 0.0f; v->y = 0.0f; v->z = 1.0f; break;
    }
    return v;
}