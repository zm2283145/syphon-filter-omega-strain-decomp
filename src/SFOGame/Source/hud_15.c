/*
 * SFOGame/Source/hud: 6 files, 00244380-00244A00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00244380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char **cMemMan_Allocate(...);                        
int cInterfaceElement_Destroy(...);                            
int cIE_GOBJ_AnimateOff(...);                              
int cIE_GOBJ_SetHost(...);                      
int cIE_GOBJ_ctor(...);                   
char * cInterfaceModel_CreateInstance(...);                           
extern char D_004A7210;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
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
extern "C" void cIE_GOBJ_Render();
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
extern "C" void HudLockTracker_Draw();
extern "C" void cIE_GOBJ_NextFrame();
extern "C" void cPIE_GOBJ_dtor();
void * const D_004E0480[72] = { (void*)0x0, (void*)0x0, (void*)cPIE_GOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cIE_GOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cIE_GOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)HudLockTracker_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern unsigned char g_ProfileLockEnabled;
typedef struct { char p0[92]; int f5C; int f60; int f64; int f68; } PS0_00244380;
}
extern "C" void cHud_SetTarget(PS0_00244380 *arg0, int arg1, int arg2) {
    char **temp_a0;
    char **temp_s0;
    char **temp_s0_2;
    int var_s0;
    char * temp_v1;

    if (arg2 == -1) {
        var_s0 = arg0->f5C;
    } else {
        var_s0 = arg0->f60;
    }
    temp_v1 = (char *)(arg0->f68);
    if (temp_v1 == NULL) {
        arg0->f68 = (int)(cInterfaceModel_CreateInstance(var_s0));
        {
            AllocGuard g;
        temp_s0 = cMemMan_Allocate(0, 0x90, &D_004A7210, 0x3A1);
        }
        if (temp_s0 != NULL) {
            cIE_GOBJ_ctor(temp_s0, arg0->f68, arg1);
            *temp_s0 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0);
    } else if (F_(temp_v1, 0x70, int) != var_s0) {
        temp_a0 = (char **)(arg0->f64);
        if (temp_a0 != NULL) {
            cIE_GOBJ_AnimateOff(temp_a0);
        } else {
            cInterfaceElement_Destroy(temp_v1);
        }
        arg0->f68 = (int)(cInterfaceModel_CreateInstance(var_s0));
        {
            AllocGuard g;
        temp_s0_2 = cMemMan_Allocate(0, 0x90, &D_004A7210, 0x3AD);
        }
        if (temp_s0_2 != NULL) {
            cIE_GOBJ_ctor(temp_s0_2, arg0->f68, arg1);
            *temp_s0_2 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0_2);
    }
    cIE_GOBJ_SetHost(arg0->f64, arg1, arg2);
}
static inline void merge_flush_func_00244380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244380 */

/* merge_units: begin func_00244580 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cHud_SetAimCursorPosition: places the grenade-throw marker element in camera
 * space at pos (pushed 0.3 along dir when a direction is given, and turned to
 * face along it), scaled by D_0048AE50. Euler matrix as in cInterfaceElement_SetRotation. */
