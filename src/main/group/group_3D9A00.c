#include "types.h"
#pragma opt_strength_reduction off
typedef struct Group {int capacity,count;int*items;} Group;
int Random_Next(void);
static inline float RandF(){return (float)Random_Next()/2147483648.0f;}
void Group_Shuffle(Group*g0){
 int count;Group*g=g0;int i=0;
 if(0<g->count)do{
 int n,value;count=*(volatile int*)&g->count;
 n=(int)((float)count*RandF());
 value=g->items[i];g->items[i]=g->items[n];g->items[n]=value;
 i++;
 }while(i<g->count);
}
