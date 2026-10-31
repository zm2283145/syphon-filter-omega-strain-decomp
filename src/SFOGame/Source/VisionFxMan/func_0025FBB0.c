#pragma cplusplus on
#include "types.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int Q128_25FBB0 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4A_25FBB0;
typedef struct { float x, y, z, w; } V4_25FBB0;
struct Mtx_25FBB0 { Q128_25FBB0 r[4]; Mtx_25FBB0() {} };
struct QV_25FBB0 { Q128_25FBB0 q; QV_25FBB0() {} };

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

struct Cam_25FBB0 {
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5();
    virtual QV_25FBB0 GetPos();          /* 0xE0 */
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3();
    virtual Mtx_25FBB0 GetMatrix();      /* 0xF4 */
};

struct Game_25FBB0 { char pad0[0x30]; Cam_25FBB0* cam; };

struct LightBase_25FBB0 { signed char kind; unsigned char flag1; };
struct Light_25FBB0 : LightBase_25FBB0 {
    virtual void Destroy(int flags);
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetPosition(V4A_25FBB0* pos, V4A_25FBB0* eye); /* 0x28 */
    virtual void Enable();                                    /* 0x2C */
    char pad8[4];
    float intensity;
    float f10;
    float f14;
    float invMag;
    unsigned char enabled;
    unsigned char aux;
    unsigned char type;
    char pad1F;
    V4_25FBB0 color;
    V4_25FBB0 dir;
};

typedef struct {
    V4_25FBB0 ambient;
    V4_25FBB0 color;
    float range;
    float scale;
    float level;
    unsigned char b2C;
    unsigned char b2D;
    char pad2E[0x12];
} Mode_25FBB0;

typedef struct {
    int mode;
    char pad4[4];
    unsigned char b8;
    char pad9[3];
    unsigned char bC;
    unsigned char bD;
    char padE[2];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    char pad30[0x20];
    Mode_25FBB0 modes[5];
    Light_25FBB0* ambient;
    Light_25FBB0* point;
    char pad198[0x28];
    V4_25FBB0 saved;
    int flags;
} VisionFx_25FBB0;

extern "C" {
extern int g_DrawMode;
extern unsigned char D_005382C0;
extern unsigned int D_005382E8;
extern unsigned long D_00538280;
extern unsigned long D_00538288;
extern int g_VisionNight;
extern int g_VisionThermal;
extern unsigned char D_00535D63;
extern unsigned char g_LevelLightsDirty;
extern signed char D_0048B020;
extern char g_LightMgr[];
extern char D_004D9280[];
extern char D_004D9240[];
extern char D_004D9200[];
extern Game_25FBB0* g_LocalPlayer;
Light_25FBB0* cLightMan_GetAmbientLight(void* pool);
Light_25FBB0* cLightMan_AddLight(void* pool, int kind);
}

static inline void Fog_SetColor(unsigned int c) {
    D_005382E8 = c;
    unsigned long hi = (unsigned long)*(volatile unsigned int*)&D_005382E8 << 32;
    D_00538280 = (D_00538280 & 0xFFFFFFFF) | hi;
    D_00538288 = (D_00538288 & 0xFFFFFFFF) | hi;
    D_005382C0 = 1;
}

static inline float Min_25FBB0(float a, float b) { float r = a; if (a < b) r = a; else r = b; return r; }
static inline float Max_25FBB0(float a, float b) { float r = a; if (a > b) r = a; else r = b; return r; }

static inline void Fade_Update(VisionFx_25FBB0* s) {
    switch (s->b8) { case 1: {
        float r = 0.0f;
        if (s->bC) {
            if (s->bD) {
                r = 1.0f;
                if (!(s->f20 <= 0.0f)) r = 0.0f;
            } else {
                r = Min_25FBB0(1.0f, s->f10 / s->f18);
                r = r - Max_25FBB0(0.0f, (*(volatile float*)&s->f10 - *(volatile float*)&s->f18 - s->f1C) / s->f20);
            }
        } else if (!(s->f20 <= 0.0f)) {
            r = 1.0f;
        }
        s->f28 = r;
    } break; }
}

static inline float LenSq_25FBB0(V4A_25FBB0* p) {
    int t;
    float r;
    asm {
        lqc2 vf1, 0x0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
    }
    asm { mtc1 t, r }
    return r;
}

