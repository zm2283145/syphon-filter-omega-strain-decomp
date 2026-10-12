#pragma bool off
#pragma cplusplus on
#include "types.h"
struct CxStartActor{char pad[0x10];int id;unsigned char networked;};
struct CxStartRoute{char pad[0x10];int type;char pad14[0xC];int*nodes;int unknown;int count;};
struct CxStartPath{char pad[0x48];int remaining;int node;int segB;int segA;int type;int unknown;unsigned long long hold:1;unsigned long long flag1:1;unsigned long long flag2:1;unsigned long long stopped:1;unsigned long long rest:4;char pad64[0xC];CxStartActor*actor;CxStartRoute*route;};
struct CxStartMsg{void*vt;char pad[0x28];int a,b;int unk34;float x,y,z;};
extern "C"{extern unsigned char D_005721C8;extern char D_0051F0C0[],D_004DE510[];void Event_Construct(CxStartMsg*,void*);void cMessage_dtor(CxStartMsg*,int);void func_002D7BE0(CxStartMsg*,int,CxStartRoute*);void NpcPath_HoldNode(CxStartPath*,int);int NpcRoute_Step(CxStartPath*);}
static inline void CxStart_Construct(CxStartMsg*m,CxStartMsg*loc){Event_Construct(m,D_0051F0C0);loc->x=-1.0f;loc->vt=D_004DE510;loc->y=-1.0f;loc->z=-1.0f;m->a=-1;m->b=-1;}
static inline void CxStart_Destroy(CxStartMsg*m,CxStartMsg*loc){loc->vt=D_004DE510;cMessage_dtor(m,0);}
#pragma opt_propagation off
extern "C" int NpcRoute_Start(CxStartPath*self){
 if(D_005721C8 && self->actor->networked){CxStartMsg msg;CxStartMsg*m=&msg;CxStart_Construct(m,&msg);func_002D7BE0(m,self->actor->id,self->route);CxStart_Destroy(m,&msg);}
 if(self->hold){self->hold=0;NpcPath_HoldNode(self,-1);}
 self->remaining=self->route->count;
 int n=self->remaining;
if(n>1){int*end;int seg;seg=self->segA;unsigned offset=n<<2;end=(int*)(offset+(unsigned)self->route->nodes);if(seg==end[-1] && self->segB==end[-2])self->remaining=n-1;}
 self->segB=-1;
 self->type=self->route->type;
 self->stopped=!NpcRoute_Step(self);
 return !self->stopped;
}
