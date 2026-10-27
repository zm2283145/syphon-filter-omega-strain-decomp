/*
 * SFOGame/Source/gameGobjController: 8 files, 0022EFE0-0022F430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022EFE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTimerExpiredMsg message type id.
 */

#include "types.h"

extern int D_004F7A10; /* cTimerExpiredMsg message type id */

int cTimerExpiredMsg_v05(void) {
    return D_004F7A10;
}
static inline void merge_flush_func_0022EFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EFE0 */

/* merge_units: begin func_0022EFF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A69C0[] = "gameGobjController.hh"; }
DEFINE_NET_MSG_CLONE(cTimerExpiredMsg_v01, 0x28, D_004A69C0, 0x2D, D_004DBA00, NMC_W(0x24))
static inline void merge_flush_func_0022EFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EFF0 */

/* merge_units: begin func_0022F100 */
#pragma push /* merge_units */
#include "gameGobjController_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cGameGobjController and cTimerExpiredMsg script types.
 */


extern int D_004F7A20;      /* script type key */
extern int D_004F7A28;      /* cTimerExpiredMsg script type id */
extern int D_004F7A38;      /* script type key */
extern int D_004F7A40;      /* cGameGobjController script type id */
extern char D_00555070[];   /* global script filter */
extern int cGOBJ_SOBJ_toInt(int gobj);
extern int cScriptInterpreter_CallEvent(void* filter, int a1, int a2);
extern int* cMessage_SOBJ_getClassId(void);
extern int* cSystem_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int iface);
extern void cScriptBase_declareParent(int type, int parentType);
extern int* cWeaponVisChangeMsg_GetScriptTypeKeyPtr(void);

/* Gobj(controller): the controlled game object. */
int Script_cGameGobjController_Gobj(GgcScriptArg* args) {
    cGameGobjController* ctrl = args[0].p;
    return cGOBJ_SOBJ_toInt(ctrl->gobj);
}

void cGameGobjController_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F7A40, *cSystem_SOBJ_getClassId());
    cScriptBase_declareMsgUse(D_004F7A40, *cWeaponVisChangeMsg_GetScriptTypeKeyPtr());
    cScriptBase_declareMsgUse(D_004F7A40, D_004F7A20);
}

int* func_0022F170(void) {
    return &D_004F7A38;
}

int cGameGobjController_v0B(void) {
    return D_004F7A38;
}

int cGameGobjController_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/* IsPersonal(msg) */
int Script_cTimerExpiredMsg_IsPersonal(GgcScriptArg* args) {
    cTimerExpiredMsg* msg = args[0].p;
    return 0u < (unsigned int)msg->timerId;
}

/* cTimerExpiredMsg derives from the message base type. */
void cTimerExpiredMsg_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F7A28, *cMessage_SOBJ_getClassId());
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
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);

/* Sends target a message carrying the next byte read from the D_005061D0 cursor. */
void cTimerExpiredMsg_NetReceive(void* target) {
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7A08);
    msg.vtable = D_004DBA00;
    msg.value = *D_005061D0++;
    msg.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, target, 0);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F2A0(void) {}
#undef D_005061D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022F2A0 */

/* merge_units: begin func_0022F2D0 */
#pragma push /* merge_units */
#include "npc_auth.h"
#include "vslot_pad.h"

typedef struct { char pad[0x30]; void* net; char pad34[4]; float skill; } Npc0022F2D0;
void cGameGobjController_SetSkill_float_2(Npc0022F2D0* self, float skill)
{
    self->skill = skill;
    if (g_IsMultiplayer && NpcAuth_IsLocal())
        cNetNPCMsgs_SendMessage(self->net, 0x37, 4, *(volatile int*)&skill, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F2D0 */

/* merge_units: begin func_0022F340 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cGameGobjController_Enemy_cGOBJP: true when this controller's team treats `other`'s team as an enemy */
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } IsEnRel;
struct IsEnCtrl {
    VPAD16(a) VPAD8(b)
    virtual int GetTeam();
};
extern "C" IsEnRel (*D_004EE620)[16];
extern "C" int cGOBJ_Team(void* other);
static inline int IsEn_IsEnemy(int a, int b)
{
    if (D_004EE620 && a > -1 && a < 16 && b > -1 && b < 16)
        return D_004EE620[a][b].enemy;
    return 0;
}
extern "C" unsigned char cGameGobjController_Enemy_cGOBJP(IsEnCtrl* c, void* other)
{
    unsigned char r = 0;
    if (c->GetTeam() >= 0 && other && cGOBJ_Team(other) >= 0) {
        int t = cGOBJ_Team(other);
        r = IsEn_IsEnemy(c->GetTeam(), t);
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F340 */

/* merge_units: begin func_0022F430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cGobjController_Team(void) {
    return -1;
}
static inline void merge_flush_func_0022F430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022F430 */
