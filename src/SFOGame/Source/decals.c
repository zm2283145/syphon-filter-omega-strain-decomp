/*
 * SFOGame/Source/decals: 7 files, 002783A0-00278650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002783A0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Sub78 {
    char pad[0xC];
    unsigned char unkC;
    char pad2[3];
} Sub78;

typedef struct Obj116 {
    char pad[0x60];
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Sub78 sub;
    char pad2[0xD0 - 0x88];
    unsigned char unkD0;
    char pad3;
    unsigned char unkD2;
    char pad4[0xF0 - 0xD3];
    int unkF0;
    int unkF4;
    char pad5[0x115 - 0xF8];
    unsigned char unk115;
} Obj116;

#if 0 /* merge_units */
extern void func_00278440(Sub78*);
#endif /* merge_units */
Rel * func_00278440(); /* merge_units */


extern int cArrayCapacity_Int(int*);
#if 0 /* merge_units */
extern void PtrVec_Reserve_Thunk_278430(Sub78*, int);
#endif /* merge_units */
int PtrVec_Reserve_Thunk_278430(); /* merge_units */



/* Constructor body: resets three (0, -2) pairs, sets up the sub-object and clears flags. */
Obj116* cBullet_ctor(Obj116* o) {
    int kind;
    Sub78* sub;
    o->unk64 = -2;
    sub = &o->sub;
    o->unk60 = 0;
    o->unk6C = -2;
    o->unk68 = 0;
    o->unk74 = -2;
    o->unk70 = 0;
    kind = 5;
    func_00278440(sub);
    PtrVec_Reserve_Thunk_278430(sub, cArrayCapacity_Int(&kind));
    sub->unkC = 0;
    o->unkD0 = 0;
    o->unkD2 = 0;
    o->unkF0 = 0;
    o->unkF4 = 0;
    o->unk115 = 0;
    return o;
}
static inline void merge_flush_func_002783A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002783A0 */

/* merge_units: begin func_00278430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_reserve(int, int);

int PtrVec_Reserve_Thunk_278430(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* func_00278440(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00278430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278430 */

/* merge_units: begin func_00278460 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
#pragma opt_rotateloops off


#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma opt_propagation off

struct cVector { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" {
long long Libc_Cos(long long x);
long long Libc_Sin(long long x);
long long SoftFloat_FloatToDouble(float f);
long long SoftFloat_DoubleMultiply(long long a, long long b);
float SoftFloat_DoubleToFloat(long long a);
void CreateSphereNormals(cVector* outNorms, int num);
}

static inline float Sqrt(float x) { asm { sqrt.s x, x } return x; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Normalize(cVector* a) { cVector* r = a;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(r)
    }
}

#define DEG2RAD(a) (0.017453292f * (a))
/* MW's implicit fptodp/dpmul/dptofp runtime calls, named explicitly */
#define D(a) SoftFloat_FloatToDouble(a)
#define F(a) SoftFloat_DoubleToFloat(a)
#define MUL(a, b) SoftFloat_DoubleMultiply(a, b)

void CreateSphereNormals(cVector* outNorms, int num)
{
float naxis;
 float dtheta, dphi, theta, phi;
 float b;
 float a;
phi = 0.0f; naxis = Sqrt(num); dtheta = 180.0f / naxis; dphi = 360.0f / naxis; theta = -90.0f;
    
    int cnt = num;
    int ray = 0;
    while (cnt) {
        cVector& norm = outNorms[ray++];
        norm.x = F(MUL(Libc_Cos(D(DEG2RAD(theta))), Libc_Cos(D(DEG2RAD(phi)))));
        norm.y = F(MUL(Libc_Cos(D(DEG2RAD(theta))), Libc_Sin(D(DEG2RAD(phi)))));
        norm.z = F(Libc_Sin(D(DEG2RAD(theta))));
        *(int*)&norm.w = 0;
        Normalize(&norm);
        float full = 360.0f;
        phi += dphi;
        if (!(phi < full)) {
            phi -= full;
            theta += dtheta;
        }
        cnt--;
    }
}
static inline void merge_flush_func_00278460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278460 */

