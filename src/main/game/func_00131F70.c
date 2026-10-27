/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

/* Sets matrix row 2. */
Mtx34* cMatrix_SetZAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[2].x = x;
    m->row[2].y = y;
    m->row[2].z = z;
    m->row[2].w = w;
    return m;
}

/* Sets matrix row 1. */
Mtx34* cMatrix_SetYAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[1].x = x;
    m->row[1].y = y;
    m->row[1].z = z;
    m->row[1].w = w;
    return m;
}

/* Sets matrix row 0. */
Mtx34* cMatrix_SetXAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[0].x = x;
    m->row[0].y = y;
    m->row[0].z = z;
    m->row[0].w = w;
    return m;
}

Vec4* cVector_ctor_float_float_float_float(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

Vec4* cVector_ctor_cVectorR(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
