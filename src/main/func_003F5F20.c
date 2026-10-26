#include "types.h"
typedef struct { char data[0x195000]; } E5F20;
typedef struct { E5F20* base; int m4; int head; int count; int size; } T5F20;
#pragma bool off
#pragma opt_propagation off
static inline int full5F20(T5F20* q) { return q->count == q->size; }
E5F20* voBufGetData(T5F20* q)
{
    int f = full5F20(q);
    if (f)
        return 0;
    return &q->base[q->head];
}
#pragma opt_propagation reset
#pragma bool reset
