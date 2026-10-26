#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_21AC80 { virtual void Destroy(int f); };
struct Obj_21AC80 { void* vt; char pad04[0x60]; VObj_21AC80* obj; char pad68[0xC]; char m74[0x10]; char m84[0x10]; };
extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGameGOBJ_v0B();
extern "C" void cGameGOBJ_v0C();
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
extern "C" void cGOBJ_ScaleBBox();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGameGOBJ_GetBounds();
extern "C" void cGameGOBJ_v2F();
extern "C" void cGameGOBJ_v42();
extern "C" void cGameGOBJ_Draw();
extern "C" void GObj_Tick();
extern "C" void cGameGOBJ_v10();
extern "C" void cGameGOBJ_Receive();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void cGameGOBJ_DeactivateWithPart();
extern "C" void cGameGOBJ_ActivateWithPart();
extern "C" void cGameGOBJ_v16();
extern "C" void cGameGOBJ_v15();
extern "C" void cGameGOBJ_v08();
extern "C" void cGameGOBJ_v09();
extern "C" void cGameGOBJ_GetModelCol();
extern "C" void cGameGOBJ_v04();
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
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cNode_v0D();
extern void * const D_004DB4C0[];
extern char D_004A4550[];
void Mem_Free(int pool, void* p, char* file, int line);
void std_vector_deleter_cSafePtr_cGOBJ_dtor(void* p, int f);
void std_vector_cGOBJPtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void L3_21AC80(void* p) { if (p) std_vector_deleter_cSafePtr_cGOBJ_dtor(p, 0); }
static inline void L2_21AC80(void* p) { if (p) L3_21AC80(p); }
static inline void L1_21AC80(void* p) { if (p) L2_21AC80(p); }
extern "C" Obj_21AC80* cGameGOBJ_dtor(Obj_21AC80* l, short flag)
{
    if (l) {
        VObj_21AC80* o;
        l->vt = ((char*)D_004DB4C0);
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            Mem_Free(0, o, D_004A4550, 0xFE);
        }
        L1_21AC80(l->m84);
        if (l->m74)
            std_vector_cGOBJPtr_dtor(l->m74, -1);
        cGOBJ_dtor(l, 0);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}
void * const D_004DB4C0[72] = { (void*)0x0, (void*)0x0, (void*)cGameGOBJ_dtor, (void*)cGameGOBJ_Receive, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGameGOBJ_v04, (void*)cSystem_SendCreated, (void*)cGameGOBJ_ActivateWithPart, (void*)cGameGOBJ_DeactivateWithPart, (void*)cGameGOBJ_v08, (void*)cGameGOBJ_v09, (void*)cSystem_IsDeliverable, (void*)cGameGOBJ_v0B, (void*)cGameGOBJ_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cGameGOBJ_v10, (void*)GObj_Tick, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cGameGOBJ_Draw, (void*)cGameGOBJ_v15, (void*)cGameGOBJ_v16, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBounds, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGameGOBJ_GetModelCol, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGameGOBJ_v2F, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)cGameGOBJ_v42, (void*)0x0, (void*)0x0, (void*)0x0 };
