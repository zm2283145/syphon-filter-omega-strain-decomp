/*
 * SFOGame/Source/path: 2 files, 0015E830-0015EBC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015E830 */
#pragma push /* merge_units */
/* cNodeRequest_AddNeighborsToGroupList: for every node of the current region that has
 * links, add the group of each type-10 (region link) target node to the
 * candidate list unless it is already there (cost: base + squared distance
 * from the start point or from the linking node). */
#pragma cplusplus on
#include "types.h"
/* lq/sq and VU0 ops: no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
} __attribute__((aligned(16)));
static inline void SubV(V4* pr, const V4* pa, const V4* pb) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(pa), "r"(pr), "r"(pb) : "memory"); }
static inline V4 operator-(const V4& a, const V4& b) { V4 r; SubV(&r, &a, &b); return r; }
static inline float SumSq(V4 v)
{
    V4* p = &v;
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
/* iterators are copied as one float word (retail lwc1/swc1) */
union It4 { int* p; float f; };
union It8 { int* p; float f; };
struct Link { int id; int type; };
struct PNode { char p0[0x64]; int flags; char links[0x14]; int group; };
struct NodeTab { int p0; int n; PNode** data; };
struct Region { char p0[0x10]; };
struct RegionVec { int p0; int n; Region* data; };
struct Ent { int id; int b; int c; };
struct Route { char p0[0x440]; V4 start; char p450[0x484 - 0x450]; Ent e[32]; int count; };
struct Ctx { int region; int mode; float cost; };
extern "C" {
extern NodeTab* D_004FFBE0;
extern RegionVec* D_004FFBE8;
void std_vector_int_begin(It4* out, Region* c);
void std_vector_int_end_void(It4* out, Region* c);
void cArray_int_ConstIterator_ctor(It4* out, It4* raw);
int* std_vector_imp_tNodeLink_begin_void_2(void* c);
int* std_vector_imp_tNodeLink_end_void_2(void* c);
void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(It8* out, void* c, int** raw);
V4 cNode_GetLoc(PNode* n);
void cNodeRequest_AddNeighborsToGroupList(Route* self, Ctx* ctx);
}
static inline bool Eq4(const It4& a, const It4& b) { int* x = a.p; return b.p == x; }
static inline bool Eq8(const It8& a, const It8& b) { return a.p == b.p; }

void cNodeRequest_AddNeighborsToGroupList(Route* self, Ctx* ctx)
{
    It4 it1;
    It8 it2;
    It4 t134;
    It8 t130;
    It8 end2;
    It4 end1;
    It8 t124;
    It8 t120;
    It4 raw11C;
    int* raw118;
    int* raw114;
    It4 raw110;
    NodeTab* tab = D_004FFBE0;
    Region* rg = &D_004FFBE8->data[ctx->region];
    std_vector_int_begin(&raw11C, rg);
    cArray_int_ConstIterator_ctor(&t134, &raw11C);
    it1 = t134;
    while ((std_vector_int_end_void(&raw110, rg), cArray_int_ConstIterator_ctor(&end1, &raw110), !Eq4(end1, it1))) {
        PNode* n = tab->data[*it1.p];
        if (n->flags & 0x80) {
            void* c = n->links;
            std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t124, c, (raw118 = std_vector_imp_tNodeLink_begin_void_2(c), &raw118));
            t130.p = t124.p;
            it2 = t130;
            while ((std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t120, c, (raw114 = std_vector_imp_tNodeLink_end_void_2(c), &raw114)), (end2.p = t120.p, !Eq8(it2, end2)))) {
                Link* l = (Link*)it2.p;
                if (l->type == 10) {
                    PNode* m = tab->data[l->id];
                    int grp = m->group;
                    int j;
                    int found = -1;
                    for (j = 0; j < self->count; j++) {
                        if (self->e[j].id == grp) {
                            found = j;
                            break;
                        }
                    }
                    if (found < 0) {
                        float cost = ctx->cost;
                        if (ctx->mode < 0)
                            cost += SumSq(cNode_GetLoc(m) - self->start);
                        else
                            cost += SumSq(cNode_GetLoc(m) - cNode_GetLoc(n));
                        self->e[self->count].id = grp;
                        self->e[self->count].b = -1;
                        self->e[self->count].c = 0;
                        self->count++;
                    }
                }
                it2.p += 2;
            }
        }
        it1.p += 1;
    }
}
static inline void merge_flush_func_0015E830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015E830 */

