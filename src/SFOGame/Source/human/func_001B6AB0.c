/* cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP (0x001B6AB0), mw38/mw50 MATCH.
 * From c150lg's 13-diff draft. Fix: the three NormTo sites bind the source via a const V4& local,
 * the tail copy uses the QS asm helper, and the middle site (m.r[1]) copies out into a const local
 * before the final QS, which flips vreg colouring of r/t across sites 2-3. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma inline_depth(10)
#include "types.h"
#include "alloc_guard.h"
typedef int Q128 __attribute__((mode(TI)));
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct V : V4 {
    V() {}
    V& operator=(const V& o) { float fy, fz, fw, fx; fw = o.w; fz = o.z; fy = o.y; fx = o.x; w = fw; z = fz; y = fy; x = fx; return *this; }
    V(const V& o) { *(Q128*)this = *(const Q128*)&o; }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    float DotX(const V4& b) const {
        int t; float r = 0.0f; const V* pa = this; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(pa), "r"(&b) : "memory");
        return r;
    }
    float Dot(const V4& b) const {
        int t; float r = 0.0f; const V4* pb = &b; const V* pa = this;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(pa), "r"(pb) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline void NormP(V* p) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void QS(void* d0, const void* s0) { const void* s = s0; void* d = d0; Q128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline V Normalized(const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); return *p; }
static inline void NormTo(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_1(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_2(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); Q128 q = *(const Q128*)p; V* d = out; *(Q128*)d = q; }
static inline void NormTo_3(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); Q128 q; V* d = out; q = *(const Q128*)p; *(Q128*)d = q; }
static inline void NormTo_5(V* out, const V4& v) { V t; V* const p = &t; QS(p, &v); NormP(p); QS(out, p); }
static inline void NormTo_6(V* out, const V4& v) { V t; QS(&t, &v); V* p; p = &t; NormP(p); QS(out, p); }
static inline void NormTo_7(V* out, const V4& v) { V t; const V4* s = &v; QS(&t, s); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_8(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); V* const o = out; QS(o, p); }
static inline void NormTo_4(V* out, const V4& v) { V t; QS(&t, &v); NormP(&t); QS(out, &t); }
static inline void NormToP(V* out, const V4* v) { NormTo(out, *v); }
#define SITE(k,n) { V r; const V4& s = m.r[k]; NormTo_##n(&r, s); *(V*)&m.r[k] = r; }
static inline V Origin() { V r; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&r) : "memory"); return r; }
struct Mtx {
    V4 r[4];
    void Init() { r[0].w = 0.0f; r[1].w = 0.0f; r[2].w = 0.0f; r[3].w = 1.0f; }
};
inline void* operator new(unsigned int, void* p) { return p; }
struct Skl { Q128 q[0x44]; };
struct VecPair; struct V;
extern "C" void cVector_Get0001(V*);
extern "C" void cVector_ctor_cVectorR(void*, void*);
extern "C" void cQuatVec_GetUnit(VecPair*);
extern "C" void cQuatVec_ctor_cQuatVecR(void*, VecPair*);
struct VecPair { V a; V b; VecPair() { cQuatVec_GetUnit(this); } };
static inline void SetQ(V4* d0, const V& s0) { V* d = (V*)d0; const V* s = &s0; Q128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void OriginTo(V* d0) { V* d; V r; const V* s = &r; Q128 q; __asm__ volatile(".set noreorder; sqc2 $vf0, 0x0(%0); .set reorder" : : "r"(s) : "memory"); d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct VO : V { VO() { cVector_Get0001(this); } };
struct VA { char p[0x10]; void operator=(const V& o) { cVector_ctor_cVectorR(this, (void*)&o); } };
static inline void InitPair0(void* d) { VecPair b; cQuatVec_ctor_cQuatVecR(d, &b); }
static inline void InitOrg0(void* d) { VO o; cVector_ctor_cVectorR(d, &o); }
static inline void InitPair(void* d) { InitPair0(d); }
static inline void InitOrg(void* d) { InitOrg0(d); }
static inline void InitPair1(void* d) { InitPair(d); }
static inline void InitOrg1(void* d) { InitOrg(d); }
struct VPS { char p[0x20]; void operator=(const VecPair& o) { cQuatVec_ctor_cQuatVecR(this, (VecPair*)&o); } };
struct A60 {
    char p[0x40];
    Skl skl;
    void SetSkl(Skl* s0) {
        Skl* s = s0; A60* p = this; Skl* d; int n; Q128 t;
        asm {
            .set noreorder
            addiu n, zero, 0x44
            addiu d, p, 0x40
            nop
        lp:
            lq t, 0(s)
            addiu d, d, 0x10
            addi n, n, -1
            addiu s, s, 0x10
            bgtz n, lp
            sq t, -0x10(d)
            .set reorder
        }
    }
};
struct Reader { int version; int a, b; char* cur; };
struct HObj { int q[3]; int id; };
struct H { int v; H() : v(-1) {} };
struct VP {
    HObj* a; H b;
    VP() { Clear(); }
    void Set(HObj* o) { a = o; int d; b.v = *(o ? &o->id : (d = -1, &d)); }
    void Clear() { Set(0); }
};
struct Hd { HObj* hp; int hid; Hd() : hp(0), hid(-2) {} };
struct Plane {
    float x, y, z, d;
    void Set(const V4& n, const V& p) { float dd = ((const V&)n).DotX(p); float nx, ny, nz; nz = n.z; ny = n.y; nx = n.x; x = nx; y = ny; z = nz; d = -dd; }
};

extern "C" {
extern char g_HumanActorClassKey[];
extern char D_0049D8D0[];
extern int g_NoneWord;
extern char D_004DA2F0[];
extern char D_004DA690[];
extern char D_004DA7A8[];
extern char D_004DA7B8[];
extern int g_ActorSerialCounter;
extern void* D_004FFBE0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
void cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(void*, int*, void*);
void cStatesWithHistory_1_ctor(void*);
void* cVector_GetZero(void);
void cVector_ctor_cVectorR(void*, void*);
void cSplinedMotion_Angle_ctor(void*);
void cHumanMotionParams_cTargetZRotationStack_ctor(void*);
void cSplinedMotion_Vector_ctor(void*);
int cHumanMotionParams_PushTargetZRotationOnStack(void*, float, float);
void cSplinedMotion_float_SetDamp(void*, float);
void cSplinedMotion_cVector_SetDamp(void*, float);
void cBitArray_8_ctor(void*, int);
void func_001B75B0(void*, int);
void func_001B7580(void*, int);
void cCollisionModelList_ctor(void*, int*, int*);
void cActivationTracker_ctor(void*);
void cCheckpoint_ctor(void*);
void cQuatVec_GetUnit(VecPair*);
void cQuatVec_ctor_cQuatVecR(void*, VecPair*);

void* cMemMan_Allocate(int, int, char*, int);
void* cWeapon_ctor(void*, void*, int);
void NetGetMyClientIndex(int*, int);
int* std_vector_cNodePtr_opIndex(void*, int);
V cNode_GetLoc(int);
}

struct S3030 {
    char p0[0xC];
    unsigned char bC;
    char pD[0x10 - 0xD];
    char x10[0x10];
    char x20[0x38];
    char x58[0x10];
    int x68;
    int x6C;
    int x70;
    float x74;
    int x78;
    unsigned char b7C;
    unsigned char b7D;
    char p7E[0x80 - 0x7E];
    char x80[0x10];
    int x90;
    char p94[0xA0 - 0x94];
    char xA0[0x10];
    int xB0;
    char pB4[0xC0 - 0xB4];
    char xC0[0xC0];
    unsigned char b180[8];
    char p188[0x190 - 0x188];
    char x190[0x10];
    int x1A0;
    int x1A4;
    int x1A8;
    unsigned char b1AC;
    unsigned char b1AD;
    char p1AE[0x1B0 - 0x1AE];
    int x1B0;
    void Init();
};
inline void S3030::Init()
{
    S3030* s = this;
    cStatesWithHistory_1_ctor(s);
    s->bC = 1;
    cVector_ctor_cVectorR(s->x10, cVector_GetZero());
    cSplinedMotion_Angle_ctor(s->x20);
    cHumanMotionParams_cTargetZRotationStack_ctor(s->x58);
    s->x6C = 0;
    s->x70 = 0;
    s->x74 = -3.4028235e38f;
    s->x78 = 0;
    s->b7C = 0;
    s->b7D = 0;
    cVector_ctor_cVectorR(s->x80, cVector_GetZero());
    s->x90 = 0;
    cVector_ctor_cVectorR(s->xA0, cVector_GetZero());
    s->xB0 = 0;
    cSplinedMotion_Vector_ctor(s->xC0);
    s->b180[0] = 0;
    s->b180[1] = 0;
    s->b180[2] = 0;
    s->b180[3] = 0;
    s->b180[4] = 0;
    s->b180[5] = 0;
    s->b180[6] = 0;
    s->b180[7] = 0;
    cVector_ctor_cVectorR(s->x190, cVector_GetZero());
    s->x1A0 = 0;
    s->x1A4 = 0;
    s->x1A8 = 0;
    s->b1AC = 1;
    s->b1AD = 0;
    s->x1B0 = 0;
    s->x68 = cHumanMotionParams_PushTargetZRotationOnStack(s, 0.0f, -1.0f);
    cSplinedMotion_float_SetDamp(s->x20, 15.0f);
    cSplinedMotion_cVector_SetDamp(s->xC0, 10.0f);
}
struct S3200 { int e[3]; };
struct S320C { char a[3][0x14]; char b[3][8]; };
struct S32A0 {
    void* vt;
    char p4[0x20 - 4];
    int x20;
    char p24[0x30 - 0x24];
    char x30[0x10];
    char x40[0x20];
    int x60;
};
struct S3530 {
    void* vt;
    int x4;
    char p8;
    unsigned char b9;
    unsigned char bA;
    char pB;
    int xC;
    float x10;
    int x14;
};

struct Act {
    void* vt;
    char p4[0xC - 4];
    int wC;
    char p10[0x30 - 0x10];
    int x30;
    char p34[0x60 - 0x34];
    A60 x60;
    char p4E0[0x3030 - 0x4E0];
    S3030 x3030;
    char p31E4[0x31F0 - 0x31E4];
    int x31F0;
    float x31F4;
    float x31F8;
    unsigned char b31FC;
    char p31FD[0x3200 - 0x31FD];
    S3200 x3200;
    S320C x320C;
    unsigned char b3260;
    char p3261[0x3268 - 0x3261];
    unsigned char b3268;
    unsigned char b3269;
    unsigned char b326A;
    char p326B[0x32A0 - 0x326B];
    S32A0 x32A0;
    char p3304[0x3310 - 0x3304];
    int x3310;
    int x3314;
    char p3318[0x33A0 - 0x3318];
    int x33A0;
    unsigned char b33A4;
    unsigned char b33A5;
    char p33A6[0x33A8 - 0x33A6];
    int x33A8;
    int x33AC;
    int x33B0;
    int x33B4;
    char p33B8[0x33CC - 0x33B8];
    int x33CC;
    int x33D0;
    int x33D4;
    int x33D8;
    int x33DC;
    int x33E0;
    unsigned char b33E4;
    unsigned char b33E5;
    unsigned char b33E6;
    char p33E7;
    unsigned char b33E8;
    char p33E9[0x33F0 - 0x33E9];
    char x33F0[0x3464 - 0x33F0];
    int x3464;
    unsigned char b3468;
    char p3469[0x3474 - 0x3469];
    int x3474;
    VP h3478;
    Hd h3480;
    char p3488[0x3490 - 0x3488];
    unsigned char b3490;
    char p3491[0x34A0 - 0x3491];
    char x34A0[0x20];
    char x34C0[0x10];
    char x34D0[0x10];
    char p34E0[0x3514 - 0x34E0];
    int x3514;
    signed char b3518;
    char p3519[0x351C - 0x3519];
    int x351C;
    int x3520;
    void* x3524;
    char p3528[0x3530 - 0x3528];
    S3530 x3530;
    int x3548;
    Hd h354C[3];
    char p3564[0x3570 - 0x3564];
    Plane pl;
    int x3580;
    int x3584;
    char p3588[0x3594 - 0x3588];
    int x3594;
    bool b3598;
};

extern "C" bool cHuman_InitHuman(Act* a, Mtx* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label);

static inline void* Alloc(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_0049D8D0, line);
}
static inline int LocalId()
{
    int a = D_005721A8;
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return r;
}
static inline int RdI(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void RdF(Reader* r, float* o) { *o = *(float*)r->cur; r->cur += 4; }
static inline void RdI2(Reader* r, int* o) { *o = *(int*)r->cur; r->cur += 4; }
static inline void RdV(Reader* r, V4* v0) { V4* v = v0; RdF(r, &v->x); RdF(r, &v->y); RdF(r, &v->z); }
static inline char* RdS(Reader* r)
{
    char* s = r->cur;
    while (*r->cur++) {}
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}

extern "C" Act* cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(Act* a, Reader* rd, unsigned char type, Skl* src, int flag)
{
    volatile int nid1;
    volatile int nid2;
    int weap[2];
    Mtx m;
    V o;
    {
        int id = -1;
        cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(a, &id, g_HumanActorClassKey);
    }
    a->x3030.Init();
    a->vt = D_004DA690;
    a->x31F0 = -1;
    a->x31F4 = -1.0f;
    a->x31F8 = 36.69f;
    a->b31FC = 0;
    {
        S3200* p = &a->x3200;
        cBitArray_8_ctor(&p->e[0], 0);
        cBitArray_8_ctor(&p->e[1], 0);
        cBitArray_8_ctor(&p->e[2], 0);
    }
    {
        S320C* p = &a->x320C;
        func_001B75B0(p->a[0], 0);
        func_001B75B0(p->a[1], 0);
        func_001B75B0(p->a[2], 0);
        func_001B7580(p->b[0], 0);
        func_001B7580(p->b[1], 0);
        func_001B7580(p->b[2], 0);
    }
    a->b3260 = 0;
    a->b3268 = 0;
    a->b3269 = 0;
    a->b326A = 0;
    {
        S32A0* p = &a->x32A0;
        int z1, z0; z0 = 0; z1 = 0;
        cCollisionModelList_ctor(p, &z1, &z0);
        p->vt = D_004DA2F0;
        p->x20 = 0;
        cVector_ctor_cVectorR(p->x30, cVector_GetZero());
        cActivationTracker_ctor(p->x40);
        p->x60 = 0;
    }
    a->x3310 = 0;
    a->x3314 = 0;
    a->x33A0 = 0;
    a->b33A4 = 0;
    a->b33A5 = 0;
    a->x33A8 = 0;
    a->x33AC = 0;
    a->x33B0 = 0;
    a->x33B4 = 0;
    a->x33CC = g_NoneWord;
    a->x33D0 = 0;
    a->x33D4 = 0;
    a->x33D8 = 0;
    a->x33DC = 0;
    a->x33E0 = 0;
    a->b33E4 = 0;
    a->b33E5 = 0;
    a->b33E6 = 0;
    a->b33E8 = 0;
    cCheckpoint_ctor(a->x33F0);
    a->x3464 = 0;
    a->b3468 = 0;
    a->x3474 = 0;
    a->h3478.b.v = -1;
    a->h3478.Clear();
    a->h3480.hid = -2;
    a->h3480.hp = 0;
    a->b3490 = 0;
    {
        InitPair1(a->x34A0);
    }
    InitOrg1(a->x34C0);
    cVector_ctor_cVectorR(a->x34D0, cVector_GetZero());
    a->x3514 = -1;
    a->b3518 = -1;
    a->x351C = 0;
    a->x3520 = 0;
    {
        S3530* p = &a->x3530;
        p->vt = D_004DA7B8;
        p->vt = D_004DA7A8;
        p->x4 = 0;
        p->b9 = 0;
        p->bA = 0;
        p->xC = 0;
        p->x10 = 1.0f;
        p->x14 = 0;
    }
    {
        Hd* h;
        h = a->h354C;
        do { h->hid = -2; h->hp = 0; h++; } while (h != a->h354C + 3);
    }
    {
        V4 n;
        n.x = 0.0f; n.y = 0.0f; n.z = 1.0f; n.w = 0.0f;
        OriginTo(&o);
        a->pl.Set(n, o);
    }
    a->x3580 = 0;
    a->x3584 = 0;
    a->x3594 = 0;
    a->b3598 = flag ? true : false;
    {
        void* w = Alloc(0xF8, 0x267);
        if (w) { int h = type == 1; if (!h) h = type == 3; w = cWeapon_ctor(w, a, h); }
        a->x3524 = w;
    }
    a->x3530.x4 = (int)a->x3524;
    if (type == 2 || type == 4) {
        a->x31F0 = g_ActorSerialCounter;
        g_ActorSerialCounter++;
    }
    m.Init();
    int hi = RdI(rd);
    int lo = RdI(rd);
    if (!g_IsMultiplayer) {
        nid1 = lo | (hi << 16);
        a->wC = nid1;
    } else {
        int slot = (type == 1) ? LocalId() : -1;
        if (type == 1) {
            if (slot < 0 || slot >= 4) slot = 0;
        }
        nid2 = lo | (((slot + 1) << 24) | (hi << 16));
        a->wC = nid2;
    }
    char* name = RdS(rd);
    if (src) {
        a->x60.SetSkl(src);
        name = 0;
    }
    char* label = 0;
    if (rd->version >= 0x3C) label = RdS(rd);
    int health = RdI(rd);
    int maxh = RdI(rd);
    {
        V4* v;
        v = &m.r[3]; RdV(rd, v);
        v = &m.r[0]; RdV(rd, v);
        v = &m.r[1]; RdV(rd, v);
        v = &m.r[2]; RdV(rd, v);
    }
    SITE(0, 1)
    SITE(1, 8)
    SITE(2, 1)
    {
        int i;
        for (i = 0; i < 2; i++) RdI2(rd, &weap[i]);
    }
    if (rd->version >= 0x34) {
        RdI2(rd, &a->x3548);
        if (a->x3548 >= 0) {
            SetQ(&m.r[3], cNode_GetLoc(*std_vector_cNodePtr_opIndex(D_004FFBE0, a->x3548)));
        }
    } else {
        a->x3548 = -1;
    }
    cHuman_InitHuman(a, &m, name, health, maxh, weap, flag, type, label);
    a->x30 = 1;
    return a;
}
