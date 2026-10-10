#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { int unk0; int x; int y; int x16; int y16; } Pos;

/* Stores a position and its 1/16 scaled copy; returns 1. */
int func_0010BEE8(Pos* p, int x, int y)
{
    p->x = x;
    p->y = y;
    p->x16 = x >> 4;
    p->y16 = y >> 4;
    return 1;
}

