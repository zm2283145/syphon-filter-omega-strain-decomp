/*
 * Matched functions (byte-identical with the retail executable).
 * AI script messages: accessor natives, script type registration and the
 * type-descriptor virtual slots (v03 returns the type id, the unnamed getter
 * before it returns the descriptor address).
 */

#include "types.h"
#include "aiMsgs_types.h"

extern int D_004FF128;
extern int D_004FF130;
extern int D_004FF138;
extern int D_004FF148;
extern int D_004FF168;
extern int D_004FF178;
extern int D_004FF198;
extern int D_004FF1B0;
extern int D_004FF1B8;
extern int D_004FF1C0;
extern int D_004FF1C8;
extern int D_004FF1D0;
extern int D_004FF1D8;
extern int D_004FF1E8;
extern int D_004FF1F0;
extern int D_004FF210;
extern int D_004FF218;
extern int D_004FF220;
extern int D_004FF228;
extern int D_004FF240;
extern int D_004FF248;
extern int D_004FF250;
extern int D_004FF258;
extern int GObj_IdentityA(int who);
extern int func_0015C100(int node);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cAIUnconsciousMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void ScriptType_cAIUnconsciousMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004FF258, *base);
}

int func_0026ED30(void) {
    return (int)&D_004FF250;
}

int cAIUnconsciousMsg_v03(void) {
    return D_004FF250;
}

void ScriptType_cAIDisguiseTakenMsg_Init(void) {
    ScriptType_SetParent(D_004FF248, D_004FF178);
}

int func_0026ED70(void) {
    return (int)&D_004FF240;
}

int cAIDisguiseTakenMsg_v03(void) {
    return D_004FF240;
}

/* Volatile locals in the accessors below mirror the original stack temporaries. */
int Script_cAIBodyMovedMsg_PickedUp(cAIBodyMovedMsg** msg) {
    volatile int pickedUp = (*msg)->pickedUp;
    return pickedUp;
}

int Script_cAIBodyMovedMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void ScriptType_cAIBodyMovedMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004FF228, *base);
}

int func_0026EDF0(void) {
    return (int)&D_004FF220;
}

int cAIBodyMovedMsg_v03(void) {
    return D_004FF220;
}

void ScriptType_cAIPickupableAwarenessMsg_Ini(void) {
    ScriptType_SetParent(D_004FF218, D_004FF178);
}

int func_0026EE30(void) {
    return (int)&D_004FF210;
}

int cAIPickupableAwarenessMsg_v03(void) {
    return D_004FF210;
}

int Script_cAIWeaponFiredMsg_IsThrownWeapon(cAIWeaponFiredMsg** msg) {
    return (*msg)->isThrown;
}

int Script_cAIWeaponFiredMsg_Count(cAIWeaponFiredMsg** msg) {
    volatile int count = (*msg)->count;
    return count;
}

int Script_cAIWeaponFiredMsg_WeaponId(cAIWeaponFiredMsg** msg) {
    volatile int weaponId = (*msg)->weaponId;
    return weaponId;
}

void ScriptType_cAIWeaponFiredMsg_Init(void) {
    ScriptType_SetParent(D_004FF1F0, D_004FF178);
}

int func_0026EEC0(void) {
    return (int)&D_004FF1E8;
}

int cAIWeaponFiredMsg_v03(void) {
    return D_004FF1E8;
}

int Script_cAINewAwarenessMsg_Cause(cAINewAwarenessMsg** msg) {
    return (*msg)->cause;
}

void ScriptType_cAINewAwarenessMsg_Init(void) {
    ScriptType_SetParent(D_004FF1D8, D_004FF178);
}

int func_0026EF10(void) {
    return (int)&D_004FF1D0;
}

int cAINewAwarenessMsg_v03(void) {
    return D_004FF1D0;
}

void ScriptType_cAIDestinationReachedMsg_Init(void) {
    ScriptType_SetParent(D_004FF1C8, D_004FF198);
}

int func_0026EF50(void) {
    return (int)&D_004FF1C0;
}

int cAIDestinationReachedMsg_v03(void) {
    return D_004FF1C0;
}

void ScriptType_cAIWaypointReachedMsg_Init(void) {
    ScriptType_SetParent(D_004FF1B8, D_004FF198);
}

int func_0026EF90(void) {
    return (int)&D_004FF1B0;
}

int cAIWaypointReachedMsg_v03(void) {
    return D_004FF1B0;
}

int Script_cAINodeMsg_GetNode(cAINodeMsg** msg) {
    return func_0015C100((*msg)->node);
}

void func_0026EFC0(void) {
}

int cAINodeMsg_v03(void) {
    return D_004FF198;
}

int Script_cAIGOBJMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

int Script_cAIGOBJMsg_GetGOBJ(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void func_0026F000(void) {
}

int cAIGOBJMsg_v03(void) {
    return D_004FF178;
}

void func_0026F020(void) {
}

int func_0026F030(void) {
    return (int)&D_004FF168;
}

int cAITimeElapsedMsg_v03(void) {
    return D_004FF168;
}

int Script_cAIDeadMsg_DamageType(cAIDeadMsg** msg) {
    return (*msg)->damageType;
}

int Script_cAIDeadMsg_Attacker(cAIDeadMsg** msg) {
    return GObj_IdentityA((*msg)->gobj.who);
}

void func_0026F070(void) {
}

int func_0026F080(void) {
    return (int)&D_004FF148;
}

int cAIDeadMsg_v03(void) {
    return D_004FF148;
}

void func_0026F0A0(void) {
}

int func_0026F0B0(void) {
    return (int)&D_004FF138;
}

int cAIDeactivatedMsg_v03(void) {
    return D_004FF138;
}

void ScriptType_cAIActivatedMsg_Init(void) {
    ScriptType_SetParent(D_004FF130, D_004FF178);
}

int func_0026F0F0(void) {
    return (int)&D_004FF128;
}

int cAIActivatedMsg_v03(void) {
    return D_004FF128;
}
