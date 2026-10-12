#pragma cplusplus on
#include "types.h"
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
