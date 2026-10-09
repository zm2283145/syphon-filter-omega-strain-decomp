/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7D20[];
extern char D_004F7D28[];
extern int Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

int Script_cNINotice_Action(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void ScriptType_cNINotice_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = Message_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_004F7D28;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
}

int cNINotice_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7D20;
    return tmp0;
}
