#include "types.h"

extern volatile unsigned char D_005723C8;
extern volatile int D_00582CF0;

/* Reset the shared NPC information state. */
void func_004375D0(void)
{
    if (D_005723C8 == 0)
        D_005723C8 = 1;
    D_00582CF0 = 0;
    D_005723C8 = 0;
}
