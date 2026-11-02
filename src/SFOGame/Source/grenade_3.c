/*
 * SFOGame/Source/grenade: 9 files, 0025A1C0-0025A860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025A1C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_0025A1C0(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0025A1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A1C0 */

/* merge_units: begin func_0025A1D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct Vec25A { int cap; int count; int* data; };
struct VObj25A;

struct VObj25A { int head; virtual ~VObj25A(); };
struct GObj25A { void* vt; char pad[0xCC]; VObj25A* fD0; };
extern "C" {
extern Vec25A D_004F8040; extern int D_004F8044; extern int* D_004F8048;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cAreaEffect_NextFrame();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
extern "C" void cGOBJ_Activate();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cGOBJ_getSOBJClassId();
extern "C" void cGOBJ_ScriptHandleMessage();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
extern "C" void func_00140E90();
extern "C" void cGOBJ_GetHealthState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void cGOBJ_GetTargetPosition();
extern "C" void cGOBJ_GetLosPosition();
extern "C" void cGOBJ_HasHeadset();
extern "C" void cGOBJ_SetStatus();
extern "C" void cGOBJ_GetStatus();
extern "C" void cGOBJ_GetChildList_void();
extern "C" void cGOBJ_GetChildList_void_2();
extern "C" void cGOBJ_ScaleBBox();
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cAreaEffect_Render();
extern "C" void cGOBJ_GetTransform_ForFloorTravel();
extern "C" void cGOBJ_GetCameraCollisionReferencePoint();
extern "C" void cGOBJ_GetTransform_ForCameraTracking();
extern "C" void cGOBJ_GetTransform_ForTeleporting();
extern "C" void cGOBJ_GetCenterOfMass();
extern "C" void cGOBJ_GetActivationPoint();
extern "C" void cGOBJ_v35();
extern "C" void cGOBJ_GetMatrix();
extern "C" void cGOBJ_SetTranslation_ResetPhysics();
extern "C" void cGOBJ_SetRotation_ResetPhysics();
extern "C" void cGOBJ_SetTransform_ResetPhysics();
extern "C" void cGOBJ_ApplyTranslation();
extern "C" void cGOBJ_ApplyLocalRotation();
extern "C" void cGOBJ_ApplyTransform();
extern "C" void cGOBJ_SetTranslation();
extern "C" void cGOBJ_SetRotation();
extern "C" void cGOBJ_SetTransform();
extern "C" void cGOBJ_Deactivate();
extern "C" void cGOBJ_NetDeactivate();
extern "C" void cGOBJ_NetActivate();
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cGOBJ_ProcessMessage();
extern "C" void cGOBJ_HandleMessage();
extern void * const D_004DC5B0[];
void std_vector_pod_int_resize(Vec25A* v, int n, int* fill);
void cGOBJ_dtor(void* self, short flag);
}
#pragma opt_strength_reduction off
extern "C" GObj25A* AreaEffect_dtor(GObj25A* self, short deleteFlag) {
    if (self) {
        self->vt = ((char*)D_004DC5B0);
        {
            int i;
            int last = D_004F8044 - 1;
            int fill;
            for (i = 0; last >= i; i++) {
                int* e = &D_004F8048[i];
                if (*e == (int)self) {
                    *e = D_004F8048[last];
                    last--;
                }
            }
            fill = 0;
            std_vector_pod_int_resize(&D_004F8040, last + 1, &fill);
        }
        {
            VObj25A* m = self->fD0;
            if (m) delete m;
        }
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma opt_strength_reduction reset
void * const D_004DC5B0[68] = { (void*)0x0, (void*)0x0, (void*)AreaEffect_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cAreaEffect_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cAreaEffect_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
static inline void merge_flush_func_0025A1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A1D0 */

