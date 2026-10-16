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
void Mem_Free(int,void*,char*,int);
void ActiveList_EraseMatching(void*,EQPred);
void List_Begin(EQPos*,void*);void EQList_End(EQPos*,void*);void EQList_Begin(EQPos*,void*);
void EQPos_CopyConst(EQPos*,const EQPos*);void EQPos_Copy(EQPos*,const EQPos*);
}
static inline void BeginQ(EQPos*p){EQPos r;List_Begin(&r,g_EventQueue);EQPos_CopyConst(p,&r);}
static inline void EndQ(EQPos*p){EQPos r;EQList_End(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline void Restart(EQPos*p){EQPos r;EQList_Begin(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline int Neq(const EQPos&a,const EQPos&b){return a.p!=b.p;}
static inline EQPred MakePred(EQEvent**ev){EQCmp c;return EQPred(c,ev);}
static inline void Destroy(EQEvent* ev){
 if(ev){ActiveList_EraseMatching(g_EventQueue,MakePred(&ev));{EQEvent*p=ev;AllocGuard guard;p->~EQEvent();Mem_Free(0,p,D_004BDFC8,0x36);}}
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
void EventQueue_Pump(int a, int b){
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
