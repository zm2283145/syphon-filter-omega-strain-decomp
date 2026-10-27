/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cGameSystem_PopCamera(char* world);
extern int cGameSystem_RemoveCamera(char* world, int camera);
extern int D_004EE908;
extern char g_Game[]; /* world object */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(char*, int, int);
extern int cGameSystem_PushCamera(char* world, int camera); /* push camera */
extern void cNetMsg_PutGOBJ(int);

/* Script binding: removes camera args[0] from the world camera stack. */
int Script_cGameCamera_RemoveCamera(int* args) {
    cGameSystem_RemoveCamera(g_Game, args[0]);
    return 0;
}

/* Script binding: pops the current camera. */
int Script_cGameCamera_PopCurrent(void) {
    cGameSystem_PopCamera(g_Game);
    return 0;
}

/* Script binding: pushes camera args[0] as current. */
int Script_cGameCamera_PushCurrent(int* args) {
    cGameSystem_PushCamera(g_Game, args[0]);
    return 0;
}

void cGameCamera_SOBJ_init(void) {
}

/* Returns the value of global D_004EE908. */
int cGameCamera_getSOBJClassId(void) {
    return D_004EE908;
}

int cGameCamera_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

void cHumanSeenMsg_Pack(char* msg) {
    cNetMsg_PutGOBJ(*(int*)(msg + 0x24));
}