/* merge_units: begin func_00278650 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V(const V* p, int) { V* dd = this; const V* ss = p; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q), "+r"(dd) : "r"(ss) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VX : V { VX(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; } };
typedef struct Mtx { __int128 q[4]; } Mtx;
typedef struct Strip { char pad[0x80]; int idx[12]; char padB0[0x10]; } Strip;
typedef struct Ent {
    char pad[0x24];
    Strip* c24;
    V* pos;
    V* c2C;
    V* c30;
    V* c34;
} Ent;
typedef struct Rs {
    char pad[0xA80];
    Mtx mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent ents[1];
} Rs;
struct Mdl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void Update();
    char pad4[0xC]; Mtx m; unsigned char f50;
};
typedef struct Obj { char pad[0x50]; Mdl* mdl; } Obj;
typedef struct Item { int flags; char pad4[0xC]; Mtx m; float r; int tex; Obj* obj; float fade; } Item;
typedef struct Arg { Item** items; char pad4[0xC]; int count; } Arg;

extern "C" {
typedef struct G {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C64;
extern char D_00538C68;
extern long long D_004BC1B0[];
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void XLib_DrawStrip(void* s);
void cVector_opAssign(V* d, const V* s);
void tIRGBA_opAssign_tRGBAR(V* d, const V* s);
float tVifFloatToInt_short_4_Bias(void);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS ((Rs*)g_Video)

static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MulM(void* d, const void* m) { __asm__ volatile("lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(m) : "memory"); }
static inline void Xform(V* d, const Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m) : "memory"); }
static inline V operator*(const Mtx& m, const V& v) { V t = v; const V* pt = &t; Xform((V*)pt, &m); return V(pt, 0); }
static inline void MulV(V* d, const Mtx& m, const V& v) { V t = v; const V* pt = &t; Xform((V*)pt, &m); { V* dd = d; const V* ss = pt; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q), "+r"(dd) : "r"(ss) : "memory"); } }

static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Begin(void)
{
    Ent* e;
    D_00539238 = Prim();
    D_0053923C = Mode();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}
static inline void Emit(const V& pos, const V& col, const V& uv)
{
    V tmp;
    Ent* e;
    float u;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    u = uv.x + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline bool EndStrip(void)
{
    if (D_00539220 > 0 && D_00539230 > 0) {
        int n = D_00539220 - 1;
        if (D_00539234 < 12) {
            Ent* e = &RS->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->c24[n].idx[D_00539234] = v;
            D_00539234++;
        } else {

            if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
            { int v; int j; Strip** pc; Strip* s; v = D_00539238 - 1; s = ((Strip**)(g_Video + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->idx[j] = v; }
            D_00539230 = 0;
            D_00539234 = 0;
            D_00539228++;
            D_00539220++;
        }
    }
    return true;
}

extern "C" void cDecalMan_Render(Arg* a)
{
    int saved;
    int tex;
    int blend;
    Obj* obj;
    int i;
    bool first;
    V col;
    saved = g_DrawMode;
    g_DrawMode = 0x400005;
    Begin();
    tex = -1;
    first = true;
    obj = 0;
    blend = tex;
    col.x = 1.0f;
    i = 0;
    col.y = 1.0f;
    col.z = 1.0f;
    col.w = 1.0f;
    for (; i < a->count; i++) {
        Item* it = a->items[i];
        float alpha;
        int b;
        if (it->fade == -2.0f) continue;
        alpha = 1.0f;
        if (!(it->fade < 0.0f)) {
            alpha = 1.0f - it->fade / 2.0f;
            if (alpha <= 0.0f) it->fade = -2.0f;
        }
        col.w = alpha;
        if (alpha <= 0.0f) continue;
        if (it->flags & 8) b = 3;
        else if (it->flags & 4) b = 0;
        else if (it->flags & 0x10) b = 2;
        else b = 3;
        {
            bool c3 = true;
            bool c2 = true;
            bool c1 = true;
            if (!first && tex == it->tex) c1 = 0;
            if (!c1 && b == blend) c2 = 0;
            if (!c2 && it->obj == obj) c3 = 0;
            if (c3 != false) {
                XLib_DrawStrip(g_Video);
                Begin();
                if (tex != it->tex) {
                    tex = it->tex;
                    cTexMan_SetActive(g_TextureMgr, tex);
                }
                if (b != blend) {
                    blend = b;
                    D_005392D8 = D_004BC1B0[b];
                }
                if (it->obj != obj) {
                    if (obj) {
                        D_00538C64--;
                        D_00538C68 = 1;
                    }
                    obj = it->obj;
                    if (obj) {
                        Mdl* m;
                        QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
                        D_00538C64++;
                        m = obj->mdl;
                        if (m->f50) m->Update();
                        MulM(&RS->mtx[D_00538C64], &m->m);
                        D_00538C68 = 1;
                    }
                }
            }
        }
        {
            float r = it->r;
            const Mtx* m = &it->m;
            V c0; MulV(&c0, *m, V(-r, 0.0f, -r, 1.0f));
            V c1; MulV(&c1, *m, V(-r, 0.0f, r, 1.0f));
            V c2; MulV(&c2, *m, V(r, 0.0f, -r, 1.0f));
            V c3; MulV(&c3, *m, V(r, 0.0f, r, 1.0f));
            Emit(c0, col, VX(0.0f, 1.0f, 1.0f, 0.0f));
            Emit(c1, col, V(0.0f, 0.0f, 1.0f, 0.0f));
            Emit(c2, col, V(1.0f, 1.0f, 1.0f, 0.0f));
            Emit(c3, col, V(1.0f, 0.0f, 1.0f, 0.0f));
        }
        first = !EndStrip();
    }
    XLib_DrawStrip(g_Video);
    if (obj) {
        D_00538C64--;
        D_00538C68 = 1;
    }
    g_DrawMode = saved;
    D_005392D8 = D_004BC1B0[0];
}
static inline void merge_flush_func_00278650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278650 */

