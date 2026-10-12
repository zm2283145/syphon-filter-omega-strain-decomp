#include "types.h"
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
typedef struct AmmoEntry{int primary[4];int secondary[4];int item,count;}AmmoEntry;
typedef struct AmmoSlot{unsigned char kind;char pad[3];AmmoEntry entries[5];int count;unsigned char active;char padD1[3];}AmmoSlot;
typedef struct BackpackQuery{char pad[0x64];AmmoSlot slots[3];}BackpackQuery;
int WeaponInv_SlotOfItem(int);
void func_00255500(BackpackQuery*self,int item,int*lastPrimary,int*lastSecondary,int*total){
 AmmoSlot*slot;int i;AmmoEntry*entry;int j;int k;int kind;
 kind=WeaponInv_SlotOfItem(item);slot=self->slots;i=0;kind=(unsigned char)kind;goto outer_test;
 outer_body:
 if(slot->kind==kind){entry=slot->entries;for(j=0;j<slot->count;j++,entry++){
  if(entry->item==item){*total=0;*lastPrimary=entry->primary[entry->count-1];*lastSecondary=entry->secondary[entry->count-1];k=0;if(k<entry->count){int*p=entry->primary;do{*total+=p[0];if(kind!=4)*total+=p[4];k++;p++;}while(k<entry->count);}}
 }}
 i++;slot++;
 outer_test:if(i<3)goto outer_body;
}
