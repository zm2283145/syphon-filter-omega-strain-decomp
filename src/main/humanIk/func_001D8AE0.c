#include "types.h"
typedef struct { Q a; Q b; char c; } QPair8AE0;
#pragma peephole off
QPair8AE0* func_001D8AE0(QPair8AE0* dst, QPair8AE0* src, char c)
{
    dst->a = src->a;
    dst->b = src->b;
    dst->c = c;
    return dst;
}
#pragma peephole reset