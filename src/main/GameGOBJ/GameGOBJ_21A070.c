/*
 * main/GameGOBJ: range (2 files, 0021A070-0021A0D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021A070 */
#pragma push /* merge_units */
typedef struct { char pad[0x1F0]; char a; char b; } Sub0021A070;
typedef struct { void* vtable; char pad[0x5C]; unsigned char flag; char pad61[3]; Sub0021A070* sub; } Obj0021A070;
extern void cGameGOBJ_ctor(Obj0021A070* self, void* a1, void* a2, int kind);
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cGameGOBJ_getSOBJClassId();
extern void cGameGOBJ_ScriptHandleMessage();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cSystem_IsDeliverable();
extern void cGOBJ_GetFloorPlane();
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
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_CheckBullet();
extern void cGameGOBJ_GetBBox();
extern void cGameGOBJ_GetTargetPriority();
extern void cGameGOBJ_SetParent();
extern void cFacingGOBJ_Render();
extern void cFacingGOBJ_CriticalNextFrame();
extern void cFacingGOBJ_NextFrame();
extern void cGameGOBJ_HandleMessage();
extern void cGameGOBJ_Disable();
extern void cGameGOBJ_Enable();
extern void cGameGOBJ_NetDeactivate();
extern void cGameGOBJ_NetActivate();
extern void cGameGOBJ_Deactivate();
extern void cGameGOBJ_Activate();
extern void cGameGOBJ_NetEnable();
extern void cGameGOBJ_NetDisable();
extern void cGameGOBJ_GetCollisionModel();
extern void cGameGOBJ_IsNetworked();
extern void cFacingGOBJ_dtor();
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
extern void cGOBJ_Load();
extern void cGOBJ_Init();
extern void cGOBJ_ProcessMessage();
void * const D_004DB3A0[72] = { (void*)0x0, (void*)0x0, (void*)cFacingGOBJ_dtor, (void*)cGameGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGameGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGameGOBJ_NetActivate, (void*)cGameGOBJ_NetDeactivate, (void*)cGameGOBJ_NetEnable, (void*)cGameGOBJ_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameGOBJ_getSOBJClassId, (void*)cGameGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cFacingGOBJ_NextFrame, (void*)cFacingGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cFacingGOBJ_Render, (void*)cGameGOBJ_Activate, (void*)cGameGOBJ_Deactivate, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGameGOBJ_GetCollisionModel, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGameGOBJ_GetTargetPriority, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cGameGOBJ_SetParent, (void*)0x0, (void*)0x0, (void*)0x0 };
Obj0021A070* cFacingGOBJ_ctor(Obj0021A070* self, void* a1, void* a2)
{
    cGameGOBJ_ctor(self, a1, a2, 6);
    self->vtable = ((char*)D_004DB3A0);
    if (self->flag) {
        self->sub->a = 0;
        self->sub->b = 0;
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A070 */

/* merge_units: begin func_0021A0D0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* cGOBJ_SOBJ_convert(void*);
extern void Blast_Prepare(void* obj, int kind, float x, float y, float z, int flag, int a, int b, int c);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0], flag args[5]; returns 0. */
    int Script_CreateBlast_2(ScriptArg* args)
{
    int flag;
    volatile int kind;
    float fz, fy, fx;
    int x[1];
    int y[1];
    int z[1];
    flag = args[5].i != 0;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    Blast_Prepare(cGOBJ_SOBJ_convert(args[0].p), kind, fx, fy, fz, flag, 0, 0, 0);
    return 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A0D0 */
