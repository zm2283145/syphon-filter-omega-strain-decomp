/*
 * main/callback: 2 files, 003E93E0-003E9460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E93E0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9B20;
extern char D_004E0240[];
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_CriticalNextFrame();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cGOBJ_getSOBJClassId();
extern void cGOBJ_ScriptHandleMessage();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cGOBJ_GetFloorPlane();
extern void cGOBJ_GetBBox();
extern void func_00140E90();
extern void cGOBJ_GetHealthState();
extern void cGOBJ_IsGeneratorCreated();
extern void cGOBJ_GetTargetPosition();
extern void cGOBJ_GetLosPosition();
extern void cGOBJ_HasHeadset();
extern void cGOBJ_SetStatus();
extern void cGOBJ_GetStatus();
extern void cGOBJ_GetChildList_void();
extern void cGOBJ_GetChildList_void_2();
extern void cGOBJ_ScaleBBox();
extern void cGOBJ_GetTargetPriority();
extern void cGOBJ_GetMovementState();
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_IsNetworked();
extern void cGOBJ_CheckBullet();
extern void cIE_GOBJ_Render();
extern void cGOBJ_GetTransform_ForFloorTravel();
extern void cGOBJ_GetCameraCollisionReferencePoint();
extern void cGOBJ_GetTransform_ForCameraTracking();
extern void cGOBJ_GetTransform_ForTeleporting();
extern void cGOBJ_GetCenterOfMass();
extern void cGOBJ_GetActivationPoint();
extern void cGOBJ_v35();
extern void cGOBJ_GetMatrix();
extern void cGOBJ_SetTranslation_ResetPhysics();
extern void cGOBJ_SetRotation_ResetPhysics();
extern void cGOBJ_SetTransform_ResetPhysics();
extern void cGOBJ_ApplyTranslation();
extern void cGOBJ_ApplyLocalRotation();
extern void cGOBJ_ApplyTransform();
extern void cGOBJ_SetTranslation();
extern void cGOBJ_SetRotation();
extern void cGOBJ_SetTransform();
extern void cGOBJ_Deactivate();
extern void cGOBJ_NetDeactivate();
extern void cGOBJ_NetActivate();
extern void cGOBJ_Load();
extern void cGOBJ_Init();
extern void cGOBJ_ProcessMessage();
extern void cGOBJ_HandleMessage();
extern void HudTracker_Draw();
extern void cIE_GOBJ_NextFrame();
extern void cIE_GOBJ_dtor();
void * const D_004E05A0[72] = { (void*)0x0, (void*)0x0, (void*)cIE_GOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cIE_GOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cIE_GOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)HudTracker_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern void cInterfaceElement_Destroy(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9B20* cPROJECTED_GOBJ_dtor(G9B20* self, short del)
{
    if (self) {
        self->vt = D_004E0240;
        if (self) {
            self->vt = ((char*)D_004E05A0);
            cInterfaceElement_Destroy(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E93E0 */

/* merge_units: begin func_003E9460 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V3E9460;
typedef struct { char mtx[0x110]; } Cam3E9460;
typedef struct { char p0[0x1F0]; Cam3E9460 cams[1]; } W3E9460;
typedef struct { char p0[0x60]; int h; char p64[0xC]; V3E9460 dir; } S3E9460;
extern void cXViewport_GetScreenVert(V3E9460* out, void* m, V3E9460* v);
extern void cInterfaceElement_SetLocation(int h, V3E9460* v);
extern W3E9460 g_Video;
extern int D_00538C60;
extern char D_0055A290[];
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
void func_003E9460(S3E9460* s)
{
    V3E9460 v;
    V3E9460 t;
    { V3E9460* d; __int128 w; V3E9460* q; V3E9460* o; char* m; V3E9460* p; d = &v;q = &s->dir; w = VLoadF(q); m = D_0055A290;o = &v;p = &v; VStoreF(d, w);
        asm {
            lqc2 vf8, 0x0(p)
            lqc2 vf4, 0x0(m)
            lqc2 vf5, 0x10(m)
            lqc2 vf6, 0x20(m)
            lqc2 vf7, 0x30(m)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(o)
        }
    }
    cXViewport_GetScreenVert(&t, g_Video.cams[D_00538C60].mtx, &v);
    { V3E9460* x = &v; V3E9460* d = &v; V3E9460* q = &t; VCopyF(d, q); }
    { float z = v.z; if (z < 0.0f) v.z = -z; }
    cInterfaceElement_SetLocation(s->h, &v);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003E9460 */
