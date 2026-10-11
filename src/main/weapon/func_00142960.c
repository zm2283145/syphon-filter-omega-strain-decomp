#include "types.h"
typedef struct { char pad[0xF0]; unsigned char state; char pad2[0x10C-0xF1]; int team; } S2960;
int func_00142960(void* unused, S2960* a, S2960* b)
{
    if (a && b) {
        if (a == b)
            return 1;
        if (a->team == b->team && a->state != 1 && b->state != 1)
            return 1;
    }
    return 0;
}