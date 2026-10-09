/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FF128[];
extern char D_004FF130[];
extern char D_004FF138[];
extern char D_004FF148[];
extern char D_004FF168[];
extern char D_004FF178[];
extern char D_004FF198[];
extern char D_004FF1B0[];
extern char D_004FF1B8[];
extern char D_004FF1C0[];
extern char D_004FF1C8[];
extern char D_004FF1D0[];
extern char D_004FF1D8[];
extern char D_004FF1E8[];
extern char D_004FF1F0[];
extern char D_004FF210[];
extern char D_004FF218[];
extern char D_004FF220[];
extern char D_004FF228[];
extern char D_004FF240[];
extern char D_004FF248[];
extern char D_004FF250[];
extern char D_004FF258[];
extern int GObj_IdentityA(int);
extern int func_0015C100(int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int Script_cAIUnconsciousMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void ScriptType_cAIUnconsciousMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF258;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026ED30(void) {
    return (int)D_004FF250;
}

int cAIUnconsciousMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF250;
    return tmp0;
}

void ScriptType_cAIDisguiseTakenMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF248;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026ED70(void) {
    return (int)D_004FF240;
}

int cAIDisguiseTakenMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF240;
    return tmp0;
}

int Script_cAIBodyMovedMsg_PickedUp(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(unsigned char*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_cAIBodyMovedMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void ScriptType_cAIBodyMovedMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF228;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026EDF0(void) {
    return (int)D_004FF220;
}

int cAIBodyMovedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF220;
    return tmp0;
}

void ScriptType_cAIPickupableAwarenessMsg_Ini(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF218;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EE30(void) {
    return (int)D_004FF210;
}

int cAIPickupableAwarenessMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF210;
    return tmp0;
}

int Script_cAIWeaponFiredMsg_IsThrownWeapon(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 48);
}

int Script_cAIWeaponFiredMsg_Count(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 44);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_cAIWeaponFiredMsg_WeaponId(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void ScriptType_cAIWeaponFiredMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1F0;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EEC0(void) {
    return (int)D_004FF1E8;
}

int cAIWeaponFiredMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1E8;
    return tmp0;
}

int Script_cAINewAwarenessMsg_Cause(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 40);
}

void ScriptType_cAINewAwarenessMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1D8;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF10(void) {
    return (int)D_004FF1D0;
}

int cAINewAwarenessMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1D0;
    return tmp0;
}

void ScriptType_cAIDestinationReachedMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1C8;
    tmp1 = *(int*)D_004FF198;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF50(void) {
    return (int)D_004FF1C0;
}

int cAIDestinationReachedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1C0;
    return tmp0;
}

void ScriptType_cAIWaypointReachedMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1B8;
    tmp1 = *(int*)D_004FF198;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF90(void) {
    return (int)D_004FF1B0;
}

int cAIWaypointReachedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1B0;
    return tmp0;
}

int Script_cAINodeMsg_GetNode(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return func_0015C100(tmp1);
}

void func_0026EFC0(void) {
}

int cAINodeMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF198;
    return tmp0;
}

int Script_cAIGOBJMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

int Script_cAIGOBJMsg_GetGOBJ(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026F000(void) {
}

int cAIGOBJMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF178;
    return tmp0;
}

void func_0026F020(void) {
}

int func_0026F030(void) {
    return (int)D_004FF168;
}

int cAITimeElapsedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF168;
    return tmp0;
}

int Script_cAIDeadMsg_DamageType(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 40);
}

int Script_cAIDeadMsg_Attacker(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026F070(void) {
}

int func_0026F080(void) {
    return (int)D_004FF148;
}

int cAIDeadMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF148;
    return tmp0;
}

void func_0026F0A0(void) {
}

int func_0026F0B0(void) {
    return (int)D_004FF138;
}

int cAIDeactivatedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF138;
    return tmp0;
}

void ScriptType_cAIActivatedMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF130;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026F0F0(void) {
    return (int)D_004FF128;
}

int cAIActivatedMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF128;
    return tmp0;
}
