#pragma cplusplus on
#include "types.h"
struct CxIqActor {char pad[0xC];int serial;};
struct CxIqReq { CxIqActor* actor;int serial;char pad8[4];unsigned char type;};
struct CxIqLink {CxIqLink* next;CxIqLink* prev;CxIqReq* req;};
struct CxIqList {int count;void* unused;CxIqLink* head;};
struct CxIqManager {char pad[0x20];CxIqList queue;};
struct CxIqIt { CxIqLink* link;CxIqReq* Req(){return link->req;} };
extern "C" void func_00163FA0(CxIqIt*,CxIqList*);
extern "C" void func_00163F90(CxIqIt*,CxIqIt*);
extern "C" void func_00163F60(CxIqIt*,CxIqList*);
static inline CxIqActor* CxIq_Get(CxIqReq* req){bool isNull;bool ok;CxIqActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxIq_Begin0(CxIqIt*out,CxIqList*l){CxIqIt temp;func_00163FA0(&temp,l);func_00163F90(out,&temp);}
static inline CxIqIt CxIq_Begin(CxIqList* l){CxIqIt converted;CxIq_Begin0(&converted,l);return converted;}
static inline void CxIq_End0(CxIqIt*out,CxIqList*l){CxIqIt temp;func_00163F60(&temp,l);func_00163F90(out,&temp);}
static inline CxIqLink* CxIq_End(CxIqList*l){CxIqIt out;CxIq_End0(&out,l);return out.link;}
extern "C" CxIqReq* NpcRoute_IsQueued(CxIqManager* self,CxIqActor* actor,int mask){
    CxIqReq* result=0;
    if(actor){
        CxIqIt cur=CxIq_Begin(&self->queue);
        while(cur.link!=CxIq_End(&self->queue)){
            int* serial=&actor->serial;
            CxIqReq* req=cur.Req();
            int id=CxIq_Get(req)->serial;
            if(id==*serial && (mask&req->type)){
                result=req;
                break;
            }
            cur.link=cur.link->prev;
        }
    }
    return result;
}