/* merge_units: begin func_0015EBC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
#include "vc_copy.h"
/* cPathSystem_RequestNodeIndexFromGroup: queue (or reuse) a route search request; report immediate results to the requester */
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
extern "C" void cMessage_getSOBJClassId();
extern "C" void cPathMessage_dtor();
extern "C" void cPathMessage_Clone();
void * const D_004D9760[6] = { (void*)0x0, (void*)0x0, (void*)cPathMessage_dtor, (void*)cPathMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId };
void cMessage_ctor_cMessageNameR(void* msg, void* name);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
Pt1NsReq* cPathSystem_GetRequestPending(Pt1NsRouter* r, Pt1NsActor* a, int kind);
void cLList_cPathSystemRequestPtr_Begin(Pt1NsIt* it, void* queue);
void cConstLListIterator_cPathSystemRequestPtr_opMul(Pt1NsIt* it);
Pt1NsResult* cPathSystem_FindSimilarPastRequest_cGOBJP_eRequestType_cVectorR_cVectorR_etc(Pt1NsRouter* r, Pt1NsActor* a, int kind, Pt1NsV4* from, Pt1NsV4* to, int mask, Pt1NsArea* area);
Pt1NsReq* cPathSystem_GetRequest(Pt1NsRouter* r);
int cPathSystem_Request(Pt1NsRouter* r, Pt1NsReq* req);
}

/* empty then-arm kept as its own block (barrier, emits nothing) */
static inline Pt1NsActor* Pt1Ns_Root(Pt1NsActor* a) { if (!a->owner) asm { .set reorder } else a = a->owner; return a; }
static inline unsigned char Pt1Ns_Submit(Pt1NsRouter* r, Pt1NsReq* req) { return cPathSystem_Request(r, req); }
#pragma push
#pragma opt_propagation off
extern "C" unsigned char cPathSystem_RequestNodeIndexFromGroup(Pt1NsRouter* r, Pt1NsActor* actor, Pt1NsArea* area, Pt1NsV4* from, Pt1NsV4* to, int route, int mask, float maxDist, signed char mode, int extra)
{
    int none;
    unsigned char result = 0;
    if (route >= 0) {
        unsigned char created = 0;
        Pt1NsReq* req = cPathSystem_GetRequestPending(r, actor, 2);
        if (req) {
            Pt1NsIt it;
            cLList_cPathSystemRequestPtr_Begin(&it, r->queue);
            cConstLListIterator_cPathSystemRequestPtr_opMul(&it);
        } else {
            Pt1NsResult* res = cPathSystem_FindSimilarPastRequest_cGOBJP_eRequestType_cVectorR_cVectorR_etc(r, actor, 2, from, to, mask, area);
            if (res) {
                if (res->node >= 0) {
                    Pt1NsMsg m;
                    Pt1NsMsg* mp;
                    int node;
                    int node2;
                    node = res->node;
                    node2 = res->node2;
                    mp = &m;
                    cMessage_ctor_cMessageNameR(mp, D_004ED9B8);
                    mp->vt = ((char*)D_004D9760);
                    mp->found = 0;
                    mp->node = node;
                    mp->node2 = node2;
                    actor = Pt1Ns_Root(actor);
                    QueueMessage_cMessageR_cSystemP_int(&m, actor, 1);
                    m.vt = ((char*)D_004D9760);
                    cMessage_dtor(&m, 0);
                } else {
                    Pt1NsMsg m;
                    Pt1NsMsg* mp = &m;
                    cMessage_ctor_cMessageNameR(mp, D_004ED9B8);
                    mp->vt = ((char*)D_004D9760);
                    mp->found = 1;
                    mp->node = -1;
                    actor = Pt1Ns_Root(actor);
                    QueueMessage_cMessageR_cSystemP_int(&m, actor, 1);
                    m.vt = ((char*)D_004D9760);
                    cMessage_dtor(&m, 0);
                }
                return 1;
            }
            req = cPathSystem_GetRequest(r);
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
        cMessage_ctor_cMessageNameR(mp, D_004ED9B8);
        mp->vt = ((char*)D_004D9760);
        mp->found = 1;
        mp->node = -1;
        actor = Pt1Ns_Root(actor);
        QueueMessage_cMessageR_cSystemP_int(&m, actor, 1);
        m.vt = ((char*)D_004D9760);
        cMessage_dtor(&m, 0);
    }
    return result;
}
#pragma pop
static inline void merge_flush_func_0015EBC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015EBC0 */
