#include "types.h"
extern void Actor_ApplyContactDamage();
extern void Actor_BaseLogicUpdate();
extern void Actor_BasePreLogic();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cNode_v0B();
extern void cNode_v0C();
extern void cNode_v0E();
extern void cNode_v0F();
extern void cNode_v34();
extern void cNode_v35();
extern void cNode_v36();
extern void cNode_v37();
extern void cNode_v38();
extern void cNode_v39();
extern void cNode_v3B();
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
extern void cNode_v3A();
extern void cNode_v2B();
extern void cNode_v2A();
extern void cNode_v29();
extern void cNode_v28();
extern void cNode_v27();
extern void cNode_v26();
extern void cNode_v25();
extern void cNode_v24();
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void cNode_v07();
extern void cNode_v06();
extern void cNode_v14();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const cNode_vtable[];
extern void std_vector_deleter_tNodeLink_clear(void* p);
extern void std_vector_deleter_tNodeLink_dtor(void* p, int flag);
extern void cGOBJ_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_C2F0;
#pragma opt_common_subs off
S_C2F0* cNode_dtor(S_C2F0* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)cNode_vtable);
        std_vector_deleter_tNodeLink_clear((char*)self + 0x68);
        m = (char*)self + 0x68;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_tNodeLink_dtor(m, 0);
            }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma opt_common_subs reset
void * const cNode_vtable[68] = { (void*)0x0, (void*)0x0, (void*)cNode_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cNode_v0B, (void*)cNode_v0C, (void*)cNode_v0D, (void*)cNode_v0E, (void*)cNode_v0F, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cNode_v34, (void*)cNode_v35, (void*)cNode_v36, (void*)cNode_v37, (void*)cNode_v38, (void*)cNode_v39, (void*)cNode_v3A, (void*)cNode_v3B, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
