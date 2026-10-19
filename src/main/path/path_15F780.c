/*
 * main/path: range (4 files, 0015F780-0015FB20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
void func_0015F770(CxCaIt*,CxCaList*);
void func_0015F760(CxCaIt*,CxCaIt*);
void func_0015F750(CxCaIt*,CxCaList*);
}
static inline CxCaActor* CxCa_Get(CxCaReq*req){bool isNull;bool ok;CxCaActor*actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok?actor:0;}
static inline void CxCa_Begin0(CxCaIt*out,CxCaList*l){CxCaIt temp;func_0015F770(&temp,l);func_0015F760(out,&temp);}
static inline CxCaIt CxCa_Begin(CxCaList*l){CxCaIt out;CxCa_Begin0(&out,l);return out;}
static inline void CxCa_End0(CxCaIt*out,CxCaList*l){CxCaIt temp;func_0015F750(&temp,l);func_0015F760(out,&temp);}
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
extern "C" CxCaReq*NpcRoute_NodeSearchCached(CxCaManager*self,CxCaActor*actor,int kind,CxCaV4*from,CxCaV4*to,int mask,CxCaArea*area){
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
#pragma pop /* merge_units */
/* merge_units: end func_0015F780 */

/* merge_units: begin func_0015F9B0 */
#pragma push /* merge_units */
typedef struct CxPathNode { char pad[0x7C]; int region; } CxPathNode;
typedef struct CxPathFollower { char pad[0x5C]; int current; char gap60[0x10]; void* actor; void* buffer; } CxPathFollower;
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern void* Service_Lookup(void*, void*);
extern CxPathNode* NpcPath_GetNode(int);
extern int NpcRoute_Request(void*,void*,int,int,int,int,int,int,long long);
int func_0015F9B0(CxPathFollower* self,int start,int destination,int useRegion) {
    int region=-1;
    void* manager=Service_Lookup(g_Game,g_NpcRouteMgr);
    if(useRegion && destination>=0) region=NpcPath_GetNode(destination)->region;
    return NpcRoute_Request(manager,self->actor,start,-1,self->current,destination,region,useRegion,(long long)(int)self->buffer);
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
unsigned char NpcPath_RequestRoute(CxPathFollower2* self,int kind,int region) {
    void* manager=Service_Lookup(g_Game,g_NpcRouteMgr);
    int start=self->start;
    int previous=-1;
    if(self->flags.first || self->flags.second) {
        if(start<0) {start=self->fallback;previous=self->previous;}
    }
    return NpcRoute_Request(manager,self->actor,start,previous,self->current,-1,region,kind,(long long)(int)self->buffer);
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
extern int NpcRoute_Request(void*, int, int, int, int, int, int, int, int);
#endif /* merge_units */
#define NpcRoute_Request(a0, a1, a2, a3, a4, a5, a6, a7, a8) (NpcRoute_Request((a0), (void *)(a1), (a2), (a3), (a4), (a5), (a6), (a7), (long long)(a8))) /* merge_units */

unsigned char NpcRoute_RequestToNode(Route_e1* self, int arg)
{
    void* svc = Service_Lookup(g_Game, g_NpcRouteMgr);
    int node = self->node;
    int extra = -1;
    if (self->b1 || self->b2) {
        if (node < 0) {
            node = self->altNode;
            extra = self->altArg;
        }
    }
    return NpcRoute_Request(svc, self->a1arg, node, extra, self->t0arg, arg, -1, 0, self->stackArg);
}
#undef NpcRoute_Request /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FB20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015FB20 */
