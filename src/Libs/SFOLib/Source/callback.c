/*
 * Libs/SFOLib/Source/callback: 4 files, 003E9DF0-003E9E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E9DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cCBDataPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* EQPos_Copy(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cCBDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* EQPos_CopyConst(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003E9DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E9DF0 */

/* merge_units: begin func_003E9E30 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void std_list_deleter_voidPtr_begin_void(EQPos*,void*);
#if 0 /* merge_units */
void std_list_cCBDataPtr_end(EQPos*,void*);
#endif /* merge_units */
#define std_list_cCBDataPtr_end(a0, a1) (std_list_cCBDataPtr_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */
#if 0 /* merge_units */
void std_list_cCBDataPtr_begin(EQPos*,void*);
#endif /* merge_units */
#define std_list_cCBDataPtr_begin(a0, a1) (std_list_cCBDataPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void EQPos_CopyConst(EQPos*,const EQPos*);
#endif /* merge_units */
#define EQPos_CopyConst(a0, a1) ((void)EQPos_CopyConst((Word *)(a0), (Word *)(a1))) /* merge_units */
#if 0 /* merge_units */
void EQPos_Copy(EQPos*,const EQPos*);
#endif /* merge_units */
#define EQPos_Copy(a0, a1) ((void)EQPos_Copy((Word *)(a0), (Word *)(a1))) /* merge_units */

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
#undef std_list_cCBDataPtr_end /* merge_units */
#undef std_list_cCBDataPtr_begin /* merge_units */
#undef EQPos_CopyConst /* merge_units */
#undef EQPos_Copy /* merge_units */
static inline void merge_flush_func_003E9E30(void) {} /* merge_units */
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
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void std_list_imp_voidPtr_remove_if(void* list, EQPred pred);
#endif /* merge_units */
#define std_list_imp_voidPtr_remove_if(a0, a1) (std_list_imp_voidPtr_remove_if((a0), (a1))) /* merge_units */

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
#undef cMemMan_Deallocate /* merge_units */
#undef std_list_imp_voidPtr_remove_if /* merge_units */
static inline void merge_flush_func_003EA0E0(void) {} /* merge_units */
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
static inline void merge_flush_func_003EA1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA1D0 */
