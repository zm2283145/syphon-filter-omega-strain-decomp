#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
#include "tank_obj_init_vt.h"
extern "C" {
void cTank_dtor();
void cGOBJ_HandleMessage();
void cSystem_ScriptGetObjectId();
void cGOBJ_ScriptGetRealObj();
void cGOBJ_IsNetworked();
void cSystem_SendCreated();
void cGOBJ_NetActivate();
void cGOBJ_NetDeactivate();
void cSystem_NetEnable();
void cSystem_NetDisable();
void cSystem_IsDeliverable();
void cTank_getSOBJClassId();
void cTank_ScriptHandleMessage();
void cGOBJ_ProcessMessage();
void cGOBJ_Init();
void cGOBJ_Load();
void cTank_NextFrame();
void cGOBJ_CriticalNextFrame();
void cGOBJ_UpdateMotion();
void cGOBJ_CriticalUpdateMotion();
void cGOBJ_Render();
void cGOBJ_Activate();
void cGOBJ_Deactivate();
void cGOBJ_Enable();
void cGOBJ_Disable();
void cGOBJ_IsEnabled();
void cGOBJ_HasHeadset();
void cGOBJ_SetStatus();
void cGOBJ_GetStatus();
void cGOBJ_IsGeneratorCreated();
void cGOBJ_GetChildList_void_2();
void cGOBJ_GetChildList_void();
void cGOBJ_GetBBox();
void cGOBJ_ScaleBBox();
void cGOBJ_CreateXform();
void cGOBJ_SetTransform();
void cGOBJ_SetRotation();
void cGOBJ_SetTranslation();
void cGOBJ_ApplyTransform();
void cGOBJ_ApplyLocalRotation();
void cGOBJ_ApplyTranslation();
void cGOBJ_SetTransform_ResetPhysics();
void cGOBJ_SetRotation_ResetPhysics();
void cGOBJ_SetTranslation_ResetPhysics();
void cGOBJ_GetTargetPriority();
void cGOBJ_GetLosPosition();
void cGOBJ_GetTargetPosition();
void cGOBJ_GetMovementState();
void func_00140E90();
void cGOBJ_GetSubTargetAimAdjust();
void cGOBJ_GetNumSubTargets();
void cGOBJ_IsAimed();
void cGOBJ_GetMatrix();
void cGOBJ_v35();
void cGOBJ_GetActivationPoint();
void cGOBJ_GetCenterOfMass();
void cGOBJ_GetTransform_ForTeleporting();
void cGOBJ_GetTransform_ForCameraTracking();
void cGOBJ_GetCameraCollisionReferencePoint();
void cGOBJ_GetTransform_ForFloorTravel();
void cGOBJ_GetFloorPlane();
void cGOBJ_InitNetwork();
void cGOBJ_ReceiveDamage();
void cGOBJ_CheckBullet();
void cGOBJ_GetHealthState();
void cGOBJ_Die();
void* const cTank_vtable[68] = {
    0, 0, (void*)cTank_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cTank_getSOBJClassId, (void*)cTank_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cTank_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die
};
}
typedef struct { char pad[0x24]; TankObj* obj; char id[4]; } Spawner_3E10;
extern "C" {
extern char D_004A93D0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cNetMsg_GetID(void* p);
void cGOBJ_ctor(void* p, void* id, int a, int* b);
void cTank_NetUnpack(TankObj* o);
}
extern "C" void cNetCreateTankMsg_UnpackAndProcess(Spawner_3E10* s, int arg)
{
    TankObj* p;
    cNetMsg_GetID(s->id);
    {
        AllocGuard g;
        p = (TankObj*)cMemMan_Allocate(0, 0x78, D_004A93D0, 0x305);
    }
    if (p) {
        int z[1];
        z[0] = 0;
        cGOBJ_ctor(p, s->id, 0, z);
        TankObj_Init(p, arg);
    }
    s->obj = p;
    cTank_NetUnpack(s->obj);
}