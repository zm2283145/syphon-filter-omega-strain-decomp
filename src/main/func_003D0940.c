#include "types.h"
typedef struct { int f0; char f4[0xC]; char f10[0xC]; unsigned char b1C; } M3D1020;
extern signed char D_00543740;
extern M3D1020 D_00543760;
extern char D_00543764[];
extern char D_00543770[];
extern char D_00543748[];
extern char func_003D0B90[];
extern int D_004937F0;
extern void func_003D1560(void* p);
extern void ScalarCollection_Init(void* p);
extern void __register_global_object(void* o, void* d, void* l);
#pragma push
#pragma opt_propagation off
static inline M3D1020* Def_3D0940(void)
{
    if (!D_00543740) {
        M3D1020* m = &D_00543760;
        D_00543760.f0 = 0;
        func_003D1560(D_00543764);
        ScalarCollection_Init(D_00543770);
        m->b1C = 1;
        __register_global_object(m, func_003D0B90, D_00543748);
        D_00543740 = 1;
    }
    return &D_00543760;
}
typedef struct { float x, y, z, w; } V4_940;
typedef struct S3D0940 {
    int a0, a4, a8, aC;
    unsigned char b10, b11, b12;
    int i14, i18, i1C;
    int i20;
    char pad24[0xC];
    V4_940 v30;
    float f40;
    int i44;
    float f48;
    int i4C, i50;
    float f54;
    unsigned char b58, b59, b5A, b5B;
} S3D0940;
S3D0940* func_003D0940(S3D0940* s, int a, int b, int c, int d, int e, V4_940* v)
{
    s->a0 = a;
    s->a4 = b;
    s->a8 = c;
    s->aC = d;
    s->b10 = 0;
    s->b11 = 0;
    s->b12 = 0;
    s->i14 = 0;
    s->i18 = 0;
    s->i1C = 0;
    s->i20 = e ? e : (Def_3D0940(), D_00543760.f0);
    s->v30.x = v->x;
    s->v30.y = v->y;
    s->v30.z = v->z;
    s->v30.w = v->w;
    s->f40 = (float)-s->a8;
    s->i44 = 0;
    s->f48 = (float)D_004937F0;
    s->i4C = 0;
    s->i50 = 0;
    s->f54 = 0.6f;
    s->b58 = 0;
    s->b59 = 0;
    s->b5A = 0;
    s->b5B = 0;
    return s;
}
#pragma pop
