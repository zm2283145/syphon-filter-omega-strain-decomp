/*
 * SFOGame/Source/path: 10 files, 0015F750-0015FCE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015F750 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cPathSystemRequestPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cPathSystemRequestPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cPathSystemRequestPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_0015F750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015F750 */

/* merge_units: begin func_0015F780 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) CxCaV4;
struct CxCaArea {float a,b;unsigned char flags;};
struct CxCaActor {char pad[0xC];int serial;};
struct CxCaReq {CxCaActor* actor;int serial;char pad8[4];unsigned char type,dirty,reported;char padF[0x438-0xF];unsigned char flags;char pad439[7];CxCaV4 from,to;char pad460[8];int mask;};
struct CxCaLink {CxCaLink*next;CxCaLink*prev;CxCaReq*req;};
struct CxCaList {int count;void*unused;CxCaLink*head;};
struct CxCaManager {char pad[0x2C];CxCaList cache;};
struct CxCaIt {CxCaLink*link;CxCaReq*Req(){return link->req;}};
extern "C" {
#if 0 /* merge_units */
void std_list_cPathSystemRequestPtr_begin_void(CxCaIt*,CxCaList*);
#endif /* merge_units */
#define std_list_cPathSystemRequestPtr_begin_void(a0, a1) (std_list_cPathSystemRequestPtr_begin_void((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
void cLListIterator_cPathSystemRequestPtr_ctor(CxCaIt*,CxCaIt*);
#endif /* merge_units */
#define cLListIterator_cPathSystemRequestPtr_ctor(a0, a1) ((void)cLListIterator_cPathSystemRequestPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


