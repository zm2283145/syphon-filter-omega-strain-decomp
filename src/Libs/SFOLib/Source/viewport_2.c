/*
 * Libs/SFOLib/Source/viewport: 12 files, 003751A0-003755C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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

void* XLib_GetFullscreenWindow(char* self) {
    return self + 3968;
}
static inline void merge_flush_func_003751A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003751A0 */

/* merge_units: begin func_00375210 */
#pragma push /* merge_units */
#include "types.h"
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
