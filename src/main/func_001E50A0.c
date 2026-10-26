#include "types.h"
typedef struct { char pad[0x50]; __int128 q; } Q50A0;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearForce(Q50A0* s) {
    __int128* zp = &s->q;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
