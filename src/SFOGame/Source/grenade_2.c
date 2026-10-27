/*
 * SFOGame/Source/grenade: 2 files, 002596A0-002596E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002596A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

int* func_002596A0(PtrVec* v) {
    return v->data + v->count;
}

void std_list_cAreaEffectPtr_generic_iterator_ctor(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_002596D0(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_002596A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002596A0 */

/* merge_units: begin func_002596E0 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V Sub(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
struct Query {
    struct WV { float x, y, z, w; } __attribute__((aligned(16))) v[3];
    char pad30[0x10];
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    char pad43[0x1D];
    int w60;
    int w64;
    int pad68[2];
    Query() { Query* s = this; WV* p = s->v; do { ++p; } while (p != s->v + 3); s->b40 = 0; s->b42 = 0; s->w60 = 0; s->w64 = 0; }
};
struct Hit { int w[4]; };
struct Actor { char pad[0x346B]; unsigned char b346B; };
struct Eff { char pad[0x70]; V m70; char pad80[0x10]; V m90[4]; };
extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern signed char g_HeadNodeCode;
void* cSystemContainer_GetSystem(void* a, void* b);
int cSKM_GOBJ_GetSkeleton_void(Actor* a);
void cSkeleton_GetBoneToWorldTranslation(V* out, int n, int node);
int cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(void* mgr, Hit* a, Query* b, V* c, const V& d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k);
}
extern "C" bool cAreaEffect_GasCheck(Eff* self, Actor* actor)
{
    if (!actor->b346B) {
        Hit hit;
        Query q;
        void* mgr = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        for (int i = 0; i < 5; i++) {
            V from;
            V pos;
            QC(&from, i ? &self->m90[i - 1] : &self->m70);
            cSkeleton_GetBoneToWorldTranslation(&pos, cSKM_GOBJ_GetSkeleton_void(actor), g_HeadNodeCode);
            from.z = pos.z;
            { void* xx = &pos; /* dead on purpose: retail keeps this addiu */ }
            V d(Sub(pos, from));
            if (!(unsigned char)cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(mgr, &hit, &q, &from, d, 0, 0, 0, 0x58, 0, 0, 0))
                { bool r = true; return r; }
        }
    }
    return false;
}
static inline void merge_flush_func_002596E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002596E0 */
