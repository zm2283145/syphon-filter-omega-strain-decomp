#include "types.h"
typedef struct { __int128 q; } V_5840;
typedef struct { char pad[0x10]; V_5840 a; V_5840 b; } S_5840;
#pragma push
#pragma peephole off

#pragma opt_common_subs off
V_5840 func_001E5840(S_5840* s)
{
    V_5840 r;
    V_5840* pr = &r;
V_5840* pa = &s->a;
V_5840* pb = &s->b;
    asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    return r;
}
#pragma pop
