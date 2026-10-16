#pragma cplusplus on
#include "types.h"
struct Fx_260B90 {
    unsigned char active; char p9[3];
    unsigned char c; unsigned char d; char pe[2];
    float a10; float v[4];
    void Reset() { a10 = 0; v[3] = 0; v[2] = 0; v[1] = 0; v[0] = 0; c = 0; d = 0; }
    void Reset2() { a10 = 0.0f; v[3] = 0.0f; v[2] = 0.0f; v[1] = 0.0f; v[0] = 0.0f; c = 0; d = 0; }
};
struct Elem_260B90 {
    float a[3]; float a3;
    float b[4];
    float f20; float f24; float f28;
    unsigned char c2C; unsigned char c2D; char p2E[2];
    float f30;
    char p34[0xC];
    void Init() {
        a[0] = 0.2f; a[1] = 0.2f; a[2] = 0.2f; a3 = 0;
        b[0] = 0.8f; b[1] = 0.8f; b[2] = 0.8f; b[3] = 0.8f;
        f20 = 0; f24 = 0; f28 = 0;
        c2C = 0; c2D = 0;
        f30 = 0.98f;
    }
    void Set(float s, float w, float x) {
        a[0] = s; a[1] = s; a[2] = s; a3 = 0.0f;
        b[0] = 0.8f; b[1] = 0.8f; b[2] = 0.8f; b[3] = 0.8f;
        f20 = 0.0f; f24 = w; f28 = x;
        c2C = 0; c2D = 0;
        f30 = 0.98f;
    }
};
struct Obj_260B90 {
    int f0; int f4;
    Fx_260B90 fx;            /* 0x08 */
    int f24; int f28; float f2C;
    unsigned char b30; unsigned char b31; char p32[2];
    int f34; float v38; float v3C; float v40; float v44;
    char p48[8];
    Elem_260B90 e[5];        /* 0x50 */
    int f190; int f194; float f198; int f19C; float f1A0; float f1A4; float f1A8; int f1AC; float f1B0; float f1B4;
    char p1B8[8];
    float f1C0[4];
};
extern "C" Obj_260B90* func_00260B90(Obj_260B90* o) {
    Elem_260B90* p;
    o->f0 = 0;
    o->f4 = 0;
    o->fx.active = 0;
    o->fx.Reset();
    o->f24 = 0;
    o->f28 = 0;
    o->f2C = 1.0f;
    o->f34 = 0;
    o->v44 = 0; o->v40 = 0; o->v3C = 0; o->v38 = 0;
    o->b30 = 0;
    o->b31 = 0;
    p = o->e; do { p->Init(); p++; } while (p != o->e + 5);
    o->f190 = 0;
    o->f194 = 0;
    o->f198 = 0.0f;
    o->f19C = -1;
    o->f1A0 = 0.0f;
    o->f1A4 = 0.0f;
    o->f1A8 = 1.0f;
    o->f1AC = 0;
    o->f1B0 = 0.0f;
    o->f1B4 = 0.1f;
    o->f1C0[0] = 0.0f; o->f1C0[1] = 0.0f; o->f1C0[2] = 0.0f; o->f1C0[3] = 0.0f;
    o->fx.Reset2();
    o->e[1].Set(2.0f, 20.0f, 0.3f);
    o->e[2].Set(2.0f, 25.0f, 0.5f);
    return o;
}




