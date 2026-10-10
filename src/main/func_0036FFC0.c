#include "types.h"
#pragma peephole off
typedef struct { char pad[0x40]; Vec4 v; } S;
/* Copies the vector at +0x40 of src into dst. */
void func_0036FFC0(Vec4* dst, S* src) { *dst = src->v; }
