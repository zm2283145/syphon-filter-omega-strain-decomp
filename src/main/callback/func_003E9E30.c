#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma bool off
#pragma opt_common_subs off

#pragma inline_depth(12)
struct EQBase { int a; unsigned char b[4]; };
struct EQEvent : EQBase { virtual ~EQEvent(); virtual void v0(); virtual void run(); };
struct EQCmp {};
struct EQPred { EQCmp cmp; EQEvent** pp; EQPred(const EQCmp& c,EQEvent** p):cmp(c),pp(p){} };
struct EQNode { EQNode* prev; EQNode* next; EQEvent* ev; };
struct Raw { EQNode* p; };
extern "C" {
extern char D_004BDFC8[];
extern char D_0055A2E0[];
extern EQEvent* D_0055A2F0;
void Mem_Free(int,void*,char*,int);
void ActiveList_EraseMatching(void*,EQPred);
void func_0013B180(Raw*,void*);void func_003E9DF0(Raw*,void*);void func_003E9E10(Raw*,void*);
void func_003E9E20(Raw*,const Raw*);void func_003E9E00(Raw*,const Raw*);
}
static inline void BeginQ(Raw*p){Raw r;func_0013B180(&r,D_0055A2E0);func_003E9E20(p,&r);}
static inline void EndQ(Raw*p){Raw r;func_003E9DF0(&r,D_0055A2E0);func_003E9E00(p,&r);}
static inline void Restart(Raw*p){Raw r;func_003E9E10(&r,D_0055A2E0);func_003E9E00(p,&r);}
static inline int Neq(const Raw&a,const Raw&b){return a.p!=b.p;}
static inline EQPred MakePred(EQEvent**ev){EQCmp c;return EQPred(c,ev);}
static inline void Destroy(EQEvent* ev){
 if(ev){ActiveList_EraseMatching(D_0055A2E0,MakePred(&ev));{EQEvent*p=ev;AllocGuard guard;p->~EQEvent();Mem_Free(0,p,D_004BDFC8,0x36);}}
}
static inline void Run(EQEvent* e){e->run();}
static inline void BeginQ0(Raw* p){BeginQ(p);}
static inline void BeginQ1(Raw* p){BeginQ0(p);}
static inline void EndQ0(Raw* p){EndQ(p);}
static inline void EndQ1(Raw* p){EndQ0(p);}
static inline void Restart0(Raw* p){Restart(p);}
static inline void Restart1(Raw* p){Restart0(p);}
typedef struct Raw Raw; typedef struct EQEvent EQEvent; typedef struct EQNode EQNode;
#pragma cplusplus off
/* Ages every queued event, then runs and destroys the expired ones.
 * One iterator serves both loops; MW splits its live ranges into two stack slots. */
void EventQueue_Pump(int a, int b){
 Raw i,end,rest,rest2,end2,begin;
 if(a<0||b<0) return;
 BeginQ1(&begin); i.p=begin.p;
 while((EndQ1(&end),Neq(i,end))){
  EQNode* n; EQEvent* e; n=i.p; i.p=n->next; e=n->ev;
  e->a-=e->b[0]?b:a;
 }
 Restart1(&rest); i=rest;
 while((EndQ1(&end2),Neq(i,end2))){
  EQNode* n; EQEvent* e; n=i.p; i.p=n->next; e=n->ev;
  if(e->a<=0){
   D_0055A2F0=e;Run(e);D_0055A2F0=0;
   Destroy(e);
   Restart1(&rest2); i=rest2;
  }
 }
}





