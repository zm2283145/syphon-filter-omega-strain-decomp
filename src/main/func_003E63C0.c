#include "types.h"
int Script_ValueToObj(int);int GObj_IdentityB(int);
void Global_PerformAction_WithObject(int,signed char,int,float,int,int);
int Script_PerformAction_WithObject_4(int*args){
 int on;volatile int action;int timeBits;signed char kind;float time;int obj;on=args[5]!=0;timeBits=args[4];action=args[3];kind=(signed char)args[1];
 time=*(float*)&timeBits;
 obj=Script_ValueToObj(args[0]);
 Global_PerformAction_WithObject(obj,kind,GObj_IdentityB(args[2]),time,action,on);
 return 0;
}




