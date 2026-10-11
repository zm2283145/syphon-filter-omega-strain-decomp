#include "types.h"
#pragma peephole off
#pragma opt_common_subs off
typedef struct { float s; int pad[3]; Vec4 t; } Xf32B0;
Xf32B0* func_001832B0(Xf32B0* m, float s, Vec4* t) { m->s = s; m->t = *t; return m; }
#pragma opt_common_subs reset
#pragma peephole reset