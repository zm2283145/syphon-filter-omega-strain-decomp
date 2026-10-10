#include "types.h"

typedef struct { char pad[0x50000]; int unk50000; int unk50004; int capacity; } BigBuf;

/* Resets the large buffer's counters and sets its capacity to 0x50000. */
void func_003F7840(BigBuf* self)
{
    self->unk50004 = 0;
    self->unk50000 = 0;
    self->capacity = 0x50000;
}
