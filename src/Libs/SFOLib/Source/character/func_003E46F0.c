#include "types.h"
#pragma peephole off
typedef struct { char pad[0x10]; Vec4 v; } S;
/* Copies a vector into +0x10. */
void func_003E46F0(S* dst, Vec4* src) { dst->v = *src; }
