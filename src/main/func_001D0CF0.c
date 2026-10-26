#pragma cplusplus on
#include "types.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Src { char pad[0xD0]; V4 q[2]; };
struct Bone { char pad[0x1A0]; V4 rot; };
struct Slot {
    Bone* bone;
    char pad4[0xC];
    char f10[0xB0];
    Src* src;
    char padC4[0xC];
    V4 fD0;
    char padE0[0x20];
};
extern "C" {
extern Slot UpperBodyNodeTable[];
void nIk_OneBoneDirectionalIK(V4* out, V4* q, int one, void* inner);
}
static inline void Cp(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void CpB(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void CpC(void* d, const void* s) { const void* p = s; __asm__ volatile("lq %0, 0x0(%0)" : "+r"(p)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(p), "r"(d) : "memory"); }
static inline void CpD(void* d0, const void* s) { void* d = d0; const void* p = s; __asm__ volatile("lq %0, 0x0(%0)" : "+r"(p)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(p), "r"(d) : "memory"); }
static inline void CpE(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void CpF(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void Conj(V4* p) { __asm__ volatile("lqc2 vf1, 0x0(%0)\n vsub.xyz vf1, vf0, vf1\n sqc2 vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void QMul(V4* o, const V4* b, const V4* c) {
    __asm__ volatile("lqc2 vf1, 0x0(%1)\n lqc2 vf2, 0x0(%2)\n vmul.xyzw vf3, vf1, vf2\n vopmula.xyz ACC, vf1, vf2\n vmaddaw.xyz ACC, vf1, vf2w\n vmaddaw.xyz ACC, vf2, vf1w\n vopmsub.xyz vf4, vf2, vf1\n vsubaz.w ACC, vf3, vf3z\n vmsubay.w ACC, vf0, vf3y\n vmsubx.w vf4, vf0, vf3x\n sqc2 vf4, 0x0(%0)" : : "r"(o), "r"(b), "r"(c) : "memory");
}
extern "C" void UpperBody_FootRotation(void* self, const V4* q, int idx, int flag)
{
    Slot* s = &UpperBodyNodeTable[idx];
    Src* src = s->src;
    if (flag) {
        V4 a, d, r2, c, r;
        Cp(&a, q);
        { V4* b = src->q; Cp(&c, &b[1]); }
        { V4* pc = &c; Conj(pc); Cp(&d, pc); }
        QMul(&r, &d, &a);
        { void* d2 = &a; const void* s2 = &r2; void* d1 = &r2; const void* s1 = &r; CpC(d1, s1); CpE(d2, s2); }
        nIk_OneBoneDirectionalIK(&s->fD0, &a, 1, s->f10);
    } else {
        Cp(&s->fD0, &s->bone->rot);
    }
}
