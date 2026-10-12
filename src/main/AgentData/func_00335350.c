#include "types.h"
typedef struct { char p0[4]; int count; unsigned char* data; } B335350;
typedef struct { unsigned char state; char p1[3]; B335350 b; } P335350;
typedef struct { char p0[0x10]; int arg; } Q335350;
extern void func_003352C0(void* self, int arg);
#pragma opt_strength_reduction off
/* Marks the part complete when every sub-step is done, then notifies. */
void func_00335350(void* self, P335350* p, Q335350* q, int force)
{
    B335350* b;
unsigned char all;
int i;
    b = &p->b;
all = 1;
    for (i = 0; i < *(volatile int*)&b->count; i++) {
        if (b->data[i] != 2) { all = 0; break; }
    }
    if (all) {
        if (force) p->state = 2;
        else if (p->state == 0) p->state = 1;
        func_003352C0(self, q->arg);
    }
}
