/* 0x00398E20 (mw38). Dead "void* xx = &self->m;" before the matrix multiply supplies the early dead addiu and the trailing nop. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct W { int x, y, z, w; W() {} W(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; } W& operator=(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
};
struct M {
    V r0, r1, r2, r3;
    M() {}
    M& operator=(const M& o) { void* xx = this; __int128 qa; __int128 qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { __int128 qa; __int128 qb; const M* s = &o; M* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulM(M* d, const M* a)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "lqc2 $vf8, 0x0(%0); lqc2 $vf9, 0x10(%0); lqc2 $vf10, 0x20(%0); lqc2 $vf11, 0x30(%0)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(a) : "memory");
}
static inline M Mul(const M& a, M& b) { MulM(&b, &a); return b; }
static inline M& MulInto(M* t, const M* a) { M* p = t; MulM(p, a); return *p; }
struct Info {
    char pad0[0x14];
    float x14;
    char pad18[0x8B0 - 0x18];
    M m;
    char pad8F0[0x9B8 - 0x8F0];
    float x9B8;
    float x9BC;
    char pad9C0[8];
    int x9C8;
    unsigned char x9CC;
};
struct Obj {
    void* vt;
    char pad4[0xC];
    M m;
    char pad50[0x10];
    float x60;
    char pad64[0x90 - 0x64];
    V a[5];
    char padE0[0x120 - 0xE0];
    Info* info;
    int x124;
    unsigned char x128;
};
extern "C" Obj* func_003A1990(Obj* self, Obj* parent, Info* info, float f);
extern void* const D_004DFA80[];
extern W D_00538350;
extern "C" Obj* func_00398E20(Obj* self, Obj* parent, Info* info, float f, M* m)
{
    M r;
    W c;
    func_003A1990(self, parent, info, f);
    self->vt = (void*)D_004DFA80;
    {
        V* p = self->a;
        V* e = self->a + 5;
        do { p++; } while (p != e);
    }
    self->info = info;
    self->x124 = info->x9C8 - 1;
    if (info->x9CC) {
        self->x124 = 0x7FFFFFFF;
    }
    if (!parent) {
        self->m = info->m;
    } else {
        M* pm;
        M t = *m;
        const M* pa = &parent->m;
        M& rr = (r = MulInto(&t, pa));
        void* xx = &self->m;
        pm = &self->m;
        *pm = rr;
    }
    self->a[0].w = info->x14;
    c = D_00538350;
    *(W*)&self->a[1] = c;
    self->a[2] = self->m.r2;
    self->x60 = info->x9B8 + info->x9BC;
    self->x128 = 0;
    return self;
}