/*
 * main/callback: 2 files, 003E93E0-003E9460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E93E0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9B20;
extern char D_004E0240[];
extern void Actor_ApplyContactDamage();
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
extern void cGOBJ_v0B();
extern void cGOBJ_v0C();
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
extern void HudBlip_Draw();
extern void GObj_GetWorldMatrix();
extern void cNode_v3A();
extern void cGOBJ_v39();
extern void Node_GetComponentMatrix();
extern void PathObj_GetPosition();
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
extern void Object_Deactivate();
extern void cNode_v07();
extern void cNode_v06();
extern void cGOBJ_Load();
extern void cGOBJ_Init();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void HudTracker_Draw();
extern void HudTracker_Update();
extern void HudLockTracker_Delete();
void * const D_004E05A0[72] = { (void*)0x0, (void*)0x0, (void*)HudLockTracker_Delete, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)HudTracker_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)HudBlip_Draw, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)HudTracker_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern void IeElement_Release(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9B20* HudCalloutTracker_dtor(G9B20* self, short del)
{
    if (self) {
        self->vt = D_004E0240;
        if (self) {
            self->vt = ((char*)D_004E05A0);
            IeElement_Release(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E93E0 */

/* merge_units: begin func_003E9460 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V3E9460;
typedef struct { char mtx[0x110]; } Cam3E9460;
typedef struct { char p0[0x1F0]; Cam3E9460 cams[1]; } W3E9460;
typedef struct { char p0[0x60]; int h; char p64[0xC]; V3E9460 dir; } S3E9460;
extern void Renderer_ProjectToScreen(V3E9460* out, void* m, V3E9460* v);
extern void IeElement_SetPosition(int h, V3E9460* v);
extern W3E9460 g_Video;
extern int D_00538C60;
extern char D_0055A290[];
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
void func_003E9460(S3E9460* s)
{
    V3E9460 v;
    V3E9460 t;
    { V3E9460* d; __int128 w; V3E9460* q; V3E9460* o; char* m; V3E9460* p; d = &v;q = &s->dir; w = VLoadF(q); m = D_0055A290;o = &v;p = &v; VStoreF(d, w);
        asm {
            lqc2 vf8, 0x0(p)
            lqc2 vf4, 0x0(m)
            lqc2 vf5, 0x10(m)
            lqc2 vf6, 0x20(m)
            lqc2 vf7, 0x30(m)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(o)
        }
    }
    Renderer_ProjectToScreen(&t, g_Video.cams[D_00538C60].mtx, &v);
    { V3E9460* x = &v; V3E9460* d = &v; V3E9460* q = &t; VCopyF(d, q); }
    { float z = v.z; if (z < 0.0f) v.z = -z; }
    IeElement_SetPosition(s->h, &v);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003E9460 */
