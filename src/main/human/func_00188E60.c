#include "types.h"
typedef struct { char pad[0x3204]; int flags; } O_188E60;
int Actor_GetStance(O_188E60* o)
{
    int f = o->flags;
    if ((f >> 5) & 1) return 2;
    if (((f >> 1) & 1) || ((f >> 7) & 1) || ((f >> 6) & 1)) return 1;
    if ((((f >> 3) & 1) || ((f >> 4) & 1)) && (f & 1)) return 4;
    return 0;
}