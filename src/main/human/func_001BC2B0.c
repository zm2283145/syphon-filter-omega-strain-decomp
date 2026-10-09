/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Build a 4x4 matrix from a 3x4 block; last row becomes (0, 0, 0, 1). */
void Mtx44_FromMtx34(Mtx44* dst, Mtx34* src) {
    float m23, m22, m21, m20;
    float m13, m12, m11, m10;
    float m03, m02, m01, m00;

    m23 = src->m[2][3];
    m22 = src->m[2][2];
    m21 = src->m[2][1];
    m20 = src->m[2][0];
    m13 = src->m[1][3];
    m12 = src->m[1][2];
    m11 = src->m[1][1];
    m10 = src->m[1][0];
    m03 = src->m[0][3];
    m02 = src->m[0][2];
    m01 = src->m[0][1];
    m00 = src->m[0][0];
    dst->m[0][0] = m00;
    dst->m[0][1] = m01;
    dst->m[0][2] = m02;
    dst->m[0][3] = m03;
    dst->m[1][0] = m10;
    dst->m[1][1] = m11;
    dst->m[1][2] = m12;
    dst->m[1][3] = m13;
    dst->m[2][0] = m20;
    dst->m[2][1] = m21;
    dst->m[2][2] = m22;
    dst->m[2][3] = m23;
    dst->m[3][0] = 0.0f;
    dst->m[3][1] = 0.0f;
    dst->m[3][2] = 0.0f;
    dst->m[3][3] = 1.0f;
}
