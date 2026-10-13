#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma bool off
#pragma opt_common_subs off

#pragma inline_depth(12)
#include "eventQueue.h"
extern "C" {
extern unsigned char D_00533880;
extern unsigned char g_EventQueueClosed;            /* queue closed */
extern int D_00533888;
extern char g_EventQueue[];                   /* queued events */
extern EQEvent* g_EventQueueRunning;                 /* event currently running */
void Alloc_Lock(int);void Alloc_Unlock(int);
void Mem_Free(int,void*,char*,int);
void ActiveList_EraseMatching(void*,EQPred);
void func_0013B180(EQPos*,void*);void EQList_End(EQPos*,void*);void EQList_Begin(EQPos*,void*);
void EQPos_CopyConst(EQPos*,const EQPos*);void EQPos_Copy(EQPos*,const EQPos*);
}
struct Begin:EQPos { Begin(const EQPos& r) {EQPos_CopyConst(this,&r);} };
struct EQIter:EQPos { EQIter(const EQPos& r) {EQPos_Copy(this,&r);} };
static inline void BeginQ(EQPos*p){EQPos r;func_0013B180(&r,g_EventQueue);EQPos_CopyConst(p,&r);}
static inline void EndQ(EQPos*p){EQPos r;EQList_End(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline void Restart(EQPos*p){EQPos r;EQList_Begin(&r,g_EventQueue);EQPos_Copy(p,&r);}
static inline int Neq(const EQPos&a,const EQPos&b){return a.p!=b.p;}
static inline void Delete(EQEvent*e){
 AllocGuard guard;
 e->~EQEvent();Mem_Free(0,e,"callback.cc",0x36);
 
}
static inline EQPred MakePred(EQEvent**ev){EQCmp c;return EQPred(c,ev);}
static inline void Remove(EQEvent*ev){
 if(g_EventQueueRunning!=ev){ActiveList_EraseMatching(g_EventQueue,MakePred(&ev));{EQEvent*p=ev;AllocGuard guard;p->~EQEvent();Mem_Free(0,p,"callback.cc",0x36);}}
}
static inline void Run(EQEvent* e){e->run();}


static inline void BeginQ0(EQPos* p){BeginQ(p);}
static inline void BeginQ1(EQPos* p){BeginQ0(p);}
static inline void EndQ0(EQPos* p){EndQ(p);}
static inline void EndQ1(EQPos* p){EndQ0(p);}
static inline void Restart0(EQPos* p){Restart(p);}
static inline void Restart1(EQPos* p){Restart0(p);}
typedef struct EQPos EQPos; typedef struct EQEvent EQEvent;
#pragma cplusplus off
/* Destroys every queued event, running those flagged runOnClear; reopens the queue. */
void EventQueue_ClearAll(){
 EQPos i,rest,end,begin; BeginQ1(&begin); i.p=begin.p;
 while((EndQ1(&end),Neq(i,end))){
 EQEvent*e=i.p->ev;
 if(e->runOnClear){g_EventQueueRunning=e;Run(e);g_EventQueueRunning=0;}
 Remove(e);
 Restart1(&rest); i=rest;
 }
 g_EventQueueClosed=0;
}
