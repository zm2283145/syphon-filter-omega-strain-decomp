/*
 * Matched functions (byte-identical with the retail executable).
 * cGameGobjController and cTimerExpiredMsg script types.
 */

#include "types.h"
#include "gameGobjController_types.h"

extern int D_004F7A20;      /* script type key */
extern int D_004F7A28;      /* cTimerExpiredMsg script type id */
extern int D_004F7A38;      /* script type key */
extern int D_004F7A40;      /* cGameGobjController script type id */
extern char D_00555070[];   /* global script filter */
extern int GObj_IdentityA(int gobj);
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* Message_GetScriptTypeKeyPtr(void);
extern int* func_003CB1D0(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int parentType);
extern int* func_0043FB90(void);

/* Gobj(controller): the controlled game object. */
int Script_cGameGobjController_Gobj(GgcScriptArg* args) {
    cGameGobjController* ctrl = args[0].p;
    return GObj_IdentityA(ctrl->gobj);
}

void ScriptType_cGameGobjController_Init(void) {
    ScriptType_SetParent(D_004F7A40, *func_003CB1D0());
    ScriptType_AddAccepted(D_004F7A40, *func_0043FB90());
    ScriptType_AddAccepted(D_004F7A40, D_004F7A20);
}

int* func_0022F170(void) {
    return &D_004F7A38;
}

int func_0022F180(void) {
    return D_004F7A38;
}

int func_0022F190(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* IsPersonal(msg) */
int Script_cTimerExpiredMsg_IsPersonal(GgcScriptArg* args) {
    cTimerExpiredMsg* msg = args[0].p;
    return 0u < (unsigned int)msg->timerId;
}

/* cTimerExpiredMsg derives from the message base type. */
void ScriptType_cTimerExpiredMsg_Init(void) {
    ScriptType_SetParent(D_004F7A28, *Message_GetScriptTypeKeyPtr());
}

int* func_0022F1F0(void) {
    return &D_004F7A20;
}

int cTimerExpiredMsg_v03(void) {
    return D_004F7A20;
}
