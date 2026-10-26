#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern int D_0048C410;

/* Stores a value into a global setting. */
void MGCLSetServerPort(int value)
{
    D_0048C410 = value;
}
