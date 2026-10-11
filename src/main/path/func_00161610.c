#include "types.h"
typedef struct { __int128 q; int x10; int x14; int x18; int pad1c; int* list; int pad24; int count; } S_1610;
void func_00161610(S_1610* dst, S_1610* src)
{
    dst->q = src->q;
    dst->x10 = src->x10;
    if (!src->list) {
        dst->x14 = src->x14;
        dst->x18 = src->x18;
    } else if (src->count > 0) {
        dst->x14 = src->list[src->count - 1];
        dst->x18 = src->list[0];
    } else {
        dst->x14 = -1;
    }
}