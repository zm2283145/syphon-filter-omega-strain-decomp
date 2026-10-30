/*
 * Libs/SFOLib/Source/viewport: 14 files, 00374BC0-003751A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00374BC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V a, b, c, d;
    M() {}
    M(const M& o) { void* xx = this; __int128 qa; __int128 qb; M* d = this; const M* s = &o;  __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MM(M* d, const M* a, const M* b) { __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline M operator*(const M& a, const M& b) { M r; const M* pb = &b; M* d = &r; const M* pa = &a; MM(d, pa, pb); return r; }
static inline void MulM(V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V XformPt(const V& v, const M& m) { V p = v; V* pp = &p; MulM(pp, &m); return *pp; }
static inline V Project(const V& v, const M& m) { return XformPt(v, m); }
struct Cam { float x, y, w, h; char pad10[0x40]; M m; char pad90[0x64]; float nearz; float pad; float farz; };
extern "C" M D_00539070;
extern "C" V cXViewport_GetScreenVert(Cam* c, const V* p)
{
    V sc;
    float hz = 0.5f * (c->farz - c->nearz);
    sc.x = c->w / 2.0f;
    sc.y = c->h / 2.0f;
    sc.z = hz;
    sc.w = 1.0f;
    V off;
    off.x = (c->x + 0.5f * c->w) + 0.5f * -c->w;
    off.y = (c->y + 0.5f * c->h) + 0.5f * -c->h;
    off.z = hz + c->nearz;
    off.w = 0.0f;
    M m = c->m * D_00539070;
    V r = Project(*p, m);
    float k = 1.0f / r.w;
    r.x *= k * sc.x;
    r.y *= k * sc.y;
    r.z *= k * sc.z;
    r.w = 1.0f;
    r.x += off.x;
    r.y += off.y;
    r.z += off.z;
    return r;
}
static inline void merge_flush_func_00374BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00374BC0 */

/* merge_units: begin func_00374DF0 */
#pragma push /* merge_units */
typedef struct {
    float x, y, w, h;
    char pad10[0x90 - 0x10];
    float vs[4];
    float vo[4];
    char padB0[0x104 - 0xB0];
    unsigned char ortho;
    unsigned char useView;
    unsigned char dirty;
    char pad107;
    long scissor;
} Vp374;
extern char g_Video[];
#if 0 /* merge_units */
extern void cXViewport_BuildPersp(Vp374*);
#endif /* merge_units */
void cXViewport_BuildPersp(); /* merge_units */

#if 0 /* merge_units */
extern void cXViewport_BuildOrtho(Vp374*);
#endif /* merge_units */
void cXViewport_BuildOrtho(); /* merge_units */

#if 0 /* merge_units */
extern float XLib_GetZBuffMin(char*);
#endif /* merge_units */
float XLib_GetZBuffMin(); /* merge_units */

#if 0 /* merge_units */
extern float XLib_GetZBuffMax(char*);
#endif /* merge_units */
float XLib_GetZBuffMax(); /* merge_units */

#if 0 /* merge_units */
extern float XLib_GetGuardBandScaleY(char*);
#endif /* merge_units */
float XLib_GetGuardBandScaleY(); /* merge_units */

#if 0 /* merge_units */
extern float XLib_GetGuardBandScaleX(char*);
#endif /* merge_units */
float XLib_GetGuardBandScaleX(); /* merge_units */

#if 0 /* merge_units */
extern float* XLib_GetFullscreenWindow(char*);
#endif /* merge_units */
float * XLib_GetFullscreenWindow(); /* merge_units */

extern float XLib_GetDisplayOffY(char*);
extern float XLib_GetFrameBuffOffY(char*);
extern float XLib_GetDisplayOffX(char*);
extern float XLib_GetFrameBuffOffX(char*);
extern float XLib_GetDisplaySclY(char*);
extern float XLib_GetFrameBuffSclY(char*);
extern float XLib_GetDisplaySclX(char*);
extern float XLib_GetFrameBuffSclX(char*);
extern int nSFO_Macros_FTOI(float);

