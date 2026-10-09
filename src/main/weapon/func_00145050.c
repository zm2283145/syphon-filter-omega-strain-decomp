/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int D_004EA160;   /* cOutOfAmmoMsg script type */
extern cOutOfAmmoMsg* func_001450B0(void* self);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* volatile mirrors the original stack temporary. */
int Script_cOutOfAmmoMsg_Weapon(WeaponScriptArg* args) {
    volatile int weapon = func_001450B0(args[0].p)->weapon;
    return weapon;
}

/* Registers the cOutOfAmmoMsg script type under its parent type. */
void ScriptType_cOutOfAmmoMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_004EA160, *parent);
}
