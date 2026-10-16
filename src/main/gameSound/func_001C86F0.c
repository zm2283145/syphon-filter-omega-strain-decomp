#include "types.h"
typedef struct { int type; char pad[0x40]; unsigned char state; } E1C86F0;
typedef struct { E1C86F0* a; E1C86F0* b; unsigned char active; } P1C86F0;
typedef struct { char pad[0xC]; P1C86F0* pair; } S1C86F0;
void MusicTransitionEvent_Fire(S1C86F0* s)
{
    E1C86F0* a = s->pair->a;
    E1C86F0* b = s->pair->b;
    if (a && a->state)
        a->state = 0;
    if (b && b->state) {
        if (b->type == 5 || b->type == 4)
            b->state = 2;
    }
    s->pair->a = 0;
    s->pair->b = 0;
    s->pair->active = 0;
}