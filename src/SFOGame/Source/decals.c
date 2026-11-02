/*
 * SFOGame/Source/decals: 12 files, 002783A0-00279CA0
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

/* merge_units: begin func_002797C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cDecalMan_AddProjectedDecal: cast 32 line-of-sight rays from a hit position along the manager's
   spray directions, collect the distinct models they strike (and the mean hit point), then
   place a blood decal record on each struck model. */
/* quadword copy (lq/sq): a 128-bit move C cannot express */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V_002797C0 { float x, y, z, w; V_002797C0() {} V_002797C0(const V_002797C0& o) { V_002797C0* d = this; Q16(d, &o); } V_002797C0& operator=(const V_002797C0& o) { V_002797C0* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void ScaleV(V_002797C0* r, const V_002797C0* v, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(v), "f"(k) : "memory"); }
static inline V_002797C0 Scale(const V_002797C0& v, float k) { V_002797C0 r; ScaleV(&r, &v, k); return r; }
static inline void AddV(V_002797C0* d, V_002797C0* a, V_002797C0* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void Normalize_002797C0(V_002797C0* v) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory"); }

struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Info_7C0 { int first; };
struct Owner_7C0 { char pad0[0x68]; Info_7C0* info; };
struct Obj_7C0 {
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual Owner_7C0* ModelOwner();
    char pad4[0x45];
    signed char kind;       /* 0x49 */
    unsigned char Kind() const { unsigned char k = kind; return k; }
    char pad4A[0x1A];
    Owner_7C0* owner;       /* 0x64 */
};
struct HitSub { VP v[3]; V_002797C0 pos; unsigned char b40; char pad41; unsigned char b42; char pad43[0x1D]; int i60; Obj_7C0** obj; char pad68[0x18];
    /* empty walk over v[] mirrors the retail V[3] array-ctor loop on the materialized sub-object pointer */
    HitSub* Init() { HitSub* t = this; VP* q = t->v; do { q++; } while (q != t->v + 3); t->b40 = 0; t->b42 = 0; t->i60 = 0; t->obj = 0; return t; } };
struct HitInfo { unsigned char hit; char pad1[0x1F]; HitSub s; HitInfo* Init() { HitInfo* t = this; t->s.Init(); return t; } } __attribute__((aligned(16)));
struct Rec_7C0 { char pad0[0x5C]; float f5C; };
struct DecalMgr_7C0 {
    int pad0;
    Rec_7C0** recs;         /* 0x4 */
    int pad8;
    int cap;                /* 0xC */
    int pad10;
    int count;              /* 0x14 */
    int pad18;
    unsigned int head;      /* 0x1C */
    int pad20;
    unsigned int base;      /* 0x24 */
    char pad28[8];
    V_002797C0 dirs[32];             /* 0x30 */
};
struct Svc_7C0 { VPAD1(a) virtual void Post(void*); };

extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc_7C0* cSystemContainer_GetSystem(void*, void*);
#if 0 /* merge_units */
Rec_7C0* DecalMgr_AddBloodRecord(Rec_7C0* r, int flags, V_002797C0* pos, V_002797C0* dir, float f, float g, Obj_7C0* parent);
#endif /* merge_units */
struct Rec_7A370; /* merge_units */
struct V_0027A370; /* merge_units */
struct F4_7A370; /* merge_units */
struct Obj_7A570; /* merge_units */
Rec_7A370* DecalMgr_AddBloodRecord(Rec_7A370* r, int flags, V_0027A370* pos, F4_7A370* dir, float f, float g, Obj_7A570* parent); /* merge_units */
#define DecalMgr_AddBloodRecord(a0, a1, a2, a3, a4, a5, a6) ((Rec_7C0 *)DecalMgr_AddBloodRecord((Rec_7A370 *)(a0), (a1), (V_0027A370 *)(a2), (F4_7A370 *)(a3), (a4), (a5), (Obj_7A570 *)(a6))) /* merge_units */

void cDecalMan_AddProjectedDecal(DecalMgr_7C0* self, V_002797C0* pos, int seed, V_002797C0* normal, float size);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V_002797C0 pos; V_002797C0 dir; Obj_7C0* src; Obj_7C0* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V_002797C0& p, V_002797C0 d, Obj_7C0* s, Obj_7C0* t) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; a24 = 0; a28 = 0; info = i; V_002797C0* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; n = 4; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgRay() { vtable = D_004D9180; }
} __attribute__((aligned(16)));

