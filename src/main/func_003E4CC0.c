#include "types.h"
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet{int kind,id;unsigned char action,on;char pad[2];int a,b;}Packet;
typedef struct Msg{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];int a,b;char p34[4];}Msg;
extern unsigned char D_005723C8,D_005721D0;extern char D_0055D480[],D_004E0840[],D_004E01A0[];
void cMessage_ctor5(Msg*,void*,Packet*);void**NetMap_Lookup(int);void MsgQueue_QueueClone(Msg*,void*,int,int);void cMessage_dtor(Msg*,int);
int func_003E4CC0(int a,int b,int c,Packet*p0){
 Msg msg;Packet*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor5(&msg,D_0055D480,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E01A0;msg.a=p->a;
 obj=NetMap_Lookup(p->id);if(obj)MsgQueue_QueueClone(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x10;
}
