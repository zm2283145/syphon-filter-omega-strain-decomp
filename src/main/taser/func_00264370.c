#include "types.h"
typedef struct E264370 {
    char p0[0x10]; float f10; char p14[4]; float f18; char p1c[4];
    float f20; char p24[4]; float f28; char p2c[4]; float f30; float f34; char p38[8];
} E264370;
typedef struct { char p[0x14]; int n; E264370* d; } V264370;
extern float D_0048B110;
extern float D_0048B128;
extern float D_0048B138;
extern float D_0048B178;
extern float D_0048B1B8;
static inline float Abs264370(float x) { float r; asm { abs.s r, x } return r; }
static inline float Sign264370(float x) { return x > 0.0f ? 1.0f : -1.0f; }
static inline E264370* Get264370(V264370* v, int i) { return &v->d[i]; }
static inline float Calc264370(float k, float* p, float x, int flag)
{
    float d = k * -x;
    float sp = Sign264370(*p);
    float sd = Sign264370(d);
    if (sd != sp) d *= 2.0f;
    if (flag && Abs264370(d) < D_0048B128) d *= D_0048B138;
    return d;
}
#pragma opt_strength_reduction off
void func_00264370(V264370* v, float dt, int flag)
{
    int i;
    float k = D_0048B110 * dt;
    int n = v->n;
    for (i = 1; i < n - 1; i++) {
        E264370* e = Get264370(v, i);
        float* p = &e->f20;
        float d = Calc264370(k, p, e->f10, flag);
        {
            float a = Abs264370(d * D_0048B178);
            float lo = D_0048B1B8;
            float hi = 1.0f;
            asm {
                max.s a, a, lo
                min.s a, a, hi
            }
            Get264370(v, i)->f30 = Get264370(v, i)->f34 = a;
        }
        *p += d;
        e = Get264370(v, i);
        p = &e->f28;
        d = Calc264370(k, p, e->f18, flag);
        *p += d;
    }
}






