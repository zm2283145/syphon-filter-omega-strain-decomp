#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A4550[];
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cPathedGOBJ_HandleMessage();
extern "C" void cPathedGOBJ_ScriptHandleMessage();
extern "C" void cPathedGOBJ_NextFrame();
extern "C" void cPathedGOBJ_NetActivate();
extern "C" void cPathedGOBJ_NetDeactivate();
extern "C" void cPathedGOBJ_getSOBJClassId();
extern "C" void cPathedGOBJ_Activate();
extern "C" void cPathedGOBJ_Deactivate();
extern "C" void cPathedGOBJ_InitNetwork();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void func_00140E90();
extern "C" void cGOBJ_GetHealthState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void cGOBJ_GetTargetPosition();
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
extern "C" void cGameGOBJ_GetBBox();
extern "C" void cGameGOBJ_GetTargetPriority();
extern "C" void cGameGOBJ_SetParent();
extern "C" void cGameGOBJ_Render();
extern "C" void cGameGOBJ_CriticalNextFrame();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void cGameGOBJ_NetEnable();
extern "C" void cGameGOBJ_NetDisable();
extern "C" void cGameGOBJ_GetCollisionModel();
extern "C" void cGameGOBJ_IsNetworked();
extern "C" void cGOBJ_GetTransform_ForFloorTravel();
extern "C" void cGOBJ_GetCameraCollisionReferencePoint();
extern "C" void cGOBJ_GetTransform_ForCameraTracking();
extern "C" void cGOBJ_GetTransform_ForTeleporting();
extern "C" void cGOBJ_GetCenterOfMass();
extern "C" void cGOBJ_GetActivationPoint();
extern "C" void cGOBJ_v35();
extern "C" void cGOBJ_GetMatrix();
extern "C" void cGOBJ_SetTranslation_ResetPhysics();
extern "C" void cGOBJ_SetRotation_ResetPhysics();
extern "C" void cGOBJ_SetTransform_ResetPhysics();
extern "C" void cGOBJ_ApplyTranslation();
extern "C" void cGOBJ_ApplyLocalRotation();
extern "C" void cGOBJ_ApplyTransform();
extern "C" void cGOBJ_SetTranslation();
extern "C" void cGOBJ_SetRotation();
extern "C" void cGOBJ_SetTransform();
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cGOBJ_ProcessMessage();
extern void * const D_004DB280[];
extern unsigned char g_IsMultiplayer;
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void cGameGOBJ_dtor(void* p, int flag);
void std_vector_deleter_cVector_dtor(void* p, int flag);
int func_00211DA0(void);
void std_vector_float_dtor(void* p, int flag);
void std_vector_deleter_cQuaternion_dtor(void* p, int flag);
void NetFreeObject(int a);
void cFileMan_dtor(void* p, int flag);
void operator_delete(void* p);
}
struct E_00219470 { char pad[0x48]; char m48[0xE4 - 0x48]; char mE4[4]; };
struct D_00219470s { char pad[0xC]; unsigned char c; };
struct S_00219470 { void* vt; char pad4[0x90]; char m94[0x10]; char mA4[0x10]; char mB4[0x1C]; D_00219470s* pD0; char padd4[0x10]; E_00219470* pE4; };
static inline void Free_00219470(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004A4550, line); }
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
                cFileMan_dtor(e->mE4, -1);
                cFileMan_dtor(e->m48, -1);
            }
            cMemMan_Deallocate(0, e, D_004A4550, 0x266);
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
void * const D_004DB280[72] = { (void*)0x0, (void*)0x0, (void*)cPathedGOBJ_dtor, (void*)cPathedGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGameGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cPathedGOBJ_NetActivate, (void*)cPathedGOBJ_NetDeactivate, (void*)cGameGOBJ_NetEnable, (void*)cGameGOBJ_NetDisable, (void*)cSystem_IsDeliverable, (void*)cPathedGOBJ_getSOBJClassId, (void*)cPathedGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cPathedGOBJ_NextFrame, (void*)cGameGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGameGOBJ_Render, (void*)cPathedGOBJ_Activate, (void*)cPathedGOBJ_Deactivate, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGameGOBJ_GetCollisionModel, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGameGOBJ_GetTargetPriority, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cPathedGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cGameGOBJ_SetParent, (void*)0x0, (void*)0x0, (void*)0x0 };
