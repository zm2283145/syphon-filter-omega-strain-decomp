#include "types.h"

typedef struct { int state; unsigned char mode; char pad[0x43]; int offset; char pad2[0x10]; int time; } Timer3F6;

extern int func_003A6C70(Timer3F6* self);

/* Resets the timer state and computes its time, minus the offset unless in mode 3. */
void func_003F6E60(Timer3F6* self)
{
    self->state = 3;
    self->time = func_003A6C70(self);
    if (self->mode != 3)
        self->time -= self->offset;
}
