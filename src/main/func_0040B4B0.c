#include "types.h"
typedef struct { int pad; int count; void** data; } Vec40B4B0;
extern Vec40B4B0* GetPurgeList(void);
extern void cBaseObjList_Purge(void* p);
#pragma push
#pragma opt_strength_reduction off
void cBaseObjList_PurgeRemovals(void)
{
    Vec40B4B0* v = GetPurgeList();
    int i;
    for (i = v->count - 1; i >= 0; i--) cBaseObjList_Purge(v->data[i]);
}
#pragma pop
