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
extern void Actor_ApplyContactDamage();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void PlayerCamera_PreUpdate();
extern void PlayerCamera_Update();
extern void GObj_GetID();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cGOBJ_GetFloorPlane();
extern void cGOBJ_GetBBox();
extern void func_00140E90();
extern void GObj_GetLifeState();
extern void cGOBJ_IsGeneratorCreated();
extern void Object_GetEye();
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
extern void PlayerCamera_v13();
extern void PlayerCamera_v11();
extern void GObj_GetWorldMatrix();
extern void cNode_v3A();
extern void cGOBJ_v39();
extern void Node_GetComponentMatrix();
extern void PathObj_GetPosition();
extern void Node_GetLightRefPoint();
extern void cGOBJ_v35();
extern void Node_GetWorldMatrix();
extern void cNode_v2B();
extern void cNode_v2A();
extern void cNode_v29();
extern void cNode_v28();
extern void cNode_v27();
extern void cNode_v26();
extern void cNode_v25();
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void cNode_v07();
extern void cNode_v06();
extern void cNode_v14();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const D_004DCDE0[];

char **PlayerCamera_dtor(char **arg0, long long arg1) {
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
void * const D_004DCDE0[68] = { (void*)0x0, (void*)0x0, (void*)PlayerCamera_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameCamera_getSOBJClassId, (void*)cGameCamera_ScriptHandleMessage, (void*)cNode_v0D, (void*)cCAMERA_GOBJ_Init, (void*)cCAMERA_GOBJ_Load, (void*)PlayerCamera_PreUpdate, (void*)PlayerCamera_v11, (void*)PlayerCamera_Update, (void*)PlayerCamera_v13, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cGameCamera_SetRotation, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
