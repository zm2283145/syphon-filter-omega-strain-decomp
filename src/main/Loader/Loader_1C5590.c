#pragma cplusplus on
#include "types.h"
#include "gobj_flag_dtor.h"
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void GObj_GetID();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void Object_GetEye();
extern "C" void cGOBJ_GetLosPosition();
extern "C" void cGOBJ_HasHeadset();
extern "C" void cGOBJ_SetStatus();
extern "C" void cGOBJ_GetStatus();
extern "C" void cGOBJ_GetChildList_void();
extern "C" void cGOBJ_GetChildList_void_2();
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
extern "C" void ParticleGob_v08();
extern "C" void ParticleGob_v09();
extern "C" void ParticleGob_ScaleBBox();
extern "C" void ParticleGob_Disable();
extern "C" void ParticleGob_Enable();
extern "C" void ParticleGob_Update();
extern "C" void cPARTICLE_GOBJ_getSOBJClassId();
extern "C" void cPARTICLE_GOBJ_ScriptHandleMessage();
extern "C" void ParticleGob_OnAbsent();
extern "C" void ParticleGob_OnPresent();
extern "C" void ParticleGob_GetBounds();
extern "C" void ParticleGob_Draw();
extern "C" void ParticleGob_RequestPar();
extern "C" void ParticleGob_ResetTime();
extern "C" void GObj_GetWorldMatrix();
extern "C" void cNode_v3A();
extern "C" void cGOBJ_v39();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void cGOBJ_v35();
extern "C" void Node_GetWorldMatrix();
extern "C" void cNode_v2B();
extern "C" void cNode_v2A();
extern "C" void cNode_v29();
extern "C" void cNode_v28();
extern "C" void cNode_v27();
extern "C" void cNode_v26();
extern "C" void cNode_v25();
extern "C" void cNode_v24();
extern "C" void Player_GetActiveWeapon();
extern "C" void cNode_v07();
extern "C" void cNode_v06();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern void * const D_004DAA10[];
extern "C" char D_004DF860[];
extern "C" GobjFlagObj* ParticleGob_dtor(GobjFlagObj* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAA10);
        if (self) {
            self->vtable = D_004DF860;
            GobjFlag_Release(self);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAA10[68] = { (void*)0x0, (void*)0x0, (void*)ParticleGob_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)ParticleGob_v08, (void*)ParticleGob_v09, (void*)cSystem_IsDeliverable, (void*)cPARTICLE_GOBJ_getSOBJClassId, (void*)cPARTICLE_GOBJ_ScriptHandleMessage, (void*)cNode_v0D, (void*)ParticleGob_ResetTime, (void*)ParticleGob_RequestPar, (void*)ParticleGob_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)ParticleGob_Draw, (void*)ParticleGob_OnPresent, (void*)ParticleGob_OnAbsent, (void*)ParticleGob_Enable, (void*)ParticleGob_Disable, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)ParticleGob_GetBounds, (void*)ParticleGob_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
