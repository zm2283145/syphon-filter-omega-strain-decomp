#pragma cplusplus on
#include "types.h"
struct CxHpActor {char pad[0xC];int serial;};
struct CxHpReq { CxHpActor* actor;int serial;char pad8[6];unsigned char reported;};
struct CxHpLink {CxHpLink* next;CxHpLink* prev;CxHpReq* req;};
struct CxHpList {int count;void* unused;CxHpLink* head;};
struct CxHpManager {char pad[0x20];CxHpList queue;};
struct CxHpIt { CxHpLink* link;};
extern "C" void func_00163FA0(CxHpIt*,CxHpList*);
extern "C" void func_00163F90(CxHpIt*,CxHpIt*);
static inline CxHpActor* CxHp_Get(CxHpReq* req){bool isNull;bool ok;CxHpActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxHp_Conv(CxHpIt* out,CxHpList* l){CxHpIt it;func_00163FA0(&it,l);func_00163F90(out,&it);}
static inline int PendingCopy(CxHpIt other){return (unsigned char)!other.link->req->reported;}
static inline int Pending0(CxHpList*l){CxHpIt temp;temp.link=l->head;return PendingCopy(temp);}
/* Nested iterator conversion preserves separate temporary lifetimes. */
static inline void Conv0(CxHpIt*out,CxHpList*l){CxHp_Conv(out,l);}
static inline void Conv1(CxHpIt*out,CxHpList*l){Conv0(out,l);}
extern "C" int NpcRoute_IsHeadPending(CxHpManager* self,CxHpActor* actor){
    int result=0;
    if(self->queue.count>0){
        int* serial=&actor->serial;
        CxHpIt converted;
        Conv1(&converted,&self->queue);
        int id=CxHp_Get(converted.link->req)->serial;
        if(id==*serial){
            result=Pending0(&self->queue);
        }
    }
    return result;
}
