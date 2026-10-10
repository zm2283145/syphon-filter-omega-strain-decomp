#include "types.h"

typedef struct { Q a; Q b; } QPair;

#pragma peephole off
/* Copies a pair of quadwords and returns the destination (unit built with the peephole pass off). */
QPair* func_00182760(QPair* dst, QPair* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
#pragma peephole reset
