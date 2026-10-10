#include "types.h"

typedef struct { int unk0; unsigned int count; int unk8; float scale; } ScaledCount;

/* Returns count (unsigned) * scale. */
float func_00190EC0(ScaledCount* self)
{
    return (float)self->count * self->scale;
}