static inline int HasInfo(Owner_7C0* p) { return p->info->first ? 1 : 0; }

void cDecalMan_AddProjectedDecal(DecalMgr_7C0* self, V_002797C0* pos, int seed, V_002797C0* normal, float size)
{
    Obj_7C0* list[32];
    V_002797C0 sum;
    HitInfo info;
    int hits = 0;
    int n = 0;
    int i;
    int i2;
    float k = 2.0f * size;
    sum.x = 0.0f;
    sum.y = 0.0f;
    sum.z = 0.0f;
    sum.w = 0.0f;
    for (i = 0; i < 32; i++) {
        Svc_7C0* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        info.Init();
        MsgRay m(&info, *pos, Scale(self->dirs[i], k), 0, 0);
        svc->Post(&m);
        if (info.hit) {
            Obj_7C0* o = *info.s.obj;
            bool found = 0;
            if (o->Kind() == 1) {
                found = 1;
            } else if (o->Kind() == 15) {
                if (o->owner && HasInfo(o->owner)) {
                    o = (Obj_7C0*)o->owner;
                    found = 1;
                }
            } else if (o->Kind() == 16) {
                if (o->ModelOwner() && HasInfo(o->ModelOwner())) {
                    o = (Obj_7C0*)o->ModelOwner();
                    found = 1;
                }
            }
            if (found) {
                int j;
                { HitSub* hs = &info.s; V_002797C0* pp = &hs->pos; AddV(&sum, &sum, pp); }
                for (j = 0; j < n; j++)
                    if (list[j] == o)
                        break;
                if (j == n)
                    list[n++] = o;
                hits++;
            }
        }
    }
    if (!normal) {
        sum.x = sum.x / (float)hits;
        sum.y = sum.y / (float)hits;
        sum.z = sum.z / (float)hits;
        sum.w = 0.0f;
        Normalize_002797C0(&sum);
    } else {
        sum = *normal;
    }
    for (i2 = 0; i2 < n; i2++) {
        Obj_7C0* o = list[i2];
        if (o) {
            unsigned int h = self->head++;
            unsigned int slot = (h + self->base) % self->cap;
            if (self->head == self->cap)
                self->head = 0;
            if (self->count < self->cap) {
                self->count++;
            } else {
                Rec_7C0* old = self->recs[slot];
                if (old->f5C != -2.0f)
                    old->f5C = 0;
            }
            {
                Rec_7C0* r = self->recs[h];
                if (r)
                    DecalMgr_AddBloodRecord(r, 10, pos, &sum, size, (float)seed, o);
            }
        }
    }
}
#undef DecalMgr_AddBloodRecord /* merge_units */
static inline void merge_flush_func_002797C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002797C0 */

/* merge_units: begin func_00279CA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x5C]; float t; } E279CA0;
typedef struct {
    E279CA0** items; int pad4; int cap; int padC; int count; int pad14;
    unsigned int head; int pad1C; int base;
} R279CA0;
extern void cDecal_ctor(E279CA0* e, int flags, int a, int b, float x, float y);
void cDecalMan_AddDecal(R279CA0* r, int a1, int a2, unsigned char a3, int t0, float f)
{
    unsigned int idx;
    unsigned int slot;
    E279CA0* e;
    int fl;
    idx = r->head++;
    slot = (idx + r->base) % r->cap;
    if (r->head == r->cap) {
        r->head = 0;
    }
    if (r->count < r->cap) {
        r->count++;
    } else {
        e = r->items[slot];
        if (e->t != -2.0f) {
            e->t = 0.0f;
        }
    }
    fl = a3 | 1;
    e = r->items[idx];
    if (e) {
        cDecal_ctor(e, fl, a1, t0, f, (float)a2);
    }
}
static inline void merge_flush_func_00279CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00279CA0 */

