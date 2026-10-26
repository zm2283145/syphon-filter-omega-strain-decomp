#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct V;

extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern char D_00504030[];
extern float D_0048B348;

void* Service_Lookup(void* a, void* b);
int LosMgr_TraceBullet(void* mgr, V* a, struct LosHit* b, V* c, V d, int e1, void* e2, int g, unsigned char h, unsigned char i, void* j, unsigned char k);
void Mtx_Copy(void* d, const void* s);
void cCollisionFace_ctor_cCollisionFaceR(void* d, const void* s);
void Vec4_Assign(void* d, const void* s);
void Vec4_Copy(V* d, const V* s);
void cCollisionModel_FaceProperties_opAssign(void* d, const void* s);
void cCollisionModel_FaceLocator_opAssign(void* d, const void* s);
void Bullet_InitFromRequest(struct Bullet* b, struct Req* r);
struct Bullet* BulletPool_Request(struct Req* req);
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); }
static inline void AddV(V* d, V* a, V* b);
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(b), "r"(d), "r"(a) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; SubV(&r, this, &o); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    V& operator+=(V o) { AddV(this, this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void AddV2(V* d, V* a, V* b) { AddV(d, a, b); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len0(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
static inline float Len(V a) { return Len0(&a); }

struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Sub40 { char b[0x10]; };
struct Sub60 { char b[0x10]; };
struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0xD];
    unsigned char b50; unsigned char b51; unsigned char b52; char p53[0xD];
    int x60;
    int* x64;
    char pad68[0x8];
    LosHit() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct Mtx { VP r[4]; Mtx() {} Mtx(const Mtx& o) { Mtx_Copy(this, &o); } };
struct HV { float x, y, z, w; HV() {} HV(const HV& o) { Vec4_Assign(this, &o); } HV& operator=(const V& o) { *(V*)this = o; return *this; } } __attribute__((aligned(16)));
struct TrCopy {
    VP v[4];
    Sub40 s40;
    unsigned char b50, b51, b52; char p53[0xD];
    Sub60 s60;
    TrCopy() {}
    TrCopy(const TrCopy& o) { cCollisionFace_ctor_cCollisionFaceR(this, &o); }
};
struct Req {
    Mtx m;
    float f40;
    int f44;
    int f48;
    int f4C;
    TrCopy tr;
    HV hit;
    int fD0;
    unsigned char fD4, fD5, fD6;
    float fD8;
    int fDC;
    int fE0;
    float fE4;
    Req() {}
};
static inline void CopyReq(Req* d, const Req* s) { Mtx_Copy(&d->m, &s->m); d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48; d->f4C = s->f4C; cCollisionFace_ctor_cCollisionFaceR(&d->tr, &s->tr); Vec4_Assign(&d->hit, &s->hit); d->fD0 = s->fD0; d->fD4 = s->fD4; d->fD5 = s->fD5; d->fD6 = s->fD6; d->fD8 = s->fD8; d->fDC = s->fDC; d->fE0 = s->fE0; d->fE4 = s->fE4; }
struct BulletReq : Req {};
struct Bullet { char pad[0x115]; unsigned char active; char pad116[0x150 - 0x116]; };
extern "C" Bullet D_004FFE60[];


Bullet* BulletPool_Request(Req* req)
{
    void* svc = Service_Lookup(g_Game, g_LosCheckService);
    V hit;
    LosHit res;
    V start = *(V*)&req->m.r[3];
    start += (*(V*)&req->m.r[1]) * D_0048B348;
    unsigned char ok = (unsigned char)LosMgr_TraceBullet(svc, &hit, &res, &start, (*(V*)&req->m.r[1]) * req->fD8, req->f44, 0, 0, 0x10, 0x80, D_00504030, 1);
    Req r; Req* d = &r; const Req* s = req; Mtx_Copy(&d->m, &s->m); d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48; d->f4C = s->f4C; cCollisionFace_ctor_cCollisionFaceR(&d->tr, &s->tr); Vec4_Assign(&d->hit, &s->hit); d->fD0 = s->fD0; d->fD4 = s->fD4; d->fD5 = s->fD5; d->fD6 = s->fD6; d->fD8 = s->fD8; d->fDC = s->fDC; d->fE0 = s->fE0; d->fE4 = s->fE4;
    if (ok) {
        V h = hit;
        r.fD8 = Len(h - *(V*)&req->m.r[3]);
        r.f4C = *res.x64;
        Vec4_Copy((V*)&r.tr.v[0], (V*)&res.arr[0]);
        Vec4_Copy((V*)&r.tr.v[1], (V*)&res.arr[1]);
        Vec4_Copy((V*)&r.tr.v[2], (V*)&res.arr[2]);
        Vec4_Copy((V*)&r.tr.v[3], &res.normal);
        r.tr.b50 = res.b50;
        cCollisionModel_FaceProperties_opAssign(&r.tr.s40, &res.b40);
        cCollisionModel_FaceLocator_opAssign(&r.tr.s60, &res.x60);
        r.tr.b51 = res.b51;
        r.tr.b52 = res.b52;
        r.hit = h;
    }
    Bullet* b = 0;
    for (int i = 0; !b && i < 50; i++) {
        if (!D_004FFE60[i].active) {
            b = &D_004FFE60[i];
            Bullet_InitFromRequest(b, &r);
        }
    }
    return b;
}