static inline void V4ASet_25FBB0(V4A_25FBB0* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
static inline void V4Set_25FBB0(V4_25FBB0* v, float x, float y, float z, float w) { v->w = w; v->z = z; v->y = y; v->x = x; }
static inline void V4SetF_25FBB0(V4_25FBB0* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
static inline void Copy_25FBB0(void* dst, QV_25FBB0* v) { u_long128 r; __asm__ volatile("lq %0, 0(%1)" : "=r"(r) : "r"(v)); __asm__ volatile("sq %0, 0(%1)" : : "r"(r), "r"(dst)); }
struct V4AC_25FBB0 { float x, y, z, w; V4AC_25FBB0() {} V4AC_25FBB0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline void Light_SetColor(Light_25FBB0* l, V4_25FBB0* c) {
    V4A_25FBB0 v;
    l->color = *c;
    V4ASet_25FBB0(&v, *(volatile float*)&c->x, c->y, c->z, c->w);
    l->invMag = 1.0f / LenSq_25FBB0(&v);
}
static inline void Light_SetColorP(Light_25FBB0* l, V4_25FBB0* c) {
    V4A_25FBB0 v;
    float q = 0.0f;
    l->color = *c;
    V4ASet_25FBB0(&v, *(volatile float*)&c->x, c->y, c->z, c->w);
    q = LenSq_25FBB0(&v);
    l->invMag = 1.0f / q;
}

static inline void MulVec_25FBB0(V4A_25FBB0* out, V4A_25FBB0* v, Mtx_25FBB0* m) {
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(out)
    }
}

static inline Light_25FBB0* NewPoint_25FBB0(void) {
    Light_25FBB0* l = cLightMan_AddLight(g_LightMgr, 4);
    if (l) {
        *(void**)((char*)l + 4) = D_004D9280;
        l->kind = D_0048B020;
        l->flag1 = 0;
        *(void**)((char*)l + 4) = D_004D9240;
        l->intensity = 0.0f;
        l->enabled = 0;
        l->aux = 3;
        l->type = 4;
        l->color.x = 0.0f;
        l->color.y = 0.0f;
        l->color.z = 0.0f;
        l->color.w = 0.0f;
        l->dir.x = 0.0f;
        l->dir.y = 0.0f;
        l->dir.z = 0.0f;
        l->dir.w = 1.0f;
        g_LevelLightsDirty = 1;
        *(int*)&l->invMag = 0;
        *(void**)((char*)l + 4) = D_004D9200;
    }
    return l;
}

extern "C" void cVisionFxMan_ActivateFx(VisionFx_25FBB0* s)
{
    int f;
    Mode_25FBB0* m;
    s->flags = g_DrawMode;
    f = s->flags & ~0x60;
    switch (s->mode) {
    case 0:
        Fog_SetColor(0xFF000000);
        s->f24 = 0.0f;
        Fade_Update(s);
        g_VisionNight = 0;
        g_VisionThermal = 0;
        break;
    case 1:
        D_00535D63 = 0;
        s->ambient = cLightMan_GetAmbientLight(g_LightMgr);
        s->point = NewPoint_25FBB0();
        g_DrawMode = f;
        Fog_SetColor(0xFFFF00FF);
        Fade_Update(s);
        g_VisionNight = 1;
        break;
    case 2:
        D_00535D63 = 0;
        s->ambient = cLightMan_GetAmbientLight(g_LightMgr);
        s->point = NewPoint_25FBB0();
        g_DrawMode = f;
        Fog_SetColor(0xFF00FFFF);
        Fade_Update(s);
        g_VisionThermal = 1;
        break;
    case 3:
    case 4:
        break;
    }
    m = &s->modes[s->mode];
    if (s->ambient) {
        s->saved = s->ambient->color;
        Light_SetColor(s->ambient, &m->ambient);
    }
    if (s->point) {
        Mtx_25FBB0 mtx = g_LocalPlayer->cam->GetMatrix();
        QV_25FBB0 eye = g_LocalPlayer->cam->GetPos();
        V4A_25FBB0* tp = (V4A_25FBB0*)&mtx.r[3];
        Copy_25FBB0(tp, &eye);
        V4AC_25FBB0 pos(0.0f, 5.0f, 0.0f, 1.0f);
        V4_25FBB0 col;
        MulVec_25FBB0((V4A_25FBB0*)&pos, (V4A_25FBB0*)&pos, &mtx);
        V4Set_25FBB0((V4_25FBB0*)&col, *(volatile float*)&m->color.x * *(volatile float*)&s->f2C, *(volatile float*)&m->color.z * *(volatile float*)&s->f2C, *(volatile float*)&m->color.y * *(volatile float*)&s->f2C, *(volatile float*)&m->color.w * *(volatile float*)&s->f2C);
        s->point->SetPosition((V4A_25FBB0*)&pos, tp);
        Light_SetColorP(s->point, &m->color);
        s->point->f10 = m->range;
        s->point->f14 = m->scale * s->f2C;
        if (m->b2C) s->point->aux |= 8;
        if (m->b2D) s->point->aux |= 0x10;
        s->point->Enable();
    }
    s->f24 = m->level * s->f2C;
}

#pragma opt_rebuildconditionals off



















