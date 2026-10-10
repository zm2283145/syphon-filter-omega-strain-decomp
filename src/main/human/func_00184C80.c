#include "types.h"

typedef struct { char pad[0x32]; unsigned char b32; } Sub32;
typedef struct { char pad[0x3584]; Sub32* sub; } Obj3584;

/* Returns sub->b32, or 0 if there is no sub object. */
unsigned char func_00184C80(Obj3584* self)
{
    if (self->sub)
        return self->sub->b32;
    return 0;
}
