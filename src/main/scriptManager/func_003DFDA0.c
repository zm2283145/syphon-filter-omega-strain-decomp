#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(12)
#pragma opt_strength_reduction off
struct Param { int kind; };
struct Desc { char pad[0x10];Param**p; };
struct Ev { int x0,x4;void*vtable;char*args;int count;Desc*desc; };
extern "C" {
extern char D_004BD4C0[],D_004D9DE0[],D_004E00C0[];
void Mem_Free(int,void*,char*,int);void operator_delete(void*);
}
static inline void Free(void*p,int line){AllocGuard g;Mem_Free(0,p,D_004BD4C0,line);}
extern "C" Ev* ScriptEvent_Destruct(Ev*self,short flag){
 if(self){
 self->vtable=D_004E00C0;
 int i=0,off;
 if(0<self->count){off=0;do {
 if(self->desc->p[i]->kind==3){void*p=*(void**)(self->args+off);Free(p,0x6df);}
 ++i;off+=4;
 }while(i<self->count);}
 void*p=self->args;if(p)Free(p,0x6e3);
 if(self)self->vtable=D_004D9DE0;
 if(flag>0)operator_delete(self);
 }
 return self;
}
