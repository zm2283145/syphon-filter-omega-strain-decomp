#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
/* gcc-style asm, not MW asm{}: any MW asm{} block stops mw38 filling branch delay slots from the fall-through path */
static inline void VCopyF(void* d, const void* s) {
    void* dd = d; const void* ss = s; __int128 t;
    __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=&r"(t) : "r"(ss), "r"(dd) : "memory");
}
#include "vslot_pad.h"
/* cPathSystem_RequestPath: queue (or reuse) a node-to-node route request; trivial/cached results are reported immediately */
typedef union { __int128 q; struct { float x, y, z, w; } f; } RqV4;
struct RqMat { RqV4 r[3]; RqV4 t; RqMat() {} RqMat(const RqMat& o); RqV4& Pos() { return t; } };
struct RqMat; struct RqActor { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual RqMat GetXform(); char pad4[0xC - 0x4]; int serial; char pad10[0x14 - 0x10]; unsigned char direct; char pad15[0x58 - 0x15]; struct RqActor* owner; };
typedef struct RqCached { char pad0[0x11]; unsigned char flags; } RqCached;
typedef struct RqOut { RqV4 pos; int node; char pad14[0x20 - 0x14]; int* list; int pad24; int count; } RqOut;
typedef struct RqNode { char pad0[0x7C]; int area; } RqNode;
typedef struct RqReq {
    RqActor* actor;
    int serial;
    int serial2;
    unsigned char state;
    unsigned char dirty;
    unsigned char reported;
    char padF[0x12 - 0xF];
    unsigned char fromNode;
    char pad13;
    RqOut* out;
    char pad18[0x20 - 0x18];
    RqV4 goal;
    RqV4 start;
    int startNode;
    int arg3;
    int arg4;
    int endNode;
    int goalArea;
    int progress;
} RqReq;
typedef struct RqMsg {
    void* vt;
    char pad4[0x20];
    unsigned char found;
    char pad25[3];
    int node;
    int node2;
} RqMsg;
typedef struct RqRouter { char pad0[0x20]; char queue[0x10]; } RqRouter;
typedef struct { int i; } RqIt;
extern "C" {
extern char D_004ED9B8[];
extern void* const D_004D9760[6];
void cMessage_ctor_cMessageNameR(void* msg, void* name);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
RqReq* cPathSystem_GetRequestPending(RqRouter* r, RqActor* a, int kind);
void cLList_cPathSystemRequestPtr_Begin(RqIt* it, void* queue);
RqReq** cConstLListIterator_cPathSystemRequestPtr_opMul(RqIt* it);
RqCached* cPathSystem_FindSimilarPastRequest_int_int_int_int_etc(RqRouter* r, int startNode, int arg4, int endNode, int goalArea, RqV4* start, RqV4* goal);
RqReq* cPathSystem_GetRequest(RqRouter* r);
int cPathSystem_Request(RqRouter* r, RqReq* req);
void cPathSystem_FreeRequest(RqRouter* r, RqReq* req);
unsigned char cPathRequest_Update(RqReq* req);
RqNode* cAIPathData_GetNode(int node);
void cNode_GetLoc(RqV4* out, RqNode* node);
}

/* asm volatile{} keeps the empty then-block (barrier) without disabling fall-through delay-slot filling */
static inline RqActor* Rq_Root(RqActor* a) { if (!a->owner) asm volatile { .set reorder } else a = a->owner; return a; }
#pragma push
#pragma opt_propagation off
extern "C" unsigned char cPathSystem_RequestPath(RqRouter* r, RqActor* actor, int startNode, int arg3, int arg4, int endNode, int goalArea, RqV4* goal, RqOut* out)
{
    int none;
    unsigned char result;
    if (!out)
        return 0;
    if (startNode != endNode || (goal && actor && actor->direct)) {
        unsigned char created = 0;
        RqReq* req = cPathSystem_GetRequestPending(r, actor, 1);
        RqMat m = actor->GetXform();
        RqMat* mq = &m;
        RqV4* start = &mq->t;
        if (req) {
            RqIt it;
            cLList_cPathSystemRequestPtr_Begin(&it, r->queue);
            if (req != *cConstLListIterator_cPathSystemRequestPtr_opMul(&it))
                goto fill;
        }
        {
            RqCached* c = cPathSystem_FindSimilarPastRequest_int_int_int_int_etc(r, startNode, arg4, endNode, goalArea, start, goal);
            if (c && c->flags < 0) {
                RqMsg m2;
                if (actor) {
                RqMsg* mp = &m2;
                cMessage_ctor_cMessageNameR(mp, D_004ED9B8);
                mp->vt = ((char*)D_004D9760);
                mp->found = 3;
                mp->node = -1;
                actor = Rq_Root(actor);
                QueueMessage_cMessageR_cSystemP_int(&m2, actor, 1);
                m2.vt = ((char*)D_004D9760);
                cMessage_dtor(&m2, 0);
                return 1;
                }
            }
        }
        req = cPathSystem_GetRequest(r);
        req->dirty = 1;
        req->reported = 0;
        req->state = 1;
        req->actor = actor;
        req->serial = *(actor ? &actor->serial : (none = -1, &none));
        if (actor)
            req->serial2 = actor->serial;
        created = 1;
fill:
        req->out = out;
        req->startNode = startNode;
        req->arg3 = arg3;
        VCopyF(&req->start, start);
        req->endNode = endNode;
        if (goal) {
            VCopyF(&req->goal, goal);
            req->goalArea = goalArea;
            req->fromNode = 0;
        } else {
            RqNode* n = cAIPathData_GetNode(endNode);
            RqV4 t;
            req->goalArea = n->area;
            cNode_GetLoc(&t, n);
            VCopyF(&req->goal, &t);
            req->fromNode = 1;
        }
        req->arg4 = arg4;
        if (created) {
            req->progress = 0;
            if (startNode >= 0 && endNode >= 0 && arg4 != goalArea) {
                result = cPathRequest_Update(req);
                cPathSystem_FreeRequest(r, req);
            } else {
                result = cPathSystem_Request(r, req);
            }
        }
    } else {
        out->count = 0;
        if (endNode >= 0) {
            out->list[out->count] = endNode;
            out->count++;
        }
        if ((actor && actor->direct) || !goal) {
            RqNode* n = cAIPathData_GetNode(endNode);
            RqV4 t;
            cNode_GetLoc(&t, n);
            VCopyF(&out->pos, &t);
            out->node = endNode;
        } else {
            VCopyF(&out->pos, goal);
            out->node = -1;
        }
        if (actor) {
            RqMsg m3;
            RqMsg* mp;
            actor = Rq_Root(actor);
            mp = &m3;
            cMessage_ctor_cMessageNameR(mp, D_004ED9B8);
            mp->vt = ((char*)D_004D9760);
            mp->found = 2;
            mp->node = -1;
            QueueMessage_cMessageR_cSystemP_int(&m3, actor, 1);
            m3.vt = ((char*)D_004D9760);
            cMessage_dtor(&m3, 0);
        }
        result = 1;
    }
    return result;
}
#pragma pop
