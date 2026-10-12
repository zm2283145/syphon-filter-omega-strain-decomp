#include "types.h"
extern char D_004BD920[];
int func_003E0F50(void*,char*,int);
void func_003D7930(char*,char*,int);
int Script_CallHandler(void*,int,int*,int);
int ScriptMgr_CallFunction(void*self,char*name,int count,...){
 char*ap;int args[20];int fn,i;
 ap=(char*)__builtin_next_arg(count)-(__builtin_args_info(2)>=8?0:(8-__builtin_args_info(2))*8);
 fn=func_003E0F50(self,name,count);
 if(!fn){func_003D7930(D_004BD920,name,count);return 0;}
 for(i=0;i<count;i++)args[i]=*(int*)((ap+=8)-8);
 return Script_CallHandler(self,fn,args,count);
}

