#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
static inline __int128 LQ(const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); return t; }
static inline void SQ(void* d, __int128 t) { __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Def {
    char pad[0x140];
    float s[3];
    char pad14C[0x8F0 - 0x14C];
    int w8F0;
};
struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Def* GetDef();
    char pad[0x4C];
    V4 col;
    char pad60[4];
    float f64;
    float f68;
    char pad6C[0x18];
    unsigned char b84;
};
struct Src { char pad[0x30]; V4 pos; };
extern "C" V4 D_00535D40;
extern "C" unsigned char D_00535D60;
extern "C" unsigned char D_00535D61;
extern "C" char D_00535D20[];
extern "C" V4 D_00537D80;
extern "C" void func_003A1450(Self* self, float t, int arg);
extern "C" void LightMgr_GatherModelLights(void* m, unsigned int mask, unsigned int flags, void* out);

static inline int Vec4_Equal_(V4* a, V4* b) {
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline bool Neq(V4* a, V4* b) { return !Vec4_Equal_(a, b); }

extern "C" void func_003A1760(Self* self, float t, int arg, Src* src)
{
    func_003A1450(self, t - self->f64, arg);
    if (self->GetDef()->w8F0 && !(t - self->f68 <= 0.25f)) {
        V4* p = &src->pos;
        if (Neq(&D_00535D40, p)) {
            V4* d = &D_00535D40;
            QC(d, p);
            D_00535D60 = 1;
            D_00535D61 = 1;
        }
        LightMgr_GatherModelLights(D_00535D20, 0x16, 1, 0);
        void* xx = &self->col; /* dead on purpose: retail keeps this addiu */
        SQ(&self->col, LQ(&D_00537D80)); /* split lq/sq: retail interleaves the address setup */
        self->col.x = 0.0078125f * (self->col.x * self->GetDef()->s[0]);
        self->col.y = 0.0078125f * (self->col.y * self->GetDef()->s[1]);
        self->col.z = 0.0078125f * (self->col.z * self->GetDef()->s[2]);
        self->f68 = t;
    }
    self->b84 = 1;
}