/* merge_units: begin func_0025A2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; Q16(d, &o); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; Q16(d, s); return *this; }
} __attribute__((aligned(16)));
struct M4P { V r0, r1, r2, r3; M4P() {} } __attribute__((aligned(16)));
static inline void UM(void* p0) { void* p = p0; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline V operator-(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(p), "r"(a), "r"(b) : "memory");
    return r;
}
static inline V operator+(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(p), "r"(a), "r"(b) : "memory");
    return r;
}
static inline V operator*(const V& a0, float k) {
    V r; V* p = &r; const V* a = &a0; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(p), "r"(a), "f"(k) : "memory");
    return r;
}
static inline V Mul2(const V& a0, float k) {
    const V* a = &a0; V r; V* p = &r; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(p), "r"(a), "f"(k) : "memory");
    return r;
}

struct Def { char pad[0xBC]; unsigned char kind; char padBD[0xB]; float radius; char padCC[0x10]; int opaque; };
struct Owner { char pad[0xC]; int serial; };
struct XNode { virtual void v0(); virtual void SetMatrix(const M4P& m); };
struct RGB { float r, g, b; RGB(float r0, float g0, float b0) : r(r0), g(g0), b(b0) {} };
struct RGBA { float r, g, b, a; RGBA() {} };
struct Light { int x0; char* vt; };
struct LightV { int x0; VPAD8(a) VPAD1(b) virtual void Enable(); };
struct Face {
    struct VV { float x, y, z, w; } verts[3];
    V normal;
    unsigned char b40, b41, b42;
    char pad43[0x60 - 0x43];
    int l60, l64;
    char pad68[8];
    
} __attribute__((aligned(16)));
static inline void FaceInit(Face* f) { __asm__("" : "+r"(f)); { Face::VV* e = f->verts; Face::VV* end = f->verts + 3; do { e++; } while (e != end); } f->b40 = 0; f->b42 = 0; f->l60 = 0; f->l64 = 0; }
struct Los;
struct AE {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int on);
    VPAD8(d) VPAD4(e)
    virtual void CreateXform(const void* m, int f);
    char pad4[0x2B];
    unsigned char b2F;
    char pad30[0x50 - 0x30];
    XNode* xform;
    char pad54[0x60 - 0x54];
    float t;
    char pad64[0xC];
    V loc;
    Def* entry;
    Owner* owner;
    int ownerId;
    char pad8C[4];
    V edge[4];
    Light* light;
    unsigned char deletePending;
    unsigned char instant;
    unsigned char opaque;
};

extern "C" {
#if 0 /* merge_units */
extern char D_004DC5B0[];
#endif /* merge_units */
#define D_004DC5B0 ((char*)&D_004DC5B0) /* merge_units */


extern char D_004D9200[];
extern char g_IdentityMatrix[];
#if 0 /* merge_units */
extern char D_004F8040[];
#endif /* merge_units */
#define D_004F8040 ((char*)&D_004F8040) /* merge_units */


extern char g_LightMgr[];
extern char g_Game[];
extern char g_LosCheckService[];
extern float D_0048B010;
extern float D_0048B018;
extern signed char D_004F8050;
extern V D_004F8060[4];
void nGobjManager_GetNextId(int* id, int kind);
void cGOBJ_ctor(void* self, int* gid, int n, int* tag);
void nGobjManager_AddGOBJ(void* o);
#if 0 /* merge_units */
void func_0025A860(void* list, AE** p);
#endif /* merge_units */
int func_0025A860(PtrVec* v, int* value); /* merge_units */
#define func_0025A860(a0, a1) ((void)func_0025A860((PtrVec *)(a0), (int *)(a1))) /* merge_units */

void* cLightMan_AddLight(void* mgr, int type);
RGBA* tRGBA_ctor_tRGBR_float(RGBA* out, const RGB* c, float a);
Light* cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Light* l, int type, RGBA* c, V* pos, int f);
void LightEffect_SetInner(Light* l, float r);
void LightEffect_SetOuter(Light* l, float r);
Los* cSystemContainer_GetSystem(void* c, void* name);
bool cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(Los* los, V* hit, Face* face, V* from, V* ray, void* g1, void* g2, int a, int b, int c, void* cb, int d);

AE* cAreaEffect_ctor(AE* self, Owner* thrower, V* loc, Def* entry, unsigned char instant);
}

struct PointLight : Light {
    PointLight(const RGB& c, AE** s, float in, float out); 
    void* operator new(unsigned int, void* p) { return p; }
};

