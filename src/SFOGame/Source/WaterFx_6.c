/*
 * SFOGame/Source/WaterFx: 5 files, 002B3010-002B3920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B3010 */
#pragma push /* merge_units */
#include "types.h"

typedef struct WaterFx WaterFx;
extern void cWaterFx_Purge(WaterFx* w);
extern void operator_delete(void* p);
WaterFx* cWaterFx_dtor(WaterFx* self, short flag) {
    if (self) {
        cWaterFx_Purge(self);
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
extern void cWaterFx_CreateWaterBaseCVs(C3WaterFx* w);
extern float Libc_Sinf(float x);
C3WaterFx* cWaterFx_ctor(C3WaterFx* w)
{
    int i;
    int j;
    float a;
    w->a450 = 0;
    w->a454 = 0;
    for (i = 0; i < 20; i++) {
        w->slots[i] = 0;
    }
    cWaterFx_CreateWaterBaseCVs(w);
    a = -3.1415927f;
    for (j = 0; j < 64; j++) {
        w->sinTab[j] = Libc_Sinf(a);
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
extern char g_Video[];
extern long long D_005381F8;
extern long long D_004BC1B0[];
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void XLib_DrawStrip(void* s);
void cVector_opAssign(V* d, const V* s);
void tIRGBA_opAssign_tRGBAR(V* d, const V* s);
float tVifFloatToInt_short_4_Bias(void);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
#if 0 /* merge_units */
RLink* std_list_deleter_tNode_tail(RList* l);
#endif /* merge_units */
struct WaterListLink; /* merge_units */
struct WaterList; /* merge_units */
WaterListLink* std_list_deleter_tNode_tail(WaterList* list); /* merge_units */
#define std_list_deleter_tNode_tail(a0) ((RLink *)std_list_deleter_tNode_tail((WaterList *)(a0))) /* merge_units */

#if 0 /* merge_units */
RIter* std_list_deleter_tNode_generic_iterator_ctor_nodeP(RIter* it, RNode* n);
#endif /* merge_units */
struct WaterListIter; /* merge_units */
struct WaterListLink; /* merge_units */
WaterListIter* std_list_deleter_tNode_generic_iterator_ctor_nodeP(WaterListIter* it, WaterListLink* node); /* merge_units */
#define std_list_deleter_tNode_generic_iterator_ctor_nodeP(a0, a1) ((RIter *)std_list_deleter_tNode_generic_iterator_ctor_nodeP((WaterListIter *)(a0), (WaterListLink *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_deleter_tNode_end(RIter* out, RList* l);
#endif /* merge_units */
void std_list_deleter_tNode_end(Iter* out, Tree* t); /* merge_units */
#define std_list_deleter_tNode_end(a0, a1) (std_list_deleter_tNode_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
RIter* cLListIterator_tNode_ctor(RIter* d, RIter* s);
#endif /* merge_units */
Word* cLListIterator_tNode_ctor(Word* dst, Word* src); /* merge_units */
#define cLListIterator_tNode_ctor(a0, a1) ((RIter *)cLListIterator_tNode_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)
#define RS ((Rs*)g_Video)

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
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], (V*)&col);
    u = uv.x + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline void Emit(const V& pos, const V4c& col, const V4c& uv) { Emit_(pos, col, uv); }
static inline void TexFrame(TexMgr* m, int idx, unsigned int f) { Tex* t = m->tex[idx]; { if (f != t->frame && f < t->info->count) { t->b60 = 0; t->b61 = 0; t->frame = f; } } }
static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline RIter It0(RNode* n) { RIter t; std_list_deleter_tNode_generic_iterator_ctor_nodeP(&t, n); return t; }
static inline RIter Begin(RList* l) { return It0(std_list_deleter_tNode_tail(l)->next); }
static inline void EndT(RIter* r, RList* l) { RIter t; std_list_deleter_tNode_end(&t, l); cLListIterator_tNode_ctor(r, &t); }
static inline RIter End(RList* l) { RIter r; EndT(&r, l); return r; }

extern "C" void cWake_Render(Water* w)
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
        TexFrame(g_TextureMgr, w->tex, r->frame);
        cTexMan_SetActive(g_TextureMgr, w->tex);
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
        XLib_NewStrip(g_Video);
        D_00539224 = 0;
        Emit(c0, V4c(1.0f, 1.0f, 1.0f, s), V4c(0.0f, 1.0f, 1.0f, 0.0f));
        Emit(c1, V4c(1.0f, 1.0f, 1.0f, a), V4c(0.0f, 0.0f, 1.0f, 0.0f));
        Emit(c2, V4c(1.0f, 1.0f, 1.0f, s), V4c(1.0f, 1.0f, 1.0f, 0.0f));
        Emit(c3, V4c(1.0f, 1.0f, 1.0f, a), V4c(1.0f, 0.0f, 1.0f, 0.0f));
        XLib_DrawStrip(g_Video);
    }
    D_005392D8 = D_004BC1B0[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B3130(void) {}
#undef std_list_deleter_tNode_tail /* merge_units */
#undef std_list_deleter_tNode_generic_iterator_ctor_nodeP /* merge_units */
#undef std_list_deleter_tNode_end /* merge_units */
#undef cLListIterator_tNode_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3130 */

/* merge_units: begin func_002B3920 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "WaterFx_types.h"

Word* cLListIterator_tNode_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_deleter_tNode_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

WaterListIter* std_list_deleter_tNode_generic_iterator_ctor_nodeP(WaterListIter* it, WaterListLink* node) {
    it->node = node;
    return it;
}

/* Address of the list sentinel (end()). */
WaterListLink* std_list_deleter_tNode_tail(WaterList* list) {
    return &list->head;
}
static inline void merge_flush_func_002B3920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3920 */

/* merge_units: begin func_002B3960 */
#pragma push /* merge_units */
// cWake::NextFrame(float, cMatrix&, cVector&). Op* as wrapper over Mul0 + return *pt removes dead addiu; Length asm non-volatile lets w copy-prop to a0;
// RandN via asm cvt.w.s/mfc1 helper with 'int r = 0' gives retail's dead daddu zero inits.
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q3960(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QS(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
struct V_002B3960 {
    float x, y, z, w;
    V_002B3960() {}
    V_002B3960(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V_002B3960(const V_002B3960& o) { { V_002B3960* dd = this; const V_002B3960* ss = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); } }
    V_002B3960(const V_002B3960* p, int) { Q3960(this, p); }
    V_002B3960& operator=(const V_002B3960& o) { { V_002B3960* dd = this; const V_002B3960* ss = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); } return *this; }
    void Set2(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct RotM;
extern "C" void cMatrix_ctor_void(RotM* m);
struct Q4 { float f[4]; } __attribute__((aligned(16)));
struct M {
    Q4 r[4];
    void Identity() { M* p = this; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
    void Apply(V_002B3960* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    void Apply2(V_002B3960* v) const { __asm__ volatile("lqc2 vf8, 0x0(%1); lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%1)" : : "r"(this), "r"(v) : "memory"); }
    V_002B3960 Mul0(const V_002B3960& v) const { V_002B3960 t = v; const V_002B3960* pt = &t; Apply((V_002B3960*)pt); return *pt; }
    V_002B3960 operator*(const V_002B3960& v) const { return Mul0(v); }
    void RotAxis(const V_002B3960& a, float ang);
};
struct RotM { Q4 r[4]; RotM() { cMatrix_ctor_void(this); } };
static inline const V_002B3960& Normalized(V_002B3960 v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(&v) : "memory"); return v; }
static inline float Length(const V_002B3960* v) { float r; __asm__("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(r) : "r"(v) : "memory"); return r; }
struct RNode_002B3960 { RNode_002B3960* next; };
struct It {
    RNode_002B3960* p;
    It() {}
    It(RNode_002B3960* q) : p(q) {}
    It(const It& o) : p(o.p) {}
    It& operator=(const It& o) { p = o.p; return *this; }
    It& operator++() { p = p->next; return *this; }
};
struct RHead { RNode_002B3960* n0; RNode_002B3960* n4; };
struct Ripple {
    V_002B3960 pos;
    V_002B3960 d[4];
    float f170;
    float f174;
    int i178;
    void* p17C;
};
struct RList_002B3960 { int size; RHead h; };
struct WaterFx_002B3960 {
    float timer;
    RList_002B3960 list;
    char pad10[8];
    float f18; char pad1C[4];
    int n20;
};
struct WObj { char pad[0x30]; V_002B3960 pos; };
extern "C" {
RNode_002B3960* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(RHead* h);
It std_list_deleter_tNode_erase_listdeleter(RList_002B3960* l, It pos);
It std_list_deleter_tNode_insert(RList_002B3960* l, It pos, const Ripple& r);
float Libc_Atan2f(float y, float x);
void cMatrix_SetWithAxisAngle(RotM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, const RotM* b);
void cMatrix_ctor_void(RotM* m);
int Libc_Rand(void);
void cWake_NextFrame_float(WaterFx_002B3960* w, float dt);
extern V_002B3960 D_004ABF60;
extern V_002B3960 D_004ABF70;
extern V_002B3960 D_004ABF80;
extern V_002B3960 D_004ABF90;
extern void* D_004ABFA0[];
}
static inline void MulRot(M* m, const V_002B3960& a, float ang) { RotM rm; cMatrix_SetWithAxisAngle(&rm, a.x, a.y, a.z, ang); cMatrix_Rotate(m, &rm); }
static inline void MulRot2(M* m, const V_002B3960& a, float ang) { MulRot(m, a, ang); }
static inline void MulRot3(M* m, const V_002B3960& a, float ang) { MulRot2(m, a, ang); }
inline void M::RotAxis(const V_002B3960& a, float ang) { MulRot3(this, a, ang); }
static inline void SetF(float* p, float v) { *p = v; }
static inline It End_002B3960(RHead* h) { RHead* t = h; return It(t->n4); }
static inline It EndL(RList_002B3960* l) { return End_002B3960(&l->h); }
static inline It Begin_002B3960(RList_002B3960* l) { return It(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(&l->h)); }
static inline int FtoI(float f) { int r = 0; asm { cvt.w.s f, f; mfc1 r, f } return r; }
static inline int RandN(int n) { int r = Libc_Rand(); return FtoI((float)n * ((float)r / 2147483648.0f)); }
static inline int RandRange(int lo, int hi) { int n = hi - lo + 1; return lo + RandN(n); }
extern "C" void cWake_NextFrame_float_cMatrixR_cVectorR(WaterFx_002B3960* w, WObj* o, V_002B3960* vel, float dt)
{
    V_002B3960 v;
    v.Set2(vel->x, vel->y, 0.0f, 0.0f);
    float speed = Length(&v);
    float half = 0.5f * dt;
    if (!(w->timer < 0.0375f)) {
        w->timer -= 0.0375f;
        if (w->list.size >= 0x20) {
            It it;
            It e;
            it = Begin_002B3960(&w->list);
            ++it;
            e = std_list_deleter_tNode_erase_listdeleter(&w->list, it);
        }
        float ang = Libc_Atan2f(-vel->x, vel->y);
        M m;
        m.Identity();
        m.RotAxis(V_002B3960(0.0f, 0.0f, 1.0f, 0.0f), ang);
        Ripple r;
        r.pos = o->pos;
        r.pos.z = w->f18;
        r.d[0] = Normalized(m * D_004ABF60);
        r.d[1] = Normalized(m * D_004ABF70);
        r.d[2] = Normalized(m * D_004ABF80);
        r.d[3] = Normalized(m * D_004ABF90);
        r.f174 = (speed > -vel->z) ? 0.0f : 1.0f;
        r.p17C = D_004ABFA0[RandRange(0, 2)];
        r.f170 = 1.2f;
        int k = RandRange(0, w->n20 - 2);
        r.i178 = k;
        std_list_deleter_tNode_insert(&w->list, End_002B3960(&w->list.h), r);
    }
    cWake_NextFrame_float(w, dt);
    if (!(speed <= half) || speed < -vel->z)
        w->timer += dt;
}
static inline void merge_flush_func_002B3960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3960 */
