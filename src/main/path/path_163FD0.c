/*
 * main/path: range (2 files, 00163FD0-001640B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00163FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct CxHpActor {char pad[0xC];int serial;};
struct CxHpReq { CxHpActor* actor;int serial;char pad8[6];unsigned char reported;};
struct CxHpLink {CxHpLink* next;CxHpLink* prev;CxHpReq* req;};
struct CxHpList {int count;void* unused;CxHpLink* head;};
struct CxHpManager {char pad[0x20];CxHpList queue;};
struct CxHpIt { CxHpLink* link;};
extern "C" void std_list_cPathSystemRequestPtr_begin_void_2(CxHpIt*,CxHpList*);
extern "C" void cConstLListIterator_cPathSystemRequestPtr_ctor(CxHpIt*,CxHpIt*);
static inline CxHpActor* CxHp_Get(CxHpReq* req){bool isNull;bool ok;CxHpActor* actor;actor=req->actor;isNull=!actor;ok=true;if(!isNull)if(actor->serial!=req->serial)ok=false;return ok ? actor:0;}
static inline void CxHp_Conv(CxHpIt* out,CxHpList* l){CxHpIt it;std_list_cPathSystemRequestPtr_begin_void_2(&it,l);cConstLListIterator_cPathSystemRequestPtr_ctor(out,&it);}
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163FD0 */

/* merge_units: begin func_001640B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; } Tgt_40B0;
typedef struct { Tgt_40B0* t; int serial; int x8; char c; unsigned char d; unsigned char e; } S_40B0;
S_40B0* cPathSystemRequest_ctor(S_40B0* self, Tgt_40B0* t, char c)
{
    int none;
    int* p;
    self->serial = -2;
    self->t = 0;
    self->d = 1;
    self->e = 0;
    self->c = c;
    self->t = t;
    if (t)
        p = &t->serial;
    else {
        none = -1;
        p = &none;
    }
    self->serial = *p;
    if (t)
        self->x8 = t->serial;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001640B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001640B0 */
