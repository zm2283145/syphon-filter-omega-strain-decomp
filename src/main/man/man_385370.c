/*
 * main/man: range (2 files, 00385370-00385420)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vu0_ops.h"

/* merge_units: begin func_00385370 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_385420;
typedef struct { V4_385420 r[4]; } Mtx_385420;
typedef struct { V4_385420 trans; float m[3][4]; char pad[0x10]; } Attach_385420;
typedef struct {
    char pad0[0x14];
    unsigned char flag14;
    char pad15[3];
    char nodes[0x10];
    void* xform;
} Skel_385420;
typedef struct {
    char pad0[0x2450];
    unsigned char node[0x10];
    Attach_385420 attach[0x10];
    char pad[0x2C04 - 0x2460 - 0x10 * 0x50];
    Skel_385420* skel;
} Actor_385420;
void ActorRender_GetAttachPoint(Actor_385420* a, Mtx_385420* out, int i); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void Q5370(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q5370(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Rotate(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Rotated(V v) const { V* p = &v; Rotate(p); return *p; }
    void Translate(V v) { __asm__ volatile("lqc2 vf1, 0x30(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x30(%0)" : : "r"(this), "r"(&v) : "memory"); }
};
struct Muzzle { char pad[0x130]; V off; };
struct Weapon { char pad[0x2410]; Muzzle* muzzle[4]; };
#if 0 /* merge_units */
extern "C" void ActorRender_GetAttachPoint(Weapon* a, M* out, int i);
#endif /* merge_units */
#define ActorRender_GetAttachPoint(a0, a1, a2) (ActorRender_GetAttachPoint((Actor_385420 *)(a0), (Mtx_385420 *)(a1), (a2))) /* merge_units */

extern "C" void Weapon_AddMuzzleOffset(Weapon* w, M* m, int i)
{
    ActorRender_GetAttachPoint(w, m, i);
    if (w->muzzle[i]) {
        m->Translate(m->Rotated(w->muzzle[i]->off));
    }
}
#undef ActorRender_GetAttachPoint /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00385370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00385370 */

/* merge_units: begin func_00385420 */
#pragma push /* merge_units */
extern void* Skeleton_NodeAt(void*, int);
extern void* cBone_Xform(void*);
extern Mtx_385420* Transform_GetUpdated(void*);
extern void Actor_ShotFrameNodeWorld(Mtx_385420*, Mtx_385420*, Mtx_385420*);
extern void Mtx_Copy(Mtx_385420*, Mtx_385420*);

/* Indexing through an unsized-array view emits idx*0x50 + base (retail addu order). */
#define ATT(a, i) (*(Attach_385420(*)[])(a)->attach)[i]

void ActorRender_GetAttachPoint(Actor_385420* a, Mtx_385420* out, int i)
{
    Mtx_385420 node;
    Mtx_385420 m;
    Skel_385420* s = a->skel;
    int n = a->node[i];
    Attach_385420* at;
    Mtx_385420* pm;
    V4_385420* d;
    V4_385420* src;
    Mtx_385420* pn;

    if (s->flag14) {
        Mtx_385420* t = Transform_GetUpdated(cBone_Xform(Skeleton_NodeAt(s->nodes, n)));
        Actor_ShotFrameNodeWorld(&node, t, Transform_GetUpdated(s->xform));
    } else {
        Mtx_Copy(&node, Transform_GetUpdated(s->xform));
    }
    d = &m.r[3];
    pm = &m;
    src = &ATT(a, i).trans;
    m.r[0].x = ATT(a, i).m[0][0];
    m.r[0].y = ATT(a, i).m[0][1];
    m.r[0].z = ATT(a, i).m[0][2];
    m.r[1].x = ATT(a, i).m[1][0];
    m.r[1].y = ATT(a, i).m[1][1];
    m.r[1].z = ATT(a, i).m[1][2];
    m.r[2].x = ATT(a, i).m[2][0];
    m.r[2].y = ATT(a, i).m[2][1];
    m.r[2].z = ATT(a, i).m[2][2];
    m.r[0].w = ATT(a, i).m[0][3];
    m.r[1].w = ATT(a, i).m[1][3];
    m.r[2].w = ATT(a, i).m[2][3];
    { __int128 q = V4Load(src); pn = &node; V4Store(d, q); }
    VU0_MulMtx44(out, pn, pm);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00385420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00385420 */
