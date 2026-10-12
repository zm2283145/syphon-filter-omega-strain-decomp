#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef union { __int128 q; float f[4]; } CxRuV4;
struct CxRuMtx { CxRuV4 rows[4];CxRuV4* Pos(){return rows+3;} };
struct CxRuActor { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual CxRuMtx Matrix();
    char pad4[8]; int serial;
};
struct CxRuBuffer {char pad[0x20];void* nodes;};
struct CxRuReq { CxRuActor* actor; int serial; int serial2; unsigned char type; char padD[7];CxRuBuffer* buffer;};
struct CxRuLink { CxRuLink* next; CxRuLink* prev; CxRuReq* req;};
struct CxRuList { int count; void* unk4; CxRuLink* head;};
struct CxRuManager { char pad[0x20]; CxRuList queue;};
struct CxRuIt { CxRuLink* link;};
extern "C" {
extern unsigned char D_004ED9D0;
extern int D_005383C8;
extern int D_004ED9C0[];
unsigned char NpcRoute_Search(CxRuReq*);
unsigned char NpcRoute_ScoreNodes(CxRuReq*);
void func_00138DA0(CxRuIt*,CxRuList*,CxRuIt*);
void func_001642B0(CxRuManager*,CxRuReq*);
CxRuActor* func_003FB8D0(int);
int NpcRoute_RegionAt(const CxRuV4*,int);
}
static inline CxRuActor* CxRu_Get(CxRuReq* req){ bool isNull;bool ok;CxRuActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}

extern "C" void NpcRoute_Update(CxRuManager* self){
    if(self->queue.count && !D_004ED9D0){
        CxRuReq* req;
        CxRuLink** head;
        head=&self->queue.head;
        req=(*head)->req;
        unsigned char done=1;
        if(CxRu_Get(req)){
            if(req->type==1){
                if(req->buffer && req->buffer->nodes)done=NpcRoute_Search(req);
            }else done=NpcRoute_ScoreNodes(req);
        }
        if(done){
            CxRuIt out; CxRuIt it;
            it.link=*head;
            func_00138DA0(&out,&self->queue,&it);
            func_001642B0(self,req);
        }
    }
    int slot=D_005383C8&3;
    if(slot<4 && func_003FB8D0(slot)){
        const CxRuV4* pos=func_003FB8D0(slot)->Matrix().Pos();
        int* region=&D_004ED9C0[slot];
        int id=NpcRoute_RegionAt(pos,*region);
        if(id>=0)*region=id;
    }
}
