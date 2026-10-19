/*
 * main/aiMsgs: aiMsgs.cc (43 files, 0026EBE0-00271170)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop
#include "types.h"
#include "aiMsgs_types.h"
#include "ai_msg_pack.h"
#include "vslot_pad.h"
#include "message_pack.h"
int Event_Construct(void* e, void* type);

/* the twelve per-message copies of the header name (retail keeps them unpooled) */
char D_004A8C30[16] = "aiMsgs.hh";
char D_004A8C40[16] = "aiMsgs.hh";
char D_004A8C50[16] = "aiMsgs.hh";
char D_004A8C60[16] = "aiMsgs.hh";
char D_004A8C70[16] = "aiMsgs.hh";
char D_004A8C80[16] = "aiMsgs.hh";
char D_004A8C90[16] = "aiMsgs.hh";
char D_004A8CA0[16] = "aiMsgs.hh";
char D_004A8CB0[16] = "aiMsgs.hh";
char D_004A8CC0[16] = "aiMsgs.hh";
char D_004A8CD0[16] = "aiMsgs.hh";
char D_004A8CE0[12] = "aiMsgs.hh";

/* merge_units: begin func_0026EBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004DCBD0[];
extern "C" char D_004DCD70[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIPickupableAwarenessMsg_v01, 0x28, D_004A8C60, 0x10A)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCBD0;
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_0026EBE0 */

/* merge_units: begin func_0026ECF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * AI script messages: accessor natives, script type registration and the
 * type-descriptor virtual slots (v03 returns the type id, the unnamed getter
 * before it returns the descriptor address).
 */


extern int D_004FF128;
extern int D_004FF130;
extern int D_004FF138;
extern int D_004FF148;
extern int D_004FF168;
extern int D_004FF178;
extern int D_004FF198;
extern int D_004FF1B0;
extern int D_004FF1B8;
extern int D_004FF1C0;
extern int D_004FF1C8;
extern int D_004FF1D0;
extern int D_004FF1D8;
extern int D_004FF1E8;
extern int D_004FF1F0;
extern int D_004FF210;
extern int D_004FF218;
extern int D_004FF220;
extern int D_004FF228;
extern int D_004FF240;
extern int D_004FF248;
extern int D_004FF250;
extern int D_004FF258;
extern int GObj_IdentityA(int who);
extern int cNode_Identity(int node);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cAIUnconsciousMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void ScriptType_cAIUnconsciousMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004FF258, *base);
}

int func_0026ED30(void) {
    return (int)&D_004FF250;
}

int cAIUnconsciousMsg_v03(void) {
    return D_004FF250;
}

void ScriptType_cAIDisguiseTakenMsg_Init(void) {
    ScriptType_SetParent(D_004FF248, D_004FF178);
}

int func_0026ED70(void) {
    return (int)&D_004FF240;
}

int cAIDisguiseTakenMsg_v03(void) {
    return D_004FF240;
}

/* Volatile locals in the accessors below mirror the original stack temporaries. */
int Script_cAIBodyMovedMsg_PickedUp(cAIBodyMovedMsg** msg) {
    volatile int pickedUp = (*msg)->pickedUp;
    return pickedUp;
}

int Script_cAIBodyMovedMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void ScriptType_cAIBodyMovedMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004FF228, *base);
}

int func_0026EDF0(void) {
    return (int)&D_004FF220;
}

int cAIBodyMovedMsg_v03(void) {
    return D_004FF220;
}

void ScriptType_cAIPickupableAwarenessMsg_Ini(void) {
    ScriptType_SetParent(D_004FF218, D_004FF178);
}

int func_0026EE30(void) {
    return (int)&D_004FF210;
}

int cAIPickupableAwarenessMsg_v03(void) {
    return D_004FF210;
}

int Script_cAIWeaponFiredMsg_IsThrownWeapon(cAIWeaponFiredMsg** msg) {
    return (*msg)->isThrown;
}

