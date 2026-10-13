#pragma cplusplus on

#include "types.h"
#include "vtable_member_base_dtor.h"

/* Derived destructor: member, then base, optionally delete. */
extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseLogicUpdate();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Hotbox_Contains();
extern "C" void Node_GetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cHotbox_v01();
extern "C" void cHotbox_v43();
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void func_00141850();
extern "C" void func_00148870();
extern "C" void func_0014D340();
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
extern "C" void func_0015C0A0();
extern "C" void Hotbox_Disable();
extern "C" void Hotbox_Enable();
extern "C" void func_0016FE50();
extern "C" void Hotbox_ScriptFilter();
extern "C" void func_001729A0();
extern "C" void func_001729B0();
extern "C" void func_00173640();
extern "C" void func_00173650();
extern "C" void Hotbox_GetBounds();
extern "C" void func_00173670();
extern "C" void func_00173680();
extern "C" void func_00173690();
extern "C" void func_001736A0();
extern "C" void func_001736B0();
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
extern "C" void Object_Deactivate();
extern "C" void func_003CEA00();
extern void * const D_004D9AC0[];
void* func_001363C0(void* self, short deleteFlag);
void* cGOBJ_dtor(void* self, short deleteFlag);
}
extern "C" VtableMemberObject* cHotbox_dtor(VtableMemberObject* self,
                                    short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9AC0);
        char* member = (char*)self + (0x60);
        if (member)
            func_001363C0(member, -1);
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9AC0[72] = { (void*)0x0, (void*)0x0, (void*)cHotbox_dtor, (void*)cHotbox_v01, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_001736B0, (void*)func_0012ED00, (void*)func_00173690, (void*)func_001736A0, (void*)func_00173670, (void*)func_00173680, (void*)func_001729B0, (void*)func_0016FE50, (void*)Hotbox_ScriptFilter, (void*)func_003CEA00, (void*)func_00173640, (void*)func_00173650, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_001729A0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Hotbox_Enable, (void*)Hotbox_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)Hotbox_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)Hotbox_Contains, (void*)cHotbox_v43, (void*)0x0, (void*)0x0 };