void cXViewport_Validate(Vp374* self) {
    float sx, sy, ox, oy, w, h;
    float a, b, c, half, hw, hh;
    float l, t, r, bt;
    int x0, x1, y0, y1;
    if (self->dirty == 0) return;
    if (self->ortho == 0)
        cXViewport_BuildPersp(self);
    else
        cXViewport_BuildOrtho(self);
    sx = self->useView ? XLib_GetFrameBuffSclX(g_Video) * XLib_GetDisplaySclX(g_Video) : 1.0f;
    sy = self->useView ? XLib_GetFrameBuffSclY(g_Video) * XLib_GetDisplaySclY(g_Video) : 1.0f;
    ox = self->useView ? XLib_GetFrameBuffOffX(g_Video) + XLib_GetDisplayOffX(g_Video) : 0.0f;
    oy = self->useView ? XLib_GetFrameBuffOffY(g_Video) + XLib_GetDisplayOffY(g_Video) : 0.0f;
    w = self->useView ? XLib_GetFullscreenWindow(g_Video)[2] : self->w;
    h = self->useView ? XLib_GetFullscreenWindow(g_Video)[3] : self->h;
    a = XLib_GetGuardBandScaleX(g_Video);
    b = XLib_GetGuardBandScaleY(g_Video);
    c = XLib_GetZBuffMax(g_Video);
    half = 0.5f * (c - XLib_GetZBuffMin(g_Video));
    hw = 0.5f * self->w;
    hh = 0.5f * self->h;
    self->vs[0] = 16.0f * (a * (hw * sx));
    self->vs[1] = 16.0f * (b * (-hh * sy));
    self->vs[2] = 16.0f * -half;
    self->vs[3] = 1.0f;
    self->vo[0] = 16.0f * (2048.0f + (((0.5f * w - hw) - self->x) - ox));
    self->vo[1] = 16.0f * (2048.0f + (((0.5f * h - hh) - self->y) - oy));
    self->vo[2] = 16.0f * (half + XLib_GetZBuffMin(g_Video));
    self->vo[3] = 0.0f;
    sx = XLib_GetFrameBuffSclX(g_Video);
    sy = XLib_GetFrameBuffSclY(g_Video);
    ox = XLib_GetFrameBuffOffX(g_Video);
    oy = XLib_GetFrameBuffOffY(g_Video);
    l = ox + self->x * sx;
    t = oy + self->y * sy;
    r = ox + (l + self->w * sx);
    bt = oy + (t + self->h * sy);
    x0 = nSFO_Macros_FTOI(l);
    x1 = nSFO_Macros_FTOI(r) - 1;
    y0 = nSFO_Macros_FTOI(t);
    y1 = nSFO_Macros_FTOI(bt) - 1;
    self->scissor = ((long)y1 << 48) | (((long)y0 << 32) | ((long)x0 | ((long)x1 << 16)));
    self->dirty = 0;
}
static inline void merge_flush_func_00374DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00374DF0 */

/* merge_units: begin func_003751A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

float XLib_GetZBuffMin(Obj3751A0* self) {
    return self->unk34;
}

float XLib_GetZBuffMax(Obj3751A0* self) {
    return self->unk38;
}

float XLib_GetGuardBandScaleY(Obj3751A0* self) {
    return self->unk78[self->unk88];
}

float XLib_GetGuardBandScaleX(Obj3751A0* self) {
    return self->unk68[self->unk88];
}

float* XLib_GetFullscreenWindow(char* self) {
    return (float*)(self + 3968);
}
static inline void merge_flush_func_003751A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003751A0 */

/* merge_units: begin func_00375210 */
#pragma push /* merge_units */
#include "idle_float_getter.h"

DEFINE_IDLE_FLOAT_GETTER(XLib_GetDisplayOffY, 0x40, 0.0f)
static inline void merge_flush_func_00375210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375210 */

/* merge_units: begin func_00375240 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetFrameBuffOffY, 0x58, 0.0f)
static inline void merge_flush_func_00375240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375240 */

/* merge_units: begin func_00375270 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetDisplayOffX, 0x3C, 0.0f)
static inline void merge_flush_func_00375270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375270 */

/* merge_units: begin func_003752A0 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetFrameBuffOffX, 0x54, 0.0f)
static inline void merge_flush_func_003752A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003752A0 */

/* merge_units: begin func_003752D0 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetDisplaySclY, 0x48, 1.0f)
static inline void merge_flush_func_003752D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003752D0 */

/* merge_units: begin func_00375300 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetFrameBuffSclY, 0x50, 1.0f)
static inline void merge_flush_func_00375300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375300 */

/* merge_units: begin func_00375330 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetDisplaySclX, 0x44, 1.0f)
static inline void merge_flush_func_00375330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375330 */

/* merge_units: begin func_00375360 */
#pragma push /* merge_units */
DEFINE_IDLE_FLOAT_GETTER(XLib_GetFrameBuffSclX, 0x4C, 1.0f)
static inline void merge_flush_func_00375360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375360 */

/* merge_units: begin func_00375390 */
#pragma push /* merge_units */
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
void cXViewport_BuildOrtho(Cam375* c) {
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
static inline void merge_flush_func_00375390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375390 */

/* merge_units: begin func_003754A0 */
#pragma push /* merge_units */
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
extern float Libc_Tanf(float x);
void cXViewport_BuildPersp(PjCam* c)
{
    float k = 1.0f / D_00539184;
    float t = Libc_Tanf(c->fov);
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
static inline void merge_flush_func_003754A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003754A0 */

/* merge_units: begin func_003755C0 */
#pragma push /* merge_units */
static inline void UnitMtx_55C0(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
typedef struct { __int128 r[4]; } M44;
typedef struct {
    char pad0[0x10];
    M44 m10;
    M44 m50;
    char pad90[0x105 - 0x90];
    unsigned char b105;
    unsigned char b106;
    char pad107[0x110 - 0x107];
} CameraRecord;
extern void* memset(void*, int, unsigned int);
CameraRecord* cXViewport_ctor(CameraRecord* r)
{
    memset(r, 0, sizeof(CameraRecord));
    { void* p = &r->m10; UnitMtx_55C0(p); }
    { void* xx = &r->m50; /* dead on purpose: retail keeps this addiu */ }
    UnitMtx_55C0(&r->m50);
    r->b105 = 1;
    r->b106 = 1;
    return r;
}
static inline void merge_flush_func_003755C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003755C0 */
