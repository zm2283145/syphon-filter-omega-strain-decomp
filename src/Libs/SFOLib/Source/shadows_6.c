/*
 * Libs/SFOLib/Source/shadows: 6 files, 003D4810-003D5600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D4810 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* Inline temps get stack slots by inline depth (deeper = allocated later = lower sp offset):
   Inverse is wrapped Inv2..Inv4, operator*(V,float) via MulVS0, the second ScaleR site via ScR1.
   Cp_ is a per-site copy helper (drops the dead ctor-result addiu at the camPos copy).
   Normalize(float*) stores the length in C; len goes through the asm as a tied "1"(len) -> "=r"(p)
   so it is materialised right before the asm and the store goes through the register. */
#pragma enumsalwaysint off
enum PType { PT0, PT1, PT2 };
#pragma enumsalwaysint reset
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    V& Normalize(float* len) {
        void* xx = this; __int128 t = 0; int r; float* p;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%2); qmfc2.ni %0, $vf4" : "=r"(r), "=r"(p) : "r"(this), "0"(t), "1"(len) : "memory");
        *(int*)p = r;
        return *this;
    }
    V& Normalize() {
        void* xx = this;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M;
extern "C" M* cMatrix_ctor_cMatrixR(M* d, const M* s);
struct M {
    float m[4][4];
    M() {}
    M(const M* p);
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));
struct Box { V mn; V mx; V Sum() const; V Center() const; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Xf { void* vt; char pad4[0xC]; M world; unsigned char dirty; };
struct Act { char pad0[0x50]; Xf* x50; char pad54[0xC]; Box box; };
struct Light { unsigned char type; char pad1[3]; float x4; char pad8[8]; V pos; V dir; };
struct Caster { Act* actor; int nLights; int arg; int padC; Light lights[6]; };
struct Proj { Act* actor; float x4; float fov; char padC[2]; unsigned char type; char padF; M view; M x50; float x90; float x94; char pad98[8]; float xA0[4]; V dir; };
struct Shadow { char pad0[0x10]; Caster casters[0xD9]; char padx[0x10540 - 0x10 - 0xD9 * 0x130]; Proj proj[24]; int nProj; };
extern "C" {
float Libc_Atanf(float);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
void BuildLookatMatrix(V* pos, V* dir, M* m);
void BuildProjection(M* out, float* a, float* b, float fov, float f13, float f14, float f15, float f16, float n, float f, float f19, float s0, float s8);
void cShadowMan_AssignShadow(Shadow* sh, int idx, V* c);
extern char g_Video[];
extern int D_00538C64;
extern M D_00539070;
}
static inline void Add(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void SubR(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(a), "r"(r), "r"(b) : "memory"); }
static inline V SubV(const V& a, const V& b) { V r; SubR(&r, &a, &b); return r; }
static inline void Sub(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
inline V Box::Sum() const { V c; Add(&c, &mn, &mx); return c; }
static inline V Scale(V v, float k) { __int128 z = 0; V r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline V Scale2(const V& v, float k) { return Scale(v, k); }
inline V Box::Center() const { V c = Scale(Sum(), 0.5f); return c; }
static inline void MulS_(V* pr, const V* pv, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pv), "r"(pr), "f"(k) : "memory"); }
static inline V MulVS0(const V& v, float k) { V r; V* rp = &r; MulS_(rp, &v, k); return r; }
static inline V operator*(const V& v, float k) { return MulVS0(v, k); }
static inline V ScaleR(const V& v, float k) { __int128 z = 0; V r; V* rp = &r; MulS_(rp, &v, k); return r; }
static inline V ScR0(const V& v, float k) { __int128 z = 0; V r; V* rp = &r; MulS_(rp, &v, k); return r; }
static inline V ScR1(const V& v, float k) { return ScR0(v, k); }
static inline V operator+(const V& a, const V& b) { V r; Add(&r, &a, &b); return r; }
static inline V operator-(const V& a, const V& b) { V r; Sub(&r, &a, &b); return r; }
static inline void Neg_(V* r, const V* a) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a) : "memory"); }
static inline V operator-(const V& a) { V r; Neg_(&r, &a); return r; }
static inline float Dot(const V& a, const V& b) {
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddz.w vf4, vf0, vf3z; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Max(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct V2 : V { V2(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline V XformPt2(const V& v, M* mm) { const V* sv = &v; V2 p(*sv); V* pp = &p; MulM(pp, mm); return *pp; }
static inline V XformPt(const V& v, M* m) { M* mm = m; return XformPt2(v, mm); }
static inline void GMul(void* o, const void* a, const void* b) {
    __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf7, 0x30(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(o), "r"(b), "r"(a) : "memory");
}
static inline void GMul2(void* o, const void* a, const void* b) {
    __asm__ volatile("lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%1); sqc2 vf13, 0x10(%1); sqc2 vf14, 0x20(%1); sqc2 vf15, 0x30(%1)" : : "r"(a), "r"(o), "r"(b) : "memory");
}
static inline M MulM2(const M& a, const M& b) { M r; GMul2(&r, &a, &b); return r; }
static inline M operator*(const M& a, const M& b) { M r; GMul(&r, &a, &b); return r; }
inline M::M(const M* p) { cMatrix_ctor_cMatrixR(this, p); }
static inline M Inv2(const M& m) { M t; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, &m))); }
static inline M Inv3(const M& m) { return Inv2(m); }
static inline M Inv4(const M& m) { return Inv3(m); }
static inline M Inverse(const M& m) { return Inv4(m); }
static inline void Cp_(V* d, const M& m) { void* xx = d; const V* s = (const V*)&m; s += 3; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cShadowMan_ProcessCaster(Shadow* sh, int idx)
{
    float dist;
    float len;
    V center;
    V wc;
    V camPos;
    float radius;
    float fov;
    float n;
    float f;
    float scale;
    float extra;
    Caster* e;
    int i;
    Light* l;
    Proj* p;
    Box* b;
    Xf* x;
    PType type;
    e = &sh->casters[idx];
    b = &e->actor->box;
    if (e->nLights) {
        center = b->Center();
        x = e->actor->x50;
        if (x->dirty) ((XV*)x)->Refresh();
        wc = XformPt(center, &x->world);
        radius = (b->mn - center).Length();
    }
    for (i = 0; i < e->nLights; i++) {
        l = &e->lights[i];
        p = &sh->proj[sh->nProj];
        if (l->type == 0) {
            float maxFov = 0.43633232f;
            l->dir = (wc - l->pos).Normalize(&dist);
            fov = Libc_Atanf((2.0f + radius) / dist);
            fov = fov < maxFov ? fov : maxFov;
            n = dist - radius;
            { float k = 25.0f; f = k + (dist + radius); }
            scale = 1.5f;
            type = PT1;
            extra = 0.0f;
        } else if (l->type == 1) {
            dist = 10.0f;
            l->pos = wc - l->dir * dist;
            fov = Libc_Atanf((2.0f + radius) / dist);
            n = dist - radius;
            { float k = 25.0f; f = k + (dist + radius); }
            scale = 1.5f;
            type = PT1;
            extra = 0.0f;
        } else {
            Cp_(&camPos, Inverse(*(M*)(g_Video + D_00538C64 * 0x40 + 0xA80)));
            dist = (camPos - l->pos).Length();
            fov = Libc_Atanf(radius / dist);
            n = dist - 3.0f * radius - 6.0f;
            f = dist + radius;
            scale = 5.5f;
            type = PT2;
            extra = l->x4;
        }
        if (dist < radius) continue;
        fov *= 0.9f;
        n = Max(n, 1.0f);
        p->actor = e->actor;
        p->fov = fov;
        p->x4 = l->x4;
        if (type == 2) {
            V d = (l->pos - camPos).Normalize(&len);
            V refl = SubV(ScaleR(l->dir, 2.0f * Dot(d, l->dir)), d);
            l->pos = l->pos + ScR1(refl, len);
            l->dir = (wc - l->pos).Normalize();
        }
        BuildLookatMatrix(&l->pos, &l->dir, &p->view);
        {
            M persp;
            float inv;
            BuildProjection(&persp, &p->x90, p->xA0, fov, 0.0f, 1.0f, 0.0f, 1.0f, n, f, 1.0f, 1.0f, extra);
            inv = 1.0f / scale;
            persp.m[0][0] *= inv;
            persp.m[1][1] *= inv;
            p->x90 *= scale;
            p->x94 *= scale;
            p->x50 = MulM2(persp * D_00539070, p->view);
        }
        p->dir = (type == 1) ? l->dir : -l->dir;
        p->type = type;
        cShadowMan_AssignShadow(sh, sh->nProj, &wc);
        sh->nProj++;
    }
}
static inline void merge_flush_func_003D4810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D4810 */

/* merge_units: begin func_003D5260 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x51]; unsigned char b51; unsigned char b52; } F6Info;
struct F6Act { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual F6Info* GetInfo(); char pad[0x34]; int x38; char pad2[0x14]; int x50; };
typedef struct { F6Act* actor; int x4; int arg; char pad[0x124]; } F6Ent;
typedef struct { int x0; int max; char pad[8]; F6Ent ents[219]; char pad2[0xB0]; int count; } F6Sys;
extern "C" int g_DrawMode;
extern "C" void cShadowMan_AddCaster(F6Sys* s, F6Act* a, int arg)
{
    if (g_DrawMode & 0x60) {
        if (s->count < s->max && a->x38 != 0x80 && a->x50) {
            F6Info* p = a->GetInfo();
            if (p && (p->b52 || p->b51)) {
                F6Ent* e = &s->ents[s->count];
                e->actor = a;
                e->x4 = 0;
                e->arg = arg;
                s->count++;
            }
        }
    }
}
static inline void merge_flush_func_003D5260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5260 */

/* merge_units: begin func_003D5360 */
#pragma push /* merge_units */
typedef struct { char pad[0x104D0]; int v; } BigObj;
/* Clears the word at +0x104D0. */
void cShadowMan_ClearCasters(BigObj* o) { o->v = 0; }
static inline void merge_flush_func_003D5360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5360 */

/* merge_units: begin func_003D5370 */
#pragma push /* merge_units */
typedef struct { __int128 q; } Q5600;
typedef struct { unsigned char b0; float dist; char pad8[8]; Q5600 pos; Q5600 v; } E5600;
typedef struct { int f0; int count; int max; int fC; E5600 e[6]; } G5600;
typedef struct { int max; int pad4[3]; G5600 g[1]; } S5600;
extern int g_DrawMode;
#define IDX5600(s) (*(int*)((char*)(s) + 0x11768))
static inline int Min5600(int a, int b) { int r; if (a < b) { r = a; asm { .set reorder } } else r = b; return r; }
#pragma peephole on
#pragma opt_rotateloops off
#pragma opt_common_subs off

void cShadowMan_AddReflectionSource(S5600* s, Q5600* pos, Q5600* v, float dist)
{
    if (g_DrawMode & 0x40) {
        G5600* g;
        char* p;
        int lim, n, slot;
        if (dist <= 0.0f)
            return;
        p = (char*)s + IDX5600(s)*sizeof(G5600);
        g = (G5600*)(p + 0x10);
        lim = Min5600(s->max, *(int*)(p + 0x18));
        n = g->count;
        slot = -1;
        if (n < lim) {
            slot = n;
            g->count = n + 1;
        } else {
            for (lim = 0; lim < n; lim++) {
                if (((E5600*)(lim*sizeof(E5600) + (char*)g->e))->dist < dist) {
                    slot = lim;
                    break;
                }
            }
        }
        if (slot >= 0) {
            int k = 2;
            G5600* e = (G5600*)(slot*sizeof(E5600) + (char*)g->e - 0x10);
            asm { .set reorder } /* sched barrier */
            e->e[0].b0 = k;
            { Q5600* d = &e->e[0].pos; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(pos) : "memory"); }
            ((G5600*)(slot*sizeof(E5600) + (char*)g))->e[0].v = *v;
            ((E5600*)(slot*sizeof(E5600) + (char*)g->e))->dist = dist;
        }
    }
}
static inline void merge_flush_func_003D5370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5370 */

/* merge_units: begin func_003D54B0 */
#pragma push /* merge_units */
#pragma peephole on
#pragma opt_rotateloops off
#pragma opt_common_subs off


void cShadowMan_AddParallelSource(S5600* s, Q5600* v, float dist)
{
    if (g_DrawMode & 0x20) {
        Q5600 zero;
        int slot;
        G5600* g;
        char* p;
        int lim;
        int n;
        int i;
        ((int*)&zero)[0] = 0;
        ((int*)&zero)[1] = 0;
        ((int*)&zero)[2] = 0;
        ((int*)&zero)[3] = 0;
        if (dist <= 0.0f)
            return;
        p = (char*)s + IDX5600(s)*sizeof(G5600);
        g = (G5600*)(p + 0x10);
        lim = Min5600(s->max, *(int*)(p + 0x18));
        n = g->count;
        slot = -1;
        if (n < lim) {
            slot = n;
            g->count = n + 1;
        } else {
            for (lim = 0; lim < n; lim++) {
                if (((E5600*)(lim*sizeof(E5600) + (char*)g->e))->dist < dist) {
                    slot = lim;
                    break;
                }
            }
        }
        if (slot >= 0) {
            Q5600* zp = &zero;
            int k = 1;
            G5600* e = (G5600*)(slot*sizeof(E5600) + (char*)g->e - 0x10);
            e->e[0].b0 = k;
            asm { .set reorder } /* sched barrier */
            { Q5600* d = &e->e[0].pos; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(zp) : "memory"); }
            ((G5600*)(slot*sizeof(E5600) + (char*)g))->e[0].v = *v;
            ((E5600*)(slot*sizeof(E5600) + (char*)g->e))->dist = dist;
        }
    }
}
static inline void merge_flush_func_003D54B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D54B0 */

