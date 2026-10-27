#pragma cplusplus on
#include "types.h"
/* Camera_ZoomSweep: sweeps the camera's view volume from its position to its
 * target; on a hit narrows the zoom angle so the hit point stays in view. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } Mtx;
typedef struct { unsigned char hit; char p1[0x7F]; V4 v80; char p90[0x80]; unsigned char b110; char p111[7]; unsigned char b118; char p119[0xC7]; } Res;
typedef struct { char p0[4]; unsigned char b4; char p5[3]; float zoom; char pC[4]; V4 q; float f20; float f24; char p28[8]; V4 from; V4 to; } Cam;
extern "C" {
extern V4 D_004A3FB0;
extern float D_004A3FC0;
extern float D_004A3FD8;
void cCollisionProbe_SphereSweptRay_ctor(Res*);
int ColQuery_RequestSweep(Res* r, void* a1, V4* from, V4* to, int t0, Mtx* m, V4* ext, float f12, float f13, float f14, float f15, float f16, float f17);
int ColQuery_ExecuteSweepThunk(Res* r, int a, int b);
float Libc_Atanf(float);
void Camera_ZoomSweep(Cam* self, int unused, void* filter);
}
static inline void QToM(Mtx* m, V4* q) {
    Mtx* mm = m; V4* qp = q;
    __asm__ volatile(
        "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
        "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
        "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
        "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
        "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
        "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
        : : "r"(mm), "r"(qp) : "memory");
}
static inline float Length(const V4& v)
{
    float r = 0.0f;
    int t;
    const V4* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float FovFor(float x) { return 2.0f * Libc_Atanf(1.0f / (x * D_004A3FD8)); }

#pragma opt_common_subs off
void Camera_ZoomSweep(Cam* self, int unused, void* filter)
{
    Res res;
    Mtx m;
    cCollisionProbe_SphereSweptRay_ctor(&res);
    QToM(&m, &self->q);
    { Mtx* pm = &m; ColQuery_RequestSweep(&res, filter, &self->from, &self->to, 0, pm, &D_004A3FB0, 0.05f, 0.05f, 0.0f, 1.0f, self->zoom, D_004A3FC0); }
    res.b110 = 0;
    res.b118 = 0;
    ColQuery_ExecuteSweepThunk(&res, 0, 0);
    self->b4 = res.hit != 0;
    if (res.hit)
        self->zoom = FovFor(self->f24 + Length(res.v80));
}
