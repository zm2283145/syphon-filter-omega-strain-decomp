#include "types.h"

typedef struct { char pad[0xB8]; void* unkB8; } ObjB8;

/* Returns whether the pointer field at +0xB8 is set. */
int func_001913E0(ObjB8* o)
{
    return (o->unkB8 == 0) ^ 1;
}
