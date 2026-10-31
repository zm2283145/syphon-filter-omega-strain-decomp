/* score: full 439 (b113) */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
typedef unsigned long long U64;
typedef unsigned int u32;
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void QCopy(void* d, const void* s, int n) {
    int nn = n; __int128 t; const void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
static inline float AbsR(float x) { float r = 0.0f; r = x; asm { abs.s r, r } return r; }
static inline float AbsG(float x) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "+f"(r) : "f"(x)); return r; }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { const V* s = &o; void* xx = this; RQ(this, s); }
    V& operator=(const V& o) { void* xx = this; RQ(this, &o); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline void Mul44(void* d, const void* a, const void* b)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1); lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}
struct M;
static inline void Mul3(void* d, const void* a, const M& bb)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1)\n"
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddz.xyzw $vf12, $vf6, $vf8z\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddz.xyzw $vf13, $vf6, $vf9z\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddz.xyzw $vf14, $vf6, $vf10z\n"
        "vmove.xyzw $vf15, $vf7\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(&bb), "r"(a) : "memory");
}
static inline void XformInPlace(V* v, const void* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
static inline void QuatToMtx(void* a, const void* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
}
static inline void RQW1(void* d, const void* s) { RQ4(d, s); }
static inline void RQW2(void* d, const void* s) { RQW1(d, s); }
static inline void RQ4t(void* d, const void* s, __int128& a, __int128& b) { __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void RT1(void* d, const void* s, __int128& a, __int128& b) { RQ4t(d, s, a, b); }
static inline void RT2(void* d, const void* s, __int128& a, __int128& b) { RT1(d, s, a, b); }
static inline void RQW3(void* d, const void* s) { RQW2(d, s); }
struct M {
    float m[4][4];
    M() {}
    M(const M* p);
    M(const V* q) { QuatToMtx(this, q); }
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i);
    M(const M& o) { const M* s = &o; void* xx = this; RQ4(this, s); }
    M& operator=(const M& o) { void* xx = this; RQ4(this, &o); return *this; }
    void Set(const M& o) { const M* s = &o; void* xx = this; RQ4(this, &o); }
    M(const M& o, int) { void* xx = this; RQ4(this, &o); }
    M(const M& o, long) { void* xx = this; const M* s = &o; RQ4(this, s); }
    M(const M& o, char) { void* xx = this; RQ4(this, &o); }
    M& As(const M& o) { void* xx = this; const M* s = &o; __int128 a, b; RT2(this, s, a, b); return *this; }
    V& R(int i) { return *(V*)m[i]; }
    void Set4(const V& a, const V& b, const V& c, const V& d);
    void Set4b(const V& a, const V& b, const V& c, const V& d);
    M operator*(const M& b) const { M r; Mul44(&r, this, &b); return M(r, 0); }
    void Rotate(V* v) const { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(v), "r"(this), "r"(v) : "memory"); }
    void Translate(const V& v) { void* xx = this; __asm__ volatile("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" : : "r"(this), "r"(&v) : "memory"); }
} __attribute__((aligned(16)));
struct MV { V r[4]; } __attribute__((aligned(16)));
static inline void Rot(V& v, const M& m) { m.Rotate(&v); }
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
M* cMatrix_Transpose(M* m);
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
float SIN(float);
float COS(float);
}
inline M::M(const M* p) { cMatrix_ctor_cMatrixR(this, p); void* xx = this; }
inline M::M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { cMatrix_Set_ColumnMajorForm(this, a, b, c, d, e, f, g, h, i); }
static inline M Inv1(const M& m) { M a; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, &m))); }
static inline M Inv2(const M& m) { return Inv1(m); }
static inline M Inv3(const M& m) { return Inv2(m); }
static inline M Inverse(const M& m) { return Inv3(m); }
static inline M Tr1(const M& m) { M a; return M(cMatrix_Transpose(cMatrix_ctor_cMatrixR(&a, &m))); }
static inline M Tr2(const M& m) { return Tr1(m); }
static inline M Tr3(const M& m) { return Tr2(m); }
static inline M Transposed(const M& m) { return Tr2(m); }
static inline void SQ1(void* d, __int128 t) { __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void SQ2(void* d, __int128 t) { SQ1(d, t); }
static inline void SQ3(void* d, __int128 t) { SQ2(d, t); }
struct VX : V { VX(const V& o) { const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); void* xx = this; SQ1(this, t); } };
static inline void XW1(V* v, const void* m) { XformInPlace(v, m); }
static inline void XW2(V* v, const void* m) { XW1(v, m); }
static inline V X1(VX v, const M& m) { V* p = &v; XW1(p, &m); return *p; }
static inline V X2(const V& v, const M& m) { return X1(v, m); }
static inline V Xform(const V& v, const M& m) { return X2(v, m); }
static inline M T1(float (*s)[4]) { M r; for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) r.m[i][j] = s[i][j]; return r; }
static inline M To44(float (*s)[4]) { M r; for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) r.m[i][j] = s[i][j]; return M(r, (char)0); }
static inline M To44b(float (*s)[4]) { M r; for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) r.m[i][j] = s[i][j]; return M(r, 0L); }
static inline void To34(float (*d)[4], const M& s) { for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) d[i][j] = s.m[i][j]; }
static inline void To34b(float (*d)[4], const M& s) { To34(d, s); }
static inline void MW1(void* d, const void* a, const void* b) { Mul44(d, a, b); }
static inline void MW2(void* d, const void* a, const void* b) { MW1(d, a, b); }
static inline void MW3(void* d, const void* a, const void* b) { MW2(d, a, b); }
static inline void MW4(void* d, const void* a, const void* b) { MW3(d, a, b); }
static inline void MulTo34(float (*d)[4], const M& a, const M& b) { M r; MW2(&r, &a, &b); To34(d, r); }
static inline void MulTo34r(float (*d)[4], const M& b, const M& a) { M r; const M* pa = &a; const M* pb = &b; Mul44(&r, pa, pb); To34(d, r); }

