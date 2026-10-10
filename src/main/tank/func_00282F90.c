#include "types.h"
#pragma peephole off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char pad[0x20]; float min; float max; } Turret;
typedef struct { char pad[0x6C]; Turret* turret; } Tank;
/* Sets the turret rotation limits from degrees. */
static inline void Tank_SetRotLimit(Tank* tank, float lo, float hi)
{
    Turret* t = tank->turret;
    if (t) { t->min = 0.017453292f * lo; t->max = 0.017453292f * hi; }
}
/* Script native: sets tank args[0]'s turret rotation limits from degrees args[1], args[2]; returns 0. */
int Script_cTank_SetRotLimit(ScriptArg* args)
{
    int minv[1];
    int maxv[1];
    maxv[0] = args[2].i;
    minv[0] = args[1].i;
    Tank_SetRotLimit((Tank*)args[0].p, *(float*)minv, *(float*)maxv);
    return 0;
}
#pragma peephole reset