/* merge_units: begin func_002792F0 */
#pragma push /* merge_units */
#pragma optimization_level 0
#pragma schedule on
#pragma peephole on
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma inline_depth(8)
#pragma cplusplus on
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
void cShadowMan_ClearProjTexs(void* list);
void cShadowMan_AddProjTex(void* list, Caster_92F0* c, V4_92F0* pos, V4_92F0* dir, float a, float b, int c2);
}

extern "C" void cDecalMan_PreRender(Self_92F0* self)
{
    int i;
    cShadowMan_ClearProjTexs(D_00543790);
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
            cShadowMan_AddProjTex(D_00543790, c, &pos, &dir, p->f50, 0.33f * k, p->i54);
        }
    }
}
static inline void merge_flush_func_002792F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002792F0 */

/* merge_units: begin func_002795A0 */
#pragma push /* merge_units */
typedef struct { char p[0x5C]; int f5C; } E279;
typedef struct { E279 **a; E279 **b; int p8[2]; int na; int nb; } L279;
void DecalMgr_KillAll(L279 *l) {
    int i;
    int j;
    for (i = 0; i < l->na; i++) l->a[i]->f5C = 0xC0000000;
    for (j = 0; j < l->nb; j++) l->b[j]->f5C = 0xC0000000;
}
static inline void merge_flush_func_002795A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002795A0 */

/* merge_units: begin func_00279630 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_279630 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E;
    bool Active() { return b2D && b2C && !b2E; } };
struct Item_279630 { char pad[0x58]; Ctl_279630* ctl; float t; };
struct Mgr_279630 { Item_279630** a; Item_279630** b; char pad8[8]; int na; int nb; };
static inline void Tick_279630(Item_279630* it, float dt) {
    if (*(volatile float*)&it->t >= 0.0f) {
        it->t += dt;
        if (it->t >= 2.0f) it->t = -2.0f;
    }
    { Ctl_279630* c = it->ctl; if (c && !c->Active()) it->t = -2.0f; }
}
extern "C" void cDecalMan_NextFrame(Mgr_279630* m, float dt) {
    { int i; for (i = 0; i < m->na; i++) Tick_279630(m->a[i], dt); }
    { int i; for (i = 0; i < m->nb; i++) Tick_279630(m->b[i], dt); }
}
static inline void merge_flush_func_00279630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00279630 */
