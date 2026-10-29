#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } M4;
#pragma push
#pragma peephole off
#pragma opt_common_subs off
static inline float Dot3(V4* a, V4* b) {
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline void RotMul(V4* d, M4* m, V4* s) {
    asm {
        lqc2 vf8, 0x0(s)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(d)
    }
}
static inline void Scale(V4* d, V4* s, float f) {
    __int128 t = 0;
    asm { .set noreorder; lqc2 vf1, 0x0(s); mfc1 t, f; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(d); .set reorder }
}
static inline void Add3(V4* d, V4* a, V4* b) {
    asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(b); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(d) }
}
static inline void CopyV(V4* d, V4* s) { *d = *s; }
static inline V4* Tr(M4* m) { return &m->r[3]; }
static inline void CpV(V4* d, V4* s) { *d = *s; }
static inline void Set4(V4* v, float w, float x, float y, float z) { v->w = w; v->x = x; v->y = y; v->z = z; }
static inline void Cp(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
V4* func_003E4720(V4* p, M4* m)
{
    V4 n;
    V4 pt;
    V4 r;
    V4 s;
    V4 t;
    float x, y, z;
    float d;
    { V4* b; V4* a; void* xx; V4* tp; V4* cn; V4* td; __int128 q0;
    td = &t; xx = &n; tp = &t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q0) : "r"(p), "r"(td) : "memory");
    tp->w = 0.0f; cn = &n; Cp(cn, tp);
    a = &n; b = &n; RotMul(b, m, a); }
{ V4* q; V4* x; V4* d; __int128 t; q = &s; Scale(q, &n, -p->w); __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(q)); d = &pt; q = &m->r[3]; *(__int128*)d = t; x = &pt; x = &pt; Add3(x, x, q); }


    { V4* a = &n; V4* b = &pt; int t; d = 0.0f;
      asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, d

      }
    }
    { float w; w = d; z = n.z; y = n.y; x = n.x; w = -w; Set4(&r, w, x, y, z); }
    *p = r;
    return p;
}
#pragma pop
