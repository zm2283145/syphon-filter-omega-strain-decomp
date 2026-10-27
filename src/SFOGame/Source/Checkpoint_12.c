/*
 * SFOGame/Source/Checkpoint: 3 files, 0022EBA0-0022ECA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022EBA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                         
int cGOBJ_dtor(...);                            
int operator_delete(...);                          
extern char D_004A6698;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
extern "C" void cGOBJ_Activate();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cCheckpoint_HandleMessage();
extern "C" void cCheckpoint_getSOBJClassId();
extern "C" void cCheckpoint_ScriptHandleMessage();
extern "C" void cCheckpoint_Init();
extern "C" void cCheckpoint_Load();
extern "C" void cCheckpoint_NextFrame();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
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
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
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
extern "C" void cGOBJ_Deactivate();
extern "C" void cGOBJ_NetDeactivate();
extern "C" void cGOBJ_NetActivate();
extern "C" void cGOBJ_Render();
extern "C" void cGOBJ_ProcessMessage();
extern void * const D_004DB8F0[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * cCheckpoint_dtor(char * arg0, long long arg1) {
    int temp_s2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004DB8F0));
        temp_s2 = F_(arg0, 0x70, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, temp_s2, &D_004A6698, 0x38);
            }
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DB8F0[68] = { (void*)0x0, (void*)0x0, (void*)cCheckpoint_dtor, (void*)cCheckpoint_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cCheckpoint_getSOBJClassId, (void*)cCheckpoint_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cCheckpoint_Init, (void*)cCheckpoint_Load, (void*)cCheckpoint_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
static inline void merge_flush_func_0022EBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EBA0 */

/* merge_units: begin func_0022ECA0 */
#pragma push /* merge_units */
#include "Checkpoint_types.h"

typedef struct cCheckpoint {
    void* vtable;
    char pad[0x5C];
    int unk60;
    int unk64;
    char pad2[8];
    int unk70;
} cCheckpoint;

extern char D_004F7980[];
#if 0 /* merge_units */
extern char D_004DB8F0[]; /* cCheckpoint vtable */
#endif /* merge_units */
#define D_004DB8F0 ((char*)&D_004DB8F0) /* merge_units */

extern void cGOBJ_ctor(cCheckpoint* self, int* handle, int flags, const char* name);

/* cCheckpoint constructor. */
cCheckpoint* cCheckpoint_ctor(cCheckpoint* self) {
    int handle = -1;
    cGOBJ_ctor(self, &handle, 0, D_004F7980);
    self->vtable = D_004DB8F0;
    self->unk60 = 100;
    self->unk64 = 100;
    self->unk70 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022ECA0(void) {}
#undef D_004DB8F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022ECA0 */

/* merge_units: begin func_0022ED00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * SetCheckpointFont script native and its setter.
 */


extern unsigned char D_004F7960; /* current checkpoint font index */
extern void Checkpoint_SetFont(int font);

/* SetCheckpointFont(font) */
int Script_SetCheckpointFont(CheckpointScriptArg* args) {
    Checkpoint_SetFont(args[0].u8);
    return 0;
}

void Checkpoint_SetFont(int font) {
    D_004F7960 = font;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022ED00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022ED00 */