/* merge_units: begin func_00279D80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void operator_delete(void* p);
}
struct S_00279D80 { void** a; void** b; int na; int nb; };
static inline void Free_00279D80(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, "decals.cc", line); }
extern "C" S_00279D80* cDecalMan_dtor(S_00279D80* self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < self->na; i++) Free_00279D80(self->a[i], 0x87);
        { int j; for (j = 0; j < self->nb; j++) Free_00279D80(self->b[j], 0x89); }
        Free_00279D80(self->a, 0x8B);
        Free_00279D80(self->b, 0x8C);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00279D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00279D80 */

/* merge_units: begin func_0027A020 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Item_27A020 { int f0; char pad4[0x4C]; int f50; int f54; int f58; float f5C; };
struct Mgr_27A020 {
    Item_27A020** a; Item_27A020** b; int na; int nb; int f10; int f14; int f18; int f1C;
    int f20; int f24; char pad28[8]; char f30[1];
};
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void CreateSphereNormals(void* p, int n);
#endif /* merge_units */
#define CreateSphereNormals(a0, a1) (CreateSphereNormals((cVector *)(a0), (a1))) /* merge_units */

extern char D_004A9238[];
extern int D_00543798;
}
extern "C" Mgr_27A020* cDecalMan_ctor(Mgr_27A020* self, int na, int nb) {
    self->a = 0;
    self->b = 0;
    self->na = na;
    self->nb = nb;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    { Item_27A020** t; { int sz = self->na * 4; AllocGuard g; t = (Item_27A020**)cMemMan_Allocate(0, sz, D_004A9238, 0x74); } self->a = t; }
    { Item_27A020** t; { int sz = self->nb * 4; AllocGuard g; t = (Item_27A020**)cMemMan_Allocate(0, sz, D_004A9238, 0x75); } self->b = t; }
    {
        int i;
        for (i = 0; i < self->na; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)cMemMan_Allocate(0, 0x60, D_004A9238, 0x78); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->a[i] = p;
        }
    }
    {
        int i;
        for (i = 0; i < self->nb; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)cMemMan_Allocate(0, 0x60, D_004A9238, 0x7A); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->b[i] = p;
        }
    }
    self->f20 = (int)(0.1f * (float)self->na);
    self->f24 = (int)(0.1f * (float)self->nb);
    CreateSphereNormals(self->f30, 0x20);
    D_00543798 = self->nb;
    return self;
}
#undef CreateSphereNormals /* merge_units */
static inline void merge_flush_func_0027A020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A020 */

