#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
static inline void QRot(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct Nd { Plc world; char pad20[0x30]; Plc local; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; Nd* parent; };
extern "C" {
Nd* Root_GetParent(Nd* n);
void Root_RefreshWorldCache(Nd* n);
Nd* Root_Identity(Nd* n);
void Quat_Assign(V4* d, V4* s);
void Vec4_Copy(V4* d, V4* s);
V4* Placement_GetQuat(Plc* p);
V4* Placement_GetPosition(Plc* p);
void func_00132530(Plc* p, V4* q);
void func_00132510(Plc* p, V4* v);
void func_00132840(V4* q);
void Quat_Multiply(V4* a, V4* b, V4* c);
void func_00132800(V4* d, V4* s);
}
static inline Plc* WorldX(Nd* n)
{
    if (Root_GetParent(n)) {
        Root_RefreshWorldCache(n);
        return &Root_Identity(n)->world;
    }
    return &Root_Identity(n)->local;
}
static inline void Refresh(Nd* n)
{
    Nd* gp = n->parent;
    if (gp && n->dirty) {
        Plc* gw = WorldX(gp);
        Plc* w;
        Plc* l = &Root_Identity(n)->local;
        w = &Root_Identity(n)->world;
        Quat_Assign(&w->rot, &l->rot);
        Vec4_Copy(&w->pos, &l->pos);
        Plc* w2 = &Root_Identity(n)->world;
        func_00132530(w2, Placement_GetQuat(gw));
        func_00132510(w2, Placement_GetPosition(gw));
        n->dirty = 0;
    }
}
static inline Plc* World(Nd* n)
{
    if (n->parent) {
        Refresh(n);
        return &n->world;
    }
    return &n->local;
}
extern "C" void func_00362AF0(Nd* self)
{
    Nd* par = self->parent;
    if (par && self->dirty) {
        Plc* pw = World(par);
        { Plc* s = &self->local; QC(&self->world.rot, &s->rot); QC(&self->world.pos, &s->pos); }
        V4 r;
        V4 m;
        func_00132840(&m);
        Quat_Multiply(&m, &pw->rot, &self->world.rot);
        func_00132800(&r, &m);
        { void* xx = &r; /* dead on purpose: retail keeps this addiu */ }
        V4* v = &self->world.pos;
        QC(&self->world.rot, &r);
        QRot(v, &pw->rot);
        VAdd3(&pw->pos, &self->world.pos);
        self->dirty = 0;
    }
}
