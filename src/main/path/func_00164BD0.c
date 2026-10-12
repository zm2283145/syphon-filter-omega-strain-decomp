#pragma opt_unroll_loops off
#pragma opt_dead_code off
#pragma cplusplus on
#pragma opt_rotateloops off
#include "types.h"
struct CxEraseItem {__int128 q[2];~CxEraseItem(){}};
struct CxEraseVec {int capacity,count;CxEraseItem*data;};
extern "C" CxEraseItem*func_00164BD0(CxEraseVec*self,CxEraseItem*first,CxEraseItem*last){
 if(first==last)return first;
 CxEraseItem*end=self->data+self->count;
 int count=((int)end-(int)last)/32;
 CxEraseItem*src;CxEraseItem*dst=first;
 if(count){for(src=last;src<end;++dst,++src)*dst=*src;}
 for(CxEraseItem*p=first+count;p<end;++p)p->~CxEraseItem();
 self->count-=((int)last-(int)first)/32;
 return first;
}

