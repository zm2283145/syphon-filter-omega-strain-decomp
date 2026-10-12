#include "types.h"
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackRegistry{int capacity,count;void**items;}BackpackRegistry;
extern BackpackRegistry*D_004F7F30;extern int D_004F7F70;extern char D_004A7B50[];
void Object_Unregister(void*);void func_003CB230(void*,float);void func_00257230(BackpackRegistry*,int);
void func_00136DA0(int*);void func_0012F530(int*,int);void Mem_Free(int,void*,char*,int);
void func_00257150(void){
 BackpackRegistry*list=D_004F7F30;int i;int guard;
 for(i=0;i<list->count;i++){int off=i*4;Object_Unregister(*(void**)((char*)list->items+off));func_003CB230(*(void**)((char*)list->items+off),0.1f);}
 list=D_004F7F30;func_00136DA0(&guard);func_00257230(list,-1);Mem_Free(0,list,D_004A7B50,0x18A);func_0012F530(&guard,-1);D_004F7F30=0;D_004F7F70=0;
}
