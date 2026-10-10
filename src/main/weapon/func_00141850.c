#include "types.h"

typedef struct { char pad[0x40]; float f40; } FObj;

/* Returns 3 if the float at +0x40 truncates to 0, else 0. */
int func_00141850(FObj* self)
{
    return (int)self->f40 ? 0 : 3;
}
