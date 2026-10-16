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
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void func_00141850();
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
extern "C" void func_001C5650();
extern "C" void func_001C5660();
extern "C" void func_001C5670();
extern "C" void func_001C5680();
extern "C" void func_001C5710();
extern "C" void ParticleGob_Update();
extern "C" void func_003926A0();
extern "C" void func_003926B0();
extern "C" void ParticleGob_OnAbsent();
extern "C" void ParticleGob_OnPresent();
extern "C" void ParticleGob_GetBounds();
extern "C" void ParticleGob_Draw();
extern "C" void ParticleGob_RequestPar();
extern "C" void func_00394740();
extern "C" void func_003CCFF0();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void func_003CD1C0();
extern "C" void PathObj_GetPosition();
extern "C" void func_003CD420();
extern "C" void func_003CD4A0();
extern "C" void func_003CD520();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CEA00();
extern "C" void Object_HandleMessage();
extern void * const D_004DAA10[];
extern "C" char D_004DF860[];
extern "C" GobjFlagObj* func_001C5590(GobjFlagObj* self, short deleteFlag)
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
void * const D_004DAA10[68] = { (void*)0x0, (void*)0x0, (void*)func_001C5590, (void*)Object_HandleMessage, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_001C5650, (void*)func_001C5660, (void*)func_0012ED50, (void*)func_003926A0, (void*)func_003926B0, (void*)func_003CEA00, (void*)func_00394740, (void*)ParticleGob_RequestPar, (void*)ParticleGob_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)ParticleGob_Draw, (void*)ParticleGob_OnPresent, (void*)ParticleGob_OnAbsent, (void*)func_001C5710, (void*)func_001C5680, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)ParticleGob_GetBounds, (void*)func_001C5670, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice };
