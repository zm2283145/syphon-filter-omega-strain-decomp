#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cFireObj_v01();
extern "C" void cFireObj_v08();
extern "C" void cFireObj_v09();
extern "C" void cFireObj_v0B();
extern "C" void cFireObj_v0C();
extern "C" void cFireObj_v0E();
extern "C" void cFireObj_v0F();
extern "C" void cFireObj_v10();
extern "C" void cFireObj_v14();
extern "C" void cFireObj_v17();
extern "C" void cFireObj_v18();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
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
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void GObj_GetWorldMatrix();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void func_003CD4A0();
extern "C" void Node_GetWorldMatrix();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CEA00();
extern void * const D_004DC970[];
void* cGOBJ_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cFireObj_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC970);
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC970[68] = { (void*)0x0, (void*)0x0, (void*)cFireObj_dtor, (void*)cFireObj_v01, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)cFireObj_v08, (void*)cFireObj_v09, (void*)func_0012ED50, (void*)cFireObj_v0B, (void*)cFireObj_v0C, (void*)func_003CEA00, (void*)cFireObj_v0E, (void*)cFireObj_v0F, (void*)cFireObj_v10, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cFireObj_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)cFireObj_v17, (void*)cFireObj_v18, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
