#include "types.h"

typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { char pad[0x50]; Tracked* obj; int serial; } RefHolder;

/* Returns the referenced object at +0x50 if it is still the same instance (serial matches), else 0. */
Tracked* func_0014D410(RefHolder* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