struct M;
extern "C" void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az) { __int128 tt = 0; /* dead: retail's paddub zero */ x = ax; y = ay; z = az; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
} __attribute__((aligned(16)));
struct Hud { char pad[0x58]; void* node; char pad5C[0x68 - 0x5C]; void* marker; };
extern "C" {
extern char g_CameraObject[];
extern float D_0048AE50;
void cInterfaceModel_SetPerspective(void* n, int f);
int func_00159570(void* l);
void** cLList_cCAMERA_GOBJPtr_Front(void* l);
void* cGOBJ_GetXform_void(void* o);
void cXform_GetInverseMatrix(M* out, void* xf);
void cInterfaceElement_SetLocation(void* e, const V& p);
void cInterfaceElement_SetView(void* e, M* m);
float Libc_Atan2f(float y, float x);
float COS(float);
float SIN(float);
void cHud_SetAimCursorPosition(Hud* self, V* pos, V* dir);
}
static inline void* GetCam() { if (func_00159570(g_CameraObject)) return *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject); return 0; }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline void Apply33(V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline void ScaleV(V* r, const V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline void AddV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void NegV(V* r, const V* a) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(a), "r"(r) : "memory"); }
static inline V operator*(const V& a, float k) { V r; ScaleV(&r, &a, k); return r; }
static inline V operator+(const V& a, V b) { V r; AddV(&r, &a, &b); return r; }
static inline V operator-(V a) { V r; NegV(&r, &a); return r; }
static inline float Length(const V& v)
{
    float r = 0.0f;
    int t;
    const V* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline V Xf(const V& v, M* m) { const V* pv = &v; V t = *pv; V* p = &t; MulM(p, m); return *p; }
static inline V Rot2(const V& v, M* m) { V t = v; V* p = &t; Apply33(p, m); return *p; }
static inline V Rot(const V& v, M* m) { return Rot2(v, m); }
static inline float LenYZ3(const V& d) { V h = d; h.x = 0.0f; return Length(h); }
static inline float LenYZ2(const V& d) { return LenYZ3(d); }
static inline float LenYZ(const V& d) { return LenYZ2(d); }
void cHud_SetAimCursorPosition(Hud* self, V* pos, V* dir)
{
    M inv;
    V ang;
    M* pi;
    if (!self->marker)
        return;
    cInterfaceModel_SetPerspective(self->node, 1);
    cXform_GetInverseMatrix(&inv, cGOBJ_GetXform_void(GetCam()));
    pi = &inv;
    ang.x = 0.0f; ang.y = 0.0f; ang.z = 0.0f;
    if (dir) {
        cInterfaceElement_SetLocation(self->marker, Xf(*pos + *dir * 0.3f, pi));
        V d = -Rot(*dir, pi);
        V* pd = &d;
        {
            float ax = Libc_Atan2f(-pd->x, LenYZ(*pd));
            float dy = pd->y;
            float ay = Libc_Atan2f(pd->z, dy);
            ang = V(ay, 0.0f, ax);
        }
    } else {
        cInterfaceElement_SetLocation(self->marker, Xf(*pos, pi));
    }
    M m;
    {
        float y = ang.y;
        float z = ang.z;
        float x = ang.x;
        float cy = COS(y);
        float sy = SIN(y);
        float cz = COS(z);
        float sz = SIN(z);
        float cx = COS(x);
        float sx = SIN(x);
        cMatrix_Set_ColumnMajorForm(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    }
    {
        float k = D_0048AE50;
        m.m[0][0] *= k; m.m[0][1] *= k; m.m[0][2] *= k;
        m.m[1][0] *= k; m.m[1][1] *= k; m.m[1][2] *= k;
        m.m[2][0] *= k; m.m[2][1] *= k; m.m[2][2] *= k;
    }
    cInterfaceElement_SetView(self->marker, &m);
}
static inline void merge_flush_func_00244580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244580 */

/* merge_units: begin func_00244960 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; void* obj; } O4960;
extern void nHud_ComputeColor(void* tmp);
extern void cInterfaceElement_SetFilterColor(void* obj, void* tmp);
void cHud_SetAimCursorColor(O4960* self) {
    if (self->obj) {
        char tmp[16];
        nHud_ComputeColor(tmp);
        cInterfaceElement_SetFilterColor(self->obj, tmp);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244960 */

/* merge_units: begin func_002449A0 */
#pragma push /* merge_units */
extern void cInterfaceElement_Activate(int, int);

void cHud_DeactivateNoFireIcon(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L002449C0;
    cInterfaceElement_Activate(a0, a1);
L002449C0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449A0 */

/* merge_units: begin func_002449D0 */
#pragma push /* merge_units */
void cHud_ActivateNoFireIcon(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0 + 1;
    if (cond) goto L002449F0;
    cInterfaceElement_Activate(a0, a1);
L002449F0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449D0 */

/* merge_units: begin func_00244A00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "hud_types.h"

extern void cHud_ClearTarget(void* self);

void cHud_DeactivateAimCursor(void* self) {
    cHud_ClearTarget(self);
}
static inline void merge_flush_func_00244A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244A00 */
