/*
 * main/hud: 4 files, 00260ED0-00261090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00260ED0 */
#pragma push /* merge_units */
#include "types.h"
#pragma global_optimizer off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { float v; float pad[3]; } E_0ED0;
extern E_0ED0 D_004F8190[], D_004F8194[], D_004F8198[], D_004F819C[];
extern unsigned char D_004F8230;
static inline void SetNVLockColor_0ED0(int idx, float f, int b, int g, int r)
{
    D_004F8230 = 1;
    if (idx < 10) {
        if (f > 0.0f) D_004F8190[idx].v = f;
        D_004F8194[idx].v = r;
        D_004F8198[idx].v = g;
        D_004F819C[idx].v = b;
    }
}
int Script_SetNVLockColor(ScriptArg* args)
{
    int b[1];
    int g[1];
    int r[1];
    int f[1];
    int i[1];
    b[0] = args[4].i;
    g[0] = args[3].i;
    r[0] = args[2].i;
    f[0] = args[1].i;
    i[0] = args[0].i;
    SetNVLockColor_0ED0(*(int*)i, *(float*)f, *(int*)b, *(int*)g, *(int*)r);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260ED0 */

/* merge_units: begin func_00260FB0 */
#pragma push /* merge_units */
typedef struct { float v; float pad[3]; } B5fEnt;
extern B5fEnt D_004F80F0[];
extern B5fEnt D_004F80F4[];
extern B5fEnt D_004F80F8[];
extern B5fEnt D_004F80FC[];
#define B5F_ARG(var, i) (*(int*)&(var) = args[i])
int Script_SetLockColor(int* args) {
    int b;
    int g;
    int r;
    float a;
    int idx;
    int bb, gg, rr, ii;
    float aa;
    B5F_ARG(b, 4);
    bb = b;
    B5F_ARG(g, 3);
    gg = g;
    B5F_ARG(r, 2);
    rr = r;
    B5F_ARG(a, 1);
    aa = a;
    B5F_ARG(idx, 0);
    ii = idx;
    if (ii < 10) {
        if (!(aa <= 0.0f)) {
            D_004F80F0[ii].v = aa;
        }
        D_004F80F4[ii].v = rr;
        D_004F80F8[ii].v = gg;
        D_004F80FC[ii].v = bb;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260FB0 */

/* merge_units: begin func_00261080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* LockSetting_ctor(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00261080 */

/* merge_units: begin func_00261090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_ApplyContactDamage();
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
extern "C" void HudBlip_Draw();
extern "C" void HudBlip_Place();
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
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern "C" void HudTracker_Update();
extern void * const D_004DC810[];
void* HudLockTracker_Delete(void* self, short deleteFlag);
}
extern "C" VtableObject* HudBlip_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC810);
        HudLockTracker_Delete(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC810[72] = { (void*)0x0, (void*)0x0, (void*)HudBlip_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)HudTracker_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)HudBlip_Draw, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)HudBlip_Place, (void*)0x0, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00261090 */
