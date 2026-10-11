#include "types.h"

/* Zero the bone's translation and rotation accumulators. */
typedef struct { __int128 q; } Q_3BA710;
typedef struct { unsigned char pad[0x180]; Q_3BA710 accumT; Q_3BA710 accumR; } Bone_3BA710;

#pragma peephole off
#pragma opt_propagation off
void Bone_ResetAccumulators(Bone_3BA710* b)
{
    __int128* p;
    p = &b->accumT.q; *p = 0;
    p = &b->accumR.q; *p = 0;
}
#pragma opt_propagation reset
#pragma peephole reset