#include "types.h"
#pragma peephole off
typedef struct { char pad[0x40]; Vec4 v; } S;
/* Sets the curve's target vector (+0x40). */
void VecCurve_SetTarget(S* dst, Vec4* src) { dst->v = *src; }
