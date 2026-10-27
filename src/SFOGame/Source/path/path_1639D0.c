/*
 * main/path: range (5 files, 001639D0-00163E20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001639D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

extern "C" {
extern char D_004D9740[];
extern char D_004D9730[];
extern char D_004D9720[];
void operator_delete(void* allocation);
}

struct Member_3A3210 { void* vtable; };
struct Obj_3A3210 {
    void* vtable;
    Member_3A3210 a;
    int pad[2];
    Member_3A3210 b;
};

static inline void MemberDtor_3A3210(Member_3A3210* m)
{
    if (m) {
        m->vtable = D_004D9730;
        if (m)
            m->vtable = D_004D9720;
    }
}

extern "C" Obj_3A3210* cInsertList_cNodeIndex_dtor(Obj_3A3210* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004D9740;
        MemberDtor_3A3210(&self->b);
        MemberDtor_3A3210(&self->a);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001639D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001639D0 */

/* merge_units: begin func_00163A70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cInsertList_cNodeIndex_cStartNode_dtor, D_004D9730, D_004D9720)
#pragma pop /* merge_units */
/* merge_units: end func_00163A70 */

/* merge_units: begin func_00163AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern int g_VideoFrameCounter;
extern int g_NpcRegionTable[];
unsigned char cPathRequest_Update(CxRuReq*);
unsigned char cNodeRequest_Update(CxRuReq*);
void std_list_deleter_voidPtr_erase_listdeleter(CxRuIt*,CxRuList*,CxRuIt*);
void cPathSystem_FreeRequest(CxRuManager*,CxRuReq*);
CxRuActor* cNetObj_GetPlayer(int);
int cAIPathData_GetGroupIndex(const CxRuV4*,int);
}
static inline CxRuActor* CxRu_Get(CxRuReq* req){ bool isNull;bool ok;CxRuActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}

extern "C" void cPathSystem_NextFrame(CxRuManager* self){
    if(self->queue.count && !D_004ED9D0){
        CxRuReq* req;
        CxRuLink** head;
        head=&self->queue.head;
        req=(*head)->req;
        unsigned char done=1;
        if(CxRu_Get(req)){
            if(req->type==1){
                if(req->buffer && req->buffer->nodes)done=cPathRequest_Update(req);
            }else done=cNodeRequest_Update(req);
        }
        if(done){
            CxRuIt out; CxRuIt it;
            it.link=*head;
            std_list_deleter_voidPtr_erase_listdeleter(&out,&self->queue,&it);
            cPathSystem_FreeRequest(self,req);
        }
    }
    int slot=g_VideoFrameCounter&3;
    if(slot<4 && cNetObj_GetPlayer(slot)){
        const CxRuV4* pos=cNetObj_GetPlayer(slot)->Matrix().Pos();
        int* region=&g_NpcRegionTable[slot];
        int id=cAIPathData_GetGroupIndex(pos,*region);
        if(id>=0)*region=id;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163AD0 */

/* merge_units: begin func_00163C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(12)
struct CxRelActor{char pad[0xC];int serial;};
struct CxRelReq{CxRelActor* actor;int serial;};
struct CxRelLink{CxRelLink*next;CxRelLink*prev;CxRelReq*req;};
struct CxRelList{int count;void*unused;CxRelLink*head;};
struct CxRelManager{char pad[0x20];CxRelList queue;};
struct CxRelIt{CxRelLink*link;};
struct CxRelTag{};
struct CxRelPredicate{CxRelTag tag;CxRelReq**req;CxRelPredicate(const CxRelTag&t,CxRelReq**p):tag(t),req(p){} };
extern "C" {
void std_list_cPathSystemRequestPtr_begin_void(CxRelIt*,CxRelList*);
void cLListIterator_cPathSystemRequestPtr_ctor(CxRelIt*,CxRelIt*);
void std_list_cPathSystemRequestPtr_end_void(CxRelIt*,CxRelList*);
#if 0 /* merge_units */
void cPathSystem_FreeRequest(CxRelManager*,CxRelReq*);
#endif /* merge_units */
#define cPathSystem_FreeRequest(a0, a1) (cPathSystem_FreeRequest((CxRuManager *)(a0), (CxRuReq *)(a1))) /* merge_units */

