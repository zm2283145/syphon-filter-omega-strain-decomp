#pragma cplusplus on
#pragma inline_depth(8)
#pragma bool on
extern "C" {
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef __int128 s128; typedef unsigned __int128 u128;
#define M2C_ERROR(x) 1
#define M2C_FIELD(expr, type, off) (*(type)((char*)(expr) + (off)))
#define M2C_BITWISE(type, x) (*(type*)&(x))
#define M2C_CARRY 0
#define NULL 0
void Curve_Retime1s(f32, int);      /* extern */
f32 Math_Atan2f(f32, f32);        /* extern */
f32 Math_Cos(f32);          /* extern */
f32 Math_CosThunk(f32);                     /* extern */
f32 Math_Sin(f32);                                  /* extern */
f32 Math_SinThunk(f32);                             /* extern */
int Model_GetComponentTransform(int, int, s8);        /* extern */
void Mtx44_SetRotation(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32);                 /* extern */
f32* Mtx_ToEuler(void*, void*);            /* extern */
int Placement_GetIdentity(int, int, int);             /* extern */
int Placement_GetPosition(int);                   /* extern */
int PlayerCamera_ComputeSlopePitch(f32, int, int, int); /* extern */
int Quat_SetIdentity(int);                            /* extern */
s32 Root_GetWorldPlacement(int);                    /* extern */
s32 Secondary_RootWeight(int, int);         /* extern */
int Vec4_SetOrigin(int);                              /* extern */
f32 VecCurve_SetDuration(f32, int);                /* extern */
int VecPair_Copy(int, int);                        /* extern */
s32 Actor_GetSkeleton(int);                         /* extern */
int func_0017A5F0(int);                        /* extern */
int func_0027F7A0(int);          /* extern */
int PlayerCamera_UpdateR1Pick(int, void*, int);            /* extern */
s32 PlayerCamera_LookAtLock(int, void*, int, int, int, int);        /* extern */
int func_00280390(int, int, s8, int);          /* extern */
int func_00280470(int, int, int, int);    /* extern */
int Mtx_ToEulerXYZ(int, int);                        /* extern */
extern int D_00497F00;
extern s32 D_0049D010;
extern s8 D_0049D024;
extern int D_004A9338;
extern s8 D_004E1D80;
extern s8 D_004E1D88;
extern s32 D_004E1D90;
extern s32 D_004E1D94;
extern s32 D_004E1D98;
extern s32 D_004E1D9C;


static inline void MtxToQuat(void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}
static inline void QuatToMtx(void* a_, void* b) {
    void* a = a_;
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
static inline void QuatMul(void* rq, void* q, void* p_) { void* p = p_;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(rq)
    }
}
static inline unsigned char VecIsZero(void* v) {
    int k, fl; unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline float Dot4(void* a, void* b) { int rv0; float ret; __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah zero, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %0, vf4; qfsrv %0, %0, %0; mtc1 %0, %1" : "=&r"(rv0), "=f"(ret) : "r"(a), "r"(b) : "memory"); return ret; }
static inline float Clamp01P(float x, float hi) { float lo = 0.0f; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float Clamp01Q(float x, float h) { float lo = 0.0f; float hi = h; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float Clamp01R(float x, float h) { float hi = h; float lo = 0.0f; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float Clamp01(float x) { float lo = 0.0f; float hi = 1.0f; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float VLen(void* a) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void QuatIdent(void* q) { asm { sqc2 vf0, 0x0(q) } }
static inline void MtxMulVec(void* v, void* m) { asm {
 lqc2 vf8, 0x0(v)
 lqc2 vf4, 0x0(m)
 lqc2 vf5, 0x10(m)
 lqc2 vf6, 0x20(m)
 lqc2 vf7, 0x30(m)
 vmulax.xyzw ACC, vf4, vf8x
 vmadday.xyzw ACC, vf5, vf8y
 vmaddaz.xyzw ACC, vf6, vf8z
 vmaddw.xyzw vf12, vf7, vf8w
 sqc2 vf12, 0x0(v)
 } }
static inline void MtxMulVec3(void* o, void* m, void* v) { asm {
 lqc2 vf8, 0x0(v)
 lqc2 vf4, 0x0(m)
 lqc2 vf5, 0x10(m)
 lqc2 vf6, 0x20(m)
 lqc2 vf7, 0x30(m)
 vmulax.xyzw ACC, vf4, vf8x
 vmadday.xyzw ACC, vf5, vf8y
 vmaddaz.xyzw ACC, vf6, vf8z
 vmaddw.xyzw vf12, vf7, vf8w
 sqc2 vf12, 0x0(o)
 } }
static inline void MtxMulVec4(void* o, void* v, void* m) { asm {
 lqc2 vf8, 0x0(v)
 lqc2 vf4, 0x0(m)
 lqc2 vf5, 0x10(m)
 lqc2 vf6, 0x20(m)
 lqc2 vf7, 0x30(m)
 vmulax.xyzw ACC, vf4, vf8x
 vmadday.xyzw ACC, vf5, vf8y
 vmaddaz.xyzw ACC, vf6, vf8z
 vmaddw.xyzw vf12, vf7, vf8w
 sqc2 vf12, 0x0(o)
 } }
static inline void MtxMulVecR(void* m, void* v) { asm {
 lqc2 vf8, 0x0(v)
 lqc2 vf4, 0x0(m)
 lqc2 vf5, 0x10(m)
 lqc2 vf6, 0x20(m)
 lqc2 vf7, 0x30(m)
 vmulax.xyzw ACC, vf4, vf8x
 vmadday.xyzw ACC, vf5, vf8y
 vmaddaz.xyzw ACC, vf6, vf8z
 vmaddw.xyzw vf12, vf7, vf8w
 sqc2 vf12, 0x0(v)
 } }
static inline float CR_Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float CR_Max2(float a, float b) { float r = 0.0f; r = a; asm { max.s r, r, b } return r; }
static inline bool Bit(int v, int n) { return (v >> n) & 1; }
static inline bool BitS(int v, int n) { return Bit(v, n) != 0; }
static inline bool NBit(int v, int n) { return !(Bit(v, n) != 0); }
static inline bool FlagA(int o) { bool r = false; int v = *(int*)(o + 0xCF4); if (BitS(v, 2) && NBit(v, 3)) r = true; return r; }
static inline bool JustOn(int o, int n) { bool r = false; if (NBit(*(int*)(o + 0xCF0), n) && BitS(*(int*)(o + 0xCF4), n)) r = true; return r; }
static inline bool JustOff(int o, int n) { bool r = false; if (BitS(*(int*)(o + 0xCF0), n) && NBit(*(int*)(o + 0xCF4), n)) r = true; return r; }
static inline bool BS(bool b) { return b != 0; }
static inline bool NBS(bool b) { return !(b != 0); }
static inline bool JustOnV(int o, int n, int cb) { bool r = false; if (NBit(*(int*)(o + 0xCF0), n) && BS(cb)) r = true; return r; }
static inline bool JustOffV(int o, int n, int cb) { bool r = false; if (BitS(*(int*)(o + 0xCF0), n) && NBS(cb)) r = true; return r; }
static inline bool BothP(int* a, int n, int* b, int m) { bool r = false; if (BitS(*a, n) && BitS(*b, m)) r = true; return r; }
static inline bool PFlag(int o, int off) { int p = *(int*)(o + 0x3310); bool r = false; if (p != 0 && *(u8*)(p + off) != 0) r = true; return r; }
struct QuatF { float x, y, z, w; } __attribute__((aligned(16)));
struct AxisAng { float x, y, z, a; } __attribute__((aligned(16)));
struct Mtx { QuatF r[4]; };
struct M44 { QuatF r[4]; M44() {} M44(const M44&); };
struct Q58 { float x, y, z, w; Q58() {} Q58(const Q58&); } __attribute__((aligned(16)));
typedef struct { char pad[0xD84]; int d84; } CamD84;
class VCam { public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual M44 s57(int* a, int b);
    virtual Q58 s58();
    virtual void s59();
    virtual int s60(void* a, int b, int c);
};
static inline void V4Init(QuatF* v, const float& x, const float& y, const float& z) { v->x = x; v->y = y; v->z = z; v->w = 0.0f; }
static inline void AAInit(AxisAng* r, QuatF* ax, float ang) { r->a = ang; r->x = ax->x; r->y = ax->y; r->z = ax->z; }
static inline void QuatFromAA(QuatF* q, AxisAng* r) { float h = 0.5f * r->a; float c = Math_Cos(h); float s = Math_Sin(h); q->w = c; q->x = s * r->x; q->y = s * r->y; q->z = s * r->z; }
static inline bool NonNull(int p) { return p != 0; }
static inline bool IsNull(int p) { return !NonNull(p); }
static inline bool IEq(int a, int b) { return a == b; }
static inline bool IEqB(int a, int b) { return IEq(a, b) != 0; }
static inline bool WRValid(int h) { bool ok = true; int o = *(int*)h; if (((o != 0) ^ 1) == 0) if (IEq(*(int*)(o + 0xC), *(int*)(h + 4)) == false) ok = false; return ok; }
static inline int WRGet(int h) { return WRValid(h) ? *(int*)h : 0; }
static inline void QSetV(QuatF* q, f32 x, f32 y, f32 z) { q->x = x; q->y = y; q->z = z; q->w = 0.0f; }
static inline void QCopy(void* d, const void* s) { const void* ss = s; void* dd = d; s128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline void QFromEul(QuatF* qo, const QuatF* e) {
    float half = 0.5f;
    float hy = half * e->y;
    float hz = half * e->z;
    float ex = e->x;
    float hx = half * ex;
    float cx = Math_Cos(hx);
                float cy = Math_Cos(hy);
                float cz = Math_Cos(hz);
                float sx = Math_Sin(hx);
                float sy = Math_Sin(hy);
                float sz = Math_Sin(hz);
                float cycz = cy * cz;
                float sysz = sy * sz;
                float sycz = sy * cz;
                float cysz = cy * sz;
                
                qo->w = cx * cycz - sx * sysz;
                qo->x = sx * cycz - cx * sysz;
                qo->y = cx * sycz + sx * cysz;
                qo->z = cx * cysz + sx * sycz;
}
static inline void MtxFromEuler(void* m, f32* e) {
    f32 ex = e[0];
    f32 ey = e[1];
    f32 ez = e[2];
    f32 cx = Math_CosThunk(ex);
    f32 sx = Math_SinThunk(ex);
    f32 cy = Math_CosThunk(ey);
    f32 sy = Math_SinThunk(ey);
    f32 cz = Math_CosThunk(ez);
    f32 sz = Math_SinThunk(ez);
    f32 szcx = sz * cx;
    f32 szsx = sz * sx;
    f32 czcx = cz * cx;
    f32 czsx = cz * sx;
    Mtx44_SetRotation(m, cz * cy, czsx * sy - szcx, szsx + czcx * sy, sz * cy, czcx + szsx * sy, szcx * sy - czsx, -sy, cy * sx, cy * cx);
}
static inline void InitIdentPl_() { QuatF q; QuatF p; Quat_SetIdentity(((int)&q)); Vec4_SetOrigin(((int)&p)); Placement_GetIdentity(((int)&D_00497F00), ((int)&q), ((int)&p)); }
static inline void InitIdentPl1() { InitIdentPl_(); }
static inline void InitIdentPl2() { InitIdentPl1(); }
static inline void InitIdentPl3() { InitIdentPl2(); }
static inline void InitIdentPl() { InitIdentPl3(); }
static inline void SetIdent(void* dst) { QuatF t; QuatIdent(&t); { s128* d = (s128*)dst; s128* q = (s128*)&t; *d = *q; } }
static inline float Dot4m(void* a, void* b_) { void* b = b_; int rv0; float ret; asm {
 lqc2 vf1, 0x0(a)
 lqc2 vf2, 0x0(b)
 vmul.xyzw vf3, vf1, vf2
 mtsah zero, 0x6
 vmulax.w ACC, vf0, vf3x
 vmadday.w ACC, vf0, vf3y
 vmaddaz.w ACC, vf0, vf3z
 vmaddw.w vf4, vf0, vf3w
 qmfc2.ni rv0, vf4
 qfsrv rv0, rv0, rv0
 mtc1 rv0, ret
 } return ret; }
static inline f32 PlaneZ(QuatF* n, f32 nz, f32 x, f32 y) { f32 d = 0.0f; if (d != nz) { QuatF pt; pt.x = x; pt.y = y; pt.z = d; pt.w = 1.0f; d = -Dot4m(n, &pt) / nz; } else asm { .set reorder } return d; }
static inline f32 PitchOf(int p) { s128 t; { s128* d = &t; asm { .set noreorder } /* scheduling barrier: keeps the &t addiu ahead of the lq */ s128* q = (s128*)p; s128 v = *q; *d = v; } QuatF* pt = (QuatF*)&t; ((QuatF*)&t)->z = 0.0f; return Math_Atan2f((*(f32*)((char*)(p) + 0x8)), VLen(&t)); }
static inline void QMulR(void* o, void* a, QuatF* q) { s128 r; QuatMul(&r, a, q); { s128* d = (s128*)o; s128* qq = (s128*)&r; *d = *qq; } }
static inline void QMulInto(void* a, QuatF* q) { s128 t; QMulR(&t, a, q); { s128* d = (s128*)a; s128* qq = (s128*)&t; *d = *qq; } }
static inline void QMulW1(void* a, QuatF* q) { QMulInto(a, q); }
static inline void QMulW2(void* a, QuatF* q) { QMulW1(a, q); }
static inline void QCopyB(void* d, const void* s) { void* dd = d; const void* ss = s; s128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline void QCopyC(void* d, const void* s) { s128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void QCopyD(void* d, const void* s) { const void* ss = s; s128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(ss) : "memory"); }
static inline void QCopyE(void* d, const void* s) { void* dd = d; s128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(s) : "memory"); }
static inline void QCopyF(void* d, const void* s) { s128 q; const void* ss = s; void* dd = d; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline void QCopyH(void* d, const void* s) { s128 q; void* dd = d; const void* ss = s; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline void QCopyN1(void* d, const void* s) { s128* dd = (s128*)d; s128* ss = (s128*)s; *dd = *ss; }
static inline void QCopyN2(void* d, const void* s) { s128* ss = (s128*)s; s128* dd = (s128*)d; *dd = *ss; }
static inline void QCopyN3(void* d, const void* s) { *(s128*)d = *(s128*)s; }
static inline void QCopyN4(void* d, const void* s) { s128 t = *(s128*)s; *(s128*)d = t; }
static inline bool JustOnV2(int o, int n, int cb) { bool r = false; if (NBit(*(int*)(o + 0xCF0), n) && (cb != 0)) r = true; return r; }
static inline void QuatToMtxB(void* a, void* b) {
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
static inline void QuatToMtxC(void* a_, void* b_) {
    void* b = b_; void* a = a_;
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
static inline void QuatToMtxD(void* a_, void* b_) {
    void* a = a_; void* b = b_;
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
static inline void QuatToMtxE(void* a, void* b_) {
    void* b = b_;
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
static inline f32* TE1(void* a, void* b) { return Mtx_ToEuler(a, b); }
static inline f32* TE2(void* a, void* b_) { void* b = b_; return Mtx_ToEuler(a, b); }
static inline f32* TE3(void* a_, void* b) { void* a = a_; return Mtx_ToEuler(a, b); }
static inline f32* TE4(void* a_, void* b_) { void* b = b_; void* a = a_; return Mtx_ToEuler(a, b); }
static inline f32* TE5(void* a_, void* b_) { void* a = a_; void* b = b_; return Mtx_ToEuler(a, b); }
static inline void FE1(int a, int b) { Mtx_ToEulerXYZ(a, b); }
static inline void FE2(int a, int b_) { int b = b_; Mtx_ToEulerXYZ(a, b); }
static inline void FE3(int a_, int b) { int a = a_; Mtx_ToEulerXYZ(a, b); }
static inline void FE4(int a_, int b_) { int b = b_; int a = a_; Mtx_ToEulerXYZ(a, b); }
static inline void FE5(int a_, int b_) { int a = a_; int b = b_; Mtx_ToEulerXYZ(a, b); }
static inline void PutD70(int a, f32 v) { f32* p = (f32*)((char*)a + 0xD70); *p = v; }
static inline void PutD70b(void* a, f32 v) { f32* p = (f32*)((char*)a + 0xD70); *p = v; }
static inline f32 GetD70(int a) { f32* p = (f32*)((char*)a + 0xD70); return *p; }
static inline f32* PD70(int a) { f32* p = (f32*)((char*)a + 0xD70); return p; }
static inline f32* PD70b(int a) { return (f32*)((char*)a + 0xD70); }
static inline void QuatMulB(void* rq, void* q, void* p) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(rq), "r"(q), "r"(p) : "memory"); }
static inline void QMulRB(void* o, void* a, QuatF* q) { s128 r; QuatMulB(&r, a, q); { s128* d = (s128*)o; s128* qq = (s128*)&r; *d = *qq; } }
static inline void QMulIntoB(void* a, QuatF* q) { s128 t; QMulRB(&t, a, q); { s128* d = (s128*)a; s128* qq = (s128*)&t; *d = *qq; } }
static inline void QMulW1B(void* a, QuatF* q) { QMulIntoB(a, q); }
static inline void QMulW2B(void* a, QuatF* q) { QMulW1B(a, q); }
void PlayerCamera_Follow(int arg0, int arg1) {
    bool jr2;
    f32 sp54C;
    int sp548;
    s128 sp530;
    s128 sp520;
    s128 sp510;
    s128 sp500;
    QuatF sp4F0;
    QuatF sp4E0;
    QuatF sp4D0;
    QuatF sp4C0;
    s128 sp4B0;
    s128 sp4A0;




    f32 var_f25;
    f32 var_f24;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    f32 var_f1;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f26;
    f32 temp_f26_10;
    f32 temp_f26_11;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f26_4;
    f32 temp_f26_5;
    f32 temp_f26_6;
    f32 temp_f26_7;
    f32 temp_f26_8;
    f32 temp_f26_9;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f27_3;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f28_3;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f29_3;
    f32 temp_f29_4;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f3;
    int temp_s0_2;
    s128 temp_a1_3;
    int var_a1_6;
    s32 temp_a0_2;
    s32 temp_a0_4;
    bool jr;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a2;
    s32 one;
    s32 temp_s2;
    bool var_s1;
    s32 temp_s0;
    s32 temp_s5;
    s32 temp_t0;
    s32 temp_v1_6;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_3;
    s32 var_a0_9;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a0;
    s32 var_a0_11;
    bool var_a0_12;
    bool var_a0_13;
    s32 var_a0_2;
    bool var_a0_3;
    bool var_a0_4;
    bool var_a0_5;
    bool var_a0_6;
    bool var_a0_7;
    bool var_a0_8;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_7;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0;
    s32 var_v0_2;
    bool var_v1_10;
    s32 var_v1_3;
    s32 var_v1_4;
    bool var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    bool var_v1_8;
    bool var_v1_9;
    s8 var_a0_10;
    u32 var_a1_5;
    int temp_a0;
    int temp_a0_3;
    int temp_a0_7;
    int temp_v0;
    int temp_v1_12;
    int temp_v1_2;
    int var_a1_8;
    int var_s5;
    int var_v1;
    int var_v1_11;
    int var_v1_2;
    int temp_a1;
    int temp_a1_2;
    int temp_s0_3;
    int temp_v0_2;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;

    temp_s2 = FlagA(arg0) & 0xFF;
    if (D_004E1D80 == 0) {
        InitIdentPl();
        D_004E1D80 = 1;
    }
    VecPair_Copy(((int)&sp520), ((int)&D_00497F00));
    asm { .set noreorder } var_f25 = 0.0f; asm { .set reorder }
    sp54C = 0.0f;
    var_s1 = true; asm { .set reorder }
    SetIdent(&sp510);
    var_f24 = -1.0f;
    var_f23 = -1.0f;
    temp_s0 = (*(int*)((char*)(arg0) + 0xD84));
    temp_f26 = (*(f32*)((char*)(arg0) + 0xD88));
    var_f22 = -1.0f;
    var_f21 = -1.0f;
    var_f20 = 0.19f;
    (*(int*)((char*)(arg0) + 0xD84)) = 0;
    {
    f32 d88;
    if (temp_s2 != 0) {
        d88 = 5.0f;
    } else {
        d88 = var_f25;
    }
    (*(f32*)((char*)(arg0) + 0xD88)) = d88;
    }
    var_v1 = WRGet(arg0 + 0xCFC);
    if (var_v1 != NULL) {
        temp_v0 = func_0027F7A0(arg0 + 0xCFC);
        M44 m44 = ((VCam*)temp_v0)->s57(&((int*)arg0)[0xD84/4], temp_s2);
        MtxToQuat(&m44, &sp4A0);
        QCopy(&sp4B0, &m44.r[3]);
        { s128* d = (s128*)(&sp520); s128* q = (s128*)(&sp4A0); *d = *q; }
        s128* p530 = &sp530;
        { s128* p4b0 = &sp4B0; QCopy(p530, p4b0); }
        if ((*(int*)((char*)(arg0) + 0xD84)) != -1) {
            int* pg = &D_0049D010;
            var_v1_2 = WRGet(arg0 + 0xCFC);
            int g = *(volatile int*)pg;
            if ((*(volatile int*)((char*)(var_v1_2) + 0x4C)) == g) {
                var_s5 = WRGet(arg0 + 0xCFC);
                func_00280470(arg0, var_s5, ((int)pg), ((int)p530));
                temp_v1_3 = (*(int*)((char*)(arg0) + 0xCF4));
                if ((temp_v1_3 >> 3) & 1) {
                    float up = 0.25f;
                    QuatF v;
                    Mtx sp410;
                    Model_GetComponentTransform(((int)&sp410), Actor_GetSkeleton(var_s5), D_0049D024);
                    Mtx* pm = &sp410;
                    v.x = 0.0f; v.z = up; v.y = 0.0f; v.w = 1.0f;
                    QuatF* pv = &v;
                    MtxMulVec(pv, &sp410);
                    QCopy(&sp500, pv);
                    QCopy(&sp530, &sp500);
                } else {
                    temp_s5 = ((temp_v1_3 >> 5) & 1) != 0;
                    func_00280390(arg0 + 0xD88, var_s5, (s8) (*(int*)((char*)(arg0) + 0xD84)), temp_s5);
                    temp_a0_4 = (*(int*)((char*)(arg0) + 0xCF4));
                    if (((temp_a0_4 >> 0xA) & 1) || ((temp_a0_4 >> 0xB) & 1) || (temp_s5 != 0)) {
                        (*(f32*)((char*)(arg0) + 0xD88)) += 2.25f;
                    } else {
                        (*(f32*)((char*)(arg0) + 0xD88)) += (*(f32*)((char*)(arg0) + 0xD18));
                    }
                }
            }
            ((QuatF*)&sp530)->z += (*(f32*)((char*)(arg0) + 0xD88));
            if (!JustOn(arg0, 2)) {
                if (JustOff(arg0, 2)) {
                    goto block_58;
                }
            } else {
block_58:
                if (temp_s2 != 0) {
                    var_f24 = CR_Max2(0.5f, var_f24);
                    var_f23 = CR_Max(0.5f, var_f23);
                    var_f21 = CR_Max(0.5f, var_f21);
                } else {
                    var_f24 = CR_Max(0.33f, var_f24);
                    var_f23 = CR_Max(0.33f, var_f23);
                    var_f21 = CR_Max(0.33f, var_f21);
                }
            }
            if ((!(((*(int*)((char*)(arg0) + 0xCF4)) >> 2) & 1))) {
                if ((temp_s0 == (*(int*)((char*)(arg0) + 0xD84))) && (temp_s0 != -1)) {
                    var_f0 = (*(f32*)((char*)(arg0) + 0xD88));
                    if (temp_f26 != var_f0) {
                        goto block_67;
                    }
                } else {
block_67:
                    var_f24 = CR_Max(0.67f, var_f24);
                    var_f23 = CR_Max(0.67f, var_f23);
                }
                if (JustOn(arg0, 0xB)) {
                    if ((((*(int*)((char*)(arg0) + 0xCF4)) >> 5) & 1) || ((*(int*)((char*)(arg1) + 0x320C)) != 2)) {
                        var_f21 = var_f23 = 0.4f;
                    } else {
                        var_f21 = var_f23 = 0.33f;
                    }
                } else {
                    if (JustOff(arg0, 0xB)) {
                        var_f23 = CR_Max2(1.0f, var_f23);
                        var_f21 = CR_Max(1.0f, var_f21);
                    } else if (JustOn(arg0, 0xA) || JustOff(arg0, 0xA)) {
                        var_f23 = CR_Max(1.5f, var_f23);
                        var_f21 = CR_Max(1.5f, var_f21);
                    }
                }
                if (((*(int*)((char*)(arg0) + 0xCF4)) >> 5) & 1) {
                    if (((*(int*)((char*)(arg1) + 0x3248)) >> 5) & 1) {
                        var_f21 = 1.3f;
                    } else {
                        var_f21 = 0.9f;
                    }
                }
                temp_a0_5 = ((s32) (*(int*)((char*)(arg0) + 0xCF4)) >> 1) & 1;
                if (temp_a0_5 != 0) {
                    var_f24 = CR_Max2(0.67f, var_f24);
                } else {
                    jr = false;
                    if (BitS(*(int*)(arg0 + 0xCF0), 1) && NBS(temp_a0_5)) jr = true;
                    if (jr) {
                    var_f24 = CR_Max2(1.0f, var_f24);
                    }
                }
            }
        }
    }
    if ((*(int*)((char*)(arg0) + 0xCF4)) & 1) {
        temp_s0_2 = func_0017A5F0(arg0);
        {
            s128 sp400;
            s128 sp3F0;
            float half = 0.5f;
            float hx = half * (*(f32*)((char*)(arg0) + 0xD70));
            float hy = half * (*(f32*)((char*)(arg0) + 0xD74));
            float hz = half * (*(f32*)((char*)(arg0) + 0xD78));
            float cx = Math_Cos(hx);
            float cy = Math_Cos(hy);
            float cz = Math_Cos(hz);
            float sx = Math_Sin(hx);
            float sy = Math_Sin(hy);
            float sz = Math_Sin(hz);
            float cycz = cy * cz;
            float sysz = sy * sz;
            float sycz = sy * cz;
            float cysz = cy * sz;
            QuatF q;
            q.w = cx * cycz - sx * sysz;
            q.x = sx * cycz - cx * sysz;
            q.y = cx * sycz + sx * cysz;
            q.z = cx * cysz + sx * sycz;
            s128* s3 = &sp3F0; s128* s4 = &sp400;
            QCopyN1(&sp3F0, &q);
            QCopy(&sp400, (void*)temp_s0_2);
            QCopyD((char*)arg0 + 0xAD0, s3);
            QCopy((char*)arg0 + 0xAE0, s4);
        }
        (*(s8*)((char*)(arg0) + 0x200)) = 1;
        (*(s8*)((char*)(arg0) + 0xC60)) = 0;
        (*(s8*)((char*)(arg0) + 0xC61)) = 0;
    } else if ((*(int*)((char*)(arg0) + 0xD84)) != -1) {
        var_v0 = VecIsZero((char*)arg0 + 0xD30);
        if (var_v0 & 0xFF) {
            var_a0_9 = (*(int*)((char*)(arg0) + 0xCF4));
            temp_v1_4 = (var_a0_9 >> 6) & 1;
            if (temp_v1_4 != 0) {
                if ((var_a0_9 >> 7) & 1) {
                    var_f25 = 0.7853982f;
                } else if ((var_a0_9 >> 8) & 1) {
                    var_f25 = -0.7853982f;
                } else {
                    jr2 = false; if (NBit(*(int*)(arg0 + 0xCF0), 6) && BS(temp_v1_4)) jr2 = true; if (jr2 || JustOff(arg0, 1) || JustOff(arg0, 2)) {
                        var_f25 = 0.0f;
                    } else {
                        var_s1 = false;
                    }
                }
            }
        }
        if ((!(((*(int*)((char*)(arg0) + 0xCF4)) >> 2) & 1))) {
            {
            float ang = (*(f32*)((char*)(arg0) + 0x6E8));
            QuatF q; AxisAng aa; QuatF ax;
            ax.x = 0.0f; ax.y = 0.0f; ax.z = 1.0f; ax.w = 0.0f;
            AAInit(&aa, &ax, ang);
            QuatFromAA(&q, &aa);
            QMulW2B(&sp520, &q);
            }
            {
            QuatF sp3A0; Mtx sp360;
            f32* pd78 = (f32*)((char*)arg0 + 0xD78);
            QuatToMtxB(&sp360, &sp520);
            *pd78 = TE2(&sp3A0, &sp360)[2];
            }
        }
        PlayerCamera_ComputeSlopePitch((*(f32*)((char*)(arg0) + 0xD20)), ((int)&sp54C), ((int)&sp520), arg1);
        if (!PFlag(arg1, 0xDC) && ((*(int*)((char*)(arg1) + 0x320C)) != 1) && (temp_v1_5 = (*(int*)((char*)(arg0) + 0xCF4)), (((temp_v1_5 >> 5) & 1) == 0)) && (!((temp_v1_5 >> 6) & 1))) {
            if ((temp_v1_5 >> 9) & 1) {
                var_v0_2 = VecIsZero((char*)arg0 + 0xD30);
                if (var_v0_2 & 0xFF) {
                    goto block_152;
                }
            }
        } else {
block_152:
            var_v1_6 = BothP((int*)((char*)arg0 + 0xCF4), 9, (int*)((char*)arg1 + 0x3248), 0x1D);
            temp_a0_6 = var_v1_6 & 0xFF;
            var_v1_7 = BothP((int*)((char*)arg0 + 0xCF4), 9, (int*)((char*)arg1 + 0x3248), 0x13);
            temp_v1_6 = var_v1_7 & 0xFF;
            var_a1_4 = BothP((int*)((char*)arg0 + 0xCF4), 9, (int*)((char*)arg1 + 0x3248), 0x12);
            temp_v0_3 = var_a1_4 & 0xFF;
            var_a2 = BothP((int*)((char*)arg0 + 0xCF4), 9, (int*)((char*)arg1 + 0x3248), 0x14);
            temp_t0 = var_a2 & 0xFF;
            if ((((*(int*)((char*)(arg0) + 0xCF4)) >> 9) & 1) && (temp_a0_6 == 0) && (temp_v1_6 == 0) && (temp_v0_3 == 0) && (temp_t0 == 0)) {
                if (!PFlag(arg1, 0x99F)) {
                    if (!PFlag(arg1, 0x9A0)) {
                        var_s1 = false;
                    }
                }
            } else if (((*(int*)((char*)(arg1) + 0x320C)) == (one = 1)) || (((temp_a2 = (*(int*)((char*)(arg0) + 0xCF4))) >> 5) & 1)) {
                if (((*(int*)((char*)(arg0) + 0xCF4)) >> 5) & 1) {
                    sp54C = 0.0f;
                } else {
                    temp_v1_7 = (*(int*)((char*)(arg1) + 0x3248));
                    if ((temp_v1_7 >> 6) & 1) {
                        sp54C = -1.0471976f;
                    } else if ((temp_v1_7 >> 7) & 1) {
                        sp54C = -1.0471976f;
                    } else if ((temp_v1_7 >> 5) & 1) {
                        sp54C = -0.61086524f;
                    } else {
                        sp54C = -0.5235988f;
                    }
                }
            } else {
                if ((temp_a2 >> 6) & 1) {
                    if (((VCam*)arg1)->s60(&sp4F0, temp_a2, one) & 0xFF) {
                        float hgt = 7.0f;
                        {
                        bool z = false;
                        unsigned int i = 0;
                        s8 v;
                        s8* src = (s8*)&D_004A9338;
                        for (; i < 4U; i++) {
                            if (src[i] == 0) {
                                z = true;
                            }
                            if (z) v = 0; else v = src[i];
                            ((s8*)&sp548)[i] = v;
                        }
                        }
                        { int sub = arg1 + 0x2EC0; temp_v0_6 = Placement_GetPosition(Root_GetWorldPlacement(Secondary_RootWeight(sub + 0xB0, ((int)&sp548)))); }
                        { f32 one; f32 k; f32 x; f32 y; f32 pz; f32 nz; nz = sp4F0.z; pz = (*(f32*)((char*)(temp_v0_6) + 0x8)); y = (*(f32*)((char*)(temp_v0_6) + 0x4)); x = (*(f32*)((char*)(temp_v0_6) + 0x0)); f32 d = PlaneZ(&sp4F0, nz, x, y); k = 0.25f; one = 1.0f; var_f3 = k * ((pz - d) - hgt); var_f3 = Clamp01P(var_f3, one); }
                    } else {
                        var_f3 = 1.0f;
                    }
                    { f32 k = (-0.5235988f - -0.17453292f); f32 t = var_f3 * k; sp54C = -0.17453292f + t; }
                } else {
                temp_a1 = (*(int*)((char*)(arg1) + 0x3310));
                if (temp_a1 != NULL) {
                    var_a1_6 = temp_a1 + 0x310;
                } else {
                    if (D_004E1D88 == 0) {
                        D_004E1D88 = one; asm { .set noreorder }
                        D_004E1D90 = 0;
                        D_004E1D94 = 0;
                        D_004E1D98 = 0;
                        D_004E1D9C = 0;
                    }
                    var_a1_6 = ((int)&D_004E1D90);
                }
                if (temp_a0_6 != 0) {
                    sp54C = -0.61086524f;
                } else {
                    if (temp_v1_6 != 0) {
                        sp54C = -1.5707964f;
                        sp54C *= 0.475f;
                    } else if (temp_v0_3 != 0) {
                        sp54C = 1.5707964f;
                        sp54C *= 0.4f;
                    } else if (temp_t0 != 0) {
                        sp54C = -1.5707964f;
                        sp54C *= 0.55f;
                    } else {
                        temp_f0_4 = PitchOf(var_a1_6);
                        sp54C = temp_f0_4;
                        sp54C *= 0.8f;
                    }
                }
                }
            }
        }
        {
        QuatF q; AxisAng aa;
        aa.a = (*(f32*)((char*)(arg0) + 0xD70));
        aa.x = 1.0f; aa.y = 0.0f; aa.z = 0.0f;
        QuatFromAA(&q, &aa);
        QCopy(&sp510, &q);
        }
        temp_v1_8 = (*(int*)((char*)(arg0) + 0xCF4));
        if ((temp_v1_8 >> 2) & 1) {
            Mtx sp300; QuatF sp2F0; Mtx sp2B0;
            temp_s0_3 = (*(int*)((char*)(arg0) + 0x50));
            if ((*(u8*)((char*)(temp_s0_3) + 0x50)) != 0) {
                ((VCam*)temp_s0_3)->s20();
            }
            if (PlayerCamera_LookAtLock(arg0, &sp4E0, arg1, 4, temp_s2, temp_s0_3 + 0x40) & 0xFF) {
                (*(f32*)((char*)(arg0) + 0xD70)) = sp4E0.x;
                (*(f32*)((char*)(arg0) + 0xD78)) = sp4E0.z;
            }
            QuatToMtxB(&sp300, &sp520);
            FE2(((int)&sp4D0), ((int)&sp300));
            temp_f0_7 = (*(f32*)((char*)(arg0) + 0xD78));
            sp4D0.z = temp_f0_7;
            MtxFromEuler(&sp2B0, (f32*)&sp4D0);

            MtxToQuat(&sp2B0, &sp2F0);
            { void* dp = &sp520; void* sp = &sp2F0; s128 q; f32* pd = (f32*)((char*)arg0 + 0xD70); __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(q) : "r"(sp) : "memory"); var_f20 = 0.0f; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(dp) : "memory"); var_s1 = true; sp54C = *pd; }
        } else if ((temp_v1_8 >> 1) & 1) {
            Mtx sp270;
            PlayerCamera_UpdateR1Pick(arg0, &sp520, arg1);
            QuatToMtxB(&sp270, &sp520);
            FE2(((int)&sp4C0), ((int)&sp270));
            {
            QuatF q; AxisAng aa;
            aa.x = 1.0f; aa.y = 0.0f; aa.z = 0.0f;
            aa.a = sp4C0.x;
            QuatFromAA(&q, &aa);
            QCopy(&sp510, &q);
            }
            *PD70b(arg0) = sp4C0.x;
            sp4C0.x = 0.0f;
            QuatF sp240; Mtx sp200;
            MtxFromEuler(&sp200, (f32*)&sp4C0);

            MtxToQuat(&sp200, &sp240);
            { void* dp = &sp520; void* sp = &sp240; s128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(q) : "r"(sp) : "memory"); f32* pd = (f32*)((char*)arg0 + 0xD70); var_f20 = 0.0f; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(dp) : "memory"); var_s1 = true; sp54C = *pd; }
        } else {
            if (!PFlag(arg1, 0xDC) && (((*(int*)((char*)(arg0) + 0xCF4)) >> 9) & 1) && ((temp_v1_11 = (*(int*)((char*)(arg1) + 0x3248)), (((temp_v1_11 >> 0x12) & 1) != 0)) || ((temp_v1_11 >> 0x13) & 1) || ((temp_v1_11 >> 0x14) & 1))) {
                var_f23 = CR_Max(0.33f, var_f23);
            }
            QuatF sp1F0; Mtx sp1B0;
            f32* pd70 = (f32*)((char*)arg0 + 0xD70);
            QCopy(&sp510, ((char*)(arg0) + 0x550));
            QuatToMtx(&sp1B0, (char*)arg0 + 0x7A0);
            *pd70 = TE2(&sp1F0, &sp1B0)[0];
            {
            float ang = (*(f32*)((char*)(arg0) + 0x6E0));
            QuatF q; AxisAng aa; QuatF ax;
            ax.x = 1.0f; ax.y = 0.0f; ax.z = 0.0f; ax.w = 0.0f;
            AAInit(&aa, &ax, ang);
            QuatFromAA(&q, &aa);
            QMulW1(&sp510, &q);
            }
        }
        { void* s2 = &sp530; QCopy((char*)arg0 + 0xAD0, &sp520);
        QCopy((char*)arg0 + 0xAE0, s2); }
        (*(s8*)((char*)(arg0) + 0x200)) = 1;
        if (var_s1) {
            {
                f32 sx = sp54C; QuatF q; QuatF e;
                e.y = 0.0f;
                e.z = var_f25;
                e.x = sx;
                QFromEul(&q, &e);
                QCopy((char*)arg0 + 0x4A0, &q);
            }
            Curve_Retime1s(var_f20, arg0 + 0x460);
            Curve_Retime1s(var_f20, arg0 + 0x530);
        } else {
            Curve_Retime1s(var_f20, arg0 + 0x460);
            Curve_Retime1s(var_f20, arg0 + 0x530);
        }
        {
        QuatF v;
        f32* pz = (f32*)((char*)arg0 + 0xD38); f32* py = (f32*)((char*)arg0 + 0xD34); f32* px = (f32*)((char*)arg0 + 0xD30); f32 fx; f32 fy; f32 fz; fz = *pz; fy = *py; fx = *px;
        QSetV(&v, fx, fy, fz);
        QCopy((char*)arg0 + 0x640, &v);
        }
        QCopy((char*)arg0 + 0x7C0, &sp510);
        Curve_Retime1s(var_f24, arg0 + 0x210);
        VecCurve_SetDuration(var_f23, arg0 + 0x2E0);
        VecCurve_SetDuration(var_f23, arg0 + 0x3A0);
        Curve_Retime1s(var_f22, arg0 + 0x780);
        var_f0 = VecCurve_SetDuration(var_f21, arg0 + 0x910);
        (*(s8*)((char*)(arg0) + 0xC60)) = 1;
        var_v1_11 = WRGet(arg0 + 0xCFC);
        if (var_v1_11 != NULL) {
            var_a1_8 = WRGet(arg0 + 0xCFC);
            Q58 q58 = ((VCam*)var_a1_8)->s58();
            QCopy((char*)arg0 + 0x3E0, &q58);
            (*(s8*)((char*)(arg0) + 0xC61)) = 1;
        } else {
            (*(s8*)((char*)(arg0) + 0xC61)) = 0;
        }
    }
    if (!JustOn(arg0, 0)) {
        if (JustOff(arg0, 0)) {
            goto block_290;
        }
    } else {
block_290:
        (*(s8*)((char*)(arg0) + 0x201)) = 1;
    }
}

}
