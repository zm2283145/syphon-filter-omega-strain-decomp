/*
 * SFOGame/Source/grenade: 1 file, 0025AD80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025AD80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "sound_event.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct M;
struct V;
static inline void AddV(V* d, V* a, V* b);
static inline void AddV2(V* d, V* a, V* b) { AddV(d, a, b); }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator+(V o) const { V r; const V* tp = this; V* rp = &r; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V& operator*=(float k) { V* tp = this; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(tp), "f"(k) : "memory"); return *this; }
    V& operator+=(V o) { AddV2(this, this, &o); return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V Sub3(const V& o) const { V r; const V* op = &o; const V* tp = this; V* rp = &r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    void Set(V o) { *this = o; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V Sub2(const V& o) const { V r; const V* op = &o; V* rp = &r; const V* tp = this; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // 128-bit lq/sq quadword copy idiom
    V& Asg(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    inline V& Xform(M* m);
} __attribute__((aligned(16)));

struct M {
    V r0, r1, r2, r3;
    M() {}
    M(V* a, V* b, V* c, const V& d);
    // 128-bit lq/sq quadword copy idiom
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    float* f() { return (float*)this; }
};

// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
inline V& V::Xform(M* m) { Apply(this, m, this); return *this; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void MMulH(M* rp, M* ap, M* bp) { __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); }
static inline M MMul(M& a, M& b) { M r; M* rp = &r; M* bp = &b; M* ap = &a; MMulH(rp, ap, bp); return r; }
static inline M Transpose(M a) { float* p = a.f(); float t; t = p[1]; p[1] = p[4]; p[4] = t; t = p[2]; p[2] = p[8]; p[8] = t; t = p[6]; p[6] = p[9]; p[9] = t; return *(M*)p; }
static inline M& TransposeR(M a) { float* p = a.f(); float t; t = p[1]; p[1] = p[4]; p[4] = t; t = p[2]; p[2] = p[8]; p[8] = t; t = p[6]; p[6] = p[9]; p[9] = t; return *(M*)p; }
// Out-param form: the transposed copy happens in TransposeW (fixes register colours) with no dead ref-result address.
static inline void TransposeO(M a, const M*& out) { float* p = a.f(); float t; t = p[1]; p[1] = p[4]; p[4] = t; t = p[2]; p[2] = p[8]; p[8] = t; t = p[6]; p[6] = p[9]; p[9] = t; out = (M*)p; }
static inline M TransposeW(M& a) { const M* r; TransposeO(a, r); return *r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V Cross(const V& a, const V& b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V& Unit(V& v) { V* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// abs.s: no C equivalent for this float abs form
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Ident(M* m) { M* p = m; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

struct Obj;
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void Hit(Obj* src, int one, signed char kind, int a, int b, int c, float dmg);
    char pad4[8];
    int serial;
};
struct H { Obj* p; int serial; };
static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(H* h) { return !h->p || IEq(h->p->serial, h->serial); }
static inline Obj* HGet(H* h) { return HValid(h) ? h->p : 0; }

struct Type {
    char pad0[0x10];
    char name[0x10];
    char snd[0x10];
    unsigned char b30;
    char pad31[3];
    int t34; int t38; int t3C;
    char pad40[0x24];
    int d64; int d68; int d6C;
    char pad70[0xBC - 0x70];
    unsigned char kind;
    char padBD[0xC4 - 0xBD];
    float rC4; float rC8;
    char padCC[0xD4 - 0xCC];
    unsigned char bD4;
    char padD5[3];
    int fxD8;
    char padDC[0xF0 - 0xDC];
    unsigned char cls;
    char padF1[0xFC - 0xF1];
    float noise;
    int DamageAt(float t)
    {
        int d = d68;
        if (t > (float)t34) {
            float c, b, a;
            if (t > (float)t38) { c = (float)(d6C - d64); b = (float)(t3C - t38); a = t - (float)t38; }
            else if (t > (float)t34) { c = (float)(d64 - d68); b = (float)(t38 - t34); a = t - (float)t34; }
            d = (int)((float)d + c * a / b);
        }
        return d;
    }
};

struct XNode {
    VPAD1(a)
    virtual void SetMatrix(M m);
    VPAD16(b) VPAD2(c)
    virtual void Update();
    char pad4[0xC];
    M m;
    unsigned char b50;
    const M& Mtx() { if (b50) Update(); return m; }
    const V& Pos() { if (b50) Update(); return m.r3; }
};

struct Projectile {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    char pad4[8];
    int serial;
    char pad10[0x40];
    XNode* XNode;
    char pad54[0x10];
    float invMass;
    char pad68[8];
    V pos;
    V prev;
    V vel;
    V accel;
    V force;
    char padC0[0x20];
    float fuse;
    unsigned char retired;
    unsigned char rest;
    unsigned char first;
    char padE7;
    unsigned char stuck;
    char padE9[7];
    V launch;
    float prevdt;
    float age;
    char pad108[8];
    float sx, sy, sz;
    char pad11C[4];
    Type* rec;
    H owner;
    V Move() { return pos - prev; }
};

struct Query {
    Obj* owner;
    M* mtx;
    Obj* other;
    unsigned char b5C, b5D;
    int id;
    float step;
    Type* type;
    float age;
    unsigned char b70;
    int n74;
    float f78;
    unsigned char b7C, b7D;
    int hit;
    float dist;
    char pad38[0x18];
    Query() { id = -1; b70 = 0; age = 0.0f; b7C = 1; b7D = 1; b5C = 0; other = 0; n74 = 0; }
};

struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    H* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; VP* e = q->arr + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
};

struct Svc { VPAD1(a) virtual void Post(void* m); };

extern "C" {
extern float g_ThrowGravity;
extern V g_GameGravity;
extern float D_0048AF98;
extern float D_0048AF30;
extern float D_0048AF88;
extern float D_0048AF28;
extern float D_0048AF50;
extern float D_0048AF48;
extern float D_0048AF58;
extern float D_0048AF20;
extern float D_0048AFA0;
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
extern char g_Game[];
extern char g_LosCheckService[];
extern char D_004EE5C0[];
extern char D_004D92A0[];
extern char D_004DAE30[];
extern char D_004A7C88[];
extern char D_004A7C98[];
extern char D_004A7CA8[];
extern void* g_DecalMgr;
void cVector_opSub(V* o, V* a, V* b);
void cVector_opMul(V* o, V* a, float k);
void cVector_opAdd(V* o, V* a, V* b);
void cVector_opAssign(V* d, V* s);
void cVector_WSet1(V* v);
void cVector_ctor_cVectorR(V* d, V* s);
Svc* cSystemContainer_GetSystem(void* a, void* b);
void nGobjManager_RemoveGOBJ(Projectile* p);
void cSystem_ActualScheduleDelete(Projectile* p, float t);
void cVector_Cross(V* o, V* a, const V& b);
int cVector_IsZeroXYZ(V* v);
void cVector_GetNormalized_void(V* o, V* i);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, const V& t);
inline M::M(V* a, V* b, V* c, const V& d) { M* t = this; V* pb = b; V* pc = c; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(t, a, pb, pc, d); }
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* a);
void cMatrix_SetUnit(M* m);
void CheckBulletCollisions(Query* q);
void cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(void* msg, int* sender, int action, float a, float b);
void cAISoundSystemGOBJPositionMessage_ctor(void* msg, float a, float b, int* id, V* pos, signed char kind);
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(M* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
void Blast_Prepare(Obj* obj, int dmg, float fdmg, float r0, float r1, unsigned char flag, V* at, unsigned char skipHumans, int quiet);
void SfxLightEffect(M* m, float a, float b);
int* nSfxLoader_GetHandle(int id);
void cDecalMan_AddProjectedDecal(void* r, V* p, int id, int z, float f);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cAreaEffect_ctor(void* self, Obj* o, V pos, Type* t, int f);
void SfxParticleEffect_int_cMatrixR(int id, M* m);
}

struct AiMsg {
    void* vt; char d[0x4C];
    AiMsg(float a, float b, int* id, V* pos, signed char k) { cAISoundSystemGOBJPositionMessage_ctor(this, a, b, id, pos, k); }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AiMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); }
};

struct FireMsg {
    void* vt; char d[0x34];
    FireMsg(int* id, int act, float a, float b) { int* i = id; cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(this, i, act, a, b); }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FireMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); }
};

struct LosMsg {
    CMSG_HEADER;
    int x24;
    int x28;
    LosRes* res;
    V from;
    V dir;
    Projectile* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V& f, const V& d, Projectile* o)
    {
        LosMsg* m = this;
        const V* fp = &f;
        cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = *fp;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = 0x10;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
};

struct AreaEffect {
    char d[0xE0];
    AreaEffect(Obj* o, V p, Type* t, int f) { cAreaEffect_ctor(this, o, p, t, f); }
    static void* operator new(unsigned int sz, int line)
    {
        void* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, sz, D_004A7C88, line);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        return p;
    }
};

static inline void Integrate3(Projectile* s, float ratio, float dt2, float inv)
{
    V nx; V ov; V t3; V t2; V t1; V t4; V v2; V v1; V a2; V a1;
    cVector_opSub(&t1, &s->pos, &s->prev);
    cVector_opMul(&t2, &t1, ratio);
    cVector_opAdd(&t3, &s->pos, &t2);
    cVector_opMul(&t4, &s->force, s->invMass * dt2);
    cVector_opAdd(&nx, &t3, &t4);
    cVector_opAssign(&s->prev, &s->pos);
    cVector_opAssign(&s->pos, &nx);
    cVector_WSet1(&s->pos);
    cVector_ctor_cVectorR(&ov, &s->vel);
    cVector_opSub(&v1, &s->pos, &s->prev);
    cVector_opMul(&v2, &v1, inv);
    cVector_opAssign(&s->vel, &v2);
    cVector_opSub(&a1, &s->vel, &ov);
    cVector_opMul(&a2, &a1, inv);
    cVector_opAssign(&s->accel, &a2);
}

static inline void BuildFrame3(M* m, V* d, const V& z)
{
    V side; V fwd; V a; V up; V t;
    { const V* pz = &z; cVector_Cross(&side, d, *pz); }
    if (!cVector_IsZeroXYZ(&side)) {
        cVector_GetNormalized_void(&fwd, d);
        cVector_ctor_cVectorR(&a, cVector_Normalize_void(&side));
        cVector_Cross(&up, &a, fwd);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &a, &fwd, &up, *cVector_ctor_float_float_float_float(&t, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(d)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, d);
    } else {
        cMatrix_SetUnit(m);
    }
}

static inline void Integrate2(Projectile* s, float ratio, float dt2, float inv) { Integrate3(s, ratio, dt2, inv); }
static inline void Integrate(Projectile* s, float ratio, float dt2, float inv) { Integrate2(s, ratio, dt2, inv); }
static inline void BuildFrame2(M* m, V* d, const V& z) { BuildFrame3(m, d, z); }
static inline void BuildFrame(M* m, V* d, const V& z) { BuildFrame2(m, d, z); }
// The unused this-copy keeps the dead addiu of the temp address that retail has at 0xA50.
struct VQ : V { VQ(float a, float b, float c, float d) : V(a, b, c, d) { V* p = this; (void)p; } };
// 128-bit sq zero store (quadword clear), not expressible in C
static inline void QZero(V* p) { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void ReqKill(SoundRequest* r) { cFileMan_dtor(&r->b, -1); cFileMan_dtor(&r->a, -1); SoundRequest* p = r; (void)p; }

extern "C" void cGrenade_NextFrame(Projectile* s, float dt)
{
    V pad;
    if (s->retired) return;
    if (0) pad = s->vel;
    V move;
    V impact;
    bool det = false;
    bool sticky;
    bool hit;
    sticky = s->rec->bD4 == 2;
    s->age += dt;
    hit = false;
    if (!s->rest) {
        if (s->rec->cls == 7) g_ThrowGravity += D_0048AF98;
        if (s->first) {
            s->launch *= dt;
            s->prev.Set(s->pos.Sub3(s->launch));
            s->force += g_GameGravity * D_0048AF30;
            s->prevdt = dt;
            s->first = 0;
        }
        float inv;
        float ratio;
        float dt2 = dt * dt;
        inv = 1.0f / dt;
        ratio = dt / s->prevdt;
        s->prevdt = dt;
        Integrate(s, ratio, dt2, inv);
        V D = s->Move();
        move = D;
        if (s->rec->cls == 7) g_ThrowGravity -= D_0048AF98;
        if (s->prev.z < D_0048AF88) {
            nGobjManager_RemoveGOBJ(s);
            cSystem_ActualScheduleDelete(s, D_0048AF28);
            s->retired = 1;
            return;
        }
        LosRes res;
        LosMsg msg(&res, s->prev, D, s);
        cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&msg);
        hit = res.hit;
        if (hit) {
            s->stuck = 0;
            impact.Asg(res.pt);
            if (s->rec->cls == 7) {
                Obj* tgt = res.h.x64->p;
                Obj* src = HGet(&s->owner);
                int dmg = s->rec->DamageAt(0.0f);
                tgt->Hit(src, 1, s->rec->kind, 0, 0, 0, (float)dmg);
            }
            float k = D_0048AF50;
            k *= k;
            if (LenSq(&D) < k) s->rest = 1;
        } else if (!s->stuck) {
            Query q;
            M frame;
            BuildFrame(&frame, &D, V(0.0f, 0.0f, 1.0f, 1.0f));
            frame.r3.Asg(s->prev);
            q.owner = HGet(&s->owner);
            q.mtx = &frame;
            q.step = Len(&D);
            q.type = s->rec;
            q.b70 = s->rec->cls != 7;
            q.f78 = 0.4f;
            CheckBulletCollisions(&q);
            if (q.hit) {
                if (s->rec->cls == 7) s->retired = 1;
                hit = true;
                s->stuck = 1;
                s->prev = s->pos;
                QZero(&s->vel);
                impact = V(0.0f, q.dist, 0.0f, 1.0f).Xform(&frame);
            }
        }
        if (hit && sticky) {
            det = true;
        } else {
            if (hit) {
                V P0 = s->prev;
                s->pos.Set(P0);
                if (!s->stuck) {
                    V h(0.0f, 0.0f, 1.0f, 1.0f);
                    V n = res.h.normal;
                    if (!(Abs(n.z) <= 0.5f)) { h.x = 1.0f; h.z = 0.0f; }
                    V u = Cross(n, h);
                    u = Unit(u);
                    V v = Cross(n, u);
                    v = Unit(v);
                    V w = Cross(u, v);
                    w = Unit(w);
                    M m(&u, &v, &w, VQ(0.0f, 0.0f, 0.0f, 1.0f));
                    M mt = TransposeW(m);
                    D.Xform(&mt);
                    D.z = -D.z * D_0048AF48;
                    D.x = D.x * D_0048AF58;
                    D.y = D.y * D_0048AF58;
                    D.Xform(&m);
                    s->prev.Set(P0 - D);
                    Integrate(s, ratio, dt2, inv);
                    if (s->age > 0.5f) {
                        Svc* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
                        FireMsg(&s->serial, 5, 1.0f, 15.0f).Send(svc);
                        SoundRequest req;
                        SoundEventP ev;
                        cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, s->rec->snd, 0, 0);
                        cPlaySoundMsg_ctor_cSndFxR(&ev, &req, s);
                        ev.kind = 1;
                        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
                        s->age = 0.0f;
                        ev.vtable = D_004DAE30;
                        cFileMan_dtor(&ev.req.b, -1);
                        cFileMan_dtor(&ev.req.a, -1);
                        cMessage_dtor(&ev, 0);
                        ReqKill(&req);

                    }
                }
            }
            XNode* XNode = s->XNode;
            M nm = XNode->Mtx();
            nm.r3 = s->pos;
            V ang;
            ang.x = s->sx;
            ang.y = s->sy;
            ang.z = s->sz;
            ang.x *= dt;
            ang.y *= dt;
            ang.z *= dt;
            M r;
            {
                float ay = ang.y; float ax = ang.x; float az = ang.z;
                float cy = COS(ay); float sy = SIN(ay);
                float cx = COS(ax); float sx = SIN(ax);
                float cz = COS(az); float sz = SIN(az);
                float czcy = cz * cy; float czsy = cz * sy; float szcy = sz * cy; float szsy = sz * sy;
                cMatrix_Set_ColumnMajorForm(&r, czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                                  szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                                  -cx * sy, sx, cx * cy);
            }
            struct XNode* xn = s->XNode;
            xn->SetMatrix(MMul(nm, r));
        }
        msg.vtable = D_004D9180;
        cMessage_dtor(&msg, 0);
    }
    if (!sticky) {
        s->fuse -= dt;
        det = s->fuse <= 0.0f;
    }
    if (det) {
        M ident;
        Ident(&ident);
        XNode* XNode = s->XNode;
        if (XNode) ident.r3 = XNode->Pos();
        else ident.r3 = s->GetPos();
        unsigned char kind = s->rec->kind;
        if (kind == 2 || kind == 4 || kind == 13) {
            int r8 = (int)s->rec->rC8;
            int r4 = (int)s->rec->rC4;
            if (s->rec->kind == 4) { r8 /= 2; r4 /= 2; }
            V b = ident.r3;
            Blast_Prepare(HGet(&s->owner), s->rec->d64, D_0048AF20, (float)r4, (float)r8, 1, &b, 0, 1);
            SfxLightEffect(&ident, 10.0f, 0.5f);
            int id = *nSfxLoader_GetHandle(0x25);
            if (id > -1) {
                int z = 0;
                float dist = Len(&move);
                V d = impact.Sub2(s->prev);
                V p = s->prev + d * 0.9f;
                cDecalMan_AddProjectedDecal(g_DecalMgr, &p, id, z, D_0048AFA0);
            }
        }
        if (HGet(&s->owner)) {
            Svc* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
            int* id = &HGet(&s->owner)->serial;
            float one = 1.0f;
            AiMsg(one, s->rec->noise, id, &ident.r3, 4).Send(svc);
        }
        switch (s->rec->kind - 3) {
        case 0:
            { AreaEffect* ae = (AreaEffect*)AreaEffect::operator new(0xE0, 0x1F6); if (ae) cAreaEffect_ctor(ae, HGet(&s->owner), ident.r3, s->rec, 1); }
            break;
        case 1: case 2: case 3: case 4: case 5:
            if (hit) {
                V d = impact.Sub2(s->prev);
                V p = s->prev + d * 0.9f;
                { AreaEffect* ae = (AreaEffect*)AreaEffect::operator new(0xE0, 0x202); if (ae) cAreaEffect_ctor(ae, HGet(&s->owner), p, s->rec, 0); }
            } else {
                { AreaEffect* ae = (AreaEffect*)AreaEffect::operator new(0xE0, 0x205); if (ae) cAreaEffect_ctor(ae, HGet(&s->owner), ident.r3, s->rec, 0); }
            }
            break;
        }
        if (s->rec->fxD8 != -1) SfxParticleEffect_int_cMatrixR(s->rec->fxD8, &ident);
        const char* name = D_004A7C98;
        if (s->rec->cls == 7) name = D_004A7CA8;
        else if (s->rec->b30 == 8) name = s->rec->name;
        SoundRequest req;
        SoundEventP ev;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, name, 0, 0);
        cPlaySoundMsg_ctor_cSndFxR(&ev, &req, s);
        ev.kind = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
        nGobjManager_RemoveGOBJ(s);
        cSystem_ActualScheduleDelete(s, D_0048AF28);
        s->retired = 1;
        ev.vtable = D_004DAE30;
        cFileMan_dtor(&ev.req.b, -1);
        cFileMan_dtor(&ev.req.a, -1);
        cMessage_dtor(&ev, 0);
        cFileMan_dtor(&req.b, -1);
        cFileMan_dtor(&req.a, -1);
    }
}
static inline void merge_flush_func_0025AD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AD80 */
