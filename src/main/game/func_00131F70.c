/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

/* Sets matrix row 2. */
Mtx34* Mtx_SetRow2(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[2].x = x;
    m->row[2].y = y;
    m->row[2].z = z;
    m->row[2].w = w;
    return m;
}

/* Sets matrix row 1. */
Mtx34* Mtx_SetRow1(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[1].x = x;
    m->row[1].y = y;
    m->row[1].z = z;
    m->row[1].w = w;
    return m;
}

/* Sets matrix row 0. */
Mtx34* Mtx_SetRow0(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[0].x = x;
    m->row[0].y = y;
    m->row[0].z = z;
    m->row[0].w = w;
    return m;
}

Vec4* func_00132000(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

Vec4* Vec4_Assign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
