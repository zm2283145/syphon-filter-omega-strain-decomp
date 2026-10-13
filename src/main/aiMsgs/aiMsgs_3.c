/*
 * main/aiMsgs: 9 files, 0026FC80-002702C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin cAIDestinationReachedMsg_v02 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
typedef struct { char pad[0x78]; int netId; } GFC80;
typedef struct { char pad[0x1C]; int size; char pad2[4]; GFC80* a; GFC80* b; } EFC80;
extern int D_004FF100;
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
#pragma pop /* merge_units */
/* merge_units: end cAIDestinationReachedMsg_v02 */

/* merge_units: begin cAIWaypointReachedMsg_NetReceive */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct VObj26FD50 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FD50* sub; } Obj26FD50;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FD50;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FD50;
extern "C" {
extern void Event_Construct(Evt26FD50* e, void* type);
extern void* Object_LookupById(int* id);
extern void* NpcPath_GetNode(int id);
extern void MsgQueue_QueueClone(Evt26FD50* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26FD50* e, int f);
extern char D_004DCD50[];
extern char D_004DCCD0[];
extern char g_ScriptAIWaypointReachedMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
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
#pragma pop /* merge_units */
/* merge_units: end cAIWaypointReachedMsg_NetReceive */

/* merge_units: begin cAIWaypointReachedMsg_NetRegister */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
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
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF0F8, 2, cAIWaypointReachedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIWaypointReachedMsg_NetRegister */

/* merge_units: begin cAIWaypointReachedMsg_v02 */
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
#pragma pop /* merge_units */
/* merge_units: end cAIWaypointReachedMsg_v02 */

/* merge_units: begin cAIDeadMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt270030;
typedef struct { int header; int receiverId; int whoId; } Arg270030;
#if 0 /* merge_units */
extern void Event_Construct(Evt270030* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26FD50 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt270030* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26FD50 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt270030* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26FD50 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAIDeadMsg_NetReceive */

/* merge_units: begin cAIDeadMsg_NetRegister */
#pragma push /* merge_units */
extern int D_004FF0F0;
extern int cAIDeadMsg_NetReceive();
/* Registers the cAIDeadMsg network message (field formats, then the receive
 * handler cAIDeadMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDeadMsg_NetRegister(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_004FF0F0, 2, cAIDeadMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIDeadMsg_NetRegister */

/* merge_units: begin cAIDeadMsg_v02 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int id; } AIDeadSrc;
typedef struct { int pad[7]; int size; int pad2; AIDeadSrc* src; } AIDeadMsg;
#if 0 /* merge_units */
extern void Event_PackHeader(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);
#endif /* merge_units */
#define Event_PackHeader(a0, a1, a2, a3, a4, a5, a6) (Event_PackHeader((void *)(a0), (a1), (a2), (a3), (a4), (a5), (void *)(a6))) /* merge_units */

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
#pragma pop /* merge_units */
/* merge_units: end cAIDeadMsg_v02 */

/* merge_units: begin cAIDeactivatedMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[9]; int receiverId; int pad2; } Evt270210;
typedef struct { int header; int receiverId; } Arg270210;
#if 0 /* merge_units */
extern void Event_Construct(Evt270210* e, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Evt26FD50 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void MsgQueue_QueueClone(Evt270210* e, void* obj, int a, int b);
#endif /* merge_units */
#define MsgQueue_QueueClone(a0, a1, a2, a3) (MsgQueue_QueueClone((Evt26FD50 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Evt270210* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Evt26FD50 *)(a0), (a1))) /* merge_units */

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
#undef Event_Construct /* merge_units */
#undef MsgQueue_QueueClone /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end cAIDeactivatedMsg_NetReceive */

/* merge_units: begin cAIDeactivatedMsg_NetRegister */
#pragma push /* merge_units */
extern int D_004FF0E8;
extern int cAIDeactivatedMsg_NetReceive();
/* Registers the cAIDeactivatedMsg network message (field formats, then the receive
 * handler cAIDeactivatedMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDeactivatedMsg_NetRegister(void) {
    int buf[4];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf + 2) != 0 &&
        NetMsg_RegisterType(&D_004FF0E8, 2, cAIDeactivatedMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIDeactivatedMsg_NetRegister */
