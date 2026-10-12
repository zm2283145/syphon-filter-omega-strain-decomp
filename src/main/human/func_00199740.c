#include "types.h"
typedef struct { char pad0[0x33EC]; unsigned char* p; } O_199740;
unsigned char Actor_IsFlashlightOn(O_199740* o)
{
    unsigned char r = 0;
    if (o->p != 0 && *o->p != 0) r = 1;
    return r;
}