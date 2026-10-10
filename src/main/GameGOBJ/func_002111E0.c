#include "types.h"
typedef struct { int start; int len; int cur; } SmSeg;
typedef struct { char pad0[0xCC]; int target; SmSeg* seg; char pad1[8]; unsigned char stopped; } SmMover;
int Script_Mover_Stop(SmMover** args)
{
    SmMover* m = *args;
    if (!m->stopped) {
        m->seg->cur = m->seg->start + m->seg->len;
        m->target = m->seg->start + m->seg->len;
    }
    return 0;
}