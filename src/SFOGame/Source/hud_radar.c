/*
 * SFOGame/Source/hud_radar: 7 files, 002610F0-00261950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002610F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_classes.h"
struct Obj2610 { void* vt; char pad[0x60]; unsigned char active; };
extern "C" void cIE_GOBJ_Render(Obj2610* self) {
    if (self->active) ((VSlots67*)self)->slot66();
}
static inline void merge_flush_func_002610F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002610F0 */

/* merge_units: begin func_00261130 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Mtx { __int128 q[4]; Mtx() {} V* T() { Mtx* p = this; return (V*)&p->q[3]; } Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); return *this; } };
struct Pair { V a, b; };
static inline V& Unit(V& v) { V* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
static inline void Ident(Mtx* m) { Mtx* p = m; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
struct Ctl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsActive();
};
struct Cam {
    VPAD32(a) VPAD16(b) VPAD4(c)
    virtual Mtx GetAxes();
};
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mtx GetMtx();
    char pad4[0x54];
    Ctl* ctl;
};
extern "C" {
extern int D_004F82A0;
extern Mtx D_004F82B0;
extern char g_CameraObject[];
#if 0 /* merge_units */
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int*);
#endif /* merge_units */
void* nGobjManager_LookupGOBJ_cObjectIdR(int*); /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

int func_00159570(void*);
#if 0 /* merge_units */
Cam** cLList_cCAMERA_GOBJPtr_Front(void*);
#endif /* merge_units */
void** cLList_cCAMERA_GOBJPtr_Front(void*); /* merge_units */
#define cLList_cCAMERA_GOBJPtr_Front(a0) ((Cam * *)cLList_cCAMERA_GOBJPtr_Front((a0))) /* merge_units */

void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(Mtx* m, V* a, V* b, V* c, V* t);
void cMatrix_InvertRot(Mtx* m);
int cMatrix_IsZeroTranslation(Mtx* m);
V* func_00133EC0(Mtx* m);
void cVector_ctor_cVectorR(V* d, V* s);
void cVector_NegateXYZ(V* v);
void cVector_Rotate_cMatrixR(V* v, Mtx* m);
void cMatrix_SetTranslation(Mtx* m, V* t);
}
static inline Cam* GetCam() { return func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0; }

extern "C" void HudRadar_ComputeMarkerMatrix(void)
{
    Obj* o = nGobjManager_LookupGOBJ_cObjectIdR(&D_004F82A0);
    if (o) {
        bool ok = 0;
        Ctl* c = o->ctl;
        if (c && c->IsActive()) ok = 1;
        if (ok) {
            Mtx p = GetCam()->GetAxes();
            V fwd = *(V*)&p;
            V up = *((V*)&p + 1);
            V z(0.0f, 0.0f, 1.0f, 0.0f);
            fwd.z = 0.0f;
            up.z = 0.0f;
            Unit(fwd);
            Unit(up);
            Mtx m;
            Mtx om = o->GetMtx();
            cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&m, &fwd, &up, &z, om.T());
            cMatrix_InvertRot(&m);
            if (!cMatrix_IsZeroTranslation(&m)) {
                V t;
                cVector_ctor_cVectorR(&t, func_00133EC0(&m));
                cVector_NegateXYZ(&t);
                cVector_Rotate_cMatrixR(&t, &m);
                cMatrix_SetTranslation(&m, &t);
            }
            D_004F82B0 = m;
            return;
        }
    }
    Ident(&D_004F82B0);
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#undef cLList_cCAMERA_GOBJPtr_Front /* merge_units */
static inline void merge_flush_func_00261130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261130 */

/* merge_units: begin func_00261350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */



void cRADAR_GOBJ_SetRelative(Word* src) {
    D_004F82A0 = src->value;
}
static inline void merge_flush_func_00261350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261350 */

