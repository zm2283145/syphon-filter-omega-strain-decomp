/*
 * main/WaterFx: range (3 files, 002B3010-002B3130)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002B3010 */
#pragma push /* merge_units */
typedef struct WaterFx WaterFx;
extern void WaterFx_Clear(WaterFx* w);
extern void operator_delete(void* p);
WaterFx* WaterFx_Destroy(WaterFx* self, short flag) {
    if (self) {
        WaterFx_Clear(self);
        if (flag > 0) {
            operator_delete(self);
        }
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B3010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B3010 */

/* merge_units: begin func_002B3070 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x300];
    float sinTab[64];
    void* slots[20];
    int a450;
    int a454;
} C3WaterFx;
extern void WaterFx_BuildGrid(C3WaterFx* w);
extern float Math_Sin(float x);
C3WaterFx* WaterFx_Construct(C3WaterFx* w)
{
    int i;
    int j;
    float a;
    w->a450 = 0;
    w->a454 = 0;
    for (i = 0; i < 20; i++) {
        w->slots[i] = 0;
    }
    WaterFx_BuildGrid(w);
    a = -3.1415927f;
    for (j = 0; j < 64; j++) {
        w->sinTab[j] = Math_Sin(a);
        a += 0.09817477f;
    }
    return w;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B3070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B3070 */

/* merge_units: begin func_002B3130 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off

struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Ent { char pad[0x28]; V* pos; V* c2C; V* c30; V* c34; };
struct Rs { char pad[0xFB0]; Ent ents[1]; };
struct TexInfo { char pad[0x22]; unsigned short count; };
struct Tex { char pad[0x44]; TexInfo* info; char pad48[4]; unsigned int frame; char pad50[0x10]; unsigned char b60; unsigned char b61; };
struct TexMgr { char pad[8]; Tex** tex; };
struct Rip { V v[5]; float age; float alpha; unsigned int frame; int blend; };
struct RNode { int p0; RNode* next; char pad8[8]; Rip r; };
struct RLink { int p0; RNode* next; };
struct RList { int count; RLink head; };
struct Water { int p0; RList list; float base; float range; char pad18[4]; int tex; };
struct RIter { RNode* node; RIter() {} RIter(const RIter& o) : node(o.node) {} bool operator!=(const RIter& o) const { return node != o.node; } RIter& operator=(const RIter& o) { node = o.node; return *this; } };

extern "C" {
typedef struct G {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; TexMgr* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char D_005381F0[];
extern long long D_005381F8;
extern long long D_004BC1B0[];
void Renderer_BindTexture(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void func_00371200(void* s);
void Vec4_Copy(V* d, const V* s);
void GuiBatch_AddVertexColor(V* d, const V* s);
float GuiBatch_AddVertexUV(void);
V* func_00132000(V* o, float x, float y, float z, float w);
RLink* func_002B3950(RList* l);
RIter* func_002B3940(RIter* it, RNode* n);
void func_002B3930(RIter* out, RList* l);
RIter* func_002B3920(RIter* d, RIter* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define D_00539248 (D_00539210.f48)
#define D_005392D0 (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)
#define RS ((Rs*)D_005381F0)

static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(s) : "memory"); }
static inline void CP(V* d, const V* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void MulTo_(V* out, const V& bb, float s)
{
    int t;
    V r;
    V* pr = &r;
    const V* b = &bb;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
    GQ(out, pr);
}
static inline void MulTo(V* out, const V& b, float s) { MulTo_(out, b, s); }
static inline void AddTo(V* out, const V* a, const V* b)
{
    V r;
    V* pr = &r;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    __int128 z = 0;
    CP(out, &r);
}

static inline void AddTo0(V* out, const V* a, const V* b)
{
    V r;
    V* pr = &r;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    CP(out, &r);
}
struct V4c {
    float x, y, z, w;
    V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline void Emit_(const V& pos, const V4c& col, const V4c& uv)
{
    V tmp;
    Ent* e;
    float u;
    func_0025CA40(D_005381F0);
    e = &RS->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], &pos);
    GuiBatch_AddVertexColor(&e->c30[D_00539224 - 1], (V*)&col);
    u = uv.x + GuiBatch_AddVertexUV();
    Vec4_Copy(&e->c34[D_00539224 - 1], func_00132000(&tmp, u, uv.y + GuiBatch_AddVertexUV(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline void Emit(const V& pos, const V4c& col, const V4c& uv) { Emit_(pos, col, uv); }
static inline void TexFrame(TexMgr* m, int idx, unsigned int f) { Tex* t = m->tex[idx]; { if (f != t->frame && f < t->info->count) { t->b60 = 0; t->b61 = 0; t->frame = f; } } }
static inline unsigned char Prim(void) { if (D_005392D0 & 1) return 3; return 2; }
static inline int Mode(void) { if (D_005392D0 & 1) return 0x41; return 0x62; }

static inline RIter It0(RNode* n) { RIter t; func_002B3940(&t, n); return t; }
static inline RIter Begin(RList* l) { return It0(func_002B3950(l)->next); }
static inline void EndT(RIter* r, RList* l) { RIter t; func_002B3930(&t, l); func_002B3920(r, &t); }
static inline RIter End(RList* l) { RIter r; EndT(&r, l); return r; }

extern "C" void WaterFx_RenderRipples(Water* w)
{
    RIter it;
    for (it = Begin(&w->list); it != End(&w->list); it.node = it.node->next) {
        Rip* r;
        float a, s, k;
        a = it.node->r.age * 0.16666666f;
        r = &it.node->r;
        if (r->blend == 3) a *= 0.7f;
        s = r->alpha * a;
        if (a <= 0.0078125f) continue;
        TexFrame(D_00539248, w->tex, r->frame);
        Renderer_BindTexture(D_00539248, w->tex);
        { int bl = r->blend; D_005392D8 = D_004BC1B0[bl]; }
        k = w->base + w->range * (1.0f - r->age / 1.2f);
        V c0, c1, c2, c3;
        V m0, m1, m2, m3;
        MulTo(&m0, r->v[1], k);
        AddTo(&c0, &m0, &r->v[0]);
        MulTo(&m1, r->v[2], k);
        AddTo(&c1, &m1, &r->v[0]);
        MulTo(&m2, r->v[3], k);
        AddTo(&c2, &m2, &r->v[0]);
        MulTo(&m3, r->v[4], k);
        AddTo0(&c3, &m3, &r->v[0]);
        D_00539238 = Prim();
        D_0053923C = Mode();
        D_00539228 = 0;
        D_0053923C &= ~1;
        {
            Ent* e = &RS->ents[D_00539210.f10];
            e->pos += D_00539224;
            e->c2C += D_00539224;
            e->c30 += D_00539224;
            e->c34 += D_00539224;
        }
        func_0025CD10(D_005381F0);
        D_00539224 = 0;
        Emit(c0, V4c(1.0f, 1.0f, 1.0f, s), V4c(0.0f, 1.0f, 1.0f, 0.0f));
        Emit(c1, V4c(1.0f, 1.0f, 1.0f, a), V4c(0.0f, 0.0f, 1.0f, 0.0f));
        Emit(c2, V4c(1.0f, 1.0f, 1.0f, s), V4c(1.0f, 1.0f, 1.0f, 0.0f));
        Emit(c3, V4c(1.0f, 1.0f, 1.0f, a), V4c(1.0f, 0.0f, 1.0f, 0.0f));
        func_00371200(D_005381F0);
    }
    D_005392D8 = D_004BC1B0[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B3130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B3130 */
