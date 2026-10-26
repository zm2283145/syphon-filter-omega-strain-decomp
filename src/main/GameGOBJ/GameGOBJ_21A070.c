/*
 * main/GameGOBJ: range (2 files, 0021A070-0021A0D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021A070 */
#pragma push /* merge_units */
typedef struct { char pad[0x1F0]; char a; char b; } Sub0021A070;
typedef struct { void* vtable; char pad[0x5C]; unsigned char flag; char pad61[3]; Sub0021A070* sub; } Obj0021A070;
extern void cGameGOBJ_ctor(Obj0021A070* self, void* a1, void* a2, int kind);
extern void Actor_ApplyContactDamage();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_GetFlag2C();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cGameGOBJ_v0B();
extern void cGameGOBJ_v0C();
extern void GObj_GetID();
extern void cSystem_SendCreated();
extern void cSystem_IsDeliverable();
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
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_CheckBullet();
extern void cGameGOBJ_GetBounds();
extern void cGameGOBJ_v2F();
extern void cGameGOBJ_v42();
extern void cFacingGOBJ_Render();
extern void cFacingGOBJ_CriticalNextFrame();
extern void cFacingGOBJ_NextFrame();
extern void cGameGOBJ_Receive();
extern void cGameGOBJ_Disable();
extern void cGameGOBJ_Enable();
extern void cGameGOBJ_DeactivateWithPart();
extern void cGameGOBJ_ActivateWithPart();
extern void cGameGOBJ_v16();
extern void cGameGOBJ_v15();
extern void cGameGOBJ_v08();
extern void cGameGOBJ_v09();
extern void cGameGOBJ_GetModelCol();
extern void cGameGOBJ_v04();
extern void cFacingGOBJ_dtor();
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
extern void cGOBJ_Load();
extern void cGOBJ_Init();
extern void cNode_v0D();
void * const D_004DB3A0[72] = { (void*)0x0, (void*)0x0, (void*)cFacingGOBJ_dtor, (void*)cGameGOBJ_Receive, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGameGOBJ_v04, (void*)cSystem_SendCreated, (void*)cGameGOBJ_ActivateWithPart, (void*)cGameGOBJ_DeactivateWithPart, (void*)cGameGOBJ_v08, (void*)cGameGOBJ_v09, (void*)cSystem_IsDeliverable, (void*)cGameGOBJ_v0B, (void*)cGameGOBJ_v0C, (void*)cNode_v0D, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cFacingGOBJ_NextFrame, (void*)cFacingGOBJ_CriticalNextFrame, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cFacingGOBJ_Render, (void*)cGameGOBJ_v15, (void*)cGameGOBJ_v16, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBounds, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGameGOBJ_GetModelCol, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGameGOBJ_v2F, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)cGameGOBJ_v42, (void*)0x0, (void*)0x0, (void*)0x0 };
Obj0021A070* cGameGOBJ_CtorKind6(Obj0021A070* self, void* a1, void* a2)
{
    cGameGOBJ_ctor(self, a1, a2, 6);
    self->vtable = ((char*)D_004DB3A0);
    if (self->flag) {
        self->sub->a = 0;
        self->sub->b = 0;
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A070 */

/* merge_units: begin func_0021A0D0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* GObj_IdentityB(void*);
extern void Blast_Prepare(void* obj, int kind, float x, float y, float z, int flag, int a, int b, int c);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0], flag args[5]; returns 0. */
    int Script_CreateBlast_2(ScriptArg* args)
{
    int flag;
    volatile int kind;
    float fz, fy, fx;
    int x[1];
    int y[1];
    int z[1];
    flag = args[5].i != 0;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    Blast_Prepare(GObj_IdentityB(args[0].p), kind, fx, fy, fz, flag, 0, 0, 0);
    return 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A0D0 */
