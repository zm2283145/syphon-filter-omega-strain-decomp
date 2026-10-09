/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ActiveList_RemoveFirst(char* world);
extern int ActiveList_RemoveObject(char* world, int camera);
extern int D_004EE908;
extern char D_004FFB50[]; /* world object */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(char*, int, int);
extern int func_00131320(char* world, int camera); /* push camera */
extern void func_00282020(int);

/* Script binding: removes camera args[0] from the world camera stack. */
int Script_cGameCamera_RemoveCamera(int* args) {
    ActiveList_RemoveObject(D_004FFB50, args[0]);
    return 0;
}

/* Script binding: pops the current camera. */
int Script_cGameCamera_PopCurrent(void) {
    ActiveList_RemoveFirst(D_004FFB50);
    return 0;
}

/* Script binding: pushes camera args[0] as current. */
int Script_cGameCamera_PushCurrent(int* args) {
    func_00131320(D_004FFB50, args[0]);
    return 0;
}

void func_0017A190(void) {
}

/* Returns the value of global D_004EE908. */
int func_0017A1A0(void) {
    return D_004EE908;
}

int func_0017A1B0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

void cHumanSeenMsg_v04(char* msg) {
    func_00282020(*(int*)(msg + 0x24));
}
