/* ActorPhys_SelectEdgeRequest (retail successor of cHumanCollisionRoutine::TriggerResponseIfLedgeFound,
 * humanCollision.cc): walks the nine final ledge-search results from last to first, keeps the found
 * ledge with the highest priority, collects the "only report" subtype bits, sends one climb-failed CAS
 * event, then fires the action for the chosen ledge and a found-ledge report. Matched by lane X3.
 * Message objects keep their address in a pointer local (`T* s = this`) as retail does; the dead
 * volatile-asm trigger selects MW's less-optimised mode (unreduced loops and index arithmetic). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h" /* ALLOC_GUARD_DTOR: out-of-line dtor copies go to the discarded .dtors_drop */

struct cSystem;
struct cGOBJ;
struct cMessageName;
extern "C" {
extern cMessageName g_CasEventMsgClass;
extern cMessageName g_ActorActionMsgClass;
extern cMessageName D_004A0318;
extern char D_004DA950[], D_004E0840[], D_004E00E0[], D_004E0140[], D_004DAD40[];
void cMessage_ctor_cMessageNameR(void* m, cMessageName* n);
void cMessage_dtor(void* m, int flags);
void QueueMessage_cMessageR_cSystemP_int(void* m, cSystem* to, int immediate);
void cCharActionMsg_ctor_int_eParamType(void* m, int action, int type);
void cInteractParams_ctor_int_cQuatVecR_cGOBJP(void* p, int sub, void* xf, cGOBJ* g);
}

struct cBitArray1 {
    int chunks[1];
    cBitArray1() { int i; for (i = 0; i < 1; i++) chunks[i] = 0; }
    cBitArray1& operator|=(const cBitArray1& o) { int i; for (i = 0; i < 1; i++) chunks[i] |= o.chunks[i]; return *this; }
};
struct Q16 { __int128 q; };
struct cFinalLedgeSearchInfo {
    unsigned char mIsLedgeSearchRequested;
    unsigned char mOnlyReportFoundTypes;
    unsigned char mIsLedgeFound;
    char pad3[0x68 - 3];
    cGOBJ** owner;          /* 0x68 */
    char pad6C[4];
    cBitArray1 mSubtypes;   /* 0x70 */
    float priority;         /* 0x74 */
    char pad78[8];
    char mLedgeTransform[0x20]; /* 0x80 */
};
struct cArray9 {
    cFinalLedgeSearchInfo data[9];
    cFinalLedgeSearchInfo& operator[](int i) { return data[i]; }
};
struct cHumanCollisionRoutine {
    char pad0[0x3E0];
    cArray9 mFinalLedgeSearchInfoList;
    char pad980[0x9A7 - 0x980];
    unsigned char mRunningJumpDestinationType; /* 0x9A7 */
    char pad9A8[8];
    Q16 mRunningJumpDestination;               /* 0x9B0 */
};

struct cCasEventMsg {
    void* vt; char pad4[0x20]; int type; int id; int arg;
    cCasEventMsg(int t) { cCasEventMsg* s = this; cMessage_ctor_cMessageNameR(s, &g_CasEventMsgClass); s->vt = D_004DA950; s->type = t; s->id = -1; s->arg = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cCasEventMsg() { vt = D_004DA950; cMessage_dtor(this, 0); }
};
struct cCharActionMsg {
    void* vt; char pad4[0x1C]; unsigned char immediate; char pad21[0xF]; char params[0x30];
    cCharActionMsg(int sub, void* xf, cGOBJ* g) { cCharActionMsg* s = this; cCharActionMsg_ctor_int_eParamType(s, 0x2A, 0xE); cInteractParams_ctor_int_cQuatVecR_cGOBJP(s->params, sub, xf, g); s->vt = D_004E00E0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cCharActionMsg() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
struct cActorActionMsg {
    void* vt; char pad4[0x1C]; unsigned char immediate; char pad21[3]; int action; unsigned char kind; char pad29[7]; Q16 dest;
    cActorActionMsg(signed char a, const Q16& d) { cActorActionMsg* s = this; cMessage_ctor_cMessageNameR(s, &g_ActorActionMsgClass); s->vt = D_004E0840; s->action = a; s->kind = 4; s->vt = D_004E0140; { Q16* pd = &s->dest; __int128 t; /* 128-bit lq/sq copy (asm) */ __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&d), "r"(pd) : "memory"); } }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cActorActionMsg() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
struct cFoundLedgeMsg {
    void* vt; char pad4[0x20]; int types; char pad28[8];
    cFoundLedgeMsg(const cBitArray1& b) { cFoundLedgeMsg* s = this; int t = b.chunks[0]; cMessage_ctor_cMessageNameR(s, &D_004A0318); s->vt = D_004DAD40; s->types = t; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cFoundLedgeMsg() { vt = D_004DAD40; cMessage_dtor(this, 0); }
};

extern "C" void ActorPhys_SelectEdgeRequest(cHumanCollisionRoutine* self, cSystem* eventReceiver)
{
    float bestPriority = -3.4028235e38f;
    int best = -1;
    unsigned char reportFoundTypes = 0;
    unsigned char wasClimbFailedMessageSent = 0;
    cBitArray1 foundTypes;
    int i;
    if (0) { asm volatile { nop } } /* owner-approved dead trigger: retail is in MW's less-optimised mode */
    for (i = 8; i >= 0; i--) {
        cFinalLedgeSearchInfo* r = &self->mFinalLedgeSearchInfoList[i];
        if (!r->mIsLedgeSearchRequested)
            continue;
        if (r->mIsLedgeFound) {
            if (!r->mOnlyReportFoundTypes) {
                if (r->priority > bestPriority) {
                    bestPriority = r->priority;
                    best = i;
                }
            } else {
                foundTypes |= r->mSubtypes;
                reportFoundTypes = 1;
            }
        } else if (!r->mOnlyReportFoundTypes) {
            switch (i) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 7:
            case 8:
                if (!wasClimbFailedMessageSent) {
                    {
                    cCasEventMsg msg(8);
                    QueueMessage_cMessageR_cSystemP_int(&msg, eventReceiver, 1);
                    }
                    wasClimbFailedMessageSent = 1;
                }
                break;
            }
        } else {
            reportFoundTypes = 1;
        }
    }
    if (best >= 0) {
        cFinalLedgeSearchInfo& results = self->mFinalLedgeSearchInfoList[best];
        switch (best) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8: {
            cGOBJ** o = results.owner;
            int sub = results.mSubtypes.chunks[0];
            cCharActionMsg msg(sub, results.mLedgeTransform, *o);
            msg.immediate = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, eventReceiver, 1);
            break;
        }
        case 0: {
            signed char actionId;
            if (self->mRunningJumpDestinationType == 1)
                actionId = 0x15;
            else if (self->mRunningJumpDestinationType == 2)
                actionId = 0x16;
            {
                cActorActionMsg msg(actionId, self->mRunningJumpDestination);
                msg.immediate = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, eventReceiver, 1);
            }
            break;
        }
        }
    }
    if (reportFoundTypes) {
        cFoundLedgeMsg msg(foundTypes);
        QueueMessage_cMessageR_cSystemP_int(&msg, eventReceiver, 1);
    }
}