/* merge_units: begin func_0027A370 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* DecalMgr_AddBloodRecord: fill a blood decal record (position + direction), in the parent's local frame when attached */
struct M;
struct V_0027A370;
static inline void AddV_0027A370(V_0027A370* d, V_0027A370* a, V_0027A370* b);
static inline void AddV2(V_0027A370* d, V_0027A370* a, V_0027A370* b) { AddV_0027A370(d, a, b); }
static inline void AddV_0027A370(V_0027A370* d, V_0027A370* a, V_0027A370* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void ScaleV_0027A370(V_0027A370* rp, const V_0027A370* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V_0027A370 {
    float x, y, z, w;
    V_0027A370() {}
    V_0027A370(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V_0027A370(const V_0027A370& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V_0027A370& operator=(const V_0027A370& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0027A370 operator-(const V_0027A370& o) const { V_0027A370 r; V_0027A370* rp = &r; const V_0027A370* tp = this; const V_0027A370* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0027A370 operator+(V_0027A370 o) const { V_0027A370 r; const V_0027A370* tp = this; V_0027A370* rp = &r; const V_0027A370* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V_0027A370 operator*(float k) const { V_0027A370 r; ScaleV_0027A370(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0027A370& operator*=(float k) { V_0027A370* tp = this; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(tp), "f"(k) : "memory"); return *this; }
    V_0027A370& operator+=(V_0027A370 o) { AddV2(this, this, &o); return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0027A370 Sub3(const V_0027A370& o) const { V_0027A370 r; const V_0027A370* op = &o; const V_0027A370* tp = this; V_0027A370* rp = &r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    void Set(V_0027A370 o) { *this = o; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0027A370 Sub2(const V_0027A370& o) const { V_0027A370 r; const V_0027A370* op = &o; V_0027A370* rp = &r; const V_0027A370* tp = this; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // 128-bit lq/sq quadword copy idiom
    V_0027A370& Asg(const V_0027A370& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    inline V_0027A370& Xform(M* m);
} __attribute__((aligned(16)));

struct M {
    V_0027A370 r0, r1, r2, r3;
    M() {}
    // 128-bit lq/sq quadword copy idiom
    M& operator=(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    float* f() { return (float*)this; }
};

// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Apply(V_0027A370* o, M* m, V_0027A370* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode vector op (COP2), not expressible in C
inline V_0027A370& V_0027A370::Xform(M* m) { Apply(this, m, this); return *this; }
static inline void UM(void* p) { void* q = p; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(q) : "memory"); }
struct Node_7A570 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; M xform; unsigned char dirty;
};
struct Obj_7A570 { char pad[0x50]; Node_7A570* node; };
struct F4_7A370 { float x, y, z, w; void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; } };
struct Rec_7A370 { int flags; char pad4[0xC]; V_0027A370 r0; F4_7A370 r1; V_0027A370 r2; V_0027A370 r3; float f50; int x54; Obj_7A570* parent; float f5C; };
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, M* s);
M* cMatrix_InvertRotTrans(M* m);
Rec_7A370* DecalMgr_AddBloodRecord(Rec_7A370* r, int flags, V_0027A370* pos, F4_7A370* dir, float f, float g, Obj_7A570* parent);
}
static inline M* GetXform(Node_7A570* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline M* InvOf(M* out, Node_7A570* n) { M t; return cMatrix_ctor_cMatrixR(out, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, GetXform(n)))); }
static inline void Apply1(V_0027A370* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V_0027A370 XF(const V_0027A370& v, M* m) { V_0027A370 t = v; V_0027A370* p = &t; Apply1(p, m); return *p; }
/* XF2: pass-through layer for the second transform (register order of that call site) */
static inline V_0027A370 XF3(const V_0027A370& v, M* m) { V_0027A370 t = v; V_0027A370* p = &t; Apply1(p, m); return *p; }
static inline V_0027A370 XF2(const V_0027A370& v, M* m) { return XF3(v, m); }
/* pass-through layers: deeper inlines get lower stack slots */
static inline M* InvOf2(M* out, Node_7A570* n) { return InvOf(out, n); }
static inline M* InvOf3(M* out, Node_7A570* n) { return InvOf2(out, n); }
Rec_7A370* DecalMgr_AddBloodRecord(Rec_7A370* r, int flags, V_0027A370* pos, F4_7A370* dir, float f, float g, Obj_7A570* parent)
{
    r->flags = flags;
    r->f50 = f;
    r->x54 = (int)g;
    r->parent = parent;
    r->f5C = -1.0f;
    if ((r->flags & 2) && r->parent) {
        Node_7A570* n = r->parent->node;
        if (n) {
            M inv;
            InvOf3(&inv, n);
            V_0027A370 lp = XF(*pos, &inv);
            V_0027A370 ld = XF2(*(V_0027A370*)dir, &inv);
            UM(&r->r0);
            r->r3 = lp;
            r->r1.Set(ld.x, ld.y, ld.z, ld.w);
        } else {
            UM(&r->r0);
            r->r3 = *pos;
            r->r1.Set(dir->x, dir->y, dir->z, dir->w);
        }
    }
    return r;
}
static inline void merge_flush_func_0027A370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A370 */
