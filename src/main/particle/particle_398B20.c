/*
 * main/particle: range (3 files, 00398B20-00398E20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "pp_quad_copy.h"

/* merge_units: begin func_00398B20 */
#pragma push /* merge_units */
void func_00398D90(PPMtx* d, PPMtx* s); /* gsynth: defined below */
/* 0x00398B20 (mw38). Copy into tmp via "void* xx=&tmp; V* pt=&tmp; *pt=d;" fixes the s/d register swap. */
#pragma cplusplus on
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
void ParticleEmitterBase_Update(Obj* self, Mgr* mgr, M* m, float f, V* v);
void PhysEmitter_StepParticles(Obj* self, M* m);
#if 0 /* merge_units */
void func_00398D90(M* d, M* s);
#endif /* merge_units */
#define func_00398D90(a0, a1) (func_00398D90((PPMtx *)(a0), (PPMtx *)(a1))) /* merge_units */

V* Mtx_TransformByTranspose(V* v, M* m);
void* func_003A3430(void* mgr, void* key);
Obj* ParticleEmitter_SpawnChildren(Mgr* mgr, Obj* ins, void* name, M* m, float f);
extern char D_0053B540[];
}
static inline V* XformT(V* v, M* m) { M t; func_00398D90(&t, m); return Mtx_TransformByTranspose(v, &t); }
extern "C" void PhysEmitter_Update(Obj* self, Mgr* mgr, M* m, V* v, float f)
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
    ParticleEmitterBase_Update(self, mgr, m, f, v);
    PhysEmitter_StepParticles(self, m);
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
            Obj* n = ParticleEmitter_SpawnChildren(mgr, 0, func_003A3430(D_0053B540, self->info->x170), &id, f);
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
#undef func_00398D90 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398B20 */

/* merge_units: begin func_00398D90 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00398D90(PPMtx* d, PPMtx* s)
{
    PP_TRANSPOSE33_COPY(d, s)
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398D90 */

/* merge_units: begin func_00398E20 */
#pragma push /* merge_units */
/* 0x00398E20 (mw38). Dead "void* xx = &self->m;" before the matrix multiply supplies the early dead addiu and the trailing nop. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V_00398E20 {
    float x, y, z, w;
    V_00398E20() {}
    V_00398E20(const V_00398E20& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V_00398E20& operator=(const V_00398E20& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
};
struct M_00398E20 {
    V_00398E20 r0, r1, r2, r3;
    M_00398E20() {}
    M_00398E20& operator=(const M_00398E20& o) { void* xx = this; __int128 qa; __int128 qb; M_00398E20* d = this; const M_00398E20* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M_00398E20(const M_00398E20& o) { __int128 qa; __int128 qb; const M_00398E20* s = &o; M_00398E20* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulM_00398E20(M_00398E20* d, const M_00398E20* a)
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
static inline M_00398E20 Mul(const M_00398E20& a, M_00398E20& b) { MulM_00398E20(&b, &a); return b; }
static inline M_00398E20& MulInto(M_00398E20* t, const M_00398E20* a) { M_00398E20* p = t; MulM_00398E20(p, a); return *p; }
struct Info_00398E20 {
    char pad0[0x14];
    float x14;
    char pad18[0x8B0 - 0x18];
    M_00398E20 m;
    char pad8F0[0x9B8 - 0x8F0];
    float x9B8;
    float x9BC;
    char pad9C0[8];
    int x9C8;
    unsigned char x9CC;
};
struct Obj_00398E20 {
    void* vt;
    char pad4[0xC];
    M_00398E20 m;
    char pad50[0x10];
    float x60;
    char pad64[0x90 - 0x64];
    V_00398E20 a[5];
    char padE0[0x120 - 0xE0];
    Info_00398E20* info;
    int x124;
    unsigned char x128;
};
extern "C" Obj_00398E20* ParticleEmitterBase_Construct(Obj_00398E20* self, Obj_00398E20* parent, Info_00398E20* info, float f);
extern void* const D_004DFA80[];
extern W D_00538350;
extern "C" Obj_00398E20* PhysEmitter_Construct(Obj_00398E20* self, Obj_00398E20* parent, Info_00398E20* info, float f, M_00398E20* m)
{
    M_00398E20 r;
    W c;
    ParticleEmitterBase_Construct(self, parent, info, f);
    self->vt = (void*)D_004DFA80;
    {
        V_00398E20* p = self->a;
        V_00398E20* e = self->a + 5;
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
        M_00398E20* pm;
        M_00398E20 t = *m;
        const M_00398E20* pa = &parent->m;
        M_00398E20& rr = (r = MulInto(&t, pa));
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398E20 */
