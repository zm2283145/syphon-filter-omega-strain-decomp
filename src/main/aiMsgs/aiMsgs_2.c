/*
 * main/aiMsgs: 14 files, 0026F1D0-0026FBF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin cAIUnconsciousMsg_NetReceive */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt26F1D0;
typedef struct { int header; int receiverId; int whoId; } Arg26F1D0;
extern void Event_Construct(Evt26F1D0* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt26F1D0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26F1D0* e, int f);
extern char D_004DCD70[];
extern char D_004DCC30[];
extern char D_004FF2C0[];
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
        Event_Construct(p, D_004FF2C0);
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
#pragma pop /* merge_units */
/* merge_units: end cAIUnconsciousMsg_NetReceive */

/* merge_units: begin cAIUnconsciousMsg_NetRegister */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
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
    if (!busy) { ok = 0; do { if (!func_003C9C30(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && !busy && NetMsg_RegisterType(&D_004FF120, 2, cAIUnconsciousMsg_NetReceive) == 0) r = 1; }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIUnconsciousMsg_NetRegister */

/* merge_units: begin cAIUnconsciousMsg_v02 */
#pragma push /* merge_units */
#include "ai_msg_pack.h"

AIMSG_PACK_BEGIN(cAIUnconsciousMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF120)
#pragma pop /* merge_units */
/* merge_units: end cAIUnconsciousMsg_v02 */

/* merge_units: begin cAIDisguiseTakenMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt26F400;
typedef struct { int header; int receiverId; int whoId; } Arg26F400;
#if 0 /* merge_units */
extern void Event_Construct(Evt26F400* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26F1D0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F400* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26F1D0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F400* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26F1D0 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAIDisguiseTakenMsg_NetReceive */

/* merge_units: begin cAIDisguiseTakenMsg_NetRegister */
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
    if (!func_002E9A10()) { ok = 0; do { if (!func_003C9C30(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && NetMsg_RegisterType(&D_004FF118, 2, cAIDisguiseTakenMsg_NetReceive) == 0) r = 1; }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIDisguiseTakenMsg_NetRegister */

/* merge_units: begin cAIDisguiseTakenMsg_v02 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIDisguiseTakenMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF118)
#pragma pop /* merge_units */
/* merge_units: end cAIDisguiseTakenMsg_v02 */

/* merge_units: begin cAIBodyMovedMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; unsigned char flag; char pad2[11]; int whoId; int receiverId; } Evt26F610;
typedef struct { int header; int receiverId; int whoId; unsigned char flag; } Arg26F610;
#if 0 /* merge_units */
extern void Event_Construct(Evt26F610* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26F1D0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F610* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26F1D0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F610* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26F1D0 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAIBodyMovedMsg_NetReceive */

/* merge_units: begin cAIBodyMovedMsg_NetRegister */
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
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && func_002E9A98(&L.buf, &L.b, 1, 1) == 0 && NetMsg_RegisterType(&D_004FF110, 2, cAIBodyMovedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIBodyMovedMsg_NetRegister */

/* merge_units: begin cAIBodyMovedMsg_v02 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIBodyMovedMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((unsigned char*)buf)[0xC] = *(unsigned char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF110)
#pragma pop /* merge_units */
/* merge_units: end cAIBodyMovedMsg_v02 */

/* merge_units: begin cAINewAwarenessMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; signed char flag; char pad2[11]; int whoId; int receiverId; } Evt26F850;
typedef struct { int header; int receiverId; int whoId; signed char flag; } Arg26F850;
#if 0 /* merge_units */
extern void Event_Construct(Evt26F850* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26F1D0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt26F850* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26F1D0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt26F850* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26F1D0 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAINewAwarenessMsg_NetReceive */

/* merge_units: begin cAINewAwarenessMsg_NetRegister */
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
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && func_002E9A98(&L.buf, &L.b, 1, 1) == 0 && NetMsg_RegisterType(&D_004FF108, 2, cAINewAwarenessMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAINewAwarenessMsg_NetRegister */

/* merge_units: begin cAINewAwarenessMsg_v02 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAINewAwarenessMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((char*)buf)[0xC] = *(char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF108)
#pragma pop /* merge_units */
/* merge_units: end cAINewAwarenessMsg_v02 */

/* merge_units: begin cAIDestinationReachedMsg_NetReceive */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct VObj26FA90 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FA90* sub; } Obj26FA90;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FA90;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FA90;
extern "C" {
#if 0 /* merge_units */
extern void Event_Construct(Evt26FA90* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26F1D0 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAIDestinationReachedMsg_NetReceive */

/* merge_units: begin cAIDestinationReachedMsg_NetRegister */
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
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF100, 2, cAIDestinationReachedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIDestinationReachedMsg_NetRegister */
