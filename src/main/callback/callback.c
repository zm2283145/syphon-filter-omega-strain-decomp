/*
 * main/callback: 4 files, 003E9A60-003E9C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E9A60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma opt_rebuildconditionals off
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M9A60;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V9A60;
struct O9A60 { char pad[0xC]; int serial; };
struct H9A60 { O9A60* p; int serial; };
extern "C" {
extern H9A60 D_00583878;
void* Camera_GetNode(O9A60* o);
void Transform_GetInverseMatrix(M9A60* out, void* t);
}

static inline bool Valid9A60(H9A60* h)
{
    O9A60* t = h->p;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if ((t->serial == h->serial) == false)
            ok = false;
    return ok != false;
}
static inline O9A60* Get9A60(H9A60* h)
{
    return Valid9A60(h) ? (O9A60*)*(O9A60* volatile*)&h->p : (O9A60*)0;
}
extern "C" void HudTracker_ToCameraSpace(V9A60* v)
{
    O9A60* o = Get9A60(&D_00583878);
    if (o) {
        M9A60 m;
        M9A60* pm;
        Transform_GetInverseMatrix(&m, Camera_GetNode(o));
        pm = &m;
        asm {
            lqc2 vf8, 0x0(v)
            lqc2 vf4, 0x0(pm)
            lqc2 vf5, 0x10(pm)
            lqc2 vf6, 0x20(pm)
            lqc2 vf7, 0x30(pm)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(v)
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9A60 */

/* merge_units: begin func_003E9B20 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9B20;
extern char D_004E0360[];
extern char D_004E05A0[];
extern void IeElement_Release(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9B20* cMAP_GOBJ_dtor(G9B20* self, short del)
{
    if (self) {
        self->vt = D_004E0360;
        if (self) {
            self->vt = D_004E05A0;
            IeElement_Release(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9B20 */

/* merge_units: begin func_003E9BA0 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9BA0;
extern char D_004E0480[];
G9BA0* HudTracker_Delete(G9BA0* self, short del)
{
    if (self) {
        self->vt = D_004E0480;
        if (self) {
            self->vt = D_004E05A0;
            IeElement_Release(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9BA0 */

/* merge_units: begin func_003E9C20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma bool off
#pragma opt_common_subs off

#pragma inline_depth(12)
#include "eventQueue.h"
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern unsigned char g_EventQueueClosed;            /* queue closed */
extern int g_ProfileLockDepth;
extern char g_EventQueue[];                   /* queued events */
extern EQEvent* g_EventQueueRunning;                 /* event currently running */
void Alloc_Lock(int);void Alloc_Unlock(int);
void Mem_Free(int,void*,char*,int);
void ActiveList_EraseMatching(void*,EQPred);
void List_Begin(EQPos*,void*);void EQList_End(EQPos*,void*);void EQList_Begin(EQPos*,void*);
void EQPos_CopyConst(EQPos*,const EQPos*);void EQPos_Copy(EQPos*,const EQPos*);
}
struct Begin:EQPos { Begin(const EQPos& r) {EQPos_CopyConst(this,&r);} };
struct EQIter:EQPos { EQIter(const EQPos& r) {EQPos_Copy(this,&r);} };
static inline void BeginQ(EQPos*p){EQPos r;List_Begin(&r,g_EventQueue);EQPos_CopyConst(p,&r);}
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
#pragma pop /* merge_units */
/* merge_units: end func_003E9C20 */
