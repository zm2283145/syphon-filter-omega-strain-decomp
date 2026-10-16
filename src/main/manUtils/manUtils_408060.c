/*
 * Matched functions (byte-identical with the retail executable).
 * cDamageMsg script accessor natives, script type registration and the
 * type-descriptor virtual slots.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_00571700;
extern int D_00571708;
extern int GObj_IdentityA(int who);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cDamageMsg_Type(cDamageMsg** msg) {
    return (*msg)->type;
}

int Script_cDamageMsg_Where(cDamageMsg** msg) {
    return (*msg)->where;
}

int Script_cDamageMsg_Attacker(cDamageMsg** msg) {
    return GObj_IdentityA((*msg)->attacker);
}

/* Returns the float damage value as its raw bits. */
int Script_cDamageMsg_Damage(cDamageMsg** msg) {
    int loc[1];

    loc[0] = *(int*)&(*msg)->damage;
    return *(int*)loc;
}

void ScriptType_cDamageMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_00571708, *base);
}

int func_004080E0(void) {
    return (int)&D_00571700;
}

int cDamageMsg_v03(void) {
    return D_00571700;
}
