#include "types.h"
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackRegistry{int capacity,count;void**items;}BackpackRegistry;
extern BackpackRegistry*g_BackpackList;extern int D_004F7F70;extern char D_004A7B50[];
void nGobjManager_RemoveGOBJ(void*);void cSystem_ActualScheduleDelete(void*,float);void cArray_cBackpackPtr_dtor(BackpackRegistry*,int);
void cTimerDisable_ctor(int*);void cTimerDisable_dtor(int*,int);void cMemMan_Deallocate(int,void*,char*,int);
void cBackpack_Reset(void){
 BackpackRegistry*list=g_BackpackList;int i;int guard;
 for(i=0;i<list->count;i++){int off=i*4;nGobjManager_RemoveGOBJ(*(void**)((char*)list->items+off));cSystem_ActualScheduleDelete(*(void**)((char*)list->items+off),0.1f);}
 list=g_BackpackList;cTimerDisable_ctor(&guard);cArray_cBackpackPtr_dtor(list,-1);cMemMan_Deallocate(0,list,D_004A7B50,0x18A);cTimerDisable_dtor(&guard,-1);g_BackpackList=0;D_004F7F70=0;
}