/* merge_units: begin func_003D5600 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_rotateloops off
#pragma opt_common_subs off


void cShadowMan_AddPointSource(S5600* s, Q5600* pos, float dist)
{
    if (g_DrawMode & 0x20) {
        Q5600 zero;
        int slot;
        G5600* g;
        char* p;
        int lim;
        int n;
        ((int*)&zero)[0] = 0;
        ((int*)&zero)[1] = 0;
        ((int*)&zero)[2] = 0;
        ((int*)&zero)[3] = 0;
        if (dist <= 0.0f)
            return;
        p = (char*)s + IDX5600(s)*sizeof(G5600);
        g = (G5600*)(p + 0x10);
        lim = Min5600(s->max, *(int*)(p + 0x18));
        n = g->count;
        slot = -1;
        if (n < lim) {
            slot = n;
            g->count = n + 1;
        } else {
            for (lim = 0; lim < n; lim++) {
                if (((E5600*)(lim*sizeof(E5600) + (char*)g->e))->dist < dist) {
                    slot = lim;
                    break;
                }
            }
        }
        if (slot >= 0) {
            G5600* e = (G5600*)(slot*sizeof(E5600) + (char*)g->e - 0x10);
            e->e[0].b0 = 0;
            asm { .set reorder } /* sched barrier */
            { Q5600* d = &e->e[0].pos; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(pos) : "memory"); }
            ((G5600*)(slot*sizeof(E5600) + (char*)g))->e[0].v = zero;
            ((E5600*)(slot*sizeof(E5600) + (char*)g->e))->dist = dist;
        }
    }
}
static inline void merge_flush_func_003D5600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5600 */
