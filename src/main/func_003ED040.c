#include "types.h"
typedef struct { float x, y, z; } Vec3_003ED040;
extern float Math_Cos(float a);
extern float Math_Sin(float a);
/* Build a rotation matrix from Euler angles (x, y, z). */
Mtx44* Mtx_FromEuler(Mtx44* m, Vec3_003ED040* angles)
{
    /* declaration order chosen to reproduce the original register allocation */
    float z;
    float cy;
    float czcx;
    float sx;
    float cx;
    float sy;
    float czsx;
    float szsx;
    float sz;
    float y;
    float x;
    float szcx;
    float cz;
    x = angles->x;
    y = angles->y;
    z = angles->z;
    cx = Math_Cos(x);
    sx = Math_Sin(x);
    cy = Math_Cos(y);
    sy = Math_Sin(y);
    cz = Math_Cos(z);
    sz = Math_Sin(z);
    czsx = cz * sx;
    szsx = sz * sx;
    szcx = sz * cx;
    czcx = cz * cx;
    m->m[0][0] = cz * cy;
    m->m[0][1] = sz * cy;
    m->m[0][2] = -sy;
    m->m[1][0] = czsx * sy - szcx;
    m->m[1][1] = czcx + szsx * sy;
    m->m[1][2] = cy * sx;
    m->m[2][0] = szsx + czcx * sy;
    m->m[2][1] = szcx * sy - czsx;
    m->m[2][2] = cy * cx;
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    m->m[3][0] = 0.0f;
    m->m[3][1] = 0.0f;
    m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
    return m;
}
