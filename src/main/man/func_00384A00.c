/*
 * Matched functions (byte-identical with the retail executable).
 * In-place 4x4 matrix transpose.
 */

#include "types.h"
#include "man_types.h"

/* Each swap uses its own pair of locals (keeps the original scheduling). */
ManMatrix* Matrix_TransposeInPlace(ManMatrix* mat) {
    float a01, a10, a02, a20, a12, a21, a03, a30, a13, a31, a23, a32;

    a01 = mat->m[0][1];
    a10 = mat->m[1][0];
    mat->m[0][1] = a10;
    mat->m[1][0] = a01;
    a02 = mat->m[0][2];
    a20 = mat->m[2][0];
    mat->m[0][2] = a20;
    mat->m[2][0] = a02;
    a12 = mat->m[1][2];
    a21 = mat->m[2][1];
    mat->m[1][2] = a21;
    mat->m[2][1] = a12;
    a03 = mat->m[0][3];
    a30 = mat->m[3][0];
    mat->m[0][3] = a30;
    mat->m[3][0] = a03;
    a13 = mat->m[1][3];
    a31 = mat->m[3][1];
    mat->m[1][3] = a31;
    mat->m[3][1] = a13;
    a23 = mat->m[2][3];
    a32 = mat->m[3][2];
    mat->m[2][3] = a32;
    mat->m[3][2] = a23;
    return mat;
}
