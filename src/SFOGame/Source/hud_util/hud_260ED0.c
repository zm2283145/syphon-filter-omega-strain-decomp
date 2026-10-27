/*
 * main/hud: 4 files, 00260ED0-00261090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00260ED0 */
#pragma push /* merge_units */
#include "types.h"
#pragma global_optimizer off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { float v; float pad[3]; } E_0ED0;
extern E_0ED0 D_004F8190[], D_004F8194[], D_004F8198[], D_004F819C[];
extern unsigned char D_004F8230;
static inline void SetNVLockColor_0ED0(int idx, float f, int b, int g, int r)
{
    D_004F8230 = 1;
    if (idx < 10) {
        if (f > 0.0f) D_004F8190[idx].v = f;
        D_004F8194[idx].v = r;
        D_004F8198[idx].v = g;
        D_004F819C[idx].v = b;
    }
}
int Script_SetNVLockColor(ScriptArg* args)
{
    int b[1];
    int g[1];
    int r[1];
    int f[1];
    int i[1];
    b[0] = args[4].i;
    g[0] = args[3].i;
    r[0] = args[2].i;
    f[0] = args[1].i;
    i[0] = args[0].i;
    SetNVLockColor_0ED0(*(int*)i, *(float*)f, *(int*)b, *(int*)g, *(int*)r);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260ED0 */

/* merge_units: begin func_00260FB0 */
#pragma push /* merge_units */
typedef struct { float v; float pad[3]; } B5fEnt;
extern B5fEnt D_004F80F0[];
extern B5fEnt D_004F80F4[];
extern B5fEnt D_004F80F8[];
extern B5fEnt D_004F80FC[];
#define B5F_ARG(var, i) (*(int*)&(var) = args[i])
int Script_SetLockColor(int* args) {
    int b;
    int g;
    int r;
    float a;
    int idx;
    int bb, gg, rr, ii;
    float aa;
    B5F_ARG(b, 4);
    bb = b;
    B5F_ARG(g, 3);
    gg = g;
    B5F_ARG(r, 2);
    rr = r;
    B5F_ARG(a, 1);
    aa = a;
    B5F_ARG(idx, 0);
    ii = idx;
    if (ii < 10) {
        if (!(aa <= 0.0f)) {
            D_004F80F0[ii].v = aa;
        }
        D_004F80F4[ii].v = rr;
        D_004F80F8[ii].v = gg;
        D_004F80FC[ii].v = bb;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260FB0 */

/* merge_units: begin func_00261080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* LockSetting_ctor(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00261080 */

/* merge_units: begin func_00261090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
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
extern "C" void HudBlip_Place();
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
extern "C" void cIE_GOBJ_NextFrame();
extern void * const D_004DC810[];
void* cIE_GOBJ_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cRADAR_GOBJ_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC810);
        cIE_GOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC810[72] = { (void*)0x0, (void*)0x0, (void*)cRADAR_GOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cIE_GOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cIE_GOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)HudBlip_Place, (void*)0x0, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00261090 */