inline PointLight::PointLight(const RGB& c, AE** s, float in, float out) { cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(this, 4, tRGBA_ctor_tRGBR_float(&RGBA(), &c, 0.0f), &(*s)->loc, 3); vt = D_004D9200; LightEffect_SetInner(this, in); LightEffect_SetOuter(this, out); }
static inline Light* NewLight(AE** ps) { return new (cLightMan_AddLight(g_LightMgr, 4)) PointLight(RGB(1.0f, 1.0f, 1.0f), ps, D_0048B018, D_0048B010); }
static inline Light* NewLight2(AE** ps) { return NewLight(ps); }
static inline Light* NewLight3(AE** ps) { return NewLight2(ps); }
static inline Light* NewLight4(AE** ps) { return NewLight3(ps); }
AE* cAreaEffect_ctor(AE* self, Owner* thrower, V* loc, Def* entry, unsigned char instant)
{
    int id;
    int tag;
    tag = 0;
    nGobjManager_GetNextId(&id, 245);
    cGOBJ_ctor(self, &id, 3, &tag);
    *(char**)self = D_004DC5B0;
    self->ownerId = -2;
    self->owner = 0;
    { V* e = self->edge; V* end = self->edge + 4; do { e++; } while (e != end); }
    self->b2F = 1;
    self->owner = thrower;
    {
        int none;
        self->ownerId = *(thrower ? &thrower->serial : (none = -1, &none));
    }
    self->loc = *loc;
    self->entry = entry;
    self->deletePending = 0;
    self->t = 0.0f;
    self->instant = instant;
    {
        M4P mat;
        UM(&mat);
        mat.r3 = *loc;
        self->CreateXform(g_IdentityMatrix, 0);
        self->xform->SetMatrix(mat);
        self->Activate(1);
        nGobjManager_AddGOBJ(self);
        func_0025A860(D_004F8040, &self);
        self->opaque = self->entry->opaque != 0;
        if (self->entry->kind == 3) {
            self->light = NewLight4(&self);
        } else {
            self->light = 0;
        }
        if (self->light) ((LightV*)self->light)->Enable();
        {
            unsigned char k = self->entry->kind;
            if (k == 5 || k == 6 || k == 7) {
                Los* los = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                if (!D_004F8050) {
                    D_004F8060[0].x = 0.0f; D_004F8060[0].y = 1.0f; D_004F8060[0].z = 0.0f; D_004F8060[0].w = 0.0f;
                    D_004F8060[1].x = 0.0f; D_004F8060[1].y = -1.0f; D_004F8060[1].z = 0.0f; D_004F8060[1].w = 0.0f;
                    D_004F8060[2].x = 1.0f; D_004F8060[2].y = 0.0f; D_004F8060[2].z = 0.0f; D_004F8060[2].w = 0.0f;
                    D_004F8060[3].x = -1.0f; D_004F8060[3].y = 0.0f; D_004F8060[3].z = 0.0f; D_004F8060[3].w = 0.0f;
                    D_004F8050 = 1;
                }
                for (int i = 0; i < 4; i++) {
                    V hitPoint;
                    Face face;
                    FaceInit(&face);
                    V ray = D_004F8060[i] * self->entry->radius;
                    bool hit = cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(los, &hitPoint, &face, loc, &ray, 0, 0, 0, 88, 0, 0, 0);
                    if (hit) {
                        self->edge[i] = *loc + Mul2(hitPoint - *loc, 0.9f);
                    } else {
                        self->edge[i] = *loc + ray;
                    }
                }
            }
        }
    }
    return self;
}
#undef D_004DC5B0 /* merge_units */
#undef D_004F8040 /* merge_units */
#undef func_0025A860 /* merge_units */
static inline void merge_flush_func_0025A2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A2D0 */

