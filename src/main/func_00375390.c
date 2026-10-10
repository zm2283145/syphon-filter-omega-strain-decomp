#include "types.h"
typedef struct {
    char pad0[8];
    float width;
    float height;
    float m[4][4];
    char pad50[0xB0 - 0x50];
    float v[8];
    char padD0[0xF0 - 0xD0];
    float znear;
    float padF4;
    float zfar;
} Cam375;
extern int D_00539254;
extern float D_0053824C;
extern float D_00538250;
void func_00375390(Cam375* c) {
    float sx = 2.0f * ((D_00539254 != -1) ? 1.0f : D_0053824C);
    float sy = 2.0f * ((D_00539254 != -1) ? 1.0f : D_00538250);
    c->m[0][0] = sx / c->width;
    c->m[1][0] = 0.0f;
    c->m[2][0] = 0.0f;
    c->m[3][0] = 0.0f;
    c->m[0][1] = 0.0f;
    c->m[1][1] = sy / c->height;
    c->m[2][1] = 0.0f;
    c->m[3][1] = 0.0f;
    c->m[0][2] = 0.0f;
    c->m[1][2] = 0.0f;
    c->m[2][2] = 2.0f / (c->zfar - c->znear);
    c->m[3][2] = -(c->zfar + c->znear) / (c->zfar - c->znear);
    c->m[0][3] = 0.0f;
    c->m[1][3] = 0.0f;
    c->m[2][3] = 0.0f;
    c->m[3][3] = 1.0f;
    c->v[0] = 0.0f;
    c->v[1] = 0.0f;
    c->v[2] = -1.0f;
    c->v[3] = 1.0f;
    c->v[4] = 0.0f;
    c->v[5] = 0.0f;
    c->v[6] = 1.0f;
    c->v[7] = 1.0f;
}