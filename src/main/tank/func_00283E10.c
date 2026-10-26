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
void Object_HandleMessage();
void GObj_GetID();
void Object_GetAttachedOrSelf();
void cGOBJ_IsNetworked();
void cSystem_SendCreated();
void cNode_v06();
void cNode_v07();
void cSystem_NetEnable();
void cSystem_NetDisable();
void cSystem_IsDeliverable();
void cTank_v0B();
void cTank_v0C();
void cNode_v0D();
void cGOBJ_Init();
void cGOBJ_Load();
void cTank_v10();
void Actor_BasePreLogic();
void Actor_BaseWorldUpdate();
void Actor_VirtualNop();
void cNode_v14();
void Object_Activate();
void Object_Deactivate();
void Node_SetFlag2C();
void Node_ClearFlag2C();
void Node_GetFlag2C();
void cGOBJ_HasHeadset();
void cGOBJ_SetStatus();
void cGOBJ_GetStatus();
void cGOBJ_IsGeneratorCreated();
void cGOBJ_GetChildList_void_2();
void cGOBJ_GetChildList_void();
void cGOBJ_GetBBox();
void cGOBJ_ScaleBBox();
void Object_AttachTransform();
void Player_GetActiveWeapon();
void cNode_v24();
void cNode_v25();
void cNode_v26();
void cNode_v27();
void cNode_v28();
void cNode_v29();
void cNode_v2A();
void cNode_v2B();
void cGOBJ_GetTargetPriority();
void cGOBJ_GetLosPosition();
void Object_GetEye();
void cGOBJ_GetMovementState();
void func_00140E90();
void cGOBJ_GetSubTargetAimAdjust();
void cGOBJ_GetNumSubTargets();
void cGOBJ_IsAimed();
void Node_GetWorldMatrix();
void cGOBJ_v35();
void Node_GetLightRefPoint();
void PathObj_GetPosition();
void Node_GetComponentMatrix();
void cGOBJ_v39();
void cNode_v3A();
void GObj_GetWorldMatrix();
void cGOBJ_GetFloorPlane();
void cGOBJ_InitNetwork();
void Actor_ApplyContactDamage();
void cGOBJ_CheckBullet();
void GObj_GetLifeState();
void Controller_DeathNotice();
void* const cTank_vtable[68] = {
    0, 0, (void*)cTank_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cTank_v0B, (void*)cTank_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cTank_v10, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice
};
}
typedef struct { char pad[0x24]; TankObj* obj; char id[4]; } Spawner_3E10;
extern "C" {
extern char D_004A93D0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Script_ReadU32(void* p);
void cGOBJ_ctor(void* p, void* id, int a, int* b);
void cTank_NetUnpack(TankObj* o);
}
extern "C" void cNetCreateTankMsg_Apply(Spawner_3E10* s, int arg)
{
    TankObj* p;
    Script_ReadU32(s->id);
    {
        AllocGuard g;
        p = (TankObj*)Mem_Alloc(0, 0x78, D_004A93D0, 0x305);
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