/* merge_units: begin func_0025A860 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int*);

/* push_back */
int func_0025A860(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_0025A860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A860 */

/* merge_units: begin func_0025A880 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_A880;
static inline V4_A880 Sub_A880(V4_A880* a, V4_A880* b) {
    V4_A880 r; V4_A880* p = &r;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma opt_common_subs off
int ClipSegmentToZRange(V4_A880* a, V4_A880* b, float lo, float hi) {
    V4_A880 d = Sub_A880(b, a);
    float t;
    float z;
    z = a->z;
    if (z > hi) {
        if (b->z > hi) return 0;
        t = (hi - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = hi;
    } else if (z < lo) {
        if (b->z < lo) return 0;
        t = (lo - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = lo;
    }
    z = b->z;
    if (z > hi) {
        t = (hi - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = hi;
    } else if (z < lo) {
        t = (lo - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = lo;
    }
    return 1;
}
static inline void merge_flush_func_0025A880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A880 */

/* merge_units: begin func_0025AA20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* SegmentIntersectsSphere: does the segment a-b pass within radius r of point c */
struct V_0025AA20;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V_0025AA20* rp, const V_0025AA20* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V_0025AA20 {
    float x, y, z, w;
    V_0025AA20() {}
    // 128-bit lq/sq quadword copy idiom
    V_0025AA20(const V_0025AA20& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_0025AA20 operator-(const V_0025AA20& o) const;
    V_0025AA20 operator*(float k) const { V_0025AA20 r; ScaleV(&r, this, k); return r; }
} __attribute__((aligned(16)));
static inline void SubV(V_0025AA20* d, const V_0025AA20* a, const V_0025AA20* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
inline V_0025AA20 V_0025AA20::operator-(const V_0025AA20& o) const { V_0025AA20 r; SubV(&r, this, &o); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V_0025AA20* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(const V_0025AA20* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// VU0 macro-mode dot product (COP2), not expressible in C
static inline float Dot3(const V_0025AA20* a, const V_0025AA20* b)
{
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
extern "C" int SegmentIntersectsSphere(V_0025AA20* a, V_0025AA20* b, V_0025AA20* c, float r);
static inline float LenSq0(const V_0025AA20* a) { return LenSq(a); }
static inline float LenSqV(V_0025AA20 v) { return LenSq0(&v); }
int SegmentIntersectsSphere(V_0025AA20* a, V_0025AA20* b, V_0025AA20* c, float r)
{
    
    V_0025AA20 ac = *c - *a;
    float r2 = r * r;
    float d2 = LenSq(&ac);
    if (d2 < r2 || LenSqV(*c - *b) < r2) return 1;
    V_0025AA20 ab = *b - *a;
    float len = Len(&ab);
    V_0025AA20 dir = ab * (1.0f / len);
    float t = Dot3(&ac, &dir);
    if (t > 0.0f && t < len && d2 - t * t < r2) return 1;
    return 0;
}
static inline void merge_flush_func_0025AA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AA20 */

/* merge_units: begin func_0025AC00 */
#pragma push /* merge_units */
typedef struct ObjBC {
    char pad[0xBC];
    signed char value;
} ObjBC;

typedef struct Holder120 {
    char pad[0x120];
    ObjBC* obj;
} Holder120;

/* Returns the signed byte at obj+0xBC of the linked object, or 0. */
int cGrenade_GetDamageType(Holder120* h) {
    if (h->obj != 0) return h->obj->value;
    return 0;
}
static inline void merge_flush_func_0025AC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC00 */

/* merge_units: begin func_0025AC20 */
#pragma push /* merge_units */
#include "grenade_types.h"

extern char D_005716C0[];   /* default resource */

/* Vtable slot +0x88: resource for the projectile, or the default one. */
char* cGrenade_GetBBox(Grenade* self) {
    char* res = self->def->unk13C;

    if (res != 0) {
        return res + 992;
    }
    return D_005716C0;
}
static inline void merge_flush_func_0025AC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC20 */

/* merge_units: begin func_0025AC50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_AC5 { float x, y, z, w; V_AC5() {} } __attribute__((aligned(16)));
struct R_AC5 {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad[0x4C];
    unsigned char x50;
};
struct Q_AC5 { char pad[0x11C]; void* x11C; char pad2[0x1C]; void* x13C; };
struct O_AC5 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V_AC5 GetPos();
    char pad[0x34];
    int x38;
    char pad3C[0x14];
    R_AC5* x50;
    char pad54[0x90];
    unsigned char xE4;
    char padE5[0x3B];
    Q_AC5* x120;
};
extern "C" {
extern V_AC5 D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
void gunList_GunRender(void* a, int b, void* c, int d);
void cGrenade_Render(O_AC5* o);
}
static inline unsigned char eq4_(V_AC5* a, V_AC5* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
#pragma push
#pragma bool off
#pragma opt_common_subs off

void cGrenade_Render(O_AC5* o)
{
    if (!o->xE4) {
        void* m; R_AC5* r; V_AC5 p = o->GetPos();
        if ((eq4_(&D_00535D40, (V_AC5*)&p) != 0) ^ 1) {
            { const V_AC5* s = &p; V_AC5* d = &D_00535D40; __int128 t; asm { .set reorder; lq t, 0(s) } asm { sq t, 0(d) } }
            D_00535D60 = 1; D_00535D61 = 1;
        }
        /* empty barrier keeps the then-block (b over the else) like retail */
        { Q_AC5* q = o->x120; m = q->x11C; if (m) { asm { .set reorder } } else m = q->x13C; }
        if (m) {
            r = o->x50;
            if (r->x50) r->Update();
            gunList_GunRender(m, o->x38, (void*)((int)r + 0x10), 0);
        }
    }
}
#pragma pop
static inline void merge_flush_func_0025AC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC50 */
