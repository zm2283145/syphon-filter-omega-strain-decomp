#include "types.h"
typedef struct { char pad0[0xA4]; int cur; char pad1[0x1130-0xA8]; int counts[32]; int total; } ObjManD4;
int ObjMan_GetTotalCount(ObjManD4* m)
{
    int sum = 0;
    int i;
    for (i = 0; i < 2; i++) {
        int v;
        if (i == 0) v = m->total;
        else v = m->counts[m->cur];
        sum += v;
    }
    return sum;
}