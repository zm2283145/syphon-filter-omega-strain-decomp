#include "types.h"
typedef struct { unsigned int count; float rate; float peak; } R2F6998;
int func_002F6998(R2F6998* p, unsigned int ms)
{
    if (!p) return 2;
    if (ms != 0) p->rate = (float)p->count / ((float)ms / 1000.0f);
    else p->rate = 0.0f;
    if (p->rate > p->peak) p->peak = p->rate;
    p->count = 0;
    return 0;
}