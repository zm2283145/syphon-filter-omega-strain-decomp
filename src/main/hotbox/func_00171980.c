/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

/* trigger-zone class table (handler TriggerZone_HandleEvent) */
extern void Actor_ApplyContactDamage();
extern void Actor_BaseLogicUpdate();
extern void Actor_BasePreLogic();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Hotbox_Contains();
extern void Node_GetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void TriggerZone_HandleEvent();
extern void func_0012ECE0();
extern void func_0012ED00();
extern void func_0013E060();
extern void func_00140E90();
extern void func_00141850();
extern void func_00148870();
extern void func_0014D340();
extern void func_00153860();
extern void func_0015BFB0();
extern void func_0015BFC0();
extern void func_0015BFD0();
extern void func_0015BFE0();
extern void func_0015BFF0();
extern void func_0015C000();
extern void func_0015C010();
extern void func_0015C020();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C0A0();
extern void Hotbox_Disable();
extern void Hotbox_Enable();
extern void func_0016FE50();
extern void Hotbox_ScriptFilter();
extern void func_00171880();
extern void func_001729A0();
extern void func_001729B0();
extern void func_001735E0();
extern void func_00173640();
extern void func_00173650();
extern void Hotbox_GetBounds();
extern void func_00173670();
extern void func_00173680();
extern void func_00173690();
extern void func_001736A0();
extern void func_001736B0();
extern void func_003CCFF0();
extern void func_003CD090();
extern void func_003CD110();
extern void func_003CD1C0();
extern void PathObj_GetPosition();
extern void func_003CD420();
extern void func_003CD4A0();
extern void func_003CD520();
extern void func_003CD7A0();
extern void func_003CD920();
extern void func_003CDA60();
extern void func_003CDBE0();
extern void func_003CDC20();
extern void func_003CDD40();
extern void func_003CDD80();
extern void func_003CDDC0();
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void func_003CEA00();
void * const D_004D99A0[72] = { (void*)0x0, (void*)0x0, (void*)func_001735E0, (void*)TriggerZone_HandleEvent, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_001736B0, (void*)func_0012ED00, (void*)func_00173690, (void*)func_001736A0, (void*)func_00173670, (void*)func_00173680, (void*)func_001729B0, (void*)func_0016FE50, (void*)Hotbox_ScriptFilter, (void*)func_003CEA00, (void*)func_00173640, (void*)func_00173650, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_001729A0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Hotbox_Enable, (void*)Hotbox_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)Hotbox_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)Hotbox_Contains, (void*)func_00171880, (void*)0x0, (void*)0x0 };
extern void cHotbox_ctor(cHotbox* self, int a1, int a2);

/* Trigger-zone constructor: a cHotbox with its own class table. */
cHotbox* TriggerZone_ctor(cHotbox* self, int a1) {
    cHotbox_ctor(self, a1, 12);
    self->vtable = ((char*)D_004D99A0);
    return self;
}