void std_list_imp_voidPtr_remove_if(CxRelList*,CxRelPredicate);
}
static inline CxRelActor* CxRel_Get(CxRelReq* req){bool isNull;bool ok;CxRelActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxRel_First0(CxRelIt*out,CxRelList*l){CxRelIt tmp;std_list_cPathSystemRequestPtr_begin_void(&tmp,l);cLListIterator_cPathSystemRequestPtr_ctor(out,&tmp);}
static inline void CxRel_First00(CxRelIt*out,CxRelList*l){CxRel_First0(out,l);}
static inline CxRelLink* CxRel_First(CxRelList*l){CxRelIt out;CxRel_First00(&out,l);return out.link;}
static inline CxRelIt CxRel_Begin(CxRelList*l){CxRelIt out;CxRelIt converted;CxRel_First00(&converted,l);out.link=converted.link;return out;}
static inline void CxRel_End0(CxRelIt*out,CxRelList*l){CxRelIt tmp;std_list_cPathSystemRequestPtr_end_void(&tmp,l);cLListIterator_cPathSystemRequestPtr_ctor(out,&tmp);}
static inline void CxRel_End00(CxRelIt*out,CxRelList*l){CxRel_End0(out,l);}
static inline CxRelLink* CxRel_End(CxRelList*l){CxRelIt out;CxRel_End00(&out,l);return out.link;}
static inline void CxRel_Erase(CxRelList*l,const CxRelTag& tag,CxRelReq**req){CxRelPredicate p(tag,req);std_list_imp_voidPtr_remove_if(l,p);}
static inline void CxRel_Erase0(CxRelList*l,CxRelReq**req){CxRelTag tag;CxRel_Erase(l,tag,req);}
static inline void ErWrap(CxRelList*l,CxRelReq**r){CxRel_Erase0(l,r);}
extern "C" void cPathSystem_ClearRequests(CxRelManager*self,CxRelActor*actor){
    bool removed;
    CxRelLink*first=CxRel_First(&self->queue);
    do{
        removed=false;
        CxRelIt cur=CxRel_Begin(&self->queue);
        for(;cur.link!=CxRel_End(&self->queue);cur.link=cur.link->prev){
            if(actor){int*serial=&actor->serial;int id=CxRel_Get(cur.link->req)->serial;if(id!=*serial)continue;}
            {
                if(cur.link==first && D_004ED9D0==1)D_004ED9D0=2;
                cPathSystem_FreeRequest(self,cur.link->req);
                ErWrap(&self->queue,&cur.link->req);
                removed=true;
                break;
            }

        }
    }while(removed);
}
#undef cPathSystem_FreeRequest /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163C50 */

/* merge_units: begin func_00163E20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct CxIqActor {char pad[0xC];int serial;};
struct CxIqReq { CxIqActor* actor;int serial;char pad8[4];unsigned char type;};
struct CxIqLink {CxIqLink* next;CxIqLink* prev;CxIqReq* req;};
struct CxIqList {int count;void* unused;CxIqLink* head;};
struct CxIqManager {char pad[0x20];CxIqList queue;};
struct CxIqIt { CxIqLink* link;CxIqReq* Req(){return link->req;} };
extern "C" void std_list_cPathSystemRequestPtr_begin_void_2(CxIqIt*,CxIqList*);
extern "C" void cConstLListIterator_cPathSystemRequestPtr_ctor(CxIqIt*,CxIqIt*);
extern "C" void std_list_cPathSystemRequestPtr_end_void_2(CxIqIt*,CxIqList*);
static inline CxIqActor* CxIq_Get(CxIqReq* req){bool isNull;bool ok;CxIqActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxIq_Begin0(CxIqIt*out,CxIqList*l){CxIqIt temp;std_list_cPathSystemRequestPtr_begin_void_2(&temp,l);cConstLListIterator_cPathSystemRequestPtr_ctor(out,&temp);}
static inline CxIqIt CxIq_Begin(CxIqList* l){CxIqIt converted;CxIq_Begin0(&converted,l);return converted;}
static inline void CxIq_End0(CxIqIt*out,CxIqList*l){CxIqIt temp;std_list_cPathSystemRequestPtr_end_void_2(&temp,l);cConstLListIterator_cPathSystemRequestPtr_ctor(out,&temp);}
static inline CxIqLink* CxIq_End(CxIqList*l){CxIqIt out;CxIq_End0(&out,l);return out.link;}
extern "C" CxIqReq* cPathSystem_GetRequestPending(CxIqManager* self,CxIqActor* actor,int mask){
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163E20 */
