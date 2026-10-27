#include "types.h"
typedef struct { float x, y, z; } Vec3_0017DD20;
extern float Libc_Cosf(float a);
extern float Libc_Sinf(float a);
/* cMatrix_ctor_cEulerAngleTR: rotation matrix from Euler angles (x, y, z), the
 * y-first variant of cMatrix_ctor_cEulerAngleTR_2. */
Mtx44* cMatrix_ctor_cEulerAngleTR(Mtx44* m, Vec3_0017DD20* angles)
{
    /* declaration order sets the saved FPR of each value (retail's f20-f24) */
    float czcy, cy, y, sz, szsy, z, sy, x, sx, cx, cz, czsy, szcy;
    y = angles->y;
    x = angles->x;
    z = angles->z;
    cy = Libc_Cosf(y);
    sy = Libc_Sinf(y);
    cx = Libc_Cosf(x);
    sx = Libc_Sinf(x);
    cz = Libc_Cosf(z);
    sz = Libc_Sinf(z);
    czsy = cz * sy;
    szcy = sz * cy;
    czcy = cz * cy;
    szsy = sz * sy;
    m->m[0][0] = czcy - szsy * sx;
    m->m[0][1] = szcy + czsy * sx;
    m->m[0][2] = -cx * sy;
    m->m[1][0] = -sz * cx;
    m->m[1][1] = cz * cx;
    m->m[1][2] = sx;
    m->m[2][0] = czsy + szcy * sx;
    m->m[2][1] = szsy - czcy * sx;
    m->m[2][2] = cx * cy;
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    m->m[3][0] = 0.0f;
    m->m[3][1] = 0.0f;
    m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
    return m;
}
