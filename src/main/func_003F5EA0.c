#include "types.h"
typedef struct { char data[0x4CE40]; } E5EA0;
typedef struct { int m0; E5EA0* base; int head; int count; int size; } T5EA0;
#pragma bool off
#pragma opt_propagation off
static inline int empty5EA0(T5EA0* q) { return q->count == 0; }
E5EA0* func_003F5EA0(T5EA0* q)
{
    int e = empty5EA0(q);
    if (e)
        return 0;
    return &q->base[(q->size + (q->head - *(volatile int*)&q->count)) % q->size];
}
#pragma opt_propagation reset
#pragma bool reset