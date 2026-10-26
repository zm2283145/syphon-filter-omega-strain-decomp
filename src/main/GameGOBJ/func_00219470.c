#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A4550[];
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void PathObj_Receive();
extern "C" void PathObj_ScriptFilter();
extern "C" void PathObj_Update();
extern "C" void cPathedGOBJ_v06();
extern "C" void cPathedGOBJ_v07();
extern "C" void cPathedGOBJ_v0B();
extern "C" void cPathedGOBJ_v15();
extern "C" void cPathedGOBJ_v16();
extern "C" void cPathedGOBJ_v3D();
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
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGameGOBJ_GetBounds();
extern "C" void cGameGOBJ_v2F();
extern "C" void cGameGOBJ_v42();
extern "C" void cGameGOBJ_Draw();
extern "C" void GObj_Tick();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
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
extern void * const D_004DB280[];
extern unsigned char g_IsMultiplayer;
void Mem_Free(int heap, void* p, char* file, int line);
void cGameGOBJ_dtor(void* p, int flag);
void std_vector_deleter_cVector_dtor(void* p, int flag);
int func_00211DA0(void);
void std_vector_float_dtor(void* p, int flag);
void std_vector_deleter_cQuaternion_dtor(void* p, int flag);
void NetFreeObject(int a);
void FileMan_Release(void* p, int flag);
void operator_delete(void* p);
}
struct E_00219470 { char pad[0x48]; char m48[0xE4 - 0x48]; char mE4[4]; };
struct D_00219470s { char pad[0xC]; unsigned char c; };
struct S_00219470 { void* vt; char pad4[0x90]; char m94[0x10]; char mA4[0x10]; char mB4[0x1C]; D_00219470s* pD0; char padd4[0x10]; E_00219470* pE4; };
static inline void Free_00219470(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A4550, line); }
static inline void M3_0021C090(void* m) { if (m) { if (m) { if (m) std_vector_deleter_cQuaternion_dtor(m, 0); } } }
static inline void M3_001810D0(void* m) { if (m) { if (m) { if (m) std_vector_deleter_cVector_dtor(m, 0); } } }
extern "C" S_00219470* cPathedGOBJ_dtor(S_00219470* self, short flag)
{
    if (self) {
        void* m;
        E_00219470* e;
        D_00219470s* d;
        self->vt = ((char*)D_004DB280);
        e = self->pE4;
        if (e) {
            AllocGuard g;
            if (e) {
                FileMan_Release(e->mE4, -1);
                FileMan_Release(e->m48, -1);
            }
            Mem_Free(0, e, D_004A4550, 0x266);
        }
        if (g_IsMultiplayer) {
            d = self->pD0;
            if (d) {
                if (d->c) NetFreeObject(func_00211DA0());
                else Free_00219470(d, 0xB83);
                self->pD0 = 0;
            }
        } else {
            d = self->pD0;
            if (d) {
                Free_00219470(d, 0x270);
                self->pD0 = 0;
            }
        }
        m = self->mB4; if (m) std_vector_float_dtor(m, -1);
        M3_0021C090(self->mA4);
        M3_001810D0(self->m94);
        cGameGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB280[72] = { (void*)0x0, (void*)0x0, (void*)cPathedGOBJ_dtor, (void*)PathObj_Receive, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGameGOBJ_v04, (void*)cSystem_SendCreated, (void*)cPathedGOBJ_v06, (void*)cPathedGOBJ_v07, (void*)cGameGOBJ_v08, (void*)cGameGOBJ_v09, (void*)cSystem_IsDeliverable, (void*)cPathedGOBJ_v0B, (void*)PathObj_ScriptFilter, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)PathObj_Update, (void*)GObj_Tick, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cGameGOBJ_Draw, (void*)cPathedGOBJ_v15, (void*)cPathedGOBJ_v16, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBounds, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGameGOBJ_GetModelCol, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGameGOBJ_v2F, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cPathedGOBJ_v3D, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)cGameGOBJ_v42, (void*)0x0, (void*)0x0, (void*)0x0 };
