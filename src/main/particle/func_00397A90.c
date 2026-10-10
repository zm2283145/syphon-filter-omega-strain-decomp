#include "types.h"

typedef struct { char pad[0xE0]; char sub[0x48]; unsigned char enabled; } Obj128;

/* Returns the sub-block at +0xE0 when the flag at +0x128 is set, else NULL. */
void* func_00397A90(Obj128* o)
{
    if (o->enabled)
        return o->sub;
    return 0;
}
