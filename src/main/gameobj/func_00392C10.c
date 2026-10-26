#include "types.h"
typedef struct { char pad[0x2EC0]; } F8Actor_pad;
typedef struct {
    void* vt;
    char pad4[0x5C];
    char x60[0x2E50 - 0x60];
    char x2E50[4];
    char x2E54[0x14];
    char x2E68[0x2EC0 - 0x2E68];
    char x2EC0[0x10];
    char x2ED0[0xF0];
    char x2FC0[4];
} F8Actor_392;
extern void Actor_ApplyContactDamage();
extern void Actor_BasePreLogic();
extern void Actor_VirtualNop();
extern void Actor_WorldUpdate();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void Skel_Bind();
extern void cGOBJ_v0B();
extern void cGOBJ_v0C();
extern void GObj_GetID();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void Actor_GetPosition();
extern void cGOBJ_GetFloorPlane();
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
extern void cSKM_GOBJ_GetBBox();
extern void cSKM_GOBJ_GetFloorPoly();
extern void Actor_v07();
extern void Actor_Deactivate();
extern void Actor_v06();
extern void ActorModel_Activate();
extern void ActorModel_Draw();
extern void Actor_LogicUpdate();
extern void cSKM_GOBJ_Init();
extern void GObj_GetWorldMatrix();
extern void cNode_v3A();
extern void cGOBJ_v39();
extern void Node_GetComponentMatrix();
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
extern void cNode_v24();
extern void Player_GetActiveWeapon();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const D_004DF740[];
extern void cSkaSystem_DetachParent(void* p);
extern void cSkaSystem_DetachChildren(void* p);
extern void cTreeNode_cSkaSystemPtr_dtor(void* p, int f);
extern void cSkaParams_dtor(void* p, int f);
extern void std_vector_deleter_cSkaPlaybackItem_dtor(void* p, int f);
extern void std_vector_deleter_cBone_dtor(void* p, int f);
extern void cMan_dtor(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void F8L3a(void* p) { if (p) std_vector_deleter_cSkaPlaybackItem_dtor(p, 0); }
static inline void F8L2a(void* p) { if (p) F8L3a(p); }
static inline void F8L1a(void* p) { if (p) F8L2a(p); }
static inline void F8L3b(void* p) { if (p) std_vector_deleter_cBone_dtor(p, 0); }
static inline void F8L2b(void* p) { if (p) F8L3b(p); }
static inline void F8L1b(void* p) { if (p) F8L2b(p); }
F8Actor_392* Actor_Destroy(F8Actor_392* a, short del)
{
    if (a) {
        a->vt = ((char*)D_004DF740);
        if (a->x2EC0) {
            cSkaSystem_DetachParent(a->x2EC0);
            cSkaSystem_DetachChildren(a->x2EC0);
            cTreeNode_cSkaSystemPtr_dtor(a->x2FC0, -1);
            cSkaParams_dtor(a->x2ED0, -1);
        }
        if (a->x2E50) {
            F8L1a(a->x2E68);
            F8L1b(a->x2E54);
        }
        cMan_dtor(a->x60, -1);
        cGOBJ_dtor(a, 0);
        if (del > 0)
            operator_delete(a);
    }
    return a;
}
void * const D_004DF740[72] = { (void*)0x0, (void*)0x0, (void*)Actor_Destroy, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)Actor_v06, (void*)Actor_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)cSKM_GOBJ_Init, (void*)Skel_Bind, (void*)Actor_LogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_WorldUpdate, (void*)Actor_VirtualNop, (void*)ActorModel_Draw, (void*)ActorModel_Activate, (void*)Actor_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cSKM_GOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)Actor_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)cSKM_GOBJ_GetFloorPoly, (void*)0x0, (void*)0x0, (void*)0x0 };
