#pragma opt_dead_assignments off
#include "types.h"
typedef struct { float x, y, z, w; } V4_CC810;
extern float D_004A3F50, D_004A3F58, D_004A3F60;
extern V4_CC810 D_004A3F70;
extern float D_004A3F80, D_004A3F88, D_004A3F90, D_004A3F98, D_004A3FA0;
extern V4_CC810 D_004A3FB0;
extern float D_004A3FC0, D_004A3FC8, D_004A3FD0, D_004A3FD8;
extern float Math_Tan(float x);
void func_004CC810(void)
{
    float t, h, s;
    D_004A3F50 = 1.74f;
    D_004A3F58 = 0.02f;
    D_004A3F60 = 1.72f;
    D_004A3F70.x = 1.0f;
    D_004A3F70.y = 0.5f;
    D_004A3F70.z = 0.96f;
    D_004A3F70.w = 0.0f;
    D_004A3F80 = D_004A3F60 * (0.5f * (1.0f + D_004A3F70.y));
    D_004A3F88 = 1.72f;
    D_004A3F90 = D_004A3F80;
    D_004A3F98 = 1.1170107f;
    t = 1.0f / Math_Tan(D_004A3F98 * 0.5f);
    D_004A3FB0.x = 1.0f;
    D_004A3FB0.y = 0.05f;
    D_004A3FB0.z = 0.75f;
    D_004A3FB0.w = 0.0f;
    h = D_004A3F88;
    { float y = D_004A3F70.y; s = h + D_004A3F60 * y; }
    D_004A3FC0 = h;
    D_004A3FA0 = t;
    D_004A3FC8 = s;
    D_004A3FD0 = s / t;
    D_004A3FD8 = t / s;
}







