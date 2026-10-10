#include "types.h"
typedef struct PjCam {
    char p0[0x50];
    float m[4][4];
    char p90[0x40];
    float d[8];
    char pf0[4];
    float znear;
    char pf8[4];
    float zfar;
    float fov;
} PjCam;
extern float D_00539184;
extern float Math_Tan(float x);
void func_003754A0(PjCam* c)
{
    float k = 1.0f / D_00539184;
    float t = Math_Tan(c->fov);
    float ty = t * k;
    c->m[0][0] = 1.0f / t;
    c->m[1][0] = 0.0f;
    c->m[2][0] = 0.0f;
    c->m[3][0] = 0.0f;
    c->m[0][1] = 0.0f;
    c->m[1][1] = 1.0f / ty;
    c->m[2][1] = 0.0f;
    c->m[3][1] = 0.0f;
    c->m[0][2] = 0.0f;
    c->m[1][2] = 0.0f;
    c->m[2][2] = (c->zfar + c->znear) / (c->zfar - c->znear);
    c->m[3][2] = -(2.0f * c->zfar * c->znear) / (c->zfar - c->znear);
    c->m[0][3] = 0.0f;
    c->m[1][3] = 0.0f;
    c->m[2][3] = 1.0f;
    c->m[3][3] = 0.0f;
    c->d[0] = 0.0f;
    c->d[1] = 0.0f;
    c->d[2] = -c->znear;
    c->d[3] = 1.0f / c->znear;
    c->d[4] = 0.0f;
    c->d[5] = 0.0f;
    c->d[6] = c->zfar;
    c->d[7] = 1.0f / c->zfar;
}