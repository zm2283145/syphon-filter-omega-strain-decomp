/* 0x00398B20 (mw38). Copy into tmp via "void* xx=&tmp; V* pt=&tmp; *pt=d;" fixes the s/d register swap. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct W { int x, y, z, w; W() {} W(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; } W& operator=(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    void SetXYZ(const V& o) { float w = this->w; *this = o; this->w = w; }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    V& operator+=(const V& b) { V* d = this; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(this), "r"(&b) : "memory"); return *this; }
    V& operator=(const V& o) { const V* s = &o; void* xx = this; __int128 t; V* d = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
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
static inline void UnitMtx(void* m) { int t; void* p = m; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
struct Info {
    char pad0[0x68];
    float x68;
    char pad6C[0x170 - 0x6C];
    char x170[0x8F4 - 0x170];
    int x8F4;
    char pad8F8[0x9CC - 0x8F8];
    unsigned char x9CC;
};
struct Mgr { char pad[0x6A]; unsigned char x6A; };
struct Obj {
    void* vt;
    char pad4[0xC];
    M m;
    char pad50[0x10];
    float x60;
    float x64;
    char pad68[0x84 - 0x68];
    unsigned char x84;
    char pad85[0x90 - 0x85];
    V a[5];
    M mE0;
    Info* info;
    int x124;
    unsigned char x128;
};
extern "C" {
void func_003A1760(Obj* self, Mgr* mgr, M* m, float f, V* v);
void func_00398470(Obj* self, M* m);
void func_00398D90(M* d, M* s);
V* Mtx_TransformByTranspose(V* v, M* m);
void* func_003A3430(void* mgr, void* key);
Obj* func_003A26A0(Mgr* mgr, Obj* ins, void* name, M* m, float f);
extern char D_0053B540[];
}
static inline V* XformT(V* v, M* m) { M t; func_00398D90(&t, m); return Mtx_TransformByTranspose(v, &t); }
extern "C" void func_00398B20(Obj* self, Mgr* mgr, M* m, V* v, float f)
{
    V tmp;
    M id;
    if (!self->x84) {
        self->a[0].SetXYZ(self->m.r3);
        if (self->x124 > 0) {
            self->mE0 = *m;
            self->x128 = 1;
        }
    }
    func_003A1760(self, mgr, m, f, v);
    func_00398470(self, m);
    if (v && self->info->x68 > 0.01f) {
        tmp = *v;
        float s = self->info->x68;
        V d = *XformT(&tmp, m) * s;
        void* xx = &tmp;
        V* pt = &tmp;
        *pt = d;
        self->a[0] += tmp;
    }
    if (!mgr->x6A) {
        if (self->x124 > 0) {
            void* xx = &id;
            UnitMtx(&id);
            Obj* n = func_003A26A0(mgr, 0, func_003A3430(D_0053B540, self->info->x170), &id, f);
            if (!self->info->x9CC) {
                self->x124--;
            }
            n->x124 = self->x124;
            self->x124 = 0;
        }
        if (self->info->x8F4 && !(f - self->x64 <= self->x60)) {
            self->x64 = f;
            self->a[0].SetXYZ(self->m.r3);
        }
    }
}