static inline void ShR(float (*d)[4], const M& b, const M& a) { M r; const M* pb = &b; MW1(&r, &a, pb); To34(d, r); }

static inline V& R3a(M& m) { return m.R(3); }
static inline V& R3b(M& m) { return R3a(m); }
static inline void SetP(M& m, const V& p) { m.R(3) = p; }
static inline void SetP2(M& m, const V& p) { SetP(m, p); }
static inline M MQ(const V* q) { return M(q); }

static inline void SQa(void* d, __int128 t) { __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void SQb(void* d, __int128 t) { SQa(d, t); }
static inline void SetQ0(M& m, const V& p) { __int128 tt; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(tt) : "r"(&p) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(tt), "r"(&m.R(3)) : "memory"); }
static inline void SetQ(M& m, const V& p) { SetQ0(m, p); }

static inline void SetQ2(M& m, const V& p) { SetQ(m, p); }
struct XformNode {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update();
    char pad04[0x10 - 4];
    M transform;
    unsigned char dirty;
};
static inline M* TGU(XformNode* o) { if (o->dirty) o->Update(); return &o->transform; }
struct Skel {
    char pad0[0x14];
    unsigned char b14;
    char pad15[3];
    char nodes[0x10];
    XformNode* xf;
};
struct AB { float x, y, z; int parent; char pad[0x10]; };
struct Att {
    char pad0[0x150];
    AB b[11];
    char pad[0x410 - 0x150 - 11 * 0x20];
    signed char c410;
    char pad411[4];
    unsigned char c415;
    char pad416;
    signed char c417;
};
struct Attach { V trans; float m[3][4]; char pad[0x10]; };
struct QE { V pos; V quat; char pad[0x18]; int i27F8; short h27FC; unsigned short h27FE; };
struct Skm {
    char pad0[0x480];
    M bh[5][21];
    char pad1980[0x23C0 - 0x1EC0];
    unsigned short u23C0;
    char pad23C2[0x2410 - 0x23C2];
    Att* att[8];
    char pad2430[8];
    signed char hide[8];
    char pad2440[0x10];
    unsigned char node[0x10];
    Attach attach[10];
    char pad2780[0x40];
    QE q[16];
    char pad2BC0[0x2BD4 - 0x2BC0];
    int flags;
    short h2BD8;
    signed char c2BDA;
    signed char c2BDB;
    signed char c2BDC;
    signed char c2BDD;
    char pad2BDE[0x2BE4 - 0x2BDE];
    float f2BE4;
    int i2BE8;
    short h2BEC;
    char pad2BEE[2];
    u32 hist[5];
    void* hv;
    int i2C08;
    char pad2C0C[0x2C11 - 0x2C0C];
    signed char c2C11;
    signed char c2C12;
    char pad2C13[0x2D90 - 0x2C13];
    unsigned char u2D90;
    unsigned char u2D91;
    char pad2D92[0x2DA0 - 0x2D92];
    signed char c2DA0;
    char pad2DA1[3];
    int x2DA4;
    int x2DA8;
    int x2DAC;
};
#define ATT(a, i) (*(Attach(*)[])(a)->attach)[i]
struct PB { M m; float m34[3][4]; };
struct Pkt {
    char pad0[0x70];
    int i70;
    char pad74[0xE4 - 0x74];
    u32 r5;
    char padE8[0x110 - 0xE8];
    PB pal[21];
    char padA40[0xD50 - 0xA40];
    M sb[8][11];
    float sm[8][3][4];
    U64 d24D0;
};
struct Spr2 {
    PB e[16];
    int i700[16];
    short h740[16];
    int i760;
    int i764;
    int i768;
    int i76C;
    U64 d770;
};
struct Cam { char pad[0x100]; float f100; char pad104[0xC]; };
struct Ctx {
    char pad0[0x1F0];
    Cam cams[8];
    char pad[0xA80 - 0x1F0 - 8 * 0x110];
    M stk[32];
};
extern "C" {
extern Ctx D_005381F0;
extern int D_00538C64;
extern int D_00538C60;
extern char D_00538C68;
extern int D_005382C8;
extern int D_005382CC;
extern int D_005382D0;
extern int D_005382D4;
extern int D_004933E8;
extern float D_00538380;
extern float D_00538370;
}
static inline float Sc(float y) { y = 1.0f / y; y = y * 700.0f; y = Abs(y); return y; }
static inline int BL(int l) { float f = (float)l; l = (u32)(0.1f * f); return l + 0x47000000; }
static inline float FogF(float n, float y) { float b = D_00538370; return b + n / y; }

static inline void QM2(M& qm, QE* e) { qm = M(&e->quat); qm.R(3) = e->pos; }
static inline M QMk(QE* e) { M m; m = M(&e->quat); m.R(3) = e->pos; return m; }
static inline void MulP(M* d, M& p, M& b) { M* pp = &p; Mul44(d, pp, &b); }
static inline void MulP2(M* d, M* p, M& b) { p = p; Mul44(d, p, &b); }
static inline void MulP3(M* d, M* p, M& b) { Mul44(d, p, &b); }
static inline void MulR(float (*d)[4], const V* qq, float (*s)[4]) { MulTo34r(d, M(qq), To44b(s)); }
static inline void MulR2(float (*d)[4], const V* qq, float (*s)[4]) { M a(qq); MulTo34r(d, a, To44b(s)); }
static inline void TrH(M* m, const V& v) { m->Translate(v); }
extern "C" {
extern int D_005381C4;
extern int D_00538164;
extern int D_00538168;
extern int D_0053816C;
extern int D_00538170;
extern int D_004932C0[];
extern int D_004932E0[];
extern char D_00537F80[];
extern int D_0053B358;
extern u32 D_005383C8;
extern M D_0055DF00;
extern float D_00537DD0[3][4];
extern char D_0047DB00[];
void cMan_CheckLoading(void);
int XLib_SetModelContext(Ctx*, M*, void*, int);
void cDmaMan_InsertChain(void*, int, int, int);
U64 cMan_ManRequestTextures(Skm*, int, int);
void cMan_GetLocal2ScreenMatrix(M*, M*);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M*, const V&, const V&, const V&, const V&);
}
static inline void Set4(M* m, const V& a, const V& b, const V& c, const V& d) { cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, a, b, c, d); }
inline void M::Set4(const V& a, const V& b, const V& c, const V& d) { const V* pa = &a; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, *pa, b, c, d); }
inline void M::Set4b(const V& a, const V& b, const V& c, const V& d) { M* t = this; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(t, a, b, c, d); }
extern "C" {
void* cDmaMan_BeginChain_eDmaChannel_int(void*, unsigned char, int);
void cMan_ManDMAHeader(Skm*, Pkt*, void*, void*, U64, int, int, int, int);
char* cMan_ManDMA(Skm*, char*, int, int, ...);
void* cArray_cBone_opIndex_int(void*, int);
XformNode* cBone_Xform(void*);
M* cXform_GetMatrix(XformNode*);
char* cMan_ManDMAGuns(Skm*, char*, int, int, int);
char* cMan_ManDMAShells(Skm*, char*, int);
void cDmaMan_EndChain_int_ulongP(void*, unsigned char, void*);
void XLib_Restore(Ctx*);
}
typedef char* (*DrawCpu4)(Skm*, char*, int, int);
#define TIMER (*(volatile int*)0x10000000)
#define TOP (&D_005381F0.stk[D_00538C64])
static inline void SetFog(int v) { D_005382C8 = 1; D_005382CC = 5; D_005382D0 = v; D_005382D4 = 3; }
static inline void SetTex(int v) {
    if (v != D_00538170) {
        cDmaMan_InsertChain(D_00537F80, 1, D_004932C0[v], D_004932E0[v]);
        D_00538170 = v;
    }
    D_005381C4++;
}
static inline Cam* CurCam() { return &D_005381F0.cams[D_00538C60]; }
static inline void MulBy(M* d, const M* b) { Mul44(d, d, b); }
static inline void Pop(Skm* s) { s->x2DAC = TIMER; D_00538C68 = 1; D_00538C64--; }

extern "C" void cMan_ManRender(Skm* s, Skel* k, void* cam, int a3, int t0, int blur)
{
    Pkt* spr = (Pkt*)0x70000000;
    M saved;
    V pos;
    M bones;
    float m34[3][4];
    M pal;
    int level;
    int lod;
    u32 frame;
    U64 bv;
    U64 spC0;
    char* pk;
    int i, j;
    float fov;
    float q;

    if (s->c2BDA < 0) return;
    if (s->c2BDB) {
        cMan_CheckLoading();
        if (s->c2BDB && s->c2BDC) return;
    }
    saved = *TOP;
    D_005381F0.stk[D_00538C64 + 1] = D_005381F0.stk[D_00538C64];
    D_00538C64++;
    MulBy(TOP, TGU(k->xf));
    D_00538C68 = 1;
    pos = TOP->R(3);
    if (!a3 && !t0) {
        if (D_004933E8 >= 0) {
            SetFog(D_004933E8);
            s->h2BEC = D_004933E8 + 1;
        } else if (s->flags & 0x100) {
            s->h2BEC = s->h2BD8;
            s->h2BEC >>= 1;
            s->h2BD8 = 0xFF;
        } else if (s->c2BDD) {
            if (pos.y >= 4.5f) {
                SetFog(0x80);
                s->h2BEC = 0x80;
            } else {
                s->h2BEC = 51.0f * (pos.y - 2.0f);
                if (s->h2BEC <= 0) s->h2BEC = 1;
                if (s->h2BEC >= 0x80) s->h2BEC = 0x7F;
                SetFog(s->h2BEC);
                s->h2BEC++;
            }
        } else {
            if (pos.y >= 3.0f) {
                SetFog(0x80);
                s->h2BEC = 0x80;
            } else {
                s->h2BEC = 128.0f * (pos.y - 2.0f);
                if (s->h2BEC <= 0) s->h2BEC = 1;
                if (s->h2BEC >= 0x80) s->h2BEC = 0x7F;
                SetFog(s->h2BEC);
                s->h2BEC++;
            }
        }
        level = s->h2BEC;
    } else {
        SetFog(0x80);
        level = 0x80;
    }
    s->flags = XLib_SetModelContext(&D_005381F0, TGU(k->xf), cam, 0x480000);
    if (s->flags & 0x180) {
        float f = FogF(D_00538380, pos.y);
        if (f > 255.0f) f = 255.0f;
        if (f < 0.0f) f = 0.0f;
        s->h2BD8 = (int)f;
        if (0.0f == f) {
            Pop(s);
            return;
        }
    }
    if (s->flags & 0x80000000) s->c2BDA = 0;
    else if (s->flags & 0x40000000) s->c2BDA = 2;
    else s->c2BDA = 1;
    if (s->c2BDA == 2 && s->c2DA0 == 2) s->c2BDA = 0;
    if (s->c2BDA == 2 && s->c2DA0 == 0 && pos.y < 2.5f) s->c2BDA = 0;
    s->x2DA4 = TIMER;
    s->x2DA8 = s->x2DA4;
    if (s->c2BDA) {
        D_005381C4 = 0;
        if (a3) SetTex(D_00538168);
        else if (D_0053B358) SetTex(D_0053816C);
        else SetTex(D_00538164);
        frame = D_005383C8;
        if (!a3 && !t0) {
            s->f2BE4 = pos.Length();
            lod = 0;
            fov = CurCam()->f100;
            lod = s->f2BE4 * fov / 12.0f;
            if (lod > 1) lod = 1;
            if (s->i2C08) lod = 0;
            if (s->i2BE8 != lod) s->i2BE8 = lod;
        } else {
            lod = 1;
        }
        if (s->c2BDA == 1) {
            float kk = Sc(pos.y);
            if (kk + Abs(kk * pos.x) > 1024.0f) s->c2BDA = 2;
            if (kk + Abs(kk * pos.z) > 1024.0f) s->c2BDA = 2;
        }
        bv = cMan_ManRequestTextures(s, lod, a3);
        spC0 = spr->d24D0;
        cMan_GetLocal2ScreenMatrix(&bones, TOP);
        pal = bones;
        if (s->c2C11) {
            M t = *TOP;
            M inv = Inverse(t);
            M f = inv * D_0055DF00;
            f = Transposed(f);
            To34b(m34, f);
            blur = 0;
        } else if (D_0053B358) {
            M f;
            f.Set4(V(-1.0f, 0.0f, 0.0f, 0.0f), V(0.0f, 0.0f, -1.0f, 0.0f), V(0.0f, 0.0f, 0.0f, 0.0f), V(0.0f, 0.0f, 0.0f, 0.0f));
            M t = *TOP;
            M inv = Inverse(t);
            ((MV*)&f)->r[0] = Xform(f.R(0), inv);
            ((MV*)&f)->r[1] = Xform(f.R(1), inv);
            f = Transposed(f);
            To34b(m34, f);
        } else {
            float (*src)[4] = D_00537DD0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 4; j++)
                    m34[i][j] = src[i][j];
        }
        {
            int n = 0;
            for (int k = 0; k < 8; k++)
                if (s->att[k]) n++;
            int size = s->u23C0 * 4 + 0x1B1 + n * 0x57;
            if (s->i2C08) size += 0xF0;
            if (s->c2C12) size += s->c2C12 * 18 + 12;
            pk = (char*)cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, size);
            *(U64*)pk = ((U64)(u32)D_0047DB00 << 32) + 0x3000000A; pk += 8;
            *(U64*)pk = 0; pk += 8;
        }
        cMan_ManDMAHeader(s, blur == 0 ? (Pkt*)pk : spr, &bones, &pal, bv, lod, a3, t0, level);
        if (blur) {
            M sv[21];
            for (int k1 = 0; k1 < 21; k1++) sv[k1] = spr->pal[k1].m;
            U64 old = spr->r5;
            if (s->flags & 0x80) spr->r5 = 0x303E4000;
            else spr->r5 = 0x302E4000;
            for (int h = 4; h >= 0; h--) {
                if (frame - h - 1 <= s->hist[h]) {
                    for (int k2 = 0; k2 < 21; k2++) spr->pal[k2].m = s->bh[h][k2];
                    int lv = (u32)(0.1f * (float)(level * (5 - h)));
                    spr->i70 = lv + 0x47000000;
                    QCopy(pk, spr, 0xA5);
                    pk += 0xA50;
                    pk = cMan_ManDMA(s, pk, lod, a3, lv);
                }
            }
            spr->r5 = old;
            spr->i70 = level + 0x47000000;
            QCopy(s->bh[4], s->bh[3], 0x54);
            QCopy(s->bh[3], s->bh[2], 0x54);
            QCopy(s->bh[2], s->bh[1], 0x54);
            QCopy(s->bh[1], s->bh[0], 0x54);
            for (int k3 = 0; k3 < 21; k3++) {
                M* d = &s->bh[0][k3];
                RQ4(d, &sv[k3]);
                spr->pal[k3].m = sv[k3];
            }
            s->hist[4] = s->hist[3];
            s->hist[3] = s->hist[2];
            s->hist[2] = s->hist[1];
            s->hist[1] = s->hist[0];
            s->hist[0] = frame;
            QCopy(pk, spr, 0xA5);
            pk += 0xA50;
            pk = cMan_ManDMA(s, pk, lod, a3, level);
        } else {
            pk += 0xA50;
            pk = cMan_ManDMA(s, pk, lod, a3, level);
        }
        if (s->att[0] && s->att[0]->c410 != -1) {
            M res;
            M m;
            V* d = &m.R(3);
            V* src = &ATT(s, 3).trans;
            m.m[0][0] = ATT(s, 3).m[0][0];
            m.m[0][1] = ATT(s, 3).m[0][1];
            m.m[0][2] = ATT(s, 3).m[0][2];
            m.m[1][0] = ATT(s, 3).m[1][0];
            m.m[1][1] = ATT(s, 3).m[1][1];
            m.m[1][2] = ATT(s, 3).m[1][2];
            m.m[2][0] = ATT(s, 3).m[2][0];
            m.m[2][1] = ATT(s, 3).m[2][1];
            m.m[2][2] = ATT(s, 3).m[2][2];
            m.m[0][3] = ATT(s, 3).m[0][3];
            m.m[1][3] = ATT(s, 3).m[1][3];
            m.m[2][3] = ATT(s, 3).m[2][3];
            RQ(d, src);
            int nd = s->node[3];
            M* n = k->b14 ? cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(k->nodes, nd))) : cXform_GetMatrix(k->xf);
            Mul44(&res, n, &m);
            spr->sb[3][0] = res;
            MulTo34(spr->sm[3], To44(m34), res);
            V v = *(V*)&s->att[0]->b[0];
            Rot(v, res);
            spr->sb[3][0].Translate(v);
            Mul44(&spr->sb[3][0], &bones, &spr->sb[3][0]);
        }
        if (s->att[1] && s->att[1]->c410 != -1) {
            M res;
            M m;
            V* d = &m.R(3);
            V* src = &ATT(s, 4).trans;
            m.m[0][0] = ATT(s, 4).m[0][0];
            m.m[0][1] = ATT(s, 4).m[0][1];
            m.m[0][2] = ATT(s, 4).m[0][2];
            m.m[1][0] = ATT(s, 4).m[1][0];
            m.m[1][1] = ATT(s, 4).m[1][1];
            m.m[1][2] = ATT(s, 4).m[1][2];
            m.m[2][0] = ATT(s, 4).m[2][0];
            m.m[2][1] = ATT(s, 4).m[2][1];
            m.m[2][2] = ATT(s, 4).m[2][2];
            m.m[0][3] = ATT(s, 4).m[0][3];
            m.m[1][3] = ATT(s, 4).m[1][3];
            m.m[2][3] = ATT(s, 4).m[2][3];
            RQ(&m.R(3), src);
            int nd = s->node[4];
            M* n = k->b14 ? cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(k->nodes, nd))) : cXform_GetMatrix(k->xf);
            Mul44(&res, n, &m);
            spr->sb[4][0] = res;
            MulTo34(spr->sm[4], To44(m34), res);
            V v = *(V*)&s->att[1]->b[0];
            Rot(v, res);
            spr->sb[4][0].Translate(v);
            Mul44(&spr->sb[4][0], &bones, &spr->sb[4][0]);
        }
        for (int si = 0; si < 8; si++) {
            Att* a = s->att[si];
            if (!a || s->hide[si] || a->c417) continue;
            M res;
            M m;
            V v;
            V* d = &m.R(3);
            m.m[0][0] = ATT(s, si).m[0][0];
            m.m[0][1] = ATT(s, si).m[0][1];
            m.m[0][2] = ATT(s, si).m[0][2];
            m.m[1][0] = ATT(s, si).m[1][0];
            m.m[1][1] = ATT(s, si).m[1][1];
            m.m[1][2] = ATT(s, si).m[1][2];
            m.m[2][0] = ATT(s, si).m[2][0];
            m.m[2][1] = ATT(s, si).m[2][1];
            m.m[2][2] = ATT(s, si).m[2][2];
            m.m[0][3] = ATT(s, si).m[0][3];
            m.m[1][3] = ATT(s, si).m[1][3];
            m.m[2][3] = ATT(s, si).m[2][3];
            RQ(&m.R(3), &s->attach[si].trans);
            int nd = s->node[si];
            M* n = k->b14 ? cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(k->nodes, nd))) : cXform_GetMatrix(k->xf);
            Mul44(&res, n, &m);
            spr->sb[si][0] = res;
            MulTo34(spr->sm[si], To44(m34), res);
            for (j = 1; j < 11; j++) {
                v = *(V*)&a->b[j];
                Rot(v, res);
                spr->sb[si][j] = spr->sb[si][a->b[j].parent];
                TrH(&spr->sb[si][j], v);
            }
            if (si == 0 && s->u2D90 && s->u2D90 < 3) {
                float ang = (float)((frame >> 1 & 7) * 72) * 0.017453292f;
                float sn = SIN(ang);
                float cs = COS(ang);
                Mul3(&spr->sb[si][3], &spr->sb[si][3], M(1.0f, 0.0f, 0.0f, 0.0f, cs, -sn, 0.0f, sn, cs));
                if (s->u2D90 == 3 || s->u2D90 == 4) spr->sb[si][5] = spr->sb[si][4];
            }
            if (si == 1 && s->u2D91 && s->u2D91 < 3) {
                float ang = (float)((frame >> 1 & 7) * 72) * 0.017453292f;
                float sn = SIN(ang);
                float cs = COS(ang);
                Mul3(&spr->sb[si][3], &spr->sb[si][3], M(1.0f, 0.0f, 0.0f, 0.0f, cs, -sn, 0.0f, sn, cs));
                if (s->u2D91 == 3 || s->u2D91 == 4) spr->sb[si][5] = spr->sb[si][4];
            }
            if (a->c415) {
                float ang = (float)((frame >> 1 & 0x1F) * 81) * 0.017453292f;
                float sn = SIN(ang);
                float cs = COS(ang);
                Mul3(&spr->sb[si][3], &spr->sb[si][3], M(cs, 0.0f, sn, 0.0f, 1.0f, 0.0f, -sn, 0.0f, cs));
            }
            for (int i2 = 0; i2 < 11; i2++) Mul44(&spr->sb[si][i2], &bones, &spr->sb[si][i2]);
        }
        pk = cMan_ManDMAGuns(s, pk, lod, a3, level);
        cMan_GetLocal2ScreenMatrix(&bones, &saved);
        pal = bones;
        if (s->c2C12 && !a3) {
            Spr2* q = (Spr2*)0x70000000;
            q->i760 = level + 0x47000000;
            q->i764 = 0;
            q->i768 = 1;
            q->i76C = s->h2BD8 << 4;
            q->d770 = spC0;
            int c = 0;
            for (int t = 0; t < 16; t++) {
                if (s->q[t].h27FE) {
                    M qm; qm.As(M(&s->q[t].quat));
                    SetQ0(qm, s->q[t].pos);
                    M* pp = &pal;
                    MulP3(&q->e[c].m, pp, qm);
                    ShR(q->e[c].m34, M(&s->q[t].quat), To44b(m34));
                    q->i700[c] = s->q[t].i27F8;
                    q->h740[c] = s->q[t].h27FC;
                    c++;
                }
            }
            pk = cMan_ManDMAShells(s, pk, level);
        }
        s->x2DA8 = TIMER;
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, pk);
        XLib_Restore(&D_005381F0);
    }
    Pop(s);
}

