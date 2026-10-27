/*
 * Libs/SFOLib/Source/gobj: 3 files, 003CEF20-003CF190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CEF20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CEF20 { virtual int v0(...); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(...); };
extern "C" {
int cMemMan_Deallocate(...);                     
int cSystemContainer_dtor(...);                         
int operator_delete(...);                          
extern char D_004BD228;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_NextFrame();
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
extern "C" void cGOBJ_getSOBJClassId();
extern "C" void cGOBJ_ScriptHandleMessage();
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
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cGOBJ_ProcessMessage();
extern "C" void cGOBJ_HandleMessage();
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
                cMemMan_Deallocate(0, temp_s2, &D_004BD228, 0x174);
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
            cMemMan_Deallocate(0, temp_s2_2, &D_004BD228, 0x210);
            }
            arg0->f54 = NULL;
        }
        cSystemContainer_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}
void * const D_004DFF50[68] = { (void*)0x0, (void*)0x0, (void*)cGOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
static inline void merge_flush_func_003CEF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CEF20 */

/* merge_units: begin func_003CF0E0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ constructor.
 */

#include "gobj_types.h"

#if 0 /* merge_units */
extern char D_004DFF50[];   /* cGOBJ vtable */
#endif /* merge_units */
#define D_004DFF50 ((char*)&D_004DFF50) /* merge_units */

extern void cSystemContainer_ctor_cObjectIdR(cGOBJ* self, int* desc);

cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3) {
    cSystemContainer_ctor_cObjectIdR(self, desc);
    self->vtable = D_004DFF50;
    self->unk2C = 1;
    self->unk2D = 0;
    self->unk2E = 0;
    self->unk2F = 0;
    self->unk30 = -1;
    self->unk38 = 128;
    self->unk3C = 0;
    self->unk40 = 0;
    self->darkness = 0;
    self->unk48 = 0;
    self->unk49 = a2;
    self->unk4C = *a3;
    self->unk50 = 0;
    self->unk54 = 0;
    self->attached = 0;
    self->unk5C = 0;
    self->unk10 = *desc;
    return self;
}
#undef D_004DFF50 /* merge_units */
static inline void merge_flush_func_003CF0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF0E0 */

/* merge_units: begin func_003CF190 */
#pragma push /* merge_units */
typedef struct C3FtNode { struct C3FtNode* left; struct C3FtNode* right; int pad; int key; } C3FtNode;
typedef struct { int pad; C3FtNode* root; } C3FtTree;
extern C3FtNode* FrameTree_Insert(C3FtTree* t, C3FtNode* parent, unsigned char left, unsigned char leftmost, int* key);
void FrameTree_Find(C3FtNode** out, C3FtTree* t, int* key)
{
    C3FtNode* parent = (C3FtNode*)&t->root;
    C3FtNode* n = t->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (n != 0) {
        parent = n;
        if (*key < n->key) {
            n = n->left;
            left = 1;
        } else {
            n = n->right;
            left = 0;
            leftmost = 0;
        }
    }
    *out = FrameTree_Insert(t, parent, left, leftmost, key);
}
static inline void merge_flush_func_003CF190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF190 */
