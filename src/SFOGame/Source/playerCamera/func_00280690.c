#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* cPlayerCamera_UpdateMotion: free-fly (debug) or orbit camera step, then follow the target and push the
   camera node's transform (optionally rotated by the camera quaternion) to the node. */
struct V4 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
struct CNode {
    virtual void v0();
    virtual void SetMatrix(M4* m);
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    int pad4[3];
    M4 m;
    unsigned char dirty;
};
struct CTgt { char pad0[0xC]; int id; char pad10[0x4C - 0x10]; int cls; };
struct CHnd { CTgt* p; int id; };
struct Cam {
    char pad0[0x50];
    CNode* node;              /* 0x50 */
    char pad54[0xAF0 - 0x54];
    float speed;             /* 0xAF0 */
    float climb;             /* 0xAF4 */
    char padAF8[0xCF0 - 0xAF8];
    int prev;                /* 0xCF0 */
    int flags;               /* 0xCF4 */
    char padCF8[0xCFC - 0xCF8];
    CHnd target;              /* 0xCFC */
    char padD04[0xD14 - 0xD04];
    float climbRate;         /* 0xD14 */
    char padD18[0xD1C - 0xD18];
    float moveRate;          /* 0xD1C */
    char padD20[0xD40 - 0xD20];
    V4 fwd;                  /* 0xD40 */
    V4 side;                 /* 0xD50 */
    float rateX;             /* 0xD60 */
    char padD64[0xD68 - 0xD64];
    float rateZ;             /* 0xD68 */
    char padD6C[0xD70 - 0xD6C];
    V4 ang;                  /* 0xD70 */
    V4 padD80;
    V4 quat;                 /* 0xD90 */
    M4 xform;                /* 0xDA0 */
};
extern "C" {
extern int g_HumanActorClassKey;
extern float D_004A9318;
extern float D_004A9320;
float COS(float a);
float SIN(float a);
void cMatrix_Set_ColumnMajorForm(M4* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
V4* cGameCamera_GetGlobalOffset(Cam* c);
void cGameCamera_SetGlobalOffset(Cam* c, V4* p);
void cVector_Cross(V4* r, V4* a, V4* b);
int cVector_IsZeroXYZ(V4* v);
V4* cVector_GetNormalized_void(V4* r, V4* v);
V4* cVector_Normalize_void(V4* v);
V4* cVector_ctor_cVectorR(V4* d, V4* s);
V4* cVector_ctor_float_float_float_float(V4* v, float x, float y, float z, float w);
M4* cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M4* m, V4* a, V4* b, V4* c, V4* t);
M4* cMatrix_MakeLookAtMatrix_cVectorR(M4* m, V4* axis);
M4* cMatrix_SetUnit(M4* m);
void cPlayerCamera_UpdateCameraTrackingPoint(Cam* c, CTgt* t);
void cGameCamera_UpdateMotion(Cam* c, float dt);
void cPlayerCamera_UpdateMotion(Cam* c, float dt);
}
static inline bool IEq(int a, int b) { return a == b; }
static inline bool IdEq(CTgt* p, CHnd* h) { return p->id == h->id; }
static inline CTgt* WRGet(CHnd* h) {
    bool ok = (h->p != 0) ^ 1 || IdEq(h->p, h);
    unsigned char k = ok;
    return k ? h->p : 0;
}
static inline int Bit(int v, int n) { return (v >> n) & 1; }
static inline bool BitS(int v, int n) { return Bit(v, n) != 0; }
static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void Q4S(const void* s0, void* d0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline const M4& NM(CNode* n) { if (n->dirty) n->Refresh(); return n->m; }
static inline void QC(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
/* rotate v (xyz) by the 3x3 part of m in place (VU0) */
static inline void Rot3(V4* v, M4* m) { asm {
 lqc2 vf8, 0x0(v)
 lqc2 vf4, 0x0(m)
 lqc2 vf5, 0x10(m)
 lqc2 vf6, 0x20(m)
 vmulax.xyz ACC, vf4, vf8x
 vmadday.xyz ACC, vf5, vf8y
 vmaddz.xyz vf8, vf6, vf8z
 sqc2 vf8, 0x0(v)
 } }
static inline void VAdd(V4* r, V4* a, V4* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
/* one pass-through level: VAdd's pointers are created after RotV's copy temps (retail colours) */
static inline void VAdd1(V4* r, V4* a, V4* b) { VAdd(r, a, b); }
static inline void VScale(V4* pr, V4* pa, float k) {
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(pr), "r"(pa), "f"(k) : "memory"); }
static inline void AddTo(V4* a, V4* b) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory"); }
static inline void QuatToMtx(M4* a, V4* b) {
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
/* d = r * d: rotate d's three rows by r, keep its translation (VU0) */
static inline void MulRot(M4* d, M4* r) { asm {
 lqc2 vf8, 0x0(r)
 lqc2 vf9, 0x10(r)
 lqc2 vf10, 0x20(r)
 lqc2 vf4, 0x0(d)
 lqc2 vf5, 0x10(d)
 lqc2 vf6, 0x20(d)
 lqc2 vf7, 0x30(d)
 vmulax.xyzw ACC, vf4, vf8x
 vmadday.xyzw ACC, vf5, vf8y
 vmaddz.xyzw vf12, vf6, vf8z
 vmulax.xyzw ACC, vf4, vf9x
 vmadday.xyzw ACC, vf5, vf9y
 vmaddz.xyzw vf13, vf6, vf9z
 vmulax.xyzw ACC, vf4, vf10x
 vmadday.xyzw ACC, vf5, vf10y
 vmaddz.xyzw vf14, vf6, vf10z
 vmove.xyzw vf15, vf7
 sqc2 vf12, 0x0(d)
 sqc2 vf13, 0x10(d)
 sqc2 vf14, 0x20(d)
 sqc2 vf15, 0x30(d)
 } }
static inline float MinF(float a, float b) { float r = a; asm { min.s r, r, b } return r; }
static inline void SetClimb(Cam* c, float v) { c->climb = MinF(0.0f, -v); }
static inline M4* MtxFromEuler(M4* m, V4* e)
{
    float czcy; float cz; float sx; float czsy; float szcy; float cy; float sz; float y; float x; float sy; float cx; float szsy; float z; /*P*/
    y = e->y;
    x = e->x;
    z = e->z;
    cy = COS(y);
    sy = SIN(y);
    cx = COS(x);
    sx = SIN(x);
    cz = COS(z);
    sz = SIN(z);
    szcy = sz * cy; czcy = cz * cy; czsy = cz * sy; szsy = sz * sy; /*S*/
    cMatrix_Set_ColumnMajorForm(m, czcy - szsy * sx, -sz * cx, czsy + szcy * sx, szcy + czsy * sx, cz * cx, szsy - czcy * sx, -cx * sy, sx, cx * cy);
    return m;
}

static inline bool IEqR(int g, int v) { return v == g; }
static inline bool IEqRB(int g, int v) { return IEqR(g, v) != 0; }
static inline bool IEqB(int a, int b) { return IEq(a, b) != 0; }
static inline V4* Row0(M4* m) { V4* p = &m->r[0]; return p; }
static inline void RotV(V4* out, V4* v, M4* m) { V4 t; QC(&t, v); { V4* p = &t; Rot3(p, m); QC(out, p); } }
static inline M4* Frame2(M4* out, V4* side, V4* up)
{
    V4 cr;
    cVector_Cross(&cr, side, up);
    if (!cVector_IsZeroXYZ(&cr)) {
        V4 n;
        V4 a;
        V4 b;
        V4 o;
        cVector_GetNormalized_void(&n, side);
        cVector_ctor_cVectorR(&a, cVector_Normalize_void(&cr));
        cVector_Cross(&b, &a, &n);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(out, &a, &n, &b, cVector_ctor_float_float_float_float(&o, 0.0f, 0.0f, 0.0f, 1.0f));
        return out;
    }
    if (!cVector_IsZeroXYZ(side))
        return cMatrix_MakeLookAtMatrix_cVectorR(out, side);
    cMatrix_SetUnit(out);
    return out;
}
static inline M4* Frame(M4* out, V4* side, V4* up) { return Frame2(out, side, up); }
static inline void MulTo(M4* out, M4* r, CNode* n) { M4* rr = r; M4 w; Q4(&w, &NM(n)); { M4* p = &w; MulRot(p, r); Q4(out, p); } }
static inline float MinV(float a, float b) { float r = 0.0f; r = a; asm volatile { min.s r, r, b } return r; }
static inline void Stop(float* speed, float* climb) { *climb = MinV(0.0f, -0.0f); *speed = 0.0f; }
static inline void Wrap(float* p) { float v = *p; if (!(v <= 3.1415927f)) { float k = -6.2831855f; *p = v + k; } else if (v < -3.1415927f) { float k = 6.2831855f; *p = v + k; } }
static inline float ClampS(float x, float hi) { float r = 0.0f; float lo = -hi; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float* ZP(float* a) { return &a[2]; }
static inline float* ClimbP(Cam* c) { return &c->climb; }
static inline float* SpeedP(Cam* c) { return &c->speed; }
void cPlayerCamera_UpdateMotion(Cam* c, float dt)
{
    CTgt* human;
    {
        bool isHuman = false;
        if (WRGet(&c->target) != 0 && IEqRB(g_HumanActorClassKey, WRGet(&c->target)->cls))
            isHuman = true;
        human = isHuman ? WRGet(&c->target) : 0;
    }
    if (!(c->flags & 1)) {
        int f = c->flags;
        bool b3; bool b10; bool b11; bool b5; bool b6; bool any; bool up; float v; 
        b3 = BitS(f, 3); b10 = BitS(f, 10); b11 = BitS(f, 11); b5 = BitS(f, 5); b6 = BitS(f, 6); up = true; 
        if (!b3 && !b5)
            up = false;
        if (up)
            v = 0.0f;
        else if (b11)
            v = 2.0f;
        else if (b10)
            v = 5.0f;
        else
            v = c->climbRate;
        SetClimb(c, v);
        {
            bool d, b, a;
            any = true;
            d = true;
            b = true;
            a = true;
            if (!b3 && !b11) a = false;
            if (!a && !b10) b = false;
            if (!b && !b5) d = false;
            if (!d && !b6) any = false;
        }
        c->speed = any ? 0.0f : c->moveRate;
    } else {
        V4 pos;
        M4 rot;
        V4 fwd;
        V4 side;
        V4 up;
        M4 fm;
        V4 sv;
        M4 frame;
        QC(&pos, cGameCamera_GetGlobalOffset(c));
        MtxFromEuler(&rot, &c->ang);
        RotV(&fwd, &c->fwd, &rot);
        side.Set(-Row0(&rot)->y, Row0(&rot)->x, 0.0f, 0.0f);
        up.Set(0.0f, 0.0f, 1.0f, 0.0f);
        Q4(&fm, Frame(&frame, &side, &up));
        RotV(&sv, &c->side, &fm);
        VAdd1(&fwd, &fwd, &sv);
        VScale(&fwd, &fwd, dt);
        AddTo(&pos, &fwd);
        cGameCamera_SetGlobalOffset(c, &pos);
        *ClimbP(c) = MinV(0.0f, -0.0f);
        *SpeedP(c) = 0.0f;
    }
    {
        float lim = BitS(c->flags, 2) ? D_004A9320 : D_004A9318;
        float* a = &c->ang.x;
        c->ang.z += dt * c->rateZ;
        c->ang.x += dt * c->rateX;
        Wrap(ZP(a));
        a[0] = ClampS(a[0], lim);
    }
    cPlayerCamera_UpdateCameraTrackingPoint(c, human);
    cGameCamera_UpdateMotion(c, dt);
    {
        CNode* n = c->node;
        if (n) {
            Q4(&c->xform, &NM(n));
            if (BitS(c->flags, 3)) {
                M4 t;
                M4 r;
                QuatToMtx(&r, &c->quat);
                MulTo(&t, &r, n);
                n->SetMatrix(&t);
            }
        }
    }
}
