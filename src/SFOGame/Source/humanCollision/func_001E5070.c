#include "types.h"
typedef struct { char pad[0x10]; Q a; Q b; Q c; } S1E5070;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearVelocity(S1E5070* s)
{
    __int128* zp;
    s->b = s->a;
    zp = (__int128*)&s->c;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset