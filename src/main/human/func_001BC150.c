/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Store a 3x4 block into rows 1..3 of a 4x4 matrix (xyz first, then w). */
void Mtx44_SetRows123FromMtx34(Mtx44* dst, Mtx34* src) {
    dst->m[1][0] = src->m[0][0];
    dst->m[1][1] = src->m[0][1];
    dst->m[1][2] = src->m[0][2];
    dst->m[2][0] = src->m[1][0];
    dst->m[2][1] = src->m[1][1];
    dst->m[2][2] = src->m[1][2];
    dst->m[3][0] = src->m[2][0];
    dst->m[3][1] = src->m[2][1];
    dst->m[3][2] = src->m[2][2];
    dst->m[1][3] = src->m[0][3];
    dst->m[2][3] = src->m[1][3];
    dst->m[3][3] = src->m[2][3];
}
