#include "types.h"

extern void cNetMsg_GetFloat_floatR(float* out);

/* Fills a point from three successive cNetMsg_GetFloat_floatR reads (x, y, z) with w = 1. */
void cNetMsg_GetVector(Vec4* out) {
    float z, y, x;
    cNetMsg_GetFloat_floatR(&x);
    out->x = x;
    cNetMsg_GetFloat_floatR(&y);
    out->y = y;
    cNetMsg_GetFloat_floatR(&z);
    out->z = z;
    out->w = 1.0f;
}
