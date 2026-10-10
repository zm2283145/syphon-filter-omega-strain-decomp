#include "types.h"

/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; Vec4 c; } Vec4x3;

/* Copies three consecutive vectors out to three destinations. */
void func_001D3A90(Vec4x3* src, Vec4* a, Vec4* b, Vec4* c)
{
    *a = src->a;
    *b = src->b;
    *c = src->c;
}
