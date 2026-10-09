/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

/* Sets the three rows of a 3x4 matrix from three 4-float vectors. */
Mtx34* Mtx_SetBasis(Mtx34* m, Float4* r0, Float4* r1, Float4* r2) {
    float w0 = r0->w, z0 = r0->z, y0 = r0->y, x0 = r0->x;
    float w1, z1, y1, x1;
    float w2, z2, y2, x2;

    m->row[0].x = x0;
    m->row[0].y = y0;
    m->row[0].z = z0;
    m->row[0].w = w0;
    w1 = r1->w; z1 = r1->z; y1 = r1->y; x1 = r1->x;
    m->row[1].x = x1;
    m->row[1].y = y1;
    m->row[1].z = z1;
    m->row[1].w = w1;
    w2 = r2->w; z2 = r2->z; y2 = r2->y; x2 = r2->x;
    m->row[2].x = x2;
    m->row[2].y = y2;
    m->row[2].z = z2;
    m->row[2].w = w2;
    return m;
}
