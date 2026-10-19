#pragma cplusplus on
#include "types.h"
#include "gobj_flag_dtor.h"
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void ParticleGob_v08();
extern "C" void ParticleGob_v09();
extern "C" void ParticleGob_ScaleBBox();
extern "C" void ParticleGob_Disable();
extern "C" void ParticleGob_Enable();
extern "C" void ParticleGob_Update();
extern "C" void func_003926A0();
extern "C" void func_003926B0();
extern "C" void ParticleGob_OnAbsent();
extern "C" void ParticleGob_OnPresent();
extern "C" void ParticleGob_GetBounds();
extern "C" void ParticleGob_Draw();
extern "C" void ParticleGob_RequestPar();
extern "C" void ParticleGob_ResetTime();
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
extern "C" void cNode_v07();
extern "C" void cNode_v06();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern void * const D_004DAA10[];
extern "C" char D_004DF860[];
extern "C" GobjFlagObj* ParticleGob_dtor(GobjFlagObj* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAA10);
        if (self) {
            self->vtable = D_004DF860;
            GobjFlag_Release(self);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAA10[68] = { (void*)0x0, (void*)0x0, (void*)ParticleGob_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)ParticleGob_v08, (void*)ParticleGob_v09, (void*)func_0012ED50, (void*)func_003926A0, (void*)func_003926B0, (void*)cNode_v0D, (void*)ParticleGob_ResetTime, (void*)ParticleGob_RequestPar, (void*)ParticleGob_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)ParticleGob_Draw, (void*)ParticleGob_OnPresent, (void*)ParticleGob_OnAbsent, (void*)ParticleGob_Enable, (void*)ParticleGob_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)ParticleGob_GetBounds, (void*)ParticleGob_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
