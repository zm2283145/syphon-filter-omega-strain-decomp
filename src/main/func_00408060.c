/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00571700[];
extern char D_00571708[];
extern int GObj_IdentityA(int);
extern int Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

int Script_cDamageMsg_Type(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 44);
}

int Script_cDamageMsg_Where(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 45);
}

int Script_cDamageMsg_Attacker(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 40);
    return GObj_IdentityA(tmp1);
}

int Script_cDamageMsg_Damage(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 36);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void ScriptType_cDamageMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = Message_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_00571708;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
}

int func_004080E0(void) {
    return (int)D_00571700;
}

int cDamageMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_00571700;
    return tmp0;
}
