#include "types.h"

extern void NetRead_Float(float* out);

/* Fills a point from three successive NetRead_Float reads (x, y, z) with w = 1. */
void func_00197500(Vec4* out) {
    float z, y, x;
    NetRead_Float(&x);
    out->x = x;
    NetRead_Float(&y);
    out->y = y;
    NetRead_Float(&z);
    out->z = z;
    out->w = 1.0f;
}
