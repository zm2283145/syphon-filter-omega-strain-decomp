#pragma cplusplus on
#pragma inline_depth(12)
#include "types.h"
struct CxRelActor{char pad[0xC];int serial;};
struct CxRelReq{CxRelActor* actor;int serial;};
struct CxRelLink{CxRelLink*next;CxRelLink*prev;CxRelReq*req;};
struct CxRelList{int count;void*unused;CxRelLink*head;};
struct CxRelManager{char pad[0x20];CxRelList queue;};
struct CxRelIt{CxRelLink*link;};
struct CxRelTag{};
struct CxRelPredicate{CxRelTag tag;CxRelReq**req;CxRelPredicate(const CxRelTag&t,CxRelReq**p):tag(t),req(p){} };
extern "C" {
void func_0015F770(CxRelIt*,CxRelList*);
void func_0015F760(CxRelIt*,CxRelIt*);
void func_0015F750(CxRelIt*,CxRelList*);
void func_001642B0(CxRelManager*,CxRelReq*);
void ActiveList_EraseMatching(CxRelList*,CxRelPredicate);
extern unsigned char D_004ED9D0;
}
static inline CxRelActor* CxRel_Get(CxRelReq* req){bool isNull;bool ok;CxRelActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxRel_First0(CxRelIt*out,CxRelList*l){CxRelIt tmp;func_0015F770(&tmp,l);func_0015F760(out,&tmp);}
static inline void CxRel_First00(CxRelIt*out,CxRelList*l){CxRel_First0(out,l);}
static inline CxRelLink* CxRel_First(CxRelList*l){CxRelIt out;CxRel_First00(&out,l);return out.link;}
static inline CxRelIt CxRel_Begin(CxRelList*l){CxRelIt out;CxRelIt converted;CxRel_First00(&converted,l);out.link=converted.link;return out;}
static inline void CxRel_End0(CxRelIt*out,CxRelList*l){CxRelIt tmp;func_0015F750(&tmp,l);func_0015F760(out,&tmp);}
static inline void CxRel_End00(CxRelIt*out,CxRelList*l){CxRel_End0(out,l);}
static inline CxRelLink* CxRel_End(CxRelList*l){CxRelIt out;CxRel_End00(&out,l);return out.link;}
static inline void CxRel_Erase(CxRelList*l,const CxRelTag& tag,CxRelReq**req){CxRelPredicate p(tag,req);ActiveList_EraseMatching(l,p);}
static inline void CxRel_Erase0(CxRelList*l,CxRelReq**req){CxRelTag tag;CxRel_Erase(l,tag,req);}
static inline void ErWrap(CxRelList*l,CxRelReq**r){CxRel_Erase0(l,r);}
extern "C" void NpcRoute_Release(CxRelManager*self,CxRelActor*actor){
    bool removed;
    CxRelLink*first=CxRel_First(&self->queue);
    do{
        removed=false;
        CxRelIt cur=CxRel_Begin(&self->queue);
        for(;cur.link!=CxRel_End(&self->queue);cur.link=cur.link->prev){
            if(actor){int*serial=&actor->serial;int id=CxRel_Get(cur.link->req)->serial;if(id!=*serial)continue;}
            {
                if(cur.link==first && D_004ED9D0==1)D_004ED9D0=2;
                func_001642B0(self,cur.link->req);
                ErWrap(&self->queue,&cur.link->req);
                removed=true;
                break;
            }

        }
    }while(removed);
}
