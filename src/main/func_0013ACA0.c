#include "types.h"
#pragma peephole off

typedef struct LosProvider { char pad[0x20]; int unk20; char pad2[0xC]; Q v; } LosProvider;

/* Clears the provider's state word and stores its quadword parameter. */
void LosProvider_Setup(LosProvider* p, Q* v)
{
    p->unk20 = 0;
    p->v = *v;
}
