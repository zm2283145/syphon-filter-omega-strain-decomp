/*
 * main/aiMsgs: 4 files, 00270330-00270500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin cAIDeactivatedMsg_v02 */
#pragma push /* merge_units */
#include "types.h"
#include "ai_msg_pack.h"
extern int D_004FF0E8;
AIMSG_PACK_BEGIN(cAIDeactivatedMsg_v02, 0x8)
    Event_PackHeader(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0x8, D_004FF0E8)
#pragma pop /* merge_units */
/* merge_units: end cAIDeactivatedMsg_v02 */

/* merge_units: begin cAIActivatedMsg_NetReceive */
#pragma push /* merge_units */
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt270390;
typedef struct { int header; int receiverId; int whoId; } Arg270390;
extern void Event_Construct(Evt270390* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt270390* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt270390* e, int f);
extern char D_004DCD70[];
extern char D_004DCD30[];
extern char D_004FF268[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
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
        Event_Construct(p, D_004FF268);
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
#pragma pop /* merge_units */
/* merge_units: end cAIActivatedMsg_NetReceive */

/* merge_units: begin cAIActivatedMsg_NetRegister */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
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
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && NetMsg_RegisterType(&D_004FF0E0, 2, cAIActivatedMsg_NetReceive) == 0) r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end cAIActivatedMsg_NetRegister */

/* merge_units: begin cAIActivatedMsg_v02 */
#pragma push /* merge_units */
AIMSG_PACK_BEGIN(cAIActivatedMsg_v02, 0xC)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0xC, D_004FF0E0)
#pragma pop /* merge_units */
/* merge_units: end cAIActivatedMsg_v02 */
