/*
 * main/callback: 3 files, 003E9E30-003EA0E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E9E30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma bool off
#pragma opt_common_subs off

#pragma inline_depth(12)
#include "eventQueue.h"
extern "C" {
extern char D_004BDFC8[];
extern char g_EventQueue[];                   /* queued events */
extern EQEvent* g_EventQueueRunning;                 /* event currently running */
void cMemMan_Deallocate(int,void*,char*,int);
void std_list_imp_voidPtr_remove_if(void*,EQPred);
void std_list_deleter_voidPtr_begin_void(EQPos*,void*);void std_list_cCBDataPtr_end(EQPos*,void*);void std_list_cCBDataPtr_begin(EQPos*,void*);
void EQPos_CopyConst(EQPos*,const EQPos*);void EQPos_Copy(EQPos*,const EQPos*);
}
static inline void BeginQ(EQPos*p){EQPos r;std_list_deleter_voidPtr_begin_void(&r,g_EventQueue);EQPos_CopyConst(p,&r);}
static inline void EndQ(EQPos*p){EQPos r;std_list_cCBDataPtr_end(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline void Restart(EQPos*p){EQPos r;std_list_cCBDataPtr_begin(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline int Neq(const EQPos&a,const EQPos&b){return a.p!=b.p;}
static inline EQPred MakePred(EQEvent**ev){EQCmp c;return EQPred(c,ev);}
static inline void Destroy(EQEvent* ev){
 if(ev){std_list_imp_voidPtr_remove_if(g_EventQueue,MakePred(&ev));{EQEvent*p=ev;AllocGuard guard;p->~EQEvent();cMemMan_Deallocate(0,p,D_004BDFC8,0x36);}}
}
static inline void Run(EQEvent* e){e->run();}
static inline void BeginQ0(EQPos* p){BeginQ(p);}
static inline void BeginQ1(EQPos* p){BeginQ0(p);}
static inline void EndQ0(EQPos* p){EndQ(p);}
static inline void EndQ1(EQPos* p){EndQ0(p);}
static inline void Restart0(EQPos* p){Restart(p);}
static inline void Restart1(EQPos* p){Restart0(p);}
typedef struct EQPos EQPos; typedef struct EQEvent EQEvent; typedef struct EQNode EQNode;
#pragma cplusplus off
/* Ages every queued event, then runs and destroys the expired ones.
 * One iterator serves both loops; MW splits its live ranges into two stack slots. */
void nCallback_Process(int a, int b){
 EQPos i,end,rest,rest2,end2,begin;
 if(a<0||b<0) return;
 BeginQ1(&begin); i.p=begin.p;
 while((EndQ1(&end),Neq(i,end))){
  EQNode* n; EQEvent* e; n=i.p; i.p=n->next; e=n->ev;
  e->timeMs-=e->useClockB?b:a;
 }
 Restart1(&rest); i=rest;
 while((EndQ1(&end2),Neq(i,end2))){
  EQNode* n; EQEvent* e; n=i.p; i.p=n->next; e=n->ev;
  if(e->timeMs<=0){
   g_EventQueueRunning=e;Run(e);g_EventQueueRunning=0;
   Destroy(e);
   Restart1(&rest2); i=rest2;
  }
 }
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9E30 */

/* merge_units: begin func_003EA0E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_list_imp_voidPtr_remove_if(void* list, EQPred pred);
}

static inline void EQ_Delete(EQEvent* e)
{
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    e->~EQEvent();
    cMemMan_Deallocate(0, e, D_004BDFC8, 0x36);
    if (g_ProfileLockEnabled)
        EnableIntc(9);
    g_ProfileLockDepth--;
}
/* Removes an event from the queue and destroys it (unless it is running). */
extern "C" void nCallback_RemoveCallback(EQEvent* ev)
{
    if (g_EventQueueRunning != ev) {
        EQCmp c __attribute__((aligned(8)));
        std_list_imp_voidPtr_remove_if(g_EventQueue, EQPred(c, &ev));
        EQ_Delete(ev);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EA0E0 */

/* merge_units: begin func_003EA1D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern unsigned char g_EventQueueClosed;            /* queue closed: drop new events */
void std_list_cCBDataPtr_push_back(void* list, void* item);      /* push_back */
}
/* Queues an event; destroys it right away when the queue is closed. */
extern "C" void nCallback_SetCallback(EQEvent* e)
{
    if (g_EventQueueClosed) {
        EQEvent* p = e;
        if (p) {
            AllocGuard g;
            p->~EQEvent();
            cMemMan_Deallocate(0, p, D_004BDFC8, 0x27);
        }
        return;
    }
    std_list_cCBDataPtr_push_back(g_EventQueue, &e);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EA1D0 */
