#include "types.h"
typedef struct { int unk0; int unk4; unsigned int pending[1]; } D6ActorFlags;
void Actor_SetPendingFlag(D6ActorFlags* a, unsigned char bit, int on)
{
    if (on) {
        a->pending[(unsigned int)bit >> 5] |= 1 << (bit & 0x1F);
    } else {
        a->pending[(unsigned int)bit >> 5] &= ~(1 << (bit & 0x1F));
    }
}