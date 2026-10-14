#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 min; V4 max; } Box_18A0;
typedef struct { float r; int pad[3]; V4 c; } Sphere_18A0;
#pragma push
#pragma peephole off
#pragma opt_common_subs off
void func_003C18A0(Sphere_18A0* out, Box_18A0* b)
{
    V4 lenV;
    V4 cc;
    V4 sub;
    V4 ret;
    V4 mulV;
    V4 add;
    V4 mulT;
    float h;
    float len;
    { V4* d = &add; V4* mx = &b->max; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(mx); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { void* xx = &mulV; }
    { __int128 tt; V4* s; V4* p; __int128 t1; V4* q; V4* d; asm { paddub tt, zero, zero } s = &add; p = &mulV; q = &mulT; d = &mulV; t1 = *(__int128*)s; *(__int128*)d = t1; h = 0.5f; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, h; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder } ret = *q; }
    { void* xx = &cc; } { V4* d3 = &cc; V4* s3 = &ret; *d3 = *s3; }
    { V4* d = &sub; V4* mx = &b->max; asm { lqc2 vf1, 0x0(mx); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { V4* s4 = &sub; V4* d4 = &lenV; void* xx = &lenV; __int128 t4; len = 0.0f; t4 = *(__int128*)s4; *(__int128*)d4 = t4; { V4* v = &lenV; __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(v) : "memory"); } }
    { void* xx = &out->c; } out->r = 0.5f * len; out->c = cc;
}
#pragma pop

