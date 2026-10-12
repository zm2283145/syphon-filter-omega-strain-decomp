#include "types.h"
typedef struct Obj {char pad[0x30];struct Obj*target;} Obj;
typedef struct ActionMsg {void*vt;char pad[0x18];int kind;char flag;char p21[3];int action;char on;char p29[3];int count;} ActionMsg;
extern char D_0055D480[],D_004E01E0[],D_004E0840[];extern int D_0055A840;
Obj*func_003CB1C0(int);int*func_003CB220(Obj*);
void Event_Construct(ActionMsg*,void*);void Event_Send(ActionMsg*,Obj*,int);void cMessage_dtor(ActionMsg*,int);
void func_003E6690(Obj*obj,unsigned char count){
 ActionMsg msg;
 int type=*func_003CB220(obj);if(type==D_0055A840)obj=obj->target;
 Event_Construct(&msg,D_0055D480);
 msg.count=count;msg.action=0x28;msg.on=2;msg.vt=D_004E01E0;msg.flag=8;msg.kind=0x40;
 Event_Send(&msg,obj,0);msg.vt=D_004E0840;cMessage_dtor(&msg,0);
}

