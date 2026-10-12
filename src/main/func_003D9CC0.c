#include "types.h"
#pragma opt_strength_reduction off
typedef struct Group{int cap,count;int*items;}Group;
int Group_FindById(Group*g,int*value){int count=g->count;int i=0;if(0<count){int*items=g->items;int needle=*value;do{int current=items[i];if(current==needle)return i;i++;}while(i<count);}return -1;}



