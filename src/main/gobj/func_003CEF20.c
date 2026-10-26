#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CEF20 { virtual int v0(...); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(...); };
extern "C" {
int Mem_Free(...);                     
int ListReceiver_Dtor(...);                         
int operator_delete(...);                          
extern char D_004BD228;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseLogicUpdate();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGOBJ_v0B();
extern "C" void cGOBJ_v0C();
extern "C" void GObj_GetID();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
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
extern "C" void cGOBJ_ScaleBBox();
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
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
extern "C" void Object_Deactivate();
extern "C" void cNode_v07();
extern "C" void cNode_v06();
extern "C" void cNode_v14();
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern void * const D_004DFF50[];
extern unsigned char g_ProfileLockEnabled;
typedef struct { int f0; char p4[68]; unsigned char f48; char p49[7]; int f50; int f54; int f58; } PS0_003CEF20;
}
extern "C" char * cGOBJ_dtor(PS0_003CEF20 *arg0, long long arg1) {
    void **temp_a0;
    void **temp_s2;
    void **temp_s2_2;

    if (arg0 != NULL) {
        arg0->f0 = (int)(&(*(char*)D_004DFF50));
        temp_s2 = (void **)(arg0->f50);
        if (temp_s2 != NULL) {
            if (arg0->f48 != 0) {
                {
                    AllocGuard g;
                ((VC003CEF20 *)(temp_s2))->v0(-1);
                Mem_Free(0, temp_s2, &D_004BD228, 0x174);
                }
                arg0->f48 = 0U;
            }
            arg0->f50 = NULL;
        }
        temp_a0 = (void **)(arg0->f58);
        if (temp_a0 != NULL) {
            ((VC003CEF20 *)(temp_a0))->v33(0);
            arg0->f58 = NULL;
        }
        temp_s2_2 = (void **)(arg0->f54);
        if (temp_s2_2 != NULL) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2_2, &D_004BD228, 0x210);
            }
            arg0->f54 = NULL;
        }
        ListReceiver_Dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}
void * const D_004DFF50[68] = { (void*)0x0, (void*)0x0, (void*)cGOBJ_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
