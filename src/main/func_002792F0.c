#pragma optimization_level 0
#pragma schedule on
#pragma peephole on
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef __int128 u128;

static inline void V4_Copy(const void* s, void* d) { u128 t; asm volatile { lq t, 0(s)
 sq t, 0(d) } }
struct V4_92F0 { float x, y, z, w; V4_92F0() {} V4_92F0(const V4_92F0& o) { u128 t; const V4_92F0* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } } V4_92F0& operator=(const V4_92F0& o) { u128 t; const V4_92F0* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } return *this; } } __attribute__((aligned(16)));
struct M4_92F0 { V4_92F0 r[4]; };

static inline void MulV_92F0(V4_92F0* vp, const M4_92F0* mp)
{
    asm {
        lqc2 vf8, 0(vp)
        lqc2 vf4, 0(mp)
        lqc2 vf5, 0x10(mp)
        lqc2 vf6, 0x20(mp)
        lqc2 vf7, 0x30(mp)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0(vp)
    }
}
static inline V4_92F0 Xform_92F0(const V4_92F0& in, const M4_92F0* m)
{
    V4_92F0 v = in;
    V4_92F0* vp = &v;
    MulV_92F0(vp, m);
    return *vp;
}
struct Node_92F0 {
    VPAD16(a) VPAD4(b) virtual void Update();
    char pad4[0xC];
    M4_92F0 mtx;
    unsigned char dirty;
    const M4_92F0* GetMatrix() { if (dirty) Update(); return &mtx; }
};
struct Caster_92F0 {
    char pad0[0x2C];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x38 - 0x2F];
    int mode;
    char pad3C[0x50 - 0x3C];
    Node_92F0* node;
    bool Shown() { return !b2E; }
};
struct Proj_92F0 {
    char pad0[0x20];
    V4_92F0 dir;
    char pad30[0x10];
    V4_92F0 pos;
    float f50;
    int i54;
    Caster_92F0* caster;
    float fade;
    const V4_92F0& Pos() { return pos; }
    const V4_92F0& Dir() { return dir; }
};
struct Self_92F0 { char pad0[4]; Proj_92F0** items; char pad8[0xC]; int count; };

extern "C" {
extern char D_00543790[];
void Shadow_ResetProjectors(void* list);
void Shadow_AddProjectorSlot(void* list, Caster_92F0* c, V4_92F0* pos, V4_92F0* dir, float a, float b, int c2);
}

extern "C" void DecalMgr_DrawBloodProjectors(Self_92F0* self)
{
    int i;
    Shadow_ResetProjectors(D_00543790);
    for (i = 0; i < self->count; i++) {
        Proj_92F0* p = self->items[i];
        Caster_92F0* c;
        bool ok;
        bool vis;
        float k;
        if (p->fade == -2.0f) continue;
        c = p->caster;
        if (c->mode == 0x80) continue;
        ok = 0;
        vis = 0;
        if (c->b2D) { if (c->b2C) vis = 1; }
        if (vis) { if (c->Shown()) ok = 1; }
        if (!ok) continue;
        k = 1.0f;
        {
        float f = p->fade;
        float zero = 0.0f;
        if (!(f < zero)) {
            k -= f / 2.0f;
            if (k <= zero) p->fade = -2.0f;
        }
        }
        if (k <= 0.0f) continue;
        {
            V4_92F0 pos = p->Pos();
            V4_92F0 dir = p->Dir();
            Node_92F0* n = c->node;
            if (n) {
                const M4_92F0* m;
                m = n->GetMatrix();
                pos = Xform_92F0(pos, m);
                m = n->GetMatrix();
                dir = Xform_92F0(dir, m);
            }
            Shadow_AddProjectorSlot(D_00543790, c, &pos, &dir, p->f50, 0.33f * k, p->i54);
        }
    }
}




