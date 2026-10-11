#include "types.h"
typedef struct { int type; char pad[0x3C]; int owner; unsigned char state; } S1C9430;
static inline unsigned char S1C9430_busy(S1C9430* p)
{
    unsigned char r = 1;
    if (p->state != 1 && p->state != 3) r = 0;
    return r;
}
static inline void S1C9430_release(S1C9430* p)
{
    if (p->type == 5 && S1C9430_busy(p)) p->state = 2;
    else p->state = 0;
}
void func_001C9430(int owner, long long pp)
{
    S1C9430* p = (S1C9430*)(int)pp;
    if (owner == 0) { S1C9430_release(p); return; }
        if (S1C9430_busy(p)) p->state = 6;
        p->owner = owner;
}