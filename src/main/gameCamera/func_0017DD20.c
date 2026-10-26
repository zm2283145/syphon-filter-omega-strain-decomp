#include "types.h"
typedef struct { float x, y, z; } Vec3_0017DD20;
extern float Math_Cos(float a);
extern float Math_Sin(float a);
/* Mtx_FromEuler_17DD20: rotation matrix from Euler angles (x, y, z), the
 * y-first variant of Mtx_FromEuler. */
Mtx44* Mtx_FromEuler_17DD20(Mtx44* m, Vec3_0017DD20* angles)
{
    /* declaration order sets the saved FPR of each value (retail's f20-f24) */
    float czcy, cy, y, sz, szsy, z, sy, x, sx, cx, cz, czsy, szcy;
    y = angles->y;
    x = angles->x;
    z = angles->z;
    cy = Math_Cos(y);
    sy = Math_Sin(y);
    cx = Math_Cos(x);
    sx = Math_Sin(x);
    cz = Math_Cos(z);
    sz = Math_Sin(z);
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