int Script_cAIWeaponFiredMsg_Count(cAIWeaponFiredMsg** msg) {
    volatile int count = (*msg)->count;
    return count;
}

int Script_cAIWeaponFiredMsg_WeaponId(cAIWeaponFiredMsg** msg) {
    volatile int weaponId = (*msg)->weaponId;
    return weaponId;
}

void ScriptType_cAIWeaponFiredMsg_Init(void) {
    ScriptType_SetParent(D_004FF1F0, D_004FF178);
}

int func_0026EEC0(void) {
    return (int)&D_004FF1E8;
}

int cAIWeaponFiredMsg_v03(void) {
    return D_004FF1E8;
}

int Script_cAINewAwarenessMsg_Cause(cAINewAwarenessMsg** msg) {
    return (*msg)->cause;
}

void ScriptType_cAINewAwarenessMsg_Init(void) {
    ScriptType_SetParent(D_004FF1D8, D_004FF178);
}

int func_0026EF10(void) {
    return (int)&D_004FF1D0;
}

int cAINewAwarenessMsg_v03(void) {
    return D_004FF1D0;
}

void ScriptType_cAIDestinationReachedMsg_Init(void) {
    ScriptType_SetParent(D_004FF1C8, D_004FF198);
}

int func_0026EF50(void) {
    return (int)&D_004FF1C0;
}

int cAIDestinationReachedMsg_v03(void) {
    return D_004FF1C0;
}

void ScriptType_cAIWaypointReachedMsg_Init(void) {
    ScriptType_SetParent(D_004FF1B8, D_004FF198);
}

int func_0026EF90(void) {
    return (int)&D_004FF1B0;
}

int cAIWaypointReachedMsg_v03(void) {
    return D_004FF1B0;
}

int Script_cAINodeMsg_GetNode(cAINodeMsg** msg) {
    return cNode_Identity((*msg)->node);
}

void ScriptType_cAINodeMsg_Init(void) {
}

int cAINodeMsg_v03(void) {
    return D_004FF198;
}

