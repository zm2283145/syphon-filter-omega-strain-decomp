/*
 * main/aiMsgs: 3 files, 0026EBE0-0026F110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026EBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DCBD0[];
extern "C" char D_004DCD70[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIPickupableAwarenessMsg_v01, 0x28, "aiMsgs.hh", 0x10A)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCBD0;
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_0026EBE0 */

/* merge_units: begin func_0026ECF0 */
#pragma push /* merge_units */
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
extern int cNode_Identity(int node);
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
    return cNode_Identity((*msg)->node);
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
#pragma pop /* merge_units */
/* merge_units: end func_0026ECF0 */

/* merge_units: begin func_0026F110 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Event_Construct();
int WeaponInv_GetHeldClass(int );
extern int D_004DCBF0;
#if 0 /* merge_units */
extern int D_004DCD70;
#endif /* merge_units */
#define D_004DCD70 (*(int*)&D_004DCD70) /* merge_units */

extern int g_ScriptAIWeaponFiredMsgKey;

int cAIWeaponFiredMsg_ctor(int arg0, int arg1, int arg2, int arg3) {
    Event_Construct(arg0, &g_ScriptAIWeaponFiredMsgKey);
    F_(arg0, 0x0, int) = (int)(&D_004DCD70);
    F_(arg0, 0x24, int) = arg1;
    F_(arg0, 0x20, signed char) = 2;
    F_(arg0, 0x0, int) = (int)(&D_004DCBF0);
    F_(arg0, 0x2C, int) = arg3;
    if (arg2 != NULL) {
        F_(arg0, 0x30, signed char) = (signed char) ((WeaponInv_GetHeldClass(arg2) & 0xFF) == 1);
        F_(arg0, 0x28, int) = (int) F_(((char *)(F_(arg2, 0x84, unsigned char) * 0x10) + (int)(arg2)), 0x8, int);
    } else {
        F_(arg0, 0x28, int) = -1;
        F_(arg0, 0x30, signed char) = 0;
    }
    return arg0;
}
#undef D_004DCD70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026F110 */