#if 0 /* merge_units */
void std_list_cPathSystemRequestPtr_end_void(CxCaIt*,CxCaList*);
#endif /* merge_units */
#define std_list_cPathSystemRequestPtr_end_void(a0, a1) (std_list_cPathSystemRequestPtr_end_void((Iter *)(a0), (Tree *)(a1))) /* merge_units */


}
static inline CxCaActor* CxCa_Get(CxCaReq*req){bool isNull;bool ok;CxCaActor*actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok?actor:0;}
static inline void CxCa_Begin0(CxCaIt*out,CxCaList*l){CxCaIt temp;std_list_cPathSystemRequestPtr_begin_void(&temp,l);cLListIterator_cPathSystemRequestPtr_ctor(out,&temp);}
static inline CxCaIt CxCa_Begin(CxCaList*l){CxCaIt out;CxCa_Begin0(&out,l);return out;}
static inline void CxCa_End0(CxCaIt*out,CxCaList*l){CxCaIt temp;std_list_cPathSystemRequestPtr_end_void(&temp,l);cLListIterator_cPathSystemRequestPtr_ctor(out,&temp);}
static inline CxCaLink* CxCa_End(CxCaList*l){CxCaIt out;CxCa_End0(&out,l);return out.link;}
/* VU equality uses its MAC flags after a four-cycle latency. */
static inline int CxCa_Equal(CxCaV4*a,CxCaV4*b){
    int result,mask,flags;
    asm{
        .set noreorder
        lqc2 vf1,0(a)
        lqc2 vf2,0(b)
        vsub.xyzw vf3,vf1,vf2
        and result,zero,zero
        ori mask,zero,15
        vnop
        vnop
        vnop
        vnop
        cfc2.ni flags,vi17
        bne mask,flags,done
        nop
        ori result,zero,1
    done:
        .set reorder
    }
    return result;
}
static inline bool CxCa_Area(CxCaArea*a,CxCaReq*r){
    bool result=false;
    /* The original compares each query bound with itself. */
    bool selfEqual=a->a==a->a && a->b==a->b;
    if(selfEqual)if(a->flags==r->flags)result=true;
    return result;
}
extern "C" CxCaReq*cPathSystem_FindSimilarPastRequest_cGOBJP_eRequestType_cVectorR_cVectorR_etc(CxCaManager*self,CxCaActor*actor,int kind,CxCaV4*from,CxCaV4*to,int mask,CxCaArea*area){
    CxCaIt cur=CxCa_Begin(&self->cache);
    for(;cur.link!=CxCa_End(&self->cache);cur.link=cur.link->prev){
        CxCaReq* req=cur.Req();
        if(CxCa_Get(req)!=actor)continue;
        if(req->type!=2)continue;
        if(!req->reported)continue;
        if(mask!=req->mask)continue;
        if(!CxCa_Equal(from,&req->from))continue;
        if(!CxCa_Equal(to,&req->to))continue;
        if(!CxCa_Area(area,req))continue;
        return req;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015F780(void) {}
#undef std_list_cPathSystemRequestPtr_begin_void /* merge_units */
#undef cLListIterator_cPathSystemRequestPtr_ctor /* merge_units */
#undef std_list_cPathSystemRequestPtr_end_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015F780 */

/* merge_units: begin func_0015F9B0 */
#pragma push /* merge_units */
typedef struct CxPathNode { char pad[0x7C]; int region; } CxPathNode;
typedef struct CxPathFollower { char pad[0x5C]; int current; char gap60[0x10]; void* actor; void* buffer; } CxPathFollower;
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern void* cSystemContainer_GetSystem(void*, void*);
extern CxPathNode* cAIPathData_GetNode(int);
extern int cPathSystem_RequestPath(void*,void*,int,int,int,int,int,int,long long);
int cPathNavigator_Request_int_int_cVectorP(CxPathFollower* self,int start,int destination,int useRegion) {
    int region=-1;
    void* manager=cSystemContainer_GetSystem(g_Game,g_NpcRouteMgr);
    if(useRegion && destination>=0) region=cAIPathData_GetNode(destination)->region;
    return cPathSystem_RequestPath(manager,self->actor,start,-1,self->current,destination,region,useRegion,(long long)(int)self->buffer);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015F9B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015F9B0 */

/* merge_units: begin func_0015FA70 */
#pragma push /* merge_units */
typedef struct CxRouteBits { unsigned long long zero:1; unsigned long long first:1; unsigned long long second:1; } CxRouteBits;
typedef struct CxPathFollower2 {
    char pad[0x4C]; int start; int fallback; int previous; int unk58; int current;
    CxRouteBits flags;
    char pad64[12];
    void* actor; void* buffer;
} CxPathFollower2;
unsigned char cPathNavigator_Request_cVectorR_int(CxPathFollower2* self,int kind,int region) {
    void* manager=cSystemContainer_GetSystem(g_Game,g_NpcRouteMgr);
    int start=self->start;
    int previous=-1;
    if(self->flags.first || self->flags.second) {
        if(start<0) {start=self->fallback;previous=self->previous;}
    }
    return cPathSystem_RequestPath(manager,self->actor,start,previous,self->current,-1,region,kind,(long long)(int)self->buffer);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FA70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015FA70 */

/* merge_units: begin func_0015FB20 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x4C]; int node; int altNode; int altArg; char pad58[4]; int t0arg;
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char rest : 5;
    char pad61[0x70 - 0x61]; int a1arg; int stackArg;
} Route_e1;
#if 0 /* merge_units */
extern int cPathSystem_RequestPath(void*, int, int, int, int, int, int, int, int);
#endif /* merge_units */
#define cPathSystem_RequestPath(a0, a1, a2, a3, a4, a5, a6, a7, a8) (cPathSystem_RequestPath((a0), (void *)(a1), (a2), (a3), (a4), (a5), (a6), (a7), (long long)(a8))) /* merge_units */



unsigned char cPathNavigator_Request_int(Route_e1* self, int arg)
{
    void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
    int node = self->node;
    int extra = -1;
    if (self->b1 || self->b2) {
        if (node < 0) {
            node = self->altNode;
            extra = self->altArg;
        }
    }
    return cPathSystem_RequestPath(svc, self->a1arg, node, extra, self->t0arg, arg, -1, 0, self->stackArg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FB20(void) {}
#undef cPathSystem_RequestPath /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FB20 */

/* merge_units: begin func_0015FBD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void CopyV(V* d, const V* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *(__int128*)d = t; }
struct V {    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }

    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V operator-(const V& b) const { V c; SubV(&c, this, &b); return c; }
} __attribute__((aligned(16)));
struct M { V r[4]; M() {} V& Pos() { return r[3]; } };
class Actor {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual M GetMatrix();
};
struct cPath {
    V destination;
    int destinationNodeIndex;
    int restoreFirstNode;
    int restoreLastNode;
    int pad1C;
    int* nodes;
    int capacity;
    int size;
};
struct cPathNavigator {
    V nextDestination;
    V pathDelta;
    V pathStart;
    V pathSaveDestination;
    float distanceToNextPoint;
    float pathSegmentLength;
    int pathIndex;
    int nodeIndex;
    int nextNodeIndex;
    int previousNodeIndex;
    int destinationNodeIndex;
    int nodeGroupIndex;
    unsigned char onPatrolPath : 1;
    unsigned char onPath : 1;
    unsigned char forceOnNodes : 1;
    unsigned char destinationReachedFlag : 1;
    unsigned char humanDestinationReached : 1;
    unsigned char humanDestinationReachedPrevious : 1;
    unsigned char firstActivation : 1;
    char pad61[0xF];
    Actor* gobj;
    cPath* path;
    int maxPathNodeCount;
};
extern "C" {
int cPathNavigator_NextPathSegment(cPathNavigator* self);
void cPathNavigator_ForceDestination(cPathNavigator* self, const V& destinationPosition, int);
}
static inline V GetPosition(Actor* a) { M m = a->GetMatrix(); M* pm = &m; return pm->r[3]; }
void cPathNavigator_ForceDestination(cPathNavigator* self, const V& destinationPosition, int)
{
    if (self->path) {
        if (self->path->size > 0) self->path->size = 0;
        self->path->destination = destinationPosition;
        {
            cPath* p = self->path;
            p->destinationNodeIndex = -1;
        }
        self->nextNodeIndex = -1;
        self->pathIndex = self->path->size;
        self->destinationNodeIndex = self->path->destinationNodeIndex;
        self->destinationReachedFlag = !cPathNavigator_NextPathSegment(self);
        self->pathStart = destinationPosition;
        self->nextDestination = destinationPosition;
        self->pathDelta = self->nextDestination - self->gobj->GetMatrix().Pos();
    }
}
static inline void merge_flush_func_0015FBD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FBD0 */

/* merge_units: begin func_0015FCE0 */
#pragma push /* merge_units */
#pragma opt_propagation off
/* cPathNavigator_PathFloorZ: height along the current path segment (node height, interpolated, or clamped) */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Pt1PhV4;
typedef struct Pt1PhPath {
    char pad0[0x8];
    float fromHeight;
    char padC[0x28 - 0xC];
    float toHeight;
    char pad2C[0x40 - 0x2C];
    float dist;
    float length;
    char pad48[0x4C - 0x48];
    int node;
    int segB;
    int segA;
} Pt1PhPath;
#if 0 /* merge_units */
extern void* cAIPathData_GetNode(int node);
#endif /* merge_units */
#define cAIPathData_GetNode(a0) ((void *)cAIPathData_GetNode((a0))) /* merge_units */

extern void cNode_GetLoc(Pt1PhV4* out, void* node);
static inline float Pt1Ph_Min(float a, float b) { float r; asm { min.s r, a, b } return r; }
#pragma fp_contract off
static inline float Mul(float x,float y) {return x*y;}
float cPathNavigator_PathFloorZ(Pt1PhPath* p, int clamp, int useNode)
{
    float r;
    if (p->node >= 0 && !useNode) {
        Pt1PhV4 v;
        cNode_GetLoc(&v, cAIPathData_GetNode(p->node));
        r = v.z;
    } else if (p->segA >= 0 && p->segB >= 0) {
        float d;
        float len;
        if (clamp || !((len = p->length, d = p->dist) <= 1.0f + len) || useNode)
            r = Pt1Ph_Min(p->toHeight, p->fromHeight);
        else
        {
            r = p->toHeight * d;
            r = r + Mul(p->fromHeight,(len-d));
            r = r / len;
        }
    } else {
        r = p->toHeight;
    }
    return r;
}
#undef cAIPathData_GetNode /* merge_units */
static inline void merge_flush_func_0015FCE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FCE0 */

/* merge_units: begin func_0015FDC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Writes one scalar into two fields.
 */

#include "path_types.h"

void NpcPath_SetHeight(PathScalarPair* self, float value) {
    self->unk08 = value;
    self->unk28 = value;
}
static inline void merge_flush_func_0015FDC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FDC0 */

/* merge_units: begin func_0015FDD0 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
#include "vc_copy.h"

#pragma cplusplus on
struct E8Mtx { float m[12]; float px, py, pz, pw; E8Mtx() {} float* Pos() { return &px; } float Z() { return pz; } };
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct E8Obj {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34)
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual E8Mtx GetMatrix(); /* 0xF4 */
};
struct E8Nav {
    char pad00[8];
    float y08;          /* 0x08 */
    char pad0C[0x28 - 0x0C];
    float y28;          /* 0x28 */
    char pad2C[0x54 - 0x2C];
    int node;           /* 0x54 */
    char pad58[4];
    int target;         /* 0x5C */
    char pad60[0x70 - 0x60];
    E8Obj* obj;         /* 0x70 */
};
extern "C" void cPathNavigator_SetNodeIndex(E8Nav* self, int n);
extern "C" int cAIPathData_GetClosestNodeIndex(int n, float* pos, int flags, int ex);
extern "C" void cPathNavigator_UpdateGobjBeingTransported(E8Nav* self, int n)
{
    cPathNavigator_SetNodeIndex(self, -1);
    if (n >= 0 && n != self->target) {
        self->target = n;
        int r = cAIPathData_GetClosestNodeIndex(n, self->obj->GetMatrix().Pos(), 0x80, -1);
        if (r >= 0) self->node = r;
    }
    float z = self->obj->GetMatrix().Z();
    self->y08 = z;
    self->y28 = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015FDD0 */

/* merge_units: begin func_0015FE80 */
#pragma push /* merge_units */
#pragma cplusplus on
/* NpcPath route-to-node: queue node, set destination to its translation, notify the actor's owner */
struct SnV4 { __int128 q; };
struct SnActor { char pad[0x58]; SnActor* owner; };
struct SnRoute { SnV4 dest; int target; char pad14[0xC]; int* nodes; int cap; int count; };
struct SnPath { char pad[0x70]; SnActor* actor; SnRoute* route; };
struct SnMsg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
#if 0 /* merge_units */
void* cAIPathData_GetNode(int id);
#endif /* merge_units */
#define cAIPathData_GetNode(a0) ((void *)cAIPathData_GetNode((a0))) /* merge_units */


#if 0 /* merge_units */
void cNode_GetLoc(SnV4* out, void* node);
#endif /* merge_units */
#define cNode_GetLoc(a0, a1) (cNode_GetLoc((Pt1PhV4 *)(a0), (a1))) /* merge_units */


void cMessage_ctor_cMessageNameR(SnMsg* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(SnMsg* m, SnActor* to, int flags);
void cMessage_dtor(SnMsg* m, int flags);
}
static inline void Push(SnRoute* r, int v) { r->nodes[r->count] = v; r->count++; }
static inline void Construct(SnMsg* m) { cMessage_ctor_cMessageNameR(m, D_004ED9B8); m->vt = D_004D9760; m->kind = 2; m->id = -1; }
static inline void Destroy(SnMsg* loc) { loc->vt = D_004D9760; cMessage_dtor(loc, 0); }
#pragma opt_propagation off
extern "C" bool cPathNavigator_FallToNode(SnPath* self, int node)
{
    bool r = false;
    SnRoute* rt = self->route;
    if (rt->nodes) {
    rt->count = 0;
    Push(self->route, node);
    {
        SnV4 t;
        cNode_GetLoc(&t, cAIPathData_GetNode(node));
        VCopyF(&self->route->dest, &t);
        self->route->target = node;
    }
    {
        SnMsg msg;
        SnMsg* m = &msg;
        Construct(m);
        SnActor* a = self->actor;
        SnActor* o = a->owner; SnActor* to = a; if (!o) { asm { .set reorder } /* scheduling barrier: keeps retail's empty then-arm (b + nop) */ } else to = o; QueueMessage_cMessageR_cSystemP_int(&msg, to, 1);
        Destroy(&msg);
    }
    r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FE80(void) {}
#undef cAIPathData_GetNode /* merge_units */
#undef cNode_GetLoc /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FE80 */