int Script_cAIGOBJMsg_Who(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

int Script_cAIGOBJMsg_GetGOBJ(cAIGOBJMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

void ScriptType_cAIGOBJMsg_Init(void) {
}

int cAIGOBJMsg_v03(void) {
    return D_004FF178;
}

void ScriptType_cAITimeElapsedMsg_Init(void) {
}

int func_0026F030(void) {
    return (int)&D_004FF168;
}

int cAITimeElapsedMsg_v03(void) {
    return D_004FF168;
}

int Script_cAIDeadMsg_DamageType(cAIDeadMsg** msg) {
    return (*msg)->damageType;
}

int Script_cAIDeadMsg_Attacker(cAIDeadMsg** msg) {
    return GObj_IdentityA((*msg)->gobj.who);
}

void ScriptType_cAIDeadMsg_Init(void) {
}

int func_0026F080(void) {
    return (int)&D_004FF148;
}

int cAIDeadMsg_v03(void) {
    return D_004FF148;
}

void ScriptType_cAIDeactivatedMsg_Init(void) {
}

int func_0026F0B0(void) {
    return (int)&D_004FF138;
}

int cAIDeactivatedMsg_v03(void) {
    return D_004FF138;
}

void ScriptType_cAIActivatedMsg_Init(void) {
    ScriptType_SetParent(D_004FF130, D_004FF178);
}

int func_0026F0F0(void) {
    return (int)&D_004FF128;
}

int cAIActivatedMsg_v03(void) {
    return D_004FF128;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026ECF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026ECF0 */

/* merge_units: begin func_0026F110 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int WeaponInv_GetHeldClass(int );
extern int D_004DCBF0;
#if 0 /* merge_units */
extern int D_004DCD70;
#endif /* merge_units */
#define D_004DCD70 (*(int*)&D_004DCD70) /* merge_units */


extern int g_ScriptAIWeaponFiredMsgKey;

int cAIWeaponFiredMsg_ctor(int arg0, int arg1, int arg2, int arg3) {
    Event_Construct((void*)arg0, &g_ScriptAIWeaponFiredMsgKey);
    F_(arg0, 0x0, int) = (int)(&D_004DCD70);
    F_(arg0, 0x24, int) = arg1;
    F_(arg0, 0x20, signed char) = 2;
    F_(arg0, 0x0, int) = (int)(&D_004DCBF0);
    F_(arg0, 0x2C, int) = arg3;
    if (arg2 != NULL) {
        F_(arg0, 0x30, signed char) = (signed char) ((WeaponInv_GetHeldClass(arg2) & 0xFF) == 1);
        F_(arg0, 0x28, int) = (int) F_(((char *)(F_(arg2, 0x84, unsigned char) * 0x10) + (int)(arg2)), 0x8, int);
    } else {
        F_(arg0, 0x28, int) = -1;
        F_(arg0, 0x30, signed char) = 0;
    }
    return arg0;
}
#undef D_004DCD70 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F110 */

/* merge_units: begin func_0026F1D0 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt26F1D0;
typedef struct { int header; int receiverId; int whoId; } Arg26F1D0;
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt26F1D0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26F1D0* e, int f);
#if 0 /* merge_units */
extern char D_004DCD70[];
#endif /* merge_units */
#define D_004DCD70 ((char*)&D_004DCD70) /* merge_units */

extern char D_004DCC30[];
extern char g_ScriptAIUnconsciousMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIUnconsciousMsg (registered by cAIUnconsciousMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIUnconsciousMsg_NetReceive(int a0, int a1, int a2, Arg26F1D0* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F1D0 e;
        void* obj;
        Arg26F1D0* a = arg;
        Evt26F1D0* p = &e;
        Event_Construct(p, g_ScriptAIUnconsciousMsgKey);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC30;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
#undef D_004DCD70 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F1D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F1D0 */

/* merge_units: begin func_0026F2B0 */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int Event_UnpackHeader(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004FF120;
extern int cAIUnconsciousMsg_NetReceive();
/* Registers the cAIUnconsciousMsg network message (field formats, then the receive
 * handler cAIUnconsciousMsg_NetReceive). Returns 1 on success. */
unsigned char cAIUnconsciousMsg_NetRegister(void) {
    struct { long long buf; int a[2]; } L;
    int busy;
    unsigned char r = 0;
    unsigned char ok;
    busy = func_002E9A10();
    if (!busy) { ok = 0; do { if (!Event_UnpackHeader(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && !busy && NetMsg_RegisterType(&D_004FF120, 2, cAIUnconsciousMsg_NetReceive) == 0) r = 1; }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F2B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F2B0 */

/* merge_units: begin func_0026F360 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIUnconsciousMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF120)
#pragma pop /* merge_units */
/* merge_units: end func_0026F360 */

/* merge_units: begin func_0026F400 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt26F400;
typedef struct { int header; int receiverId; int whoId; } Arg26F400;

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F400* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F400* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern char D_004DCC50[];
extern char D_004FF2B8[];
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIDisguiseTakenMsg (registered by cAIDisguiseTakenMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIDisguiseTakenMsg_NetReceive(int a0, int a1, int a2, Arg26F400* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F400 e;
        void* obj;
        Arg26F400* a = arg;
        Evt26F400* p = &e;
        Event_Construct(p, D_004FF2B8);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC50;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F400 */

/* merge_units: begin func_0026F4E0 */
#pragma push /* merge_units */
extern int D_004FF118;
extern int cAIDisguiseTakenMsg_NetReceive();
typedef struct { long long buf; int a[2]; } L4E0;

/* Registers the cAIDisguiseTakenMsg network message (field formats, then the receive
 * handler cAIDisguiseTakenMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDisguiseTakenMsg_NetRegister(void) {
    L4E0 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) { ok = 0; do { if (!Event_UnpackHeader(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && NetMsg_RegisterType(&D_004FF118, 2, cAIDisguiseTakenMsg_NetReceive) == 0) r = 1; }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F4E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F4E0 */

/* merge_units: begin func_0026F570 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIDisguiseTakenMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF118)
#pragma pop /* merge_units */
/* merge_units: end func_0026F570 */

/* merge_units: begin func_0026F610 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; unsigned char flag; char pad2[11]; int whoId; int receiverId; } Evt26F610;
typedef struct { int header; int receiverId; int whoId; unsigned char flag; } Arg26F610;

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F610* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F610* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern char D_004DCC70[];
extern char D_004FF2B0[];
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIBodyMovedMsg (registered by cAIBodyMovedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id, flag} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIBodyMovedMsg_NetReceive(int a0, int a1, int a2, Arg26F610* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F610 e;
        void* obj;
        Arg26F610* a = arg;
        Evt26F610* p = &e;
        Event_Construct(p, D_004FF2B0);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC70;
        e.flag = a->flag;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F610 */

/* merge_units: begin func_0026F6F0 */
#pragma push /* merge_units */
extern int D_004FF110;
extern int cAIBodyMovedMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_0026F6F0;
/* Registers the cAIBodyMovedMsg network message (field formats, then the receive
 * handler cAIBodyMovedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIBodyMovedMsg_NetRegister(void) {
    L_0026F6F0 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!Event_UnpackHeader(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && func_002E9A98(&L.buf, &L.b, 1, 1) == 0 && NetMsg_RegisterType(&D_004FF110, 2, cAIBodyMovedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F6F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F6F0 */

/* merge_units: begin func_0026F7A0 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIBodyMovedMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((unsigned char*)buf)[0xC] = *(unsigned char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF110)
#pragma pop /* merge_units */
/* merge_units: end func_0026F7A0 */

/* merge_units: begin func_0026F850 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; signed char flag; char pad2[11]; int whoId; int receiverId; } Evt26F850;
typedef struct { int header; int receiverId; int whoId; signed char flag; } Arg26F850;

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F850* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F850* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern char D_004DCC90[];
extern char g_ScriptAINewAwarenessMsgKey[];
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAINewAwarenessMsg (registered by cAINewAwarenessMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id, flag} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAINewAwarenessMsg_NetReceive(int a0, int a1, int a2, Arg26F850* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F850 e;
        void* obj;
        Arg26F850* a = arg;
        Evt26F850* p = &e;
        Event_Construct(p, g_ScriptAINewAwarenessMsgKey);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC90;
        e.flag = a->flag;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F850 */

/* merge_units: begin func_0026F930 */
#pragma push /* merge_units */
extern int D_004FF108;
extern int cAINewAwarenessMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_0026F930;
/* Registers the cAINewAwarenessMsg network message (field formats, then the receive
 * handler cAINewAwarenessMsg_NetReceive). Returns 1 on success. */
unsigned char cAINewAwarenessMsg_NetRegister(void) {
    L_0026F930 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!Event_UnpackHeader(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && func_002E9A98(&L.buf, &L.b, 1, 1) == 0 && NetMsg_RegisterType(&D_004FF108, 2, cAINewAwarenessMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026F930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026F930 */

/* merge_units: begin func_0026F9E0 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAINewAwarenessMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((char*)buf)[0xC] = *(char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF108)
#pragma pop /* merge_units */
/* merge_units: end func_0026F9E0 */

/* merge_units: begin func_0026FA90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VObj26FA90 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FA90* sub; } Obj26FA90;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FA90;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FA90;
extern "C" {

extern void* NpcPath_GetNode(int id);
#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26FA90* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26F1D0 *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt26FA90* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26F1D0 *)(a0), (a1))) /* merge_units */


extern char D_004DCD50[];
extern char D_004DCCB0[];
extern char g_ScriptAIDestinationReachedMsgKey[];
}
#pragma push
#pragma optimization_level 3

#pragma opt_propagation off
/* Network receive handler for cAIDestinationReachedMsg (registered by cAIDestinationReachedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
extern "C" int cAIDestinationReachedMsg_NetReceive(int a0, int a1, int a2, Arg26FA90* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26FA90 e;
        Obj26FA90* obj;
        Arg26FA90* a = arg;
        Evt26FA90* p = &e;
        Event_Construct(p, g_ScriptAIDestinationReachedMsgKey);
        e.vt = D_004DCD50;
        if (a->n1 >= 0) p->n1 = NpcPath_GetNode(a->n1); else p->n1 = 0;
        if (a->n2 >= 0) p->n2 = NpcPath_GetNode(a->n2); else p->n2 = 0;
        p->vt = D_004DCCB0;
        e.receiverId = a->receiverId;
        obj = (Obj26FA90*)Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) {
            unsigned char ok = 0;
            if (obj->sub && obj->sub->Check()) ok = 1;
            if (ok) obj->sub->f210 = 0;
            MsgQueue_QueueClone(&e, obj, 0, 0);
        }
        e.vt = D_004DCD50;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FA90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FA90 */

/* merge_units: begin func_0026FBF0 */
#pragma push /* merge_units */
extern int D_004FF100;
extern int cAIDestinationReachedMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_0026FBF0;
/* Registers the cAIDestinationReachedMsg network message (field formats, then the receive
 * handler cAIDestinationReachedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDestinationReachedMsg_NetRegister(void) {
    L_0026FBF0 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!Event_UnpackHeader(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF100, 2, cAIDestinationReachedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FBF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FBF0 */

/* merge_units: begin func_0026FC80 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; int netId; } GFC80;
typedef struct { char pad[0x1C]; int size; char pad2[4]; GFC80* a; GFC80* b; } EFC80;
static inline void pack_FC80(EFC80* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    if (sz >= 0x10 && buf) {
        int* b = (int*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        if (e->a) b[2] = e->a->netId; else b[2] = -1;
        if (e->b) b[3] = e->b->netId; else b[3] = -1;
        e->size = 0x40;
    }
}
int cAIDestinationReachedMsg_v02(EFC80* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    int r = -1;
    if (sz >= 0x10 && buf) {
        pack_FC80(e, a1, type, a3, a4, sz, buf);
        if (type) {
            r = 0x10;
            *type = D_004FF100;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FC80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FC80 */

/* merge_units: begin func_0026FD50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VObj26FD50 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FD50* sub; } Obj26FD50;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FD50;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FD50;
extern "C" {
#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26FD50* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26F1D0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt26FD50* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26F1D0 *)(a0), (a1))) /* merge_units */

extern char D_004DCCD0[];
extern char g_ScriptAIWaypointReachedMsgKey[];
}
#pragma push
#pragma optimization_level 3

#pragma opt_propagation off
/* Network receive handler for cAIWaypointReachedMsg (registered by cAIWaypointReachedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
extern "C" int cAIWaypointReachedMsg_NetReceive(int a0, int a1, int a2, Arg26FD50* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26FD50 e;
        Obj26FD50* obj;
Arg26FD50* a = arg;
Evt26FD50* p = &e;
        Event_Construct(p, g_ScriptAIWaypointReachedMsgKey);
        e.vt = D_004DCD50;
        if (a->n1 >= 0) p->n1 = NpcPath_GetNode(a->n1); else p->n1 = 0;
        if (a->n2 >= 0) p->n2 = NpcPath_GetNode(a->n2); else p->n2 = 0;
        p->vt = D_004DCCD0;
        e.receiverId = a->receiverId;
        obj = (Obj26FD50*)Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) {
            if (a->n2 >= 0) {
            unsigned char ok = 0;
            if (obj->sub && obj->sub->Check()) ok = 1;
            if (ok) obj->sub->f210 = (int)NpcPath_GetNode(a->n2);
            }
            MsgQueue_QueueClone(&e, obj, 0, 0);
        }
        e.vt = D_004DCD50;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FD50 */

/* merge_units: begin func_0026FED0 */
#pragma push /* merge_units */
extern int D_004FF0F8;
extern int cAIWaypointReachedMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_0026FED0;
/* Registers the cAIWaypointReachedMsg network message (field formats, then the receive
 * handler cAIWaypointReachedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIWaypointReachedMsg_NetRegister(void) {
    L_0026FED0 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!Event_UnpackHeader(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF0F8, 2, cAIWaypointReachedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FED0 */

/* merge_units: begin func_0026FF60 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; int netId; } GFF60;
typedef struct { char pad[0x1C]; int size; char pad2[4]; GFF60* a; GFF60* b; } EFF60;
static inline void pack_FF60(EFF60* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    if (sz >= 0x10 && buf) {
        int* b = (int*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        if (e->a) b[2] = e->a->netId; else b[2] = -1;
        if (e->b) b[3] = e->b->netId; else b[3] = -1;
        e->size = 0x40;
    }
}
int cAIWaypointReachedMsg_v02(EFF60* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    int r = -1;
    if (sz >= 0x10 && buf) {
        pack_FF60(e, a1, type, a3, a4, sz, buf);
        if (type) {
            r = 0x10;
            *type = D_004FF0F8;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026FF60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026FF60 */

/* merge_units: begin func_00270030 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt270030;
typedef struct { int header; int receiverId; int whoId; } Arg270030;

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt270030* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt270030* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern char D_004DCCF0[];
extern char g_ScriptAIDeadMsgKey[];
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIDeadMsg (registered by cAIDeadMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIDeadMsg_NetReceive(int a0, int a1, int a2, Arg270030* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270030 e;
        void* obj;
        Arg270030* a = arg;
        Evt270030* p = &e;
        Event_Construct(p, g_ScriptAIDeadMsgKey);
        e.vt = D_004DCCF0;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCCF0;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270030 */

/* merge_units: begin func_00270100 */
#pragma push /* merge_units */
extern int D_004FF0F0;
extern int cAIDeadMsg_NetReceive();
/* Registers the cAIDeadMsg network message (field formats, then the receive
 * handler cAIDeadMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDeadMsg_NetRegister(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && Event_UnpackHeader(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_004FF0F0, 2, cAIDeadMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270100 */

/* merge_units: begin func_00270180 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int id; } AIDeadSrc;
typedef struct { int pad[7]; int size; int pad2; AIDeadSrc* src; } AIDeadMsg;
#if 0 /* merge_units */
extern void Event_PackHeader(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);
#endif /* merge_units */
#define Event_PackHeader(a0, a1, a2, a3, a4, a5, a6) (Event_PackHeader((void *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


int cAIDeadMsg_v02(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    int r = -1;
    if (len >= 0x10 && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        buf[2] = self->src->id;
        self->size = 0x40;
        if (type != 0) {
            r = 0x10;
            *type = D_004FF0F0;
        }
    }
    return r;
}
#undef Event_PackHeader /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270180 */

/* merge_units: begin func_00270210 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[9]; int receiverId; int pad2; } Evt270210;
typedef struct { int header; int receiverId; } Arg270210;

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt270210* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Evt270210* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern char D_004DCD10[];
extern char g_ScriptAIDeactivatedMsgKey[];
#pragma opt_common_subs off
/* Network receive handler for cAIDeactivatedMsg (registered by cAIDeactivatedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIDeactivatedMsg_NetReceive(int a0, int a1, int a2, Arg270210* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270210 e;
        void* obj;
        Event_Construct(&e, g_ScriptAIDeactivatedMsgKey);
        e.vt = D_004DCD10;
        e.receiverId = arg->receiverId;
        obj = Object_LookupById(&e.receiverId);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD10;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 8;
}



#pragma opt_common_subs reset
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270210 */

/* merge_units: begin func_002702C0 */
#pragma push /* merge_units */
extern int D_004FF0E8;
extern int cAIDeactivatedMsg_NetReceive();
/* Registers the cAIDeactivatedMsg network message (field formats, then the receive
 * handler cAIDeactivatedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDeactivatedMsg_NetRegister(void) {
    int buf[4];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && Event_UnpackHeader(buf + 2) != 0 &&
        NetMsg_RegisterType(&D_004FF0E8, 2, cAIDeactivatedMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002702C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002702C0 */

/* merge_units: begin func_00270330 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIDeactivatedMsg_v02, 0x8)
    Event_PackHeader(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0x8, D_004FF0E8)
#pragma pop /* merge_units */
/* merge_units: end func_00270330 */

/* merge_units: begin func_00270390 */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt270390;
typedef struct { int header; int receiverId; int whoId; } Arg270390;
#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt270390* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt270390* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char D_004DCD70[];
#endif /* merge_units */
#define D_004DCD70 ((char*)&D_004DCD70) /* merge_units */

extern char D_004DCD30[];
extern char g_ScriptAIActivatedMsgKey[];
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIActivatedMsg (registered by cAIActivatedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIActivatedMsg_NetReceive(int a0, int a1, int a2, Arg270390* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270390 e;
        void* obj;
        Arg270390* a = arg;
        Evt270390* p = &e;
        Event_Construct(p, g_ScriptAIActivatedMsgKey);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCD30;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef D_004DCD70 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270390 */

/* merge_units: begin func_00270470 */
#pragma push /* merge_units */
extern int D_004FF0E0;
extern int cAIActivatedMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_00270470;
/* Registers the cAIActivatedMsg network message (field formats, then the receive
 * handler cAIActivatedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIActivatedMsg_NetRegister(void) {
    L_00270470 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!Event_UnpackHeader(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF0E0, 2, cAIActivatedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270470 */

/* merge_units: begin func_00270500 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIActivatedMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF0E0)
#pragma pop /* merge_units */
/* merge_units: end func_00270500 */

/* merge_units: begin func_002705A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; int netId; } G05A0;
typedef struct { char pad[0x1C]; int size; char pad2[4]; G05A0* a; G05A0* b; } E05A0;
int cAINodeMsg_v02(E05A0* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    if (sz >= 0x10 && buf) {
        int* b = (int*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        if (e->a) b[2] = e->a->netId; else b[2] = -1;
        if (e->b) b[3] = e->b->netId; else b[3] = -1;
        e->size = 0x40;
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002705A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002705A0 */

/* merge_units: begin func_00270630 */
#pragma push /* merge_units */
int cAIGOBJMsg_v02(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00270630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00270630 */

/* merge_units: begin func_00270690 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCBF0[];
#endif /* merge_units */
#define D_004DCBF0 ((char*)&D_004DCBF0) /* merge_units */

MSG_CLONE_BEGIN(cAIWeaponFiredMsg_v01, 0x34, D_004A8C70, 0xFC)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCBF0;
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
    F(unsigned char, 0x30) = S(unsigned char, 0x30);
MSG_CLONE_END
#undef D_004DCBF0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270690 */

/* merge_units: begin func_002707C0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004DCC10[];
MSG_CLONE_BEGIN(cAITimeElapsedMsg_v01, 0x24, D_004A8CB0, 0x9D)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCC10;
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_002707C0 */

/* merge_units: begin func_002708C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCC30[];
#endif /* merge_units */
#define D_004DCC30 ((char*)&D_004DCC30) /* merge_units */

MSG_CLONE_BEGIN(cAIUnconsciousMsg_v01, 0x28, D_004A8C30, 0x158)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCC30;
MSG_CLONE_END
#undef D_004DCC30 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002708C0 */

/* merge_units: begin func_002709D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCC50[];
#endif /* merge_units */
#define D_004DCC50 ((char*)&D_004DCC50) /* merge_units */

MSG_CLONE_BEGIN(cAIDisguiseTakenMsg_v01, 0x28, D_004A8C40, 0x13C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCC50;
MSG_CLONE_END
#undef D_004DCC50 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002709D0 */

/* merge_units: begin func_00270AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCC70[];
#endif /* merge_units */
#define D_004DCC70 ((char*)&D_004DCC70) /* merge_units */

MSG_CLONE_BEGIN(cAIBodyMovedMsg_v01, 0x2C, D_004A8C50, 0x11E)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCC70;
    F(unsigned char, 0x28) = S(unsigned char, 0x28);
MSG_CLONE_END
#undef D_004DCC70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270AE0 */

/* merge_units: begin func_00270C00 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCC90[];
#endif /* merge_units */
#define D_004DCC90 ((char*)&D_004DCC90) /* merge_units */

MSG_CLONE_BEGIN(cAINewAwarenessMsg_v01, 0x2C, D_004A8C80, 0xE4)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCC90;
    F(char, 0x28) = S(char, 0x28);
MSG_CLONE_END
#undef D_004DCC90 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270C00 */

/* merge_units: begin func_00270D20 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCCB0[];
#endif /* merge_units */
#define D_004DCCB0 ((char*)&D_004DCCB0) /* merge_units */

#if 0 /* merge_units */
extern "C" char D_004DCD50[];
#endif /* merge_units */
#define D_004DCD50 ((char*)&D_004DCD50) /* merge_units */

MSG_CLONE_BEGIN(cAIDestinationReachedMsg_v01, 0x2C, D_004A8C90, 0xC7)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD50;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
    p->vt = D_004DCCB0;
MSG_CLONE_END
#undef D_004DCCB0 /* merge_units */
#undef D_004DCD50 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270D20 */

/* merge_units: begin func_00270E40 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCCD0[];
#endif /* merge_units */
#define D_004DCCD0 ((char*)&D_004DCCD0) /* merge_units */

#if 0 /* merge_units */
extern "C" char D_004DCD50[];
#endif /* merge_units */
#define D_004DCD50 ((char*)&D_004DCD50) /* merge_units */

MSG_CLONE_BEGIN(cAIWaypointReachedMsg_v01, 0x2C, D_004A8CA0, 0xAD)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD50;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
    p->vt = D_004DCCD0;
MSG_CLONE_END
#undef D_004DCCD0 /* merge_units */
#undef D_004DCD50 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270E40 */

/* merge_units: begin func_00270F60 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCCF0[];
#endif /* merge_units */
#define D_004DCCF0 ((char*)&D_004DCCF0) /* merge_units */

MSG_CLONE_BEGIN(cAIDeadMsg_v01, 0x2C, D_004A8CC0, 0x86)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCCF0;
    F(int, 0x24) = S(int, 0x24);
    F(char, 0x28) = S(char, 0x28);
MSG_CLONE_END
#undef D_004DCCF0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00270F60 */

/* merge_units: begin func_00271070 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCD10[];
#endif /* merge_units */
#define D_004DCD10 ((char*)&D_004DCD10) /* merge_units */

MSG_CLONE_BEGIN(cAIDeactivatedMsg_v01, 0x24, D_004A8CD0, 0x65)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD10;
MSG_CLONE_END
#undef D_004DCD10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271070 */

/* merge_units: begin func_00271170 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" char D_004DCD30[];
#endif /* merge_units */
#define D_004DCD30 ((char*)&D_004DCD30) /* merge_units */

MSG_CLONE_BEGIN(cAIActivatedMsg_v01, 0x28, D_004A8CE0, 0x4A)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCD30;
MSG_CLONE_END
#undef D_004DCD30 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271170 */
