/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F7D20; /* cNINotice script type key */
extern int D_004F7D28; /* cNINotice script type id */
extern int* Message_GetScriptTypeKeyPtr(void); /* address of the cMessage type key */
extern void ScriptType_SetParent(int type, int parentType);

/* Action(notice): returns the notice's action byte (+0x24). */
int Script_cNINotice_Action(unsigned char** args) {
    return args[0][36];
}

/* cNINotice derives from cMessage. */
void ScriptType_cNINotice_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7D28, *parent);
}

int cNINotice_v03(void) {
    return D_004F7D20;
}
