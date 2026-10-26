#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
/* NpcRoute_NodeSearch: queue (or reuse) a route search request; report immediate results to the requester */
typedef union { __int128 q; struct { float x, y, z, w; } f; } Pt1NsV4;
typedef struct Pt1NsArea { float a; float b; unsigned char c; } Pt1NsArea;
typedef struct Pt1NsActor { char pad0[0xC]; int serial; char pad10[0x58 - 0x10]; struct Pt1NsActor* owner; } Pt1NsActor;
typedef struct Pt1NsResult { char pad0[0x478]; int node; int node2; } Pt1NsResult;
typedef struct Pt1NsReq {
    Pt1NsActor* actor;
    int serial;
    int serial2;
    unsigned char state;
    unsigned char dirty;
    unsigned char reported;
    char padF[0x430 - 0xF];
    float areaA;
    float areaB;
    unsigned char areaC;
    char pad439[0x440 - 0x439];
    Pt1NsV4 from;
    Pt1NsV4 to;
    float maxDist;
    int route;
    int mask;
    signed char mode;
    char pad46D[3];
    int extra;
    char pad474[0x480 - 0x474];
    unsigned char reverse;
    unsigned char retry;
    unsigned char crouched;
} Pt1NsReq;
typedef struct Pt1NsMsg {
    void* vt;
    char pad4[0x20];
    unsigned char found;
    char pad25[3];
    int node;
    int node2;
} Pt1NsMsg;
typedef struct Pt1NsRouter { char pad0[0x20]; char queue[0x10]; } Pt1NsRouter;
typedef struct { int i; } Pt1NsIt;
extern "C" {
extern char D_004ED9B8[];
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern "C" void cPathMessage_dtor();
extern "C" void cPathMessage_Clone();
void * const D_004D9760[6] = { (void*)0x0, (void*)0x0, (void*)cPathMessage_dtor, (void*)cPathMessage_Clone, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey };
void Event_Construct(void* msg, void* name);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
Pt1NsReq* NpcRoute_IsQueued(Pt1NsRouter* r, Pt1NsActor* a, int kind);
void cLList_cPathSystemRequestPtr_Begin(Pt1NsIt* it, void* queue);
void cConstLListIterator_cPathSystemRequestPtr_opMul(Pt1NsIt* it);
Pt1NsResult* NpcRoute_NodeSearchCached(Pt1NsRouter* r, Pt1NsActor* a, int kind, Pt1NsV4* from, Pt1NsV4* to, int mask, Pt1NsArea* area);
Pt1NsReq* NpcRouteMgr_TakeFreeRequest(Pt1NsRouter* r);
int NpcRouteMgr_QueueRequest(Pt1NsRouter* r, Pt1NsReq* req);
}

/* empty then-arm kept as its own block (barrier, emits nothing) */
static inline Pt1NsActor* Pt1Ns_Root(Pt1NsActor* a) { if (!a->owner) asm { .set reorder } else a = a->owner; return a; }
static inline unsigned char Pt1Ns_Submit(Pt1NsRouter* r, Pt1NsReq* req) { return NpcRouteMgr_QueueRequest(r, req); }
#pragma push
#pragma opt_propagation off
extern "C" unsigned char NpcRoute_NodeSearch(Pt1NsRouter* r, Pt1NsActor* actor, Pt1NsArea* area, Pt1NsV4* from, Pt1NsV4* to, int route, int mask, float maxDist, signed char mode, int extra)
{
    int none;
    unsigned char result = 0;
    if (route >= 0) {
        unsigned char created = 0;
        Pt1NsReq* req = NpcRoute_IsQueued(r, actor, 2);
        if (req) {
            Pt1NsIt it;
            cLList_cPathSystemRequestPtr_Begin(&it, r->queue);
            cConstLListIterator_cPathSystemRequestPtr_opMul(&it);
        } else {
            Pt1NsResult* res = NpcRoute_NodeSearchCached(r, actor, 2, from, to, mask, area);
            if (res) {
                if (res->node >= 0) {
                    Pt1NsMsg m;
                    Pt1NsMsg* mp;
                    int node;
                    int node2;
                    node = res->node;
                    node2 = res->node2;
                    mp = &m;
                    Event_Construct(mp, D_004ED9B8);
                    mp->vt = ((char*)D_004D9760);
                    mp->found = 0;
                    mp->node = node;
                    mp->node2 = node2;
                    actor = Pt1Ns_Root(actor);
                    Event_Send(&m, actor, 1);
                    m.vt = ((char*)D_004D9760);
                    cMessage_dtor(&m, 0);
                } else {
                    Pt1NsMsg m;
                    Pt1NsMsg* mp = &m;
                    Event_Construct(mp, D_004ED9B8);
                    mp->vt = ((char*)D_004D9760);
                    mp->found = 1;
                    mp->node = -1;
                    actor = Pt1Ns_Root(actor);
                    Event_Send(&m, actor, 1);
                    m.vt = ((char*)D_004D9760);
                    cMessage_dtor(&m, 0);
                }
                return 1;
            }
            req = NpcRouteMgr_TakeFreeRequest(r);
            req->dirty = 1;
            req->reported = 0;
            req->state = 2;
            req->actor = actor;
            req->serial = *(actor ? &actor->serial : (none = -1, &none));
            if (actor)
                req->serial2 = actor->serial;
            created = 1;
        }
        req->areaA = area->a;
        req->areaB = area->b;
        req->areaC = area->c;
        VCopyF(&req->from, from);
        VCopyF(&req->to, to);
        req->maxDist = maxDist;
        req->route = route;
        req->mask = mask;
        req->mode = mode;
        req->extra = extra;
        req->reverse = 0;
        req->retry = 0;
        req->crouched = 0;
        if(created) { Pt1NsRouter* p=r; /* Scheduling barrier preserves the unfilled conditional delay slot. */ asm { .set reorder } result=Pt1Ns_Submit(p,req); }
    } else {
        Pt1NsMsg m;
        Pt1NsMsg* mp = &m;
        Event_Construct(mp, D_004ED9B8);
        mp->vt = ((char*)D_004D9760);
        mp->found = 1;
        mp->node = -1;
        actor = Pt1Ns_Root(actor);
        Event_Send(&m, actor, 1);
        m.vt = ((char*)D_004D9760);
        cMessage_dtor(&m, 0);
    }
    return result;
}
#pragma pop