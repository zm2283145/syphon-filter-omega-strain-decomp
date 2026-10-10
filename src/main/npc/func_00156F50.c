#include "types.h"

typedef struct { char pad[0xC]; int id; } Ref;
typedef struct { char pad[0x40]; Ref* ref; int id; } RefHolder;

/* Returns the held reference if it is null or still matches the expected id, else 0. */
Ref* func_00156F50(RefHolder* self)
{
    Ref* ref = self->ref;
    unsigned char valid = 1;
    if (!((ref != 0) ^ 1) && ref->id != self->id)
        valid = 0;
    return valid ? ref : 0;
}
