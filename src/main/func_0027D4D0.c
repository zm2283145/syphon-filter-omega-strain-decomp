#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cCollisionModelList_Game_dtor(char * , int);                         
int cCameraShake_dtor(char * , int);                         
int cSplinedMotion_Scalar_dtor_void(char * , int);                         
int func_0017ED20(char * , int);                         
int cSplinedMotion_Vector_dtor(char * , int);                         
int cSplinedMotion_QuaternionLERP_1_dtor(char * , int);                         
int cCollisionSystem_cBox_dtor_void_2(char * , int);                         
int cGameCameraCollisionRoutine_dtor(char * , int);                         
int cCAMERA_GOBJ_dtor(char **, int);                           
int operator_delete(char **);                            
extern char D_004DA580;
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void PlayerCamera_PreUpdate();
extern void cPlayerCamera_UpdateMotion();
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
extern void cGameCamera_getSOBJClassId();
extern void cGameCamera_ScriptHandleMessage();
extern void cCAMERA_GOBJ_Init();
extern void cCAMERA_GOBJ_Load();
extern void cGameCamera_SetRotation();
extern void cPlayerCamera_CriticalUpdateMotion();
extern void cPlayerCamera_CriticalNextFrame();
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
extern void cGOBJ_SetTransform();
extern void cGOBJ_Deactivate();
extern void cGOBJ_NetDeactivate();
extern void cGOBJ_NetActivate();
extern void cGOBJ_Render();
extern void cGOBJ_ProcessMessage();
extern void cGOBJ_HandleMessage();
extern void * const D_004DCDE0[];

char **cPlayerCamera_dtor(char **arg0, long long arg1) {
    if (arg0 != NULL) {
        *arg0 = &(*(char*)D_004DCDE0);
        if (arg0 != NULL) {
            *arg0 = &D_004DA580;
            cCollisionModelList_Game_dtor((char *)arg0 + 0xC70, -1);
            cCameraShake_dtor((char *)arg0 + 0xB20, -1);
            cSplinedMotion_Scalar_dtor_void((char *)arg0 + 0xA90, -1);
            func_0017ED20((char *)arg0 + 0x9D0, -1);
            func_0017ED20((char *)arg0 + 0x910, -1);
            func_0017ED20((char *)arg0 + 0x850, -1);
            cSplinedMotion_Vector_dtor((char *)arg0 + 0x780, -1);
            func_0017ED20((char *)arg0 + 0x6C0, -1);
            func_0017ED20((char *)arg0 + 0x600, -1);
            cSplinedMotion_Vector_dtor((char *)arg0 + 0x530, -1);
            cSplinedMotion_Vector_dtor((char *)arg0 + 0x460, -1);
            func_0017ED20((char *)arg0 + 0x3A0, -1);
            func_0017ED20((char *)arg0 + 0x2E0, -1);
            cSplinedMotion_Vector_dtor((char *)arg0 + 0x210, -1);
            cCollisionSystem_cBox_dtor_void_2((char *)arg0 + 0x1C0, -1);
            cSplinedMotion_QuaternionLERP_1_dtor((char *)arg0 + 0x170, -1);
            cCollisionSystem_cBox_dtor_void_2((char *)arg0 + 0x130, -1);
            cGameCameraCollisionRoutine_dtor((char *)arg0 + 0x70, -1);
            cCAMERA_GOBJ_dtor(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DCDE0[68] = { (void*)0x0, (void*)0x0, (void*)cPlayerCamera_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameCamera_getSOBJClassId, (void*)cGameCamera_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cCAMERA_GOBJ_Init, (void*)cCAMERA_GOBJ_Load, (void*)PlayerCamera_PreUpdate, (void*)cPlayerCamera_CriticalNextFrame, (void*)cPlayerCamera_UpdateMotion, (void*)cPlayerCamera_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGameCamera_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
