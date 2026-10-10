#include "types.h"

/* Sets all 16 matrix elements (row-major) and returns the matrix. */
Mtx44* Mtx44_Set(Mtx44* m, float m00, float m01, float m02, float m03,
                     float m10, float m11, float m12, float m13,
                     float m20, float m21, float m22, float m23,
                     float m30, float m31, float m32, float m33)
{
    m->m[0][0] = m00; m->m[0][1] = m01; m->m[0][2] = m02; m->m[0][3] = m03;
    m->m[1][0] = m10; m->m[1][1] = m11; m->m[1][2] = m12; m->m[1][3] = m13;
    m->m[2][0] = m20; m->m[2][1] = m21; m->m[2][2] = m22; m->m[2][3] = m23;
    m->m[3][0] = m30; m->m[3][1] = m31; m->m[3][2] = m32; m->m[3][3] = m33;
    return m;
}
