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
extern void GObj_GetID();
extern void func_0012ED00();
extern void func_0013E060();
extern void func_00140E90();
extern void GObj_GetLifeState();
extern void func_00148870();
extern void Object_GetEye();
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
extern void cHotbox_v0B();
extern void Hotbox_ScriptFilter();
extern void Hotbox_Type12BuddyClimb();
extern void cHotbox_v14();
extern void cHotbox_v0A();
extern void TriggerZone_dtor();
extern void cHotbox_v0E();
extern void cHotbox_v0F();
extern void Hotbox_GetBounds();
extern void Hotbox_Enable_173670();
extern void cHotbox_v09();
extern void cHotbox_v06();
extern void cHotbox_v07();
extern void cHotbox_v04();
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
extern void cNode_v0D();
void * const D_004D99A0[72] = { (void*)0x0, (void*)0x0, (void*)TriggerZone_dtor, (void*)TriggerZone_HandleEvent, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cHotbox_v04, (void*)func_0012ED00, (void*)cHotbox_v06, (void*)cHotbox_v07, (void*)Hotbox_Enable_173670, (void*)cHotbox_v09, (void*)cHotbox_v0A, (void*)cHotbox_v0B, (void*)Hotbox_ScriptFilter, (void*)cNode_v0D, (void*)cHotbox_v0E, (void*)cHotbox_v0F, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cHotbox_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Hotbox_Enable, (void*)Hotbox_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)Hotbox_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)Hotbox_Contains, (void*)Hotbox_Type12BuddyClimb, (void*)0x0, (void*)0x0 };
extern void cHotbox_ctor(cHotbox* self, int a1, int a2);

/* Trigger-zone constructor: a cHotbox with its own class table. */
cHotbox* TriggerZone_ctor(cHotbox* self, int a1) {
    cHotbox_ctor(self, a1, 12);
    self->vtable = ((char*)D_004D99A0);
    return self;
}
