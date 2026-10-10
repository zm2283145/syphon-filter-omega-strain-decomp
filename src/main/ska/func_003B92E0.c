#include "types.h"

typedef struct { int size; int count; int index; } Ring;

/* Consumes one ring entry: decrements the count and advances the index with wrap-around. */
void func_003B92E0(Ring* self)
{
    self->count--;
    if (++self->index == self->size)
        self->index = 0;
}
