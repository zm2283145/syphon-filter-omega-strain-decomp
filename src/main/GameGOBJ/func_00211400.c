/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cPathedGOBJ script type registration and accessors.
 */

#include "gobj_types.h"

extern int D_004F54D0;   /* cGameGOBJ script-type value */
extern int D_004F54F0;   /* cPathedGOBJ script-type value */
extern int D_004F54F8;   /* cPathedGOBJ script-type key */
extern int D_004F5638;   /* cPathedNotice script-type value */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cPathedGOBJ script type under cGameGOBJ; accepts cPathedNotice. */
int ScriptType_cPathedGOBJ_Init(void) {
    ScriptType_SetParent(D_004F54F8, D_004F54D0);
    return ScriptType_AddAccepted(D_004F54F8, D_004F5638);
}

int cPathedGOBJ_v0B(void) {
    return D_004F54F0;
}

int PathObj_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
