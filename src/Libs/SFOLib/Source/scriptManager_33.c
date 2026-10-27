/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003E1B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E1B60 */
#pragma push /* merge_units */
#include "types.h"
int cScriptInterpreter_findFunc_charP_int(void*,char*,int);
void cScriptBase_sm_printf(char*,char*,int);
int cScriptInterpreter_callFunction(void*,int,int*,int);
int cScriptInterpreter_CallFunction(void*self,char*name,int count,...){
 char*ap;int args[20];int fn,i;
 ap=(char*)__builtin_next_arg(count)-(__builtin_args_info(2)>=8?0:(8-__builtin_args_info(2))*8);
 fn=cScriptInterpreter_findFunc_charP_int(self,name,count);
 if(!fn){cScriptBase_sm_printf("error!  function %s with %d params not found!",name,count);return 0;}
 for(i=0;i<count;i++)args[i]=*(int*)((ap+=8)-8);
 return cScriptInterpreter_callFunction(self,fn,args,count);
}
static inline void merge_flush_func_003E1B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E1B60 */