/* merge_units: begin func_00261360 */
#pragma push /* merge_units */
#pragma cplusplus on
/* HudBlip_Place: place a radar blip from its object's view-space position and heading */
struct M;
struct V_00261360 {
    float x, y, z, w;
    V_00261360() {}
    V_00261360(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V_00261360(const V_00261360& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V_00261360& operator=(const V_00261360& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
struct M { V_00261360 r0, r1, r2, r3; M() {} const V_00261360& Row1() const { return r1; } };
// VU0 macro-mode matrix * vector (COP2), not expressible in C
static inline void Apply(V_00261360* o, M* m, V_00261360* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode 3x3 rotate (COP2), not expressible in C
static inline void Rotate(V_00261360* o, M* m, V_00261360* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// sqrt.s: no C equivalent
static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float Sq(float x) { return x * x; }
struct Obj_00261360 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual V_00261360 GetPos(); /* 0xE4 */
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual M GetMtx(); /* 0xF4 */
};
struct Blip { char pad[0x60]; void* elem; char pad64[4]; int ref; char pad6C[4]; V_00261360 pos; };
struct V3 { float x, y, z; V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
extern "C" {
#if 0 /* merge_units */
extern M D_004F82B0;
#endif /* merge_units */
#define D_004F82B0 (*(M*)&D_004F82B0) /* merge_units */

extern float D_0048B0C8;
extern int D_0048B0C0;
extern float D_0048B0D0;
#if 0 /* merge_units */
Obj_00261360* nGobjManager_LookupGOBJ_cObjectIdR(int* ref);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj_00261360 *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

void cInterfaceElement_SetLocation(void* e, V_00261360* p);
void cInterfaceElement_SetRotation(void* e, V3* r);
float Libc_Atan2f(float y, float x);
void HudBlip_Place(Blip* b);
}
void HudBlip_Place(Blip* b)
{
    if (b->elem) {
        Obj_00261360* o = nGobjManager_LookupGOBJ_cObjectIdR(&b->ref);
        if (o) {
            V_00261360 p = o->GetPos();
            Apply(&p, &D_004F82B0, &p);
            float d = Sqrt(Sq(p.x) + Sq(p.y));
            float s;
            if (!(d <= D_0048B0C8)) s = (float)D_0048B0C0 / d;
            else s = (float)D_0048B0C0 * D_0048B0D0 / (D_0048B0C8 + d * (D_0048B0D0 - 1.0f));
            b->pos = V_00261360(p.x * s, 0.0f, p.y * s, 1.0f);
            cInterfaceElement_SetLocation(b->elem, &b->pos);
            V_00261360 dir = o->GetMtx().Row1();
            Rotate(&dir, &D_004F82B0, &dir);
            cInterfaceElement_SetRotation(b->elem, &V3(0.0f, -Libc_Atan2f(-dir.x, dir.y), 0.0f));
        }
    }
}
#undef D_004F82B0 /* merge_units */
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
static inline void merge_flush_func_00261360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261360 */

/* merge_units: begin func_00261540 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; float f30; } O_1540;
typedef struct { int pad0; float cur; } M_1540;
typedef struct { O_1540* obj; int pad4; M_1540* a; M_1540* b; } S_1540;
extern float cHudTargetManager_GetDangerMag(O_1540* o);
extern void cAnimator_StartAnimation(M_1540* m, float lo, float hi, unsigned char fl);
#if 0 /* merge_units */
extern void cAnimator_AnimateTo(M_1540* m, float v);
#endif /* merge_units */
void cAnimator_AnimateTo(void* e, float v); /* merge_units */
#define cAnimator_AnimateTo(a0, a1) (cAnimator_AnimateTo((void *)(a0), (a1))) /* merge_units */

extern int D_0048B0B0;
extern int D_0048B0B8;
extern int D_004F8260;

static inline float fmin_(float a, float b)
{
    float r;
    /* EE minimum has no equivalent CodeWarrior C intrinsic. */
    asm { min.s r, a, b }
    return r;
}

void cHudRadar_SetDanger(S_1540* s, int sel, float scale)
{
    M_1540* m;
    float f;
    if (sel) {
        m = s->b;
    } else {
        m = s->a;
    }
    f = scale * cHudTargetManager_GetDangerMag(s->obj);
    f = fmin_(f, 1.0f);
    if (!sel) {
        s->obj->f30 = 1.0f;
    }
    if (m) {
        if (f > 0.98f) {
            cAnimator_StartAnimation(m, (float)D_0048B0B0, (float)D_0048B0B8, 1);
            if (!sel) {
                s->obj->f30 = ((float)D_0048B0B8 - *(volatile float*)&m->cur) / (float)(D_0048B0B8 - D_0048B0B0);
            }
        } else {
            float delta = (float)(D_0048B0B0 - D_004F8260);
            delta *= f;
            cAnimator_AnimateTo(m, (float)(int)((float)D_004F8260 + delta));
        }
    }
}
#undef cAnimator_AnimateTo /* merge_units */
static inline void merge_flush_func_00261540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261540 */

/* merge_units: begin func_00261690 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cHudRadar_Update: radar heading, waypoint arrow (direction, fade by distance) and the player facing marker */
struct M_00261690;
struct V_00261690 {
    V_00261690 Minus(V_00261690 o) const { V_00261690 r; V_00261690* rp = &r; const V_00261690* ap = this; const V_00261690* bp = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
    float x, y, z, w;
    V_00261690() {}
    V_00261690(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V_00261690(const V_00261690& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V_00261690& operator=(const V_00261690& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
struct M_00261690 { V_00261690 r0, r1, r2, r3; M_00261690() {} const V_00261690& Row1() const { return r1; } };
// VU0 macro-mode matrix * vector (COP2), not expressible in C
static inline void Apply_00261690(V_00261690* o, M_00261690* m, V_00261690* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode 3x3 rotate (COP2), not expressible in C
static inline void Rotate_00261690(V_00261690* o, M_00261690* m, V_00261690* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
struct Obj_00261690 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual V_00261690 GetPos(); /* 0xE4 */
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual M_00261690 GetMtx(); /* 0xF4 */
};
struct XNode {
    VPAD1(a)
    virtual void SetMatrix(M_00261690 m);
    VPAD16(b) VPAD2(c)
    virtual void Update();
    char pad4[0xC];
    M_00261690 m;
    unsigned char b50;
    const M_00261690& Mtx() { if (b50) Update(); return m; }
};
struct Player { char pad[0x50]; XNode* node; };
struct PObj : Obj_00261690 {};
struct Cam_00261690 { char pad[0x64]; float yaw; };
struct Radar { void* owner; char pad4[0xC]; void* face; void* ring; void* arrow; };
extern "C" {
extern int D_0048B0D8;
extern int D_004F8298;
void** cLList_cCAMERA_GOBJPtr_Front(void*);
Obj_00261690* cHudTargetManager_GetWaypoint(void* o);
void cInterfaceElement_Activate(void* e, int v);
void cAnimator_AnimateTo(void* e, float v);
void* cGOBJ_GetXform_void(void* c);
M_00261690 cXform_GetInverseMatrix(void* n);
void cHudRadar_Update(Radar* r, Obj_00261690* pl);
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(V_00261690* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V_00261690 Sub(const V_00261690& a, const V_00261690& b) { V_00261690 r; V_00261690* rp = &r; const V_00261690* ap = &a; const V_00261690* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
static inline float Len1(V_00261690* a) { return Len(a); }
// min.s: no C equivalent
static inline float MinF(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V_00261690 SubV(V_00261690 a, V_00261690 b) { V_00261690 r; V_00261690* rp = &r; const V_00261690* ap = &a; const V_00261690* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
/* the unused xx reproduces retail's dead addiu of the matrix temporary's address */
static inline void RotBy(V_00261690* v, M_00261690 m) { void* xx = &m; Rotate_00261690(v, &m, v); }
static inline void* GetCam_00261690() { if (func_00159570(g_CameraObject)) return *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject); return 0; }
void cHudRadar_Update(Radar* r, Obj_00261690* pl)
{
    Cam_00261690* cam = (Cam_00261690*)GetCam_00261690();
    V3 rot(0.0f, -cam->yaw, 0.0f);
    cInterfaceElement_SetRotation(r->ring, &rot);
    if (r->arrow) {
        if (cHudTargetManager_GetWaypoint(r->owner)) {
            V_00261690 d = pl->GetPos().Minus(cHudTargetManager_GetWaypoint(r->owner)->GetPos());
            float len = Len(&d);
            float rad = D_0048B0C8;
            if (!(len <= rad)) {
                { float ny = -d.y; float nx = -d.x; rot.y += Libc_Atan2f(nx, ny); }
                cInterfaceElement_SetRotation(r->arrow, &rot);
                len -= rad;
                int k = D_0048B0D8 - D_004F8298;
                len = MinF(len, rad);
                float a = (float)D_0048B0D8 - len * (float)k / rad;
                cInterfaceElement_Activate(r->arrow, 1);
                cAnimator_AnimateTo(r->arrow, a);
            } else {
                cInterfaceElement_Activate(r->arrow, 0);
            }
        } else {
            cInterfaceElement_Activate(r->arrow, 0);
        }
    }
    V_00261690 fwd = ((Player*)pl)->node->Mtx().Row1();
    RotBy(&fwd, cXform_GetInverseMatrix(cGOBJ_GetXform_void(cam)));
    cInterfaceElement_SetRotation(r->face, &V3(0.0f, -Libc_Atan2f(-fwd.x, fwd.y), 0.0f));
}
static inline void merge_flush_func_00261690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261690 */

/* merge_units: begin func_00261950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vt4_dtor.h"

extern "C" {
#if 0 /* merge_units */
extern "C" void cHudRadar_Update();
#endif /* merge_units */

extern "C" void cHudTargetsObserver_dtor();
extern "C" void cHudTargetsObserver_Update();
extern "C" void cHudTargetsObserver_TargetAdded();
extern "C" void cHudTargetsObserver_TargetRemoved();
extern void * const D_004DC930[];
extern void * const D_004DC950[];
}
extern "C" Vt4Object* cHudRadar_dtor(Vt4Object* self, short deleteFlag) {
    if (self) {
        self->vtable = ((char*)D_004DC950);
        if (self) self->vtable = ((char*)D_004DC930);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DC930[8] = { (void*)0x0, (void*)0x0, (void*)cHudTargetsObserver_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudTargetsObserver_dtor, (void*)0x0, (void*)0x0 };
void * const D_004DC950[8] = { (void*)0x0, (void*)0x0, (void*)cHudRadar_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudRadar_dtor, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00261950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261950 */
