#include "types.h"
typedef struct { int pad; int count; void** data; } Vec40B4B0;
extern Vec40B4B0* GobjScope_GetList(void);
extern void func_0040B510(void* p);
#pragma push
#pragma opt_strength_reduction off
void func_0040B4B0(void)
{
    Vec40B4B0* v = GobjScope_GetList();
    int i;
    for (i = v->count - 1; i >= 0; i--) func_0040B510(v->data[i]);
}
#pragma pop
