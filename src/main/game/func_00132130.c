#include "types.h"
typedef struct { float m[4][4]; } Mtx_f4;
extern float Math_Sin(float);
extern float Math_Cos(float);
Mtx_f4* Mtx_MakeAxisRotation(Mtx_f4* out, float x, float y, float z, float angle)
{
    float s, c, t;
    float sz, sy, sx, tzx, tyz, txy;
    s = Math_Sin(angle);
    c = Math_Cos(angle);
    t = 1.0f - c;
    txy = t * x * y;
    tyz = t * y * z;
    tzx = t * z * x;
    sx = s * x;
    sy = s * y;
    sz = s * z;
    out->m[0][0] = c + t * (x * x);
    out->m[0][1] = txy + sz;
    out->m[0][2] = tzx - sy;
    out->m[1][0] = txy - sz;
    out->m[1][1] = c + t * (y * y);
    out->m[1][2] = tyz + sx;
    out->m[2][0] = tzx + sy;
    out->m[2][1] = tyz - sx;
    out->m[2][2] = c + t * (z * z);
    out->m[0][3] = 0.0f;
    out->m[1][3] = 0.0f;
    out->m[2][3] = 0.0f;
    out->m[3][0] = 0.0f;
    out->m[3][1] = 0.0f;
    out->m[3][2] = 0.0f;
    out->m[3][3] = 1.0f;
    return out;
}