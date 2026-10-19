/*
 * main/gameGobjController: range (3 files, 0022F100-0022F2A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "gameGobjController_types.h"

/* merge_units: begin func_0022F100 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameGobjController and cTimerExpiredMsg script types.
 */


extern int D_004F7A20;      /* script type key */
extern int D_004F7A28;      /* cTimerExpiredMsg script type id */
extern int D_004F7A38;      /* script type key */
extern int D_004F7A40;      /* cGameGobjController script type id */
extern char D_00555070[];   /* global script filter */
extern int GObj_IdentityA(int gobj);
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* Message_GetScriptTypeKeyPtr(void);
extern int* cSystem_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int parentType);
extern int* cWeaponVisChangeMsg_GetScriptTypeKeyPtr(void);

/* Gobj(controller): the controlled game object. */
int Script_cGameGobjController_Gobj(GgcScriptArg* args) {
    cGameGobjController* ctrl = args[0].p;
    return GObj_IdentityA(ctrl->gobj);
}

void ScriptType_cGameGobjController_Init(void) {
    ScriptType_SetParent(D_004F7A40, *cSystem_GetScriptTypeKeyPtr());
    ScriptType_AddAccepted(D_004F7A40, *cWeaponVisChangeMsg_GetScriptTypeKeyPtr());
    ScriptType_AddAccepted(D_004F7A40, D_004F7A20);
}

int* func_0022F170(void) {
    return &D_004F7A38;
}

int cGameGobjController_v0B(void) {
    return D_004F7A38;
}

int cGameGobjController_v0C(int a0, int a1) {
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F100 */

/* merge_units: begin func_0022F210 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct Msg {
    void* vtable;
    char base[0x1C];
    unsigned char flag;
    char pad[3];
    int value;
    char pad2[8];
} Msg;

extern char* D_005061D0; /* read cursor */
extern char D_004F7A08[];
extern char D_004DBA00[]; /* message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(Msg* msg, void* name);
extern void Event_Send(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);

/* Sends target a message carrying the next byte read from the D_005061D0 cursor. */
void cTimerExpiredMsg_NetReceive(void* target) {
    Msg msg;
    Event_Construct(&msg, D_004F7A08);
    msg.vtable = D_004DBA00;
    msg.value = *D_005061D0++;
    msg.flag = 1;
    Event_Send(&msg, target, 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F210 */

/* merge_units: begin func_0022F2A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTimerExpiredMsg serializer.
 */


/* Network stream cursor shared by message serializers. */
#if 0 /* merge_units */
extern signed char* D_005061D0;
#endif /* merge_units */
#define D_005061D0 (*(signed char **)&D_005061D0) /* merge_units */


/* Serialize: writes the timer id as one byte. */
void cTimerExpiredMsg_v04(int msg) {
    /* reusing the parameter for the value keeps the original full-word load */
    msg = ((cTimerExpiredMsg*)msg)->timerId;
    *D_005061D0 = msg;
    D_005061D0 = D_005061D0 + 1;
}
#undef D_005061D0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F2A0 */
