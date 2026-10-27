#pragma cplusplus on
#include "types.h"

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
extern signed char D_004E1D88;
extern V4 D_004E1D90;
extern float D_004A7570[2];
void cModeSwitch_12_ctor_uint_2(void* p, int v);
void cModeSwitch_2_ctor(void* p, int v);
void std_list_deleter_cSafePtr_cGOBJ_ctor(void* l);
}
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return &D_004E1D90;
}
struct V { float x, y, z, w; V& operator=(const V4& o) { const V4* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; } } __attribute__((aligned(16)));
struct Obj { char p[0xC]; int serial; };
struct H {
    Obj* p; int serial;

    void Set(Obj* o) { int none; serial = *((p = o) ? &o->serial : (none = -1, &none)); }
};
struct H2 { int serial; Obj* p; };
struct PS { int a, b; };
struct SL { int a, b; };
struct LST { int a, b, c; };

struct InputState {
    unsigned char b0;
    int w4;
    int w8;
    unsigned char bC;
    float f10, f14, f18, f1C;
    int w20;
    unsigned char b24, b25, b26, b27;
    int w28;
    unsigned char b2C, b2D;
    PS ps[3];        /* 0x30 */
    SL sl[3];        /* 0x48 */
    V v60;
    V v70;
    float f80;
    V v90;
    float fA0;
    unsigned char bA4[0x18];
    unsigned char bBC, bBD;
    H hC0;
    H hC8;
    char pD0[0x14];
    H2 hE4;
    LST lEC;
    int wF8, wFC, w100;
    char p104[4];
    unsigned char b108; int w10C;
    unsigned char b110; int w114;
    unsigned char b118, b119; int w11C; int w120;
    unsigned char b124, b125, b126; int w128;
    unsigned char b12C; int w130; int w134;
    unsigned char b138, b139; int w13C; int w140;

};


extern "C" InputState* cPlayerControls_ctor(InputState* self)
{
    int i;
    self->b0 = 0;
    self->w8 = 0;
    self->bC = 0;
    self->f10 = 4.73f;
    self->f14 = 13.0f;
    self->f18 = 0.5f;
    self->f1C = D_004A7570[0];
    self->w20 = -1;
    self->b24 = 0; self->b25 = 0; self->b26 = 0; self->b27 = 0;
    { volatile int none = -1; self->w28 = none; }
    self->b2C = 0; self->b2D = 0;
    { PS* p = self->ps; cModeSwitch_12_ctor_uint_2(p, 0); cModeSwitch_12_ctor_uint_2(p + 1, 0); cModeSwitch_12_ctor_uint_2(p + 2, 0); }
    { SL* p = self->sl; cModeSwitch_2_ctor(p, 0); cModeSwitch_2_ctor(p + 1, 0); cModeSwitch_2_ctor(p + 2, 0); }
    self->v60 = *Vec4_Zero();
    self->v70 = *Vec4_Zero();
    self->f80 = 0.0f;
    self->v90 = *Vec4_Zero();
    self->fA0 = 0.0f;
    self->bBC = 0; self->bBD = 0;
    self->hC0.serial = -1; self->hC0.Set(0);
    self->hC8.serial = -1; self->hC8.Set(0);
    self->hE4.serial = -1; self->hE4.p = 0;
    std_list_deleter_cSafePtr_cGOBJ_ctor(&self->lEC);
    self->wF8 = 0; self->wFC = 0; self->w100 = 0;
    self->b108 = 0; self->w10C = 0;
    self->b110 = 0; self->w114 = 0;
    self->b118 = 0; self->b119 = 0; self->w11C = 0; self->w120 = 0;
    self->b124 = 0; self->b125 = 0; self->b126 = 0; self->w128 = 0;
    self->b12C = 0; self->w130 = 0; self->w134 = 0;
    self->b138 = 0; self->b139 = 0; self->w13C = 0; self->w140 = 0;
    self->w4 = 0;
    for (i = 0; i < 0x18; i++) self->bA4[i] = 0;
    return self;
}



