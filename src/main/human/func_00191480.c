#include "types.h"
#pragma peephole off

typedef struct Orientation { Q a; Q b; } Orientation;

/* Copies two quadwords (orientation rows) from src to dst; returns dst. */
Orientation* Transform_SetOrientation(Orientation* dst, Orientation* